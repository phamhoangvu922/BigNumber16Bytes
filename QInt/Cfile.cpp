#include"CFile.h"
#include<fstream>
int Find_p(string &s)
{
	int tamp = 0;
	if (s[0] == '2' && s[1] == ' ')
	{
		tamp = 2;
		s.erase(0, 2);
	}
	else if (s[0] == '1')
	{
		if (s[1] == '0' && s[2] == ' ')
		{
			tamp = 10;
			s.erase(0, 3);
		}
		else if (s[1] == '6' && s[2] == ' ')
		{
			tamp = 16;
			s.erase(0, 3);
		}
	}
	return tamp;
}
void XL_String(string &s)
{
	string c;
	int p1, p2;
	cout << s << endl;
	p1 = Find_p(s);
	p2 = Find_p(s);
	if (p2 != 0) //Chuyen doi giua cac he co so
	{
		if (p1 == 2)
		{
			if (p2 == 10)
			{
				//BINTODEC
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p2 == 16)
			{
				//BINTOHEX
				s = CConvert::getInstance()->StrBintoHex(s);
			}
		}
		if (p1 == 10)
		{
			if (p2 == 2)
			{
				//DECTOBIN
				s = CConvert::getInstance()->StrDectoBin(s);
			}
			if (p2 == 16)
			{
				//DECTOHEX
				s = CConvert::getInstance()->StrDectoBin(s);
				s = CConvert::getInstance()->StrBintoHex(s);
			}
		}
		if (p1 == 16)
		{
			if (p2 == 2)
			{
				//HEXTOBIN
				s = CConvert::getInstance()->StrHextoBin(s);
			}
			if (p2 == 10)
			{
				//HEXTODEC
				s = CConvert::getInstance()->StrHextoBin(s);
				s = CConvert::getInstance()->StrBintoDec(s);
				
			}
		}
	}
	else
	{
		//rol & ror
	
		
		if (s[0] == 'r')
		{
			//ror
			if (s[2] == 'r')
			{
				s.erase(0, 4);
				if (p1 == 10)
				{
					s = CConvert::getInstance()->StrDectoBin(s);
				}
				if (p1 == 16)
				{
					s = CConvert::getInstance()->StrHextoBin(s);
				}
				
				//ROR
				CQInt temp(s);
				temp.ROR();
				s = CConvert::getInstance()->CQInttoBinaryString(temp);
				if (p1 == 10)
				{
					s = CConvert::getInstance()->StrBintoDec(s);
				}
				if (p1 == 16)
				{
					s = CConvert::getInstance()->StrBintoHex(s);
				}

			}
			//rol
			else if (s[2] == 'l')
			{
				s.erase(0, 4);
				if (p1 == 10)
				{
					s = CConvert::getInstance()->StrDectoBin(s);
				}
				if (p1 == 16)
				{
					s = CConvert::getInstance()->StrHextoBin(s);
				}
				
				//ROL
				CQInt temp(s);
				temp = temp.ROL();
				s = CConvert::getInstance()->CQInttoBinaryString(temp);
				if (p1 == 10)
				{
					s = CConvert::getInstance()->StrBintoDec(s);
				}
				if (p1 == 16)
				{
					s = CConvert::getInstance()->StrBintoHex(s);
				}
			}
		}
		//not (~)
		else if (s[0] == '~')
		{
			s.erase(0, 2);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrDectoBin(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrHextoBin(s);
			}
			CQInt temp(s);
			temp = ~temp;
			s = CConvert::getInstance()->CQInttoBinaryString(temp);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
		}
		// operator <<
		else if (s.find("<<", 0) != -1)
		{
			int vt = s.find("<<", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);       
			s2 = s.substr(vt + 3, s.length());
			int ints2 = stoi(s2);   // "Chuỗi sang số"
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
			}
			CQInt temp(s1);
			temp = temp << ints2;
			s = CConvert::getInstance()->CQInttoBinaryString(temp);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR <<
		}
		// operator >>
		else if (s.find(">>", 0) != -1)
		{
			int vt = s.find(">>", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 3, s.length());
			int ints2 = stoi(s2);   // "Chuỗi sang số"
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
			}
			CQInt temp(s1);
			//cout << s1 << endl;
			temp = temp >> ints2;
			s = CConvert::getInstance()->CQInttoBinaryString(temp);
			//cout << s << endl;
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR >>
		}
		// operator +
		else if (s.find("+", 0) != -1)
		{
			int vt = s.find("+", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1), temp2(s2);
			CQInt KQ;
			KQ = temp1 + temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(KQ);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR +
		}
		// operator -
		else if (s.find("- ", 1) != -1)      
		{
			int vt = s.find("- ", 1);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1), temp2(s2);
			CQInt KQ;
			KQ = temp1 - temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(KQ);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR -
		}          
		// operator *
		else if (s.find("*", 0) != -1)
		{
			int vt = s.find("*", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1), temp2(s2);
			CQInt KQ;
			KQ = temp1 * temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(KQ);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR *
		}
		// operator /
		else if (s.find("/", 0) != -1)
		{
			int vt = s.find("/", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1), temp2(s2);
			CQInt KQ;
			KQ = temp1 / temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(KQ);
			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR /
		}
		// operator &
		else if (s.find("&", 0) != -1)       
		{
			int vt = s.find("&", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);          
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1),temp2(s2);
			CQInt temp;
			temp = temp1 & temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(temp);
			
			if (p1 == 10)
			{
				cout << s << endl;
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR &
		}
		// operator |
		else if (s.find("|", 0) != -1)
		{
			int vt = s.find("|", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1), temp2(s2);
			CQInt temp;
			temp = temp1 | temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(temp);

			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);        
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR |
		}
		// operator ^
		else if (s.find("^", 0) != -1)
		{
			int vt = s.find("^", 0);
			string s1, s2;
			s1 = s.substr(0, vt - 1);
			s2 = s.substr(vt + 2, s.length());
			if (p1 == 10)
			{
				s1 = CConvert::getInstance()->StrDectoBin(s1);
				s2 = CConvert::getInstance()->StrDectoBin(s2);
			}
			if (p1 == 16)
			{
				s1 = CConvert::getInstance()->StrHextoBin(s1);
				s2 = CConvert::getInstance()->StrHextoBin(s2);
			}
			CQInt temp1(s1), temp2(s2);
			CQInt temp;
			temp = temp1 ^ temp2;
			s = CConvert::getInstance()->CQInttoBinaryString(temp);

			if (p1 == 10)
			{
				s = CConvert::getInstance()->StrBintoDec(s);
			}
			if (p1 == 16)
			{
				s = CConvert::getInstance()->StrBintoHex(s);
			}
			//OPERATOR ^
		}
	}
}
void ReadFile(const string Input, const string Output)
{
	ifstream f;
	ofstream p;
	
	f.open(Input);
	p.open(Output);
	while (!f.eof())
	{
		string s = "";
		getline(f, s);
		cout << "-------------------------------------------" << endl;
		XL_String(s);
		while (s[0] == '0')
		{
			s.erase(s.begin(), s.begin() + 1);
		}
		if (s == "") s = "0";
		cout << s << endl;
		p << s << endl;
	}
	f.close();
	p.close();
}


