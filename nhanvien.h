#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <sstream>
#include <cctype>

#include "date.h"
#include "dohoa.h"

using namespace std;

extern string qlnv_file_name;

class NhanVien {
protected:
    string ma_nv;
    string ten_nv;
    Date ngay_sinh;
    string SDT;
    string GioiTinh;
    string taiKhoan;
    string matKhau;
	string loai_nv;
public:
	NhanVien();
    NhanVien(string ma_nv, string ten_nv, Date ngay_sinh, string sdt, string gioiTinh, string taiKhoan, string matKhau);
    void Set_ma_nv(string ma_nv);
    string Get_ma_nv();

    void Set_ten_nv(string ten_nv);
    string Get_ten_nv();
	
	void Set_ngay_sinh(Date ngay_sinh);
    Date Get_ngay_sinh();
    
    void Set_SDT(string SDT);
    string Get_SDT();

    void Set_GioiTinh(string GioiTinh);
    string Get_GioiTinh();

    void Set_taiKhoan(string taiKhoan);
    string Get_taiKhoan();

    void Set_matKhau(string matKhau);
    string Get_matKhau();
   
    friend void hienThiThongTin(NhanVien*& ds_nv);
    bool kiemTraDangNhap(const string& taiKhoan, const string& matKhau) const;
    friend bool xuLyDangNhap(NhanVien*& ds_nv, string username, string password);
    friend void docfileNV(NhanVien*& ds_nv);
};
	bool XuLyQuenMK(const string& TK, const string& SDT);
	bool xacNhanMK(const string& MK1, const string& MK2);
	string TaoMaNV(const string& ten, const string& sdt);
	NhanVien Tim_kiem_nv(string tk_nv);

#endif