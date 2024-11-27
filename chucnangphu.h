#ifndef CHUCNANGPHU_H
#define CHUCNANGPHU_H

#include <iostream>
#include <conio.h>
#include <tchar.h> 
#include <string>
#include <fstream>
#include <windows.h>

#include "dohoa.h"

using namespace std;

bool KiemTraTen(string);
void ThongBaoNhapNhay(string s, int maunen, int mauchu, int cot, int hang);
void BangThongBaoLoi(string);
void XoaBangThongBaoLoi();
void KhungHinh(int, int, int, int);
void XoaMang(int y, int x, int h, int w, int color);
bool KiemTraNhapSoNguyen(char a[], int &DuLieu);
void BangLuaChon(int y, int x, string noidung, bool &btn_Co);
void KhungNhapMakhachhang(int y, int x);


void Ghifile(string name_file, string data);
void Docfile(int y, int x, string namefile);
string Getfile(string name_file);
void Xoadoituongtrongfile(string name_file, string tk);
void Suadoitrangthaiphong(string file_name, string t_maso, string t_trang_thai, string t_ma_kh, string t_hoten);
void Suadoitrangthaikhachhang(string file_name, string t_maso, string t_trang_thai);
string Get_trangthaiphong(string file_name, string t_maso);
string Get_trangthaikhachhang(string file_name, string t_maso);

string Xoa_khoang_trang_dau_cuoi(string data);
string Xoa_khoang_trang_giua(string data);
string Xoa_khoang_trang_thua(string t_data);

#endif