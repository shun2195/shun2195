#ifndef PHONG_H
#define PHONG_H

#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>

#include "khachhang.h"

using namespace std;

extern string qlph_file_name;
class Phong{
	private:
		string Ma_phong;
		string Loai_phong;
		double Don_gia;
		string Trang_Thai;
		KhachHang kh;
		
	public:
		Phong();
		Phong(string Ma_phong, string Loai_phong, double Don_gia, string Trang_Thai, const KhachHang& kh);

		void Set_ma_phong(string Ma_phong);
		void Set_loai_phong(string Loai_phong);
		void Set_don_gia(double Don_gia);
		void Set_trang_thai(string Trang_thai);
		
		string Get_ma_phong();
		string Get_loai_phong();
		double Get_don_gia();
		string Get_trang_thai();
		string Get_ma_kh_ph();
		string Get_hoten_kh_ph();

};
	void Khung_Ql_phong_Them_phong();
	int Xuly_Ql_phong_Them_phong();
	void Hienthi_Ql_phong_ds();
	void Hienthi_Timkiem_phong();								
	void Thucthi_Timkiem_phong();
	void Sua_thongtin_phong();
	Phong Maphong_Timkiem_phong(string Ma_phong);
	int Xoa_phong();
#endif
	
	
	
