#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "date.h"
#include "dohoa.h"

using namespace std;

class KhachHang{
	private:
		string Ma_khachhang;
		string Hoten;
		Date Ngaysinh;
		string SDT;
		string Gioitinh;
		string Trangthai;
		int Sokhach;
	public:
		KhachHang();
		KhachHang(string Ma_khachhang, string Hoten, Date Ngaysinh, string SDT,	string Gioitinh, string Trangthai, int Sokhach);
		
		void Set_ma_kh(string ma_kh);
		void Set_hoten(string Hoten);
		void Set_sdt(string SDT);
		void Set_gioitinh(string Gioitinh);
		void Set_trangthai(string Trangthai);
		void Set_ngaysinh(Date Ngaysinh);
	
		string Get_ma_kh();
		string Get_hoten();
		string Get_sdt();
		string Get_gioitinh();
		string Get_trangthai();
		Date Get_ngaysinh();
		
};
		string TaoMaKhachHang(const string& ten, const string& sdt);
		void Khung_Ql_phong_Them_khachhang();
		int Xuly_Ql_phong_Them_khachhang();
		void Hienthi_Ql_khachhang_ds();
		void Hien_thi_timkiem_khachhang();
		void Thucthi_Timkiem_khachhang();
		void Sua_thongtin_khachhang();
		KhachHang Tim_kiem_ma_kh(string ma_kh);
		int Xoa_khachhang();
#endif