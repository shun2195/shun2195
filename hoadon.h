#ifndef HOADON_H
#define HOADON_H

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "thanhtoan.h"

using namespace std;

class HoaDon{
	private:
		string mahd;
		ThanhToan tt;
	public:
		HoaDon();
		HoaDon(string mahd, const ThanhToan& tt);
		~HoaDon();
		
		string Set_ma_hd(string mahd);
};

void Hoadon_theophongkh();
void Hoadon_theongay();
void Lichsu_luutru();


#endif