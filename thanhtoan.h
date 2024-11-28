#ifndef THANHTOAN_H
#define THANHTOAN_H

#include <iostream>
#include <string>

#include "phong.h"
using namespace std;

#define VAT 0.08

class ThanhToan{
	private:
		KhachHang kh;
		Phong ph;
		Date ngay_thue;
		Date ngay_tra;
		int so_ngay = 0;
	public:
		// Constructor
		ThanhToan(){};
    	ThanhToan(const KhachHang& kh, const Phong& ph, Date ngayThue, Date ngayTra);
		~ThanhToan(){};
		
    	// Getters
    	string Get_tt_ma_kh() { return this->kh.Get_ma_kh(); }
    	string Get_tt_ma_so_phong() { return this->ph.Get_ma_phong(); }
    	string Get_tt_hoten_kh() { return this->kh.Get_hoten(); }
    	Date Get_tt_ngay_thue(){ return this->ngay_thue; }
    	Date Get_tt_ngay_tra() { return this->ngay_tra; }
		int Get_tt_so_ngay()	{ return this->so_ngay; }
    	// Setters
    	void Set_tt_ma_kh(string maKh) { this->kh.Set_ma_kh(maKh); }
    	void Set_tt_ma_so_phong(string maPh) { this->ph.Set_ma_phong(maPh);  }
    	void Set_tt_hoten_kh(string HoTen) { this->kh.Set_hoten(HoTen); }
		void Set_tt_ngay_thue(Date NgayThue) { this->ngay_thue = NgayThue; }
    	void Set_tt_ngay_tra(Date NgayTra) { this->ngay_tra = NgayTra; }
    	void Set_tt_so_ngay(int so_ngay)	{ this->so_ngay = so_ngay; }
    	
		double Thanh_tien() { return so_ngay * ph.Get_don_gia() * VAT; }
};
	
	void Khung_Ql_dat_phong();
	int Xuly_Ql_dat_phong();
	void Khung_Ql_tra_phong();
	int Xuly_Ql_tra_phong();
	
#endif
