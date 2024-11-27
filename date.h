#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

#include "dohoa.h"
#include "chucnangphu.h"

using namespace std;

class Date{
	
	public:
		int Ngay;
		int Thang;
		int Nam;
		Date();
		Date(int Ngay, int Thang, int Nam);
		
		void Set_ngay(int Ngay);
		void Set_thang(int Thang);
		void Set_nam(int Nam);
		
		int Get_ngay();
		int Get_thang();
		int Get_nam();
		
		// Kiểm tra năm nhuận
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Số ngày trong tháng
    int daysInMonth(int m, int y) const {
        static int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeapYear(y)) return 29;
        return daysInMonth[m - 1];
    }

    // Toán tử trừ trả về số ngày giữa hai ngày
    int operator-(const Date &other) const {
        int d1 = Ngay, m1 = Thang, y1 = Nam;
        int d2 = other.Ngay, m2 = other.Thang, y2 = other.Nam;

        // Hoán đổi nếu ngày sau nhỏ hơn ngày trước
        if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2)) {
            swap(d1, d2);
            swap(m1, m2);
            swap(y1, y2);
        }

        int daysDiff = 0;

        // Tính số ngày từ ngày nhỏ hơn đến ngày lớn hơn
        while (y1 > y2 || m1 > m2 || d1 > d2) {
            daysDiff += 1;
            d1--;

            // Nếu ngày nhỏ hơn 1, lùi lại tháng
            if (d1 < 1) {
                m1--;
                if (m1 < 1) {
                    m1 = 12;
                    y1--;
                }
                d1 = daysInMonth(m1, y1);
            }
        }
        return daysDiff;
    }

};
		void Thoi_Gian_Thuc(Date &x); // hàm lấy thời gian thực từ hệ thống máy tính
		string Get_thoi_Gian_Thuc();
		Date Nhapdate();
		int Tinh_songay(Date ngay_thue, Date ngay_tra);

		void Doc_File_Ngay_Thang_Nam(ifstream&, Date &);
		void Ghi_File_Ngay_Thang_Nam(ofstream&, Date x);
		bool Kiem_Tra_Tinh_Hop_Le(Date); 
		bool Kiem_Tra_Tinh_Hop_Le_3(Date x);
		bool Kiem_Tra_Nam_Nhuan(int); // hàm kiểm tra năm nhuận
		bool Kiem_quahan(Date x);
		Date chuyen_str_to_date(string str_date);
		string chuyen_date_to_str(Date x);
		
		Date Suadate(string tt_date);
		string Suadate2(char kq, string tt_date);
		string Suadate3(char kq, string tt_date);
		
		
#endif