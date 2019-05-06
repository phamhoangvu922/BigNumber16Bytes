#include "CQInt.h"
#include"CConvert.h"

CQInt::CQInt()
{

}

//Lớp số nguyên lớn được xây dụng cới dữ liệu được lưu theo Little Endian.
CQInt::CQInt(const string &Binary)
{
	this->Init();
	for (int i = Binary.length() - 1; i >= 0; i--)
	{
		if (Binary[i] == '1')
		{
			this->TurnOnBit(Binary.length() - i - 1);
		}
		else this->TurnOffBit(Binary.length() - i - 1);
	}
}

CQInt::~CQInt()
{
}

__int64* CQInt::getData()
{
	return ArrayBits;
}



CQInt& CQInt::operator ~ ()
{
	ArrayBits[0] = ~ArrayBits[0];
	ArrayBits[1] = ~ArrayBits[1];

	return *this;
}

bool CQInt::isZero()
{
	for (int i = 0; i < 2; i++)
	{
		if (ArrayBits[i] != 0)
		{
			return false;
		}
	}
	return true;
}

void CQInt::Init() //Khoi tao bang 0
{
	ArrayBits[0] = 0;
	ArrayBits[1] = 0;
}
//_____________________________________________
void CQInt :: operator =  (const string &K) //Operator Gan truc tiep 1 Chuoi //CAN XOA
{ 
	this->Init();
	__int64 tamp = 0;
	for (int i = K.length() - 1; i >= 0; i--)
	{
		if (K[i]=='1') this->TurnOnBit(K.length()-1-i); else this->TurnOffBit(K.length()-1-i);
	}
}
void CQInt :: operator =  (const CQInt &K) //Operator Gan CQInt
{
	ArrayBits[0] = K.ArrayBits[0];
	ArrayBits[1] = K.ArrayBits[1];
}
//_____________________________________________
int  CQInt::GetBit(int K) //Lay Bit Vi Tri k
{
	return (ArrayBits[K / 64] >> (K % 64)) & 1;
}
void CQInt::TurnOnBit(int K)//Bat Bit Vi Tri k Len 1
{
	__int64 tamp = 1;
	ArrayBits[K / 64] = ArrayBits[K / 64] | (tamp << (K % 64));
}
void CQInt::TurnOffBit(int K)//Tat Vi Tri Bit K=0
{
	__int64 tamp = 1;
	ArrayBits[K / 64] = ArrayBits[K / 64] & (~(tamp << (K % 64)));
}
//_____________________________________________

