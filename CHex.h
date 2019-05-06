#pragma once
#include "CQInt.h"
#include "CConvert.h"

class CHex
{
	string data;
public:
	CHex();
	CHex(string);

	string getData();
	// Phép trừ
	CHex operator-(CHex);
	// Phép cộng
	CHex operator+(CHex);
	// Phép nhân
	CHex operator*(CHex);
	// Phép chia
	CHex operator/(CHex);

	~CHex();
};


