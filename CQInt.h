#pragma warning(disable:4996)
#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
#include <string>
using namespace std;


#define _BIT_INT64_		64
#define _POSITION		((Binary.size() - 1 - i) / _BIT_INT64_) //Vị trí Vùng 4 Byte cần ghi vào.
#define _SHIFT_OFFSET	(((Binary.size() - 1) % _BIT_INT64_) - (i % _BIT_INT64_)) //Số bit cần dời.

class CQInt
{
protected:
	__int64 ArrayBits[2] = { 0,0 };
public:

	//Hàm khỏi tạo bằng cách truyền vào chuỗi bit nhị phân.
	CQInt();
	CQInt(const string&);
	//Hàm hủy dữ liệu của kiểu QInt.
	~CQInt();

	//___________________________________________________________________

	//Hàm lấy data.
	__int64* getData();

	//___________________________________________________________________

	//Kiểm tra =0.
	bool isZero();

	//Khoi Tao Bang 0
	void Init(); 
	//Gan Truc Tiep 1 Chuoi [[NEED TO FIX]]]
	void operator = (const string &K);
	//Gan 1 CQInt Khac
	void operator = (const CQInt &K);  
	//___________________________________________________________________

	//Lay Bit Khu K
	int GetBit(int K); 
	//Bat bit 1 Tai vi Tri K
	void TurnOnBit(int K); 
	//Tat bit Tai vi Tri K
	void TurnOffBit(int K);		
	//Xuat //[[[[[NEED TO FIX]]]]]]
	void Get_Data();					

	//___________________________________________________________________

	//Phép phủ định.
	CQInt& operator ~ ();
	//Operator AND
	CQInt operator & (CQInt K);	
	//Operator OR
	CQInt operator | (CQInt K);
	//Operaror XOR
	CQInt operator ^ (CQInt K);			

	//___________________________________________________________________

	//Operator Shift Left Logical 
	CQInt operator <<(const int &K);	
	//Operator Shift Arithmetic Right 
	CQInt operator >>(const int &K);	

	//___________________________________________________________________

	//Rotate Left 
	CQInt ROL();	
	//Rotate Right
	CQInt ROR();	
	// Phép trừ
	CQInt operator-(CQInt);
	// Phép cộng
	CQInt operator+(CQInt); 
	// Phép nhân
	CQInt operator*(CQInt); 
	// Phép chia
	CQInt operator/(CQInt);
	
};

#endif 

