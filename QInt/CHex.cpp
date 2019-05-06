#include "CHex.h"



CHex::CHex()
{
}

CHex::CHex(string str)
{
	data = str;
}

string CHex::getData()
{
	return data;
}

CHex CHex::operator-(CHex A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrHextoBin(x);
	string temp2 = CConvert::getInstance()->StrHextoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = C - B;
	StrResult = CConvert::getInstance()->CQInttoHex(D);
	CHex Result(StrResult);
	return Result;
}

CHex CHex::operator+(CHex A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrHextoBin(x);
	string temp2 = CConvert::getInstance()->StrHextoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = B + C;
	StrResult = CConvert::getInstance()->CQInttoHex(D);
	CHex Result(StrResult);
	return Result;
}

CHex CHex::operator*(CHex A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrHextoBin(x);
	string temp2 = CConvert::getInstance()->StrHextoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = B * C;
	StrResult = CConvert::getInstance()->CQInttoHex(D);
	CHex Result(StrResult);
	return Result;
}

CHex CHex::operator/(CHex A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrHextoBin(x);
	string temp2 = CConvert::getInstance()->StrHextoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = C / B;
	StrResult = CConvert::getInstance()->CQInttoHex(D);
	CHex Result(StrResult);
	return Result;
}

CHex::~CHex()
{
}