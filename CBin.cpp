#include "CBin.h"



CBin::CBin()
{
}

CBin::CBin(string str)
{
	data = str;
}

string CBin::getData()
{
	return data;
}

CBin CBin::operator-(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = C - B;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}

CBin CBin::operator+(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = B + C;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}

CBin CBin::operator*(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = B * C;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}

CBin CBin::operator/(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = C / B;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}

CBin CBin::operator&(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = C & B;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}
CBin CBin:: operator|(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = C | B;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}
CBin CBin::operator^(CBin A)
{
	string StrResult;
	CQInt B(A.getData());
	CQInt C(data);
	CQInt D = C ^ B;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}
CBin CBin::operator~()
{
	string StrResult;
	CQInt C(data);
	CQInt D = ~C;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}
CBin CBin::operator<<(const int k)
{
	string StrResult;
	CQInt C(data);
	CQInt D = C << k;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}
CBin CBin::operator>>(const int k)
{
	string StrResult;
	CQInt C(data);
	CQInt D = C >> k;
	StrResult = CConvert::getInstance()->CQInttoBinaryString(D);
	CBin Result(StrResult);
	return Result;
}
CBin::~CBin()
{
}
