#include "CConvert.h"
#include"sstream"


CConvert::CConvert()
{
}

CConvert::~CConvert()
{
	if (m_Instance != NULL)
	{
		delete m_Instance;
	}
}

CConvert* CConvert::m_Instance = NULL;


CConvert* CConvert::getInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CConvert;
	}
	return m_Instance;
}

//Hàm chia một chuỗi số thập phân cho 2.
//Source: https://www.geeksforgeeks.org/divide-large-number-represented-string/
string StrDivTwo(string &number)
{
	string Result;
	int Temp = 0;

	for (int i = 0; i < number.size(); i++)
	{
		Temp = Temp * 10 + (number[i] - '0');

		if (i > 0 || (i == 0 && Temp >= 2))
		{
			Result.push_back((Temp / 2) + '0');
		}

		Temp = Temp % 2;
	}

	return Result;
}

//Kiểm tra số âm.
bool CheckNegative(string &s)
{
	if (s[0] == '-')
	{
		s.erase(s.begin()+0);
		return true;
	}
	return false;
}

string CConvert::StrDectoBin(string&  strDec)
{
	string temp = strDec;
	string result;
	bool negative = false;
	//Kiểm tra số có âm không?
	//bool negative = CheckNegative(strDec);
	if (strDec[0] == '-')
	{
		strDec.erase(strDec.begin());
		negative = true;
	}

	//Chuyển đổi chuỗi số nguyên sang dãy bit
	//Source: https://www.quora.com/How-do-I-convert-a-large-decimal-number-into-binary-using-string-type-array-in-C-programming
	while (strDec != "")
	{
		result.push_back(((strDec[strDec.size() - 1] - '0') % 2) + '0');
		strDec = StrDivTwo(strDec);
	}
	reverse(result.begin(), result.end());
	//Nếu là chuỗi ban đầu là số âm.
	if (negative == true)
	{
		CQInt QInt(result); //Đưa vào số kiểu CQInt.
		QInt = CQInttoTwosComplement(QInt); //Chuyển sang dạng bù 2.
		result = CQInttoBinaryString(QInt); //Đưa lại về nhị phân.
	}
	strDec = temp;
	return result;
}

CQInt CConvert::CQInttoTwosComplement(CQInt QInt)
{
	CQInt result = ~QInt;
	result = result + CQInt("1");
	return result;
}

