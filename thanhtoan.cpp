#include "thanhtoan.h"
ThanhToan::ThanhToan(const KhachHang& kh, const Phong& ph, Date ngayThue, Date ngayTra)
    	    : kh(kh), ph(ph), ngay_thue(ngayThue), ngay_tra(ngayTra) {
	int so_ngay = ngay_tra - ngay_thue;
}

void Khung_Ql_dat_phong(){
	drawKhungGiaoDien("GIAO DIEN DAT PHONG");

	string danhmuc_hang[10] = { "Ma so phong:",
								 "Ma khach hang:",
								 "Ten khach hang:",
								 "Ngay tra:",
								 "Ngay thue:",
								};
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 25, 40 };
	int vt_hang[10] = { 5, 5, 5, 5, 5};

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);

	drawXNhan_Thoat();

}
int Xuly_Ql_dat_phong(){
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;
	for (int i = 0; i < sh; i++)
	{
		dien_x[i] = kht[i][1].Get0x() + 2;
		dien_y[i] = kht[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	str[sh - 1] = Get_thoi_Gian_Thuc();
	gotoxy(dien_y[sh-1], dien_x[sh - 1]);
	cout<< str[sh - 1] <<endl;

	str[3] = "  /  /    ";
	gotoxy(dien_y[3], dien_x[3]);
	cout << str[3];

	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);

	while (!flag_exit)
	{
		Show_point(true);
		char kk = _getch();
		//xoa thong bao
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(38, 35);
		cout << "                           " << endl;

		if (kk == -32)
		{
			char cc = _getch();
			if (cc == 80)
			{
				tt_cnt++;
				if (tt_cnt > 3) tt_cnt = 0;
			}
			if (cc == 72)
			{
				tt_cnt--;
				if (tt_cnt < 0) tt_cnt = 3;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (30 < kk && kk < 122)
		{
			if (tt_cnt != 3) {
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				cout << str[tt_cnt];
				Show_point(true);
			}
			else
			{
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				str[3] = Suadate3(kk, str[3]);
				tt_cnt++;
				if (tt_cnt > 3) tt_cnt = 0;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
		}

		if (kk == 8)
		{
			if (!str[tt_cnt].empty())
			{
				str[tt_cnt].pop_back();
			}
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			for (size_t i = 0; i < str[tt_cnt].length() + 2; i++)
			{
				cout << " ";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 13)
		{
			tt_cnt++;
			if (tt_cnt > 3) tt_cnt = 0;
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

		}
		if (kk == 19)
		{
			int vt_lcht = 0;
			lcht1.Doinen(2);

			while (1)
			{
				Show_point(false);
				char t_kk = _getch();
				if (t_kk == -32)
				{
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77)
					{
						if (vt_lcht == 0)
						{
							vt_lcht = 1;
							lcht1.Doinen(0);
							lcht2.Doinen(2);
						}
						else
						{
							vt_lcht = 0;
							lcht1.Doinen(2);
							lcht2.Doinen(0);
						}
					}
				}
				if (t_kk == 13)
				{
					if (vt_lcht == 0)
					{
						Phong tdt_phong = Maphong_Timkiem_phong(str[0]);
						KhachHang tdt_khachhang = Tim_kiem_ma_kh(str[1]);
						if (tdt_phong.Get_ma_phong() != " " && tdt_khachhang.Get_ma_kh() != " ")
						{
						    string kq = Get_trangthaiphong("Ql_tt_phong.txt", tdt_phong.Get_ma_phong());
							if (kq == "Ok")
							{
								textcolor(WHITE);
								Suadoitrangthaiphong("Ql_tt_phong.txt", tdt_phong.Get_ma_phong(), "Lock", str[1], str[2]);
								gotoxy(38, 35);
								cout << "Ban da luu" << endl;
								flag_exit = 1;
							}
							else
							{
								gotoxy(38, 35);
								cout << "Phong khong san sang thue" << endl;
								flag_exit = 0;
							}
						}
						else
						{
							gotoxy(38, 35);
							cout << "Ma phong hoac ma khach hang sai" << endl;
							flag_exit = 0;
						}

					}
					if (vt_lcht == 1)
					{
						gotoxy(38, 35);
						cout << "Ban da huy" << endl;
						flag_exit = 0;
					}
					break;
				}
				if (t_kk == 27)
				{
					return 1;
				}
			}
			SetBGColor(0);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 27)
		{
			return 1;
		}
	}
	_getch();
	return 0;
}
ThanhToan Get_tt_thanh_toan(string t_ma_phong)
{
	ThanhToan dt_tt;
	fstream f;
	f.open(qlph_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	//int count_line = 1, 
	int count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(t_ma_phong);
	str = (str);
	while (!f.eof())
	{
		getline(f, line);
		std::string t_line = (line);
		int t_vt = t_line.find(str);
		if (t_vt >= 0)
		{
			tt_data = " ";
			count_vtdt = 0;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					str_dt[count_vtdt] = Xoa_khoang_trang_thua(tt_data);
					count_vtdt++;
					tt_data = " ";
				}
				else tt_data += line.at(i);
			}
			string tt_str = " ";
			tt_str = (str_dt[0]);

			if (tt_str == str)
			{
				dt_tt.Set_tt_ma_so_phong(str_dt[0]);
				dt_tt.Set_tt_ma_kh(str_dt[1]);
				dt_tt.Set_tt_hoten_kh(str_dt[2]);
				dt_tt.Set_tt_ngay_tra(chuyen_str_to_date(str_dt[3]));
				dt_tt.Set_tt_ngay_thue(chuyen_str_to_date(str_dt[4]));
				
				break;
			}
		}
	}
	f.close();
	return dt_tt;
}

void Khung_Ql_tra_phong(){
	drawKhungGiaoDien("GIAO DIEN TRA PHONG");

	string danhmuc_hang[10] = { "Ma so phong: ",
									 "Ma Khach hang: ",
									 "Ho ten",
									 "Ngay tra: ",
									 "Ngay thue: " };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 25, 45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);

	drawXNhan_Thoat();
}
int Xuly_Ql_tra_phong(){
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;
	for (int i = 0; i < sh; i++)
	{
		dien_x[i] = kht[i][1].Get0x() + 2;
		dien_y[i] = kht[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	str[sh - 1] = Get_thoi_Gian_Thuc();
	gotoxy(dien_y[sh - 1], dien_x[sh - 1]);
	cout << str[sh - 1] << endl;

	str[3] = "  /  /    ";
	gotoxy(dien_y[3], dien_x[3]);
	cout << str[3];
	Show_point(true);
	gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

	while (!flag_exit)
	{
		//Sleep(5);
		Show_point(true);
		char kk = _getch();
		//xoa thong bao
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(38, 35);
		cout << "                                " << endl;
		gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		if (kk == -32)
		{
			char t_cc = _getch();
			if (t_cc == 75 || t_cc == 77)
			{
				//nop
			}
		}
		if (30 < kk && kk < 122)
		{
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				cout << str[tt_cnt];
				Show_point(true);
		}

		if (kk == 8)
		{
			if (!str[tt_cnt].empty())
			{
				str[tt_cnt].pop_back();
			}
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			for (size_t i = 0; i < str[tt_cnt].length() + 2; i++)
			{
				cout << " ";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 13)
		{
			ThanhToan dt_tt = Get_tt_thanh_toan(str[tt_cnt]) ;
			if (dt_tt.Get_tt_ma_so_phong() != " ")
			{
				str[0] = dt_tt.Get_tt_ma_so_phong();
				str[1] = dt_tt.Get_tt_ma_kh();
				str[2] = dt_tt.Get_tt_hoten_kh();
				str[3] = chuyen_date_to_str(dt_tt.Get_tt_ngay_tra());
				str[4] = chuyen_date_to_str(dt_tt.Get_tt_ngay_thue());
				for (int i = 1; i < 4; i++) 
				{
					gotoxy(dien_y[i], dien_x[i]);
					cout << str[i];
				}
				gotoxy(38, 35);
				cout << "                   " << endl;
			}
			else 
			{
				for (int i = 1; i < 5; i++)
				{
					str[i] = " ";
					gotoxy(dien_y[i], dien_x[i]);
					cout << "                   ";
				}
				gotoxy(38, 35);
				cout << "Ma phong sai" << endl;
			}

			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 19)
		{
			int vt_lcht = 0;
			lcht1.Doinen(2);

			while (1)
			{
				Show_point(false);
				char t_kk = _getch();
				if (t_kk == -32)
				{
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77)
					{
						if (vt_lcht == 0)
						{
							vt_lcht = 1;
							lcht1.Doinen(0);
							lcht2.Doinen(2);
						}
						else
						{
							vt_lcht = 0;
							lcht1.Doinen(2);
							lcht2.Doinen(0);
						}
					}
				}
				if (t_kk == 13)
				{
					if (vt_lcht == 0)
					{
						if (str[1] != " ")
						{
							ThanhToan dt_tt ;
							if (dt_tt.Get_tt_ma_so_phong() != " ")
							{
								Xoadoituongtrongfile(qlph_file_name, str[0]);
								Suadoitrangthaiphong("Ql_tt_phong.txt", str[0], "Ok", "", "");
								gotoxy(38, 35);
								cout << "Ban da luu" << endl;
								flag_exit = 1;
							}
							else
							{
								gotoxy(38, 35);
								cout << "Khong ton tai" << endl;
								flag_exit = 0;
							}
						}
						
					}
					if (vt_lcht == 1)
					{
						gotoxy(38, 35);
						cout << "Ban da huy" << endl;
						flag_exit = 0;
					}
					break;
				}
				if (t_kk == 27)
				{
					return 1;
				}
			}
			SetBGColor(0);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (kk == 27)
		{
			return 1;
		}
	}
	_getch();
	return 0;
}
void Hienthi_ds_thuetra(){
	
}