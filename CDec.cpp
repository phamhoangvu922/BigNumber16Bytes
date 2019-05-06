#include "CDec.h"



CDec::CDec()
{
}

CDec::CDec(string str)
{
	data = str;
}

string CDec::getData()
{
	return data;
}

CDec CDec::operator-(CDec A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrDectoBin(x);
	string temp2 = CConvert::getInstance()->StrDectoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = C - B;
	StrResult = CConvert::getInstance()->CQInttoDec(D);
	CDec Result(StrResult);
	return Result;
}

CDec CDec::operator+(CDec A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrDectoBin(x);
	string temp2 = CConvert::getInstance()->StrDectoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = C + B;
	StrResult = CConvert::getInstance()->CQInttoDec(D);
	CDec Result(StrResult);
	return Result;
}

CDec CDec::operator*(CDec A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrDectoBin(x);
	string temp2 = CConvert::getInstance()->StrDectoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = B * C;
	StrResult = CConvert::getInstance()->CQInttoDec(D);
	CDec Result(StrResult);
	return Result;
}

CDec CDec::operator/(CDec A)
{
	string StrResult;
	string x = A.getData();
	string temp1 = CConvert::getInstance()->StrDectoBin(x);
	string temp2 = CConvert::getInstance()->StrDectoBin(data);
	CQInt B(temp1);
	CQInt C(temp2);
	CQInt D = C / B;
	StrResult = CConvert::getInstance()->CQInttoDec(D);
	if (StrResult == "") StrResult = "0";
	CDec Result(StrResult);
	return Result;
}


CDec::~CDec()
{
}