string CConvert::CQInttoBinaryString(CQInt &QInt)
{
	string tamp;
	for (int i = 0; i < 128; i++) tamp = to_string(QInt.GetBit(i)) + tamp;
	if (tamp.find('/', 0) != -1) tamp[tamp.find('/', 0)] = '1';
	while (tamp[0] == '0') tamp.erase(0, 1);
	if (tamp.length() == 0) tamp = "0";
	return tamp;
}
string CConvert::StrHextoBin(string& strDec)
{
	string binary;

	for (int i = 0; i < strDec.size(); i++)
	{
		if (strDec[i] == '0') { binary += "0000"; }  // 0 từ Hex -> Bin
		else if (strDec[i] == '1') { binary += "0001"; } //
		else if (strDec[i] == '2') { binary += "0010"; }//
		else if (strDec[i] == '3') { binary += "0011"; }//				 	
		else if (strDec[i] == '4') { binary += "0100"; }//            
		else if (strDec[i] == '5') { binary += "0101"; }//
		else if (strDec[i] == '6') { binary += "0110"; }//
		else if (strDec[i] == '7') { binary += "0111"; }//
		else if (strDec[i] == '8') { binary += "1000"; }//
		else if (strDec[i] == '9') { binary += "1001"; }//
		else if (strDec[i] == 'A' || strDec[i] == 'a') { binary += "1010"; }//
		else if (strDec[i] == 'B' || strDec[i] == 'b') { binary += "1011"; }//
		else if (strDec[i] == 'C' || strDec[i] == 'c') { binary += "1100"; }//
		else if (strDec[i] == 'D' || strDec[i] == 'd') { binary += "1101"; }//
		else if (strDec[i] == 'E' || strDec[i] == 'e') { binary += "1110"; }//
		else if (strDec[i] == 'F' || strDec[i] == 'f') { binary += "1111"; } // F từ Hex -> Bin
	}
	return binary;
}
string CConvert::StrBintoHex(string& strHex)
{
	string Temp;
	string Result;
	while (strHex.size() % 4 != 0)
	{
		strHex.insert(strHex.begin(), '0'); // Thêm số không để đủ 4 bit
	}
	for (int i = 0; i < strHex.size(); i++)
	{
		Temp.push_back(strHex[i]);
		if (i % 4 == 3) //Đã nhận được 4 bit.
		{
			if (Temp == "0000") { Result.push_back('0'); }
			else if (Temp == "0001") { Result.push_back('1'); }
			else if (Temp == "0010") { Result.push_back('2'); }
			else if (Temp == "0011") { Result.push_back('3'); }
			else if (Temp == "0100") { Result.push_back('4'); }
			else if (Temp == "0101") { Result.push_back('5'); }
			else if (Temp == "0110") { Result.push_back('6'); }
			else if (Temp == "0111") { Result.push_back('7'); }
			else if (Temp == "1000") { Result.push_back('8'); }
			else if (Temp == "1001") { Result.push_back('9'); }
			else if (Temp == "1010") { Result.push_back('A'); }
			else if (Temp == "1011") { Result.push_back('B'); }
			else if (Temp == "1100") { Result.push_back('C'); }
			else if (Temp == "1101") { Result.push_back('D'); }
			else if (Temp == "1110") { Result.push_back('E'); }
			else if (Temp == "1111") { Result.push_back('F'); }
			Temp = ""; // khởi tạo lại chuỗi
		}
	}
	return Result;
}
string CConvert::StrInttoTwosComplement(string& strBin)
{
	string Temp = strBin;
	char temp;
	// Đảo bit
	for (int i = 0; i < strBin.size(); i++)
	{	if (Temp[i] == '0')
		{
			Temp[i] = '1';
		}
		else if(Temp[i] == '1')
		{
			Temp[i] ='0';
		}
	}
	// Cộng 1
	for (int i = strBin.size(); i > 0; i--)
	{
		if (Temp[i] == '0')
		{
			Temp[i] = '1';
			return Temp;
		}
		Temp[i] = '0';
	}
	return Temp ;
}
string CConvert::SubNumberString(string a, string b)
{
	int Temp = 0;
	bool Negative = false;
	if (a == b) return "0";
	if (a == "0") return '-' + b;
	else if (b == "0") return a;
	if (a[0] == '-')
	{
		a.erase(a.begin());
		if (b[0] == '-')
		{
			b.erase(b.begin());
			if (a.size() == b.size())
			{
				if (strcmp(a.c_str(), b.c_str()) > 0)
				{
					Negative = true;
				}
			}
			else if (strcmp(a.c_str(), b.c_str()) < 0)
			{
				Negative = true;
			}
		}
		else
		{
			Negative = true;
			if (a.size() > b.size())
			{
				while (a.size() != b.size())
				{
					b.insert(b.begin(), '0');
				}
			}
			else
			{
				while (a.size() != b.size())
				{
					a.insert(a.begin(), '0');
				}
			}
			for (int i = a.size() - 1; i > -1; i--)
			{
				Temp = Temp + a[i] + b[i] - 2 * '0';
				a[i] = (Temp % 10) + '0';
				Temp = Temp / 10;
			}
			while (a[0] == '0')
			{
				a.erase(a.begin());
			}

			//Nếu vẫn còn dư (Temp != 0)
			if (Negative == true)
			{
				a.insert(a.begin(), '-');
			}
			return a;
		}
	}
	else
	{
		if (b[0] == '-')
		{
			b.erase(b.begin());
			if (strcmp(a.c_str(), b.c_str()) < 0)
			{
				if (a.size() > b.size())
				{
					while (a.size() != b.size())
					{
						b.insert(b.begin(), '0');
					}
				}
				else
				{
					while (a.size() != b.size())
					{
						a.insert(a.begin(), '0');
					}
				}
				for (int i = a.size() - 1; i > -1; i--)
				{
					Temp = Temp + a[i] + b[i] - 2 * '0';
					a[i] = (Temp % 10) + '0';
					Temp = Temp / 10;
				}
				while (a[0] == '0')
				{
					a.erase(a.begin());
				}

				//Nếu vẫn còn dư (Temp != 0)
				if (Negative == true)
				{
					a.insert(a.begin(), '-');
				}
				return a;
			}
			else
			{
				if (a.size() > b.size())
				{
					while (a.size() != b.size())
					{
						b.insert(b.begin(), '0');
					}
				}
				else
				{
					while (a.size() != b.size())
					{
						a.insert(a.begin(), '0');
					}
				}
				for (int i = a.size() - 1; i > -1; i--)
				{
					Temp = Temp + a[i] + b[i] - 2 * '0';
					a[i] = (Temp % 10) + '0';
					Temp = Temp / 10;
				}
				while (a[0] == '0')
				{
					a.erase(a.begin());
				}

				//Nếu vẫn còn dư (Temp != 0)
				if (Negative == true)
				{
					a.insert(a.begin(), '-');
				}
				return a;
			}
		}
		else
		{
			if (a.size() < b.size())
			{
				while (a.size() != b.size())
				{
					a.insert(a.begin(), '0');
				}
				if (strcmp(a.c_str(), b.c_str()) < 0)
				{
					Negative = true;
				}
			}
			else
			{

				while (a.size() != b.size())
				{
					b.insert(b.begin(), '0');
				}
				if (strcmp(a.c_str(), b.c_str()) < 0)
				{

					Negative = true;
				}
			}
			
		}
	}
	//Thêm các số 0 vào đầu mỗi chuỗi.
	if (a.size() > b.size())
	{
		while (a.size() != b.size())
		{
			b.insert(b.begin(), '0');
		}
	}
	else
	{
		while (a.size() != b.size())
		{
			a.insert(a.begin(), '0');
		}
	}

	//Kiểm tra a hay b lớn hơn và chuyển a thành số lớn hơn.
	if (strcmp(a.c_str(), b.c_str()) < 0)
	{
		string TempStr = a;
		a = b;
		b = TempStr;
	}

	//Thực hiện phép trừ.
	for (int i = a.size() - 1; i > -1; i--)
	{
		if ((a[i] - Temp) < b[i])
		{
			a[i] = (10 + a[i] - b[i] - Temp) + '0';
			Temp = 1;
		}
		else
		{
			a[i] = a[i] - b[i] - Temp + '0';
			Temp = 0;
		}
	}

	//Xóa các số 0 thừa.
	while (a[0] == '0' && a.size() != 1)
	{
		a.erase(a.begin());
	}

	//Nếu vẫn còn dư (Temp != 0)
	if (Negative == true)
	{
		a.insert(a.begin(), '-');
	}
	return a;
}
string CConvert::StrBintoDec(string& strBin)             
{
	string dec;
	bool SoAm = false;
	string temp = "0";
	string pown;
	string resulttemp;
	if (strBin[0] == '1'&& strBin.length() == 128) //Kiem Tra So Am
	{
		SoAm = true;
		int i = strBin.length() - 1;
		while (i >= 0 && strBin[i] == '0') i = i - 1;
		strBin[i] = '0';
		for (int j = i + 1; j < strBin.length(); j++)strBin[j] = '1';
		for (int i = 0; i < strBin.length(); i++)
			if (strBin[i] == '1') strBin[i] = '0'; else strBin[i] = '1';
	}
	for (int i = strBin.size(); i > 0; i--)
	{
		resulttemp = "0";
		//temp = temp + (strBin[strBin.size() - i] - '0')*pown;
		if (strBin[strBin.size() - i] == '1')
		{
			resulttemp =  CConvert::getInstance()->Power(2, i - 1);
		}
		temp = CConvert::getInstance()->AddNumberString(temp, resulttemp);
	}
	dec = temp;
	if (SoAm) dec = '-' + dec;
	return dec;
}
string CConvert::AddNumberString(string a, string b)
{
	bool Negative = false;
	if (a[0] == '-' && b[0] != '-')
	{
		a.erase(a.begin());
		a = CConvert::getInstance()->SubNumberString(b, a);
	}
	else
	{
		if (b[0] == '-' && a[0] != '-')
		{
			b.erase(b.begin());
			a = CConvert::getInstance()->SubNumberString(a, b);
		}
		else
		{
			int Temp = 0;
			if (a[0] == '-' && b[0] == '-')
			{
				a.erase(a.begin());
				Negative = true;
				b.erase(b.begin());
			}

			//Thêm các số 0 vào đầu mỗi chuỗi.
			if (a.size() > b.size())
			{
				while (a.size() != b.size())
				{
					b.insert(b.begin(),'0');
				}
			}
			else
			{
				while (a.size() != b.size())
				{
					a.insert(a.begin(),'0');
				}
			}

			//Tiến hành cộng.
			for (int i = a.size() - 1; i > -1; i--)
			{
				Temp = Temp + a[i] + b[i] - 2*'0';
				a[i] = (Temp%10) + '0';
				Temp = Temp/10;
			}

			//Nếu vẫn còn dư (Temp != 0)
			if (Temp != 0)
			{
				a.insert(a.begin(), Temp + '0');
				Temp = 0;
			}
		}
	}

	//Xóa các số 0 thừa.
	while (a[0] == '0')
	{
		a.erase(a.begin());
	}
	if (Negative == true)
	{
		a.insert(a.begin(), '-');
	}
	return a;
}
string CConvert::MultiplyNumberString(string a, string b)
{
	string Result = "0";
	string TempStr;
	int Temp = 0;
	bool Negative = false;
	if (a == "0" || b == "0")
	{
		return "0";
	}
	if (a[0] == '-')
	{
		a.erase(a.begin());
		if (b[0] != '-')
		{
			Negative = true;
			
		}
		else  b.erase(b.begin());
	}
	else if (b[0] == '-')
	{
		Negative = true;
		b.erase(b.begin());
	}
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = a.size() - 1; j > -1; j--)
		{
			Temp = Temp + (a[j] - '0') * (b[b.size() - i - 1] - '0');
			TempStr.push_back((Temp % 10) + '0');
			Temp = Temp / 10;
		}
		if (Temp != 0) //Nếu vẫn còn Temp.
		{
			TempStr.push_back(Temp + '0');
			Temp = 0;
		}

		//Đảo chuỗi.
		reverse(TempStr.begin(), TempStr.end());

		//Thêm các số 0 cần thiết vào sau.
		for (int j = 0; j < i; j++)
		{
			TempStr.push_back('0');
		}

		//Cộng Result và Temp.
		Result = CConvert::getInstance()->AddNumberString(Result, TempStr);
		TempStr.clear(); //Dọn chuỗi tạm để dùng cho các bước tiếp theo.
	}
	if (Negative == true)
	{
		Result.insert(Result.begin(), '-');
	}
	return Result;
}
bool operator >(string a, string b)
{
	if (a.size() > b.size())
	{
		return true;
	}
	else if (a.size() < b.size())
	{
		return false;
	}
	else
	{
		// equal size.. check each digit
		int index = a.size() - 1;
		for (int i = index; i >= 0; i--)
		{
			int digit1 = a[a.size() - i-1] -'0';
			int digit2 = b[b.size() - i-1] -'0';
			if (digit1 > digit2)
				return true;
			else if (digit1 < digit2)
				return false;
		}
	}
	return false;
}
string CConvert::DivisionNumberString(string Dividend, string divisor)
{
	if (divisor == "0")
	{
		return "mau so bang 0";
	}
	else if (Dividend == "0")
	{
		return "0";
	}
	// find prefix of number that is larger 
	// than divisor. 
	bool Negative = false;
	if (Dividend[0] == '-')
	{
		Dividend.erase(Dividend.begin());
		if (divisor[0] != '-')
		{
			Negative = true;

		}
		else  divisor.erase(divisor.begin());
	}
	else if (divisor[0] == '-')
	{
		Negative = true;
		divisor.erase(divisor.begin());
	}
	string dividend = Dividend;

	int divisorLength = divisor.size();

	int dividendLength = dividend.size();
	std::string tempDividendString = "";
	std::string quotient = "";
	for (int i = dividendLength - 1; i >= 0; i--)
	{
		int digit = Dividend[dividendLength - i - 1] - '0';
		tempDividendString += '0' + digit;

		// get the quotient value
		if (static_cast<int>(tempDividendString.length()) >= divisorLength)
		{
			string tempDividend(tempDividendString);
			string tempDivisor(divisor);

			int newDigit = 0;
			if (tempDividend > divisor )
			{
				newDigit = 1;
				string temp = CConvert::getInstance()->AddNumberString(tempDivisor, divisor);
				while (tempDividend  > temp || tempDividend == temp)
				{
					tempDivisor = CConvert::getInstance()->AddNumberString(tempDivisor, divisor);
					temp = tempDivisor;
					newDigit++;
				}
				if (newDigit != 1)
				{
					newDigit--;
				}
			}
			tempDivisor = divisor;
			string multiplier(std::to_string(newDigit));
			string temp = CConvert::getInstance()->MultiplyNumberString(tempDivisor, multiplier);
			tempDividend = CConvert::getInstance()->SubNumberString(tempDividend,temp);

			tempDividendString = tempDividend;

			quotient += '0' + newDigit;
		}
		else
		{
			quotient += '0';
		}

	}
	while (quotient.length() != 0 && quotient[0] == '0')
	{
		quotient.erase(0, 1);
	}
	//if divisor is greater than number 
	if (quotient.length() == 0)
		return "0";

	// else return ans 
	if (Negative == true)
	{
		quotient.insert(quotient.begin(), '-');
	}
	return quotient;
}
string CConvert::Power(int a, int n)
{
	string Result;
	if (a > -1)
	{
		//Nếu a > 1
		if (a > 1)
		{
			int Pow = n;

			if (n > (_BIT_INT64_/2 - 1) * 2 / a) //Tránh trường hợp tràn số.
			{
				Pow = (_BIT_INT64_ / 2 - 1) * 2 / a;
			}

			Result = to_string((unsigned _int32)pow(a, Pow));


			//Phần có khả năng bị tràn số sẽ được nhân theo nhân chuỗi.
			for (int i = Pow + 1; i <= n; i++)
			{
				Result = CConvert::getInstance()->MultiplyNumberString(Result, to_string(a));
			}
		}
		else
		{
			Result.push_back(a + '0');
		}
	}

	return Result;
}


