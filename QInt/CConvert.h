#pragma once
#include "CQInt.h"
#include<math.h>
#define _MAX_BIT_	128


//Áp dụng design patter: singleton cho lớp chuyển đổi này
class CConvert
{
protected:
	static CConvert *m_Instance;
	//Hàm tạo.
	CConvert();
	//Hàm hủy.
	~CConvert();
public:
	//Hàm lấy đối tượng.
	static CConvert* getInstance();

	//___________________________________________________________________
	
	//NHÓM THỰC HIỆN CHỨC NĂNG THEO YÊU CẦU ĐỒ ÁN

	//Hàm chuyển đổi số QInt từ hệ nhị phân sang hệ thập phân 
	string CQIntBintoDecString(string&);
	//Hàm chuyển đổi số QInt từ hệ nhị phân sang hệ 16
	string CQIntBintoHexString(string&);
	//Hàm chuyển đổi số QInt từ hệ thập phân sang hệ nhị phân 
	string CQIntDectoBinaryString(string&);
	//Hàm chuyển đổi số QInt từ hệ thập phân sang hệ 16 
	string CQIntDectoHexString(string&);
	//Hàm chuyển đổi số QInt từ hệ 16 sang hệ thập phân 
	string CQIntHextoDecString(string&);
	//Hàm chuyển đổi số QInt từ hệ 16 sang hệ nhị phân 
	string CQIntHextoBinaryString(string&);


	//___________________________________________________________________

	//NHÓM HỖ TRỢ

	//Hàm chuyển từ QInt sang bù 2
	static CQInt CQInttoTwosComplement(CQInt);
	//Hàm chuyển từ QInt sang nhị phân
	string CQInttoBinaryString(CQInt&);
	//Hàm chuyển từ QInt sang hệ 16
	string CQInttoHex(CQInt&);
	//Hàm chuyển từ QInt sang hệ thập phân
	string CQInttoDec(CQInt&);


	//Hàm chuyển từ nhị phân sang thập phân
	string StrBintoDec(string&);
	//Hàm chuyển từ hệ thập phân sang nhị phân
	string StrDectoBin(string&);
	//Hàm chuyển từ hệ 16 thành nhị phân
	string StrHextoBin(string&);
	//Hàm chuyển từ nhị phân thành hệ 16
	string StrBintoHex(string&);
	//Hàm chuyển chuỗi int sang bù 2
	string StrInttoTwosComplement(string&);

	//Hàm trừ số nguyên dạng string
	string SubNumberString(string a, string b);
	//Hàm trừ số nguyên dạng string
	string AddNumberString(string a, string b);
	//Hàm nhân số nguyên dạng string
	string MultiplyNumberString(string a, string b);
	//Hàm chia số nguyên dạng string
	string DivisionNumberString(string number, string divisor);
	//Hàm lũy thừa số nguyên dạng string
	string Power(int a, int n);
	friend bool operator > (string a, string b);
};

	
