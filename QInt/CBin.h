#pragma once
#include "CQInt.h"
#include "CConvert.h"

class CBin
{
	string data;
public:
	CBin();
	CBin(string);

	string getData();
	// Phép trừ
	CBin operator-(CBin);
	// Phép cộng
	CBin operator+(CBin);
	// Phép nhân
	CBin operator*(CBin);
	// Phép chia
	CBin operator/(CBin);
	// Các phép toán logic, dịch bit
	CBin operator&(CBin);
	CBin operator|(CBin);
	CBin operator^(CBin);
	CBin operator~();
	CBin operator<<(const int k);
	CBin operator>>(const int k);

	~CBin();
};