//_____________________________________________
CQInt CQInt :: operator &  (CQInt K) //Operator & (AND)
{
	CQInt tamp; tamp.Init();
	for (int i = 0; i < 128; i++)
	{
		if (K.GetBit(i) & this->GetBit(i)) tamp.TurnOnBit(i);
	}
	return tamp;
}
CQInt CQInt :: operator |  (CQInt K) //Operator | (OR)
{
	CQInt tamp; tamp.Init();
	for (int i = 0; i < 128; i++)
	{
		if (K.GetBit(i) | this->GetBit(i)) tamp.TurnOnBit(i);
	}
	return tamp;
}
CQInt CQInt :: operator ^  (CQInt K) //Operator ^ (XOR)
{
	CQInt tamp; tamp.Init();
	for (int i = 0; i < 128; i++)
	{
		if (K.GetBit(i) ^ this->GetBit(i)) tamp.TurnOnBit(i);
	}
	return tamp;
}
//_____________________________________________
CQInt CQInt :: operator <<(const int &K) //Operator Shift Left Logical
{
	int tamp;			
	for (int i = 127; i >= K; i--)
	{
		tamp = this->GetBit(i - K);
		if (tamp) this->TurnOnBit(i); else this->TurnOffBit(i);
	}
	for (int i = 0; i < K; i++) this->TurnOffBit(i);
	return (*this);
}
CQInt CQInt :: operator >>(const int &K) //Operator Shift Arithmetic Right
{
	int tamp;
	int dau = this->GetBit(127);
	for (int i = 0; i < 128 - K; i++)
	{
		tamp = this->GetBit(i + K);
		if (tamp) this->TurnOnBit(i); else this->TurnOffBit(i);
	}
	if (dau) for (int i = 127; i > 127 - K; i--) this->TurnOnBit(i);
	else for (int i = 127; i > 127 - K; i--) this->TurnOffBit(i);
	if (dau) this->TurnOnBit(127); else this->TurnOffBit(127);
	return (*this);
}
//_____________________________________________
CQInt CQInt::ROL() //Rotate Left
{
	int Bit_127 = (*this).GetBit(127);
	*this=*this << 1;
	if (Bit_127) (*this).TurnOnBit(0); else (*this).TurnOffBit(0);
	return (*this);
}
CQInt CQInt::ROR() //Rotate Right
{
	int Bit_0 = (*this).GetBit(0);
	*this = *this >> 1;
	if (Bit_0) (*this).TurnOnBit(127); else (*this).TurnOffBit(127);
	return (*this);
}
CQInt CQInt :: operator-(CQInt A)
{
	string StrResult;
	string tempStr1, tempStr2;
	tempStr1 = CConvert::getInstance()->CQInttoBinaryString(*this);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr1 = CConvert::getInstance()->StrBintoDec(tempStr1);		// chuyển chuỗi nhị phân sang thập phân
	tempStr2 = CConvert::getInstance()->CQInttoBinaryString(A);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr2 = CConvert::getInstance()->StrBintoDec(tempStr2);		// chuyển chuỗi nhị phân sang thập phân
	StrResult = CConvert::getInstance()->SubNumberString(tempStr1, tempStr2);
	StrResult = CConvert::getInstance()->StrDectoBin(StrResult);
	CQInt Result(StrResult);
	return Result;
}

CQInt CQInt :: operator+(CQInt A)
{
	CQInt result = *this;
	CQInt temp;
	while (!(A.isZero()))
	{
		//Ctemp mang theo những bit cùng là 1 giữa 2 số.
		temp = result & A;
		//thực hiện cộng 2bit khác nhau 0,1
		result = result ^ A;
		//Đưa các bit cùng là 1 bên 1 bit để tiếp tục phép cộng cần thực hiện.
		A = temp << 1;
	}
	return result;
}

CQInt CQInt :: operator*(CQInt A)
{
	string StrResult;
	string tempStr1, tempStr2;
	tempStr1 = CConvert::getInstance()->CQInttoBinaryString(*this);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr1 = CConvert::getInstance()->StrBintoDec(tempStr1);		// chuyển chuỗi nhị phân sang thập phân
	tempStr2 = CConvert::getInstance()->CQInttoBinaryString(A);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr2 = CConvert::getInstance()->StrBintoDec(tempStr2);		// chuyển chuỗi nhị phân sang thập phân
	StrResult = CConvert::getInstance()->MultiplyNumberString(tempStr1, tempStr2);  // 
	StrResult = CConvert::getInstance()->StrDectoBin(StrResult);
	CQInt Result(StrResult);
	return Result;
}
CQInt CQInt :: operator/(CQInt A)
{
	string StrResult;
	string tempStr1, tempStr2;
	tempStr1 = CConvert::getInstance()->CQInttoBinaryString(*this);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr1 = CConvert::getInstance()->StrBintoDec(tempStr1);		// chuyển chuỗi nhị phân sang thập phân
	tempStr2 = CConvert::getInstance()->CQInttoBinaryString(A);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr2 = CConvert::getInstance()->StrBintoDec(tempStr2);		// chuyển chuỗi nhị phân sang thập phân
	StrResult = CConvert::getInstance()->DivisionNumberString(tempStr1, tempStr2);
	StrResult = CConvert::getInstance()->StrDectoBin(StrResult);
	CQInt Result(StrResult);
	return Result;
}
