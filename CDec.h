#pragma once
#include "CConvert.h"
#include "CQInt.h"

class CDec
{
	string data;
public:
	CDec();
	CDec(string);

	string getData();
	// Phép trừ
	CDec operator-(CDec);
	// Phép cộng
	CDec operator+(CDec);
	// Phép nhân
	CDec operator*(CDec);
	// Phép chia
	CDec operator/(CDec);

	~CDec();
};