string CConvert::CQInttoHex(CQInt& QInt)
{
	string temp = CConvert::getInstance()->CQInttoBinaryString(QInt);
	string result = CConvert::getInstance()->StrBintoHex(temp);
	return result;
}

string CConvert::CQInttoDec(CQInt& QInt)
{
	string temp = CConvert::getInstance()->CQInttoBinaryString(QInt);
	string result = CConvert::getInstance()->StrBintoDec(temp);
	return result;
}

string CConvert::CQIntBintoDecString(string& str)
{
	CQInt A(str);
	string dec = CConvert::getInstance()->CQInttoDec(A);
	return dec;
}

string CConvert::CQIntBintoHexString(string& str)
{
	CQInt A(str);
	string hex = CConvert::getInstance()->CQInttoHex(A);
	return hex;
}

string CConvert::CQIntDectoBinaryString(string& str)
{
	string temp = CConvert::getInstance()->StrDectoBin(str);
	CQInt A(temp);
	string bin = CConvert::getInstance()->CQInttoBinaryString(A);
	return bin;
}

string CConvert::CQIntDectoHexString(string& str)
{
	string temp = CConvert::getInstance()->StrDectoBin(str);
	CQInt A(temp);
	string hex = CConvert::getInstance()->CQInttoHex(A);
	return hex;
}

string CConvert::CQIntHextoDecString(string& str)
{
	string temp = CConvert::getInstance()->StrHextoBin(str);
	CQInt A(temp);
	string dec = CConvert::getInstance()->CQInttoDec(A);
	return dec;
}

string CConvert::CQIntHextoBinaryString(string& str)
{
	string temp = CConvert::getInstance()->StrHextoBin(str);
	CQInt A(temp);
	string bin = CConvert::getInstance()->CQInttoBinaryString(A);
	return bin;
}

