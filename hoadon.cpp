#include "hoadon.h"

string qlhd_file_name = "Ql_tt_hoadon.txt" ;

HoaDon::HoaDon(){}

HoaDon::HoaDon(string mahd, const ThanhToan& tt)
				: mahd(mahd), tt(tt) {}

HoaDon::~HoaDon(){}

void Hoadon_theophongkh(){
	char kk = 13;
	while (1){
		if (kk == 27) return;
		if (kk == 13){
	
	drawKhungGiaoDien(" GIAO DIEN HOA DON THEO PHONG / KHACH HANG");

    #define sl_tk 2

	int vt_trang = 1, sl_trang = 1;
	
	Khunghienthi tk_htlc[sl_tk];
	string danhmuc_tk_htlc[sl_tk] = {"Tim kiem theo ma phong",
	                                 "Tim kiem theo ten khach hang"};
	for (int i = 0; i < sl_tk; i++)
	{
		tk_htlc[i].SetKhungHienThi(6, 13+ 114 * i / sl_tk, 3, 114 / sl_tk, 0, danhmuc_tk_htlc[i]);
		tk_htlc[i].DrawKhunghienthi();
	}
	
	gotoxy(13, 13 + 60 - 7/2); cout << "KET QUA"<<endl;

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Don gia", "Ma KH" , 
									"Ho ten", "Ngay thue", "Ngay tra", "Thanh tien"};
	int vt_cot[10] = { 7, 14, 14, 14, 25, 16, 16, 18 };
	int vt_hang[15] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

	Khunghienthi kht_tk[50][50];

	Table tb2(15, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht_tk);

	textcolor(WHITE);

	int luachon_tk = 0;
	tk_htlc[luachon_tk].Doinen(2);
	while (1)
	{
		Show_point(false);
		char t_kk = _getch();
		if (t_kk == -32)
		{
			char t_cc = _getch();
			if (t_cc == 75)
			{
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk--;
				if (luachon_tk < 0) luachon_tk = sl_tk - 1;
				tk_htlc[luachon_tk].Doinen(2);
			}
			if (t_cc == 77)
			{
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk++;
				if (luachon_tk == sl_tk) luachon_tk = 0;
				tk_htlc[luachon_tk].Doinen(2);
			}
		}
		if (t_kk == 13){
			break;
		}	
	}
	
	int vt_cot_tklc[10] = { 38 , 77 };
	int vt_hang_tklc[10] = { 3 };

	string danhmuc_hang_tk[10] = { danhmuc_tk_htlc[luachon_tk] };
	string danhmuc_cot_tk[10] = { " ", " " };
	
	Khunghienthi khtklc[50][50];
	int sh_tk = 0, sc_tk = 0;
	Table tb_nhap_lc(9, 13, vt_hang_tklc, vt_cot_tklc, 0);
	tb_nhap_lc.Set_danhmuc(danhmuc_hang_tk, danhmuc_cot_tk);
	tb_nhap_lc.CreatTable(khtklc, sh_tk, sc_tk);
	Show_point(true);
	gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
	
	string str;
		while (1)
		{
			char kk = _getch();
			Show_point(false);
			
			if (30 < kk && kk < 122)
			{
				str.push_back(kk);
				gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
				cout << str;
			}

			if (kk == 8)
			{
				if (!str.empty())
				{
					str.pop_back();
				}
				for (size_t i = 0; i < str.length() + 2; i++)
				{
					cout << " ";
				}
				gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
				cout << str;
			}

			Show_point(true);

			if (kk == 13)
			{
				break;
			}
		}
	
		str = Xoa_khoang_trang_thua(str);
		str = (str);
		gotoxy(38, 13 + 60 - 5);
		cout << "Trang " << vt_trang << "/" << sl_trang << endl;
	
		Show_point(false);
		fstream f;
		f.open(qlhd_file_name, ios::in);
		string line, str_dt[8], tt_data = " ";
		int count_line = 1, count_vtdt = 0;
		while (getline(f, line))
		{
			if (line.length() > 1)
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
				tt_str = (str_dt[luachon_tk]);

				size_t x = tt_str.find(str);
				if (x != string::npos)
				{
					kht_tk[count_line][0].SetNoiDung(to_string(count_line));
					kht_tk[count_line][0].AddNoidung();
					for (int i = 0; i < 7; i++)
					{
						kht_tk[count_line][i + 1].SetNoiDung(str_dt[i]);
						kht_tk[count_line][i + 1].AddNoidung();
					}
					count_line++;
				}
			}
		}
		f.close();
    }
    kk = _getch();
}

}


void Hoadon_theongay(){
	char kk = 13;
	while (1){
		if (kk == 27) return;
		if (kk == 13){
	
	drawKhungGiaoDien("GIAO DIEN HOA DON THEO NGAY");

    #define sl_tk 2

	int vt_trang = 1, sl_trang = 1;
	
	Khunghienthi tk_htlc[sl_tk];
	string danhmuc_tk_htlc[sl_tk] = {"Tim kiem theo ngay thue",
	                                 "Tim kiem theo ngay tra"};
	for (int i = 0; i < sl_tk; i++)
	{
		tk_htlc[i].SetKhungHienThi(6, 13+ 114 * i / sl_tk, 3, 114 / sl_tk, 0, danhmuc_tk_htlc[i]);
		tk_htlc[i].DrawKhunghienthi();
	}
	
	gotoxy(13, 13 + 60 - 7/2); cout << "KET QUA"<<endl;

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Don gia", "Ma KH" , 
									"Ho ten", "Ngay thue", "Ngay tra", "Thanh tien"};
	int vt_cot[10] = { 7, 14, 14, 14, 25, 16, 16, 18 };
	int vt_hang[15] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

	Khunghienthi kht_tk[50][50];

	Table tb2(15, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht_tk);

	textcolor(WHITE);

	int luachon_tk = 0;
	tk_htlc[luachon_tk].Doinen(2);
	while (1)
	{
		Show_point(false);
		char t_kk = _getch();
		if (t_kk == -32)
		{
			char t_cc = _getch();
			if (t_cc == 75)
			{
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk--;
				if (luachon_tk < 0) luachon_tk = sl_tk - 1;
				tk_htlc[luachon_tk].Doinen(2);
			}
			if (t_cc == 77)
			{
				tk_htlc[luachon_tk].Doinen(0);
				luachon_tk++;
				if (luachon_tk == sl_tk) luachon_tk = 0;
				tk_htlc[luachon_tk].Doinen(2);
			}
		}
		if (t_kk == 13){
			break;
		}	
	}
	
	int vt_cot_tklc[10] = { 38 , 77 };
	int vt_hang_tklc[10] = { 3 };

	string danhmuc_hang_tk[10] = { danhmuc_tk_htlc[luachon_tk] };
	string danhmuc_cot_tk[10] = { " ", " " };
	
	Khunghienthi khtklc[50][50];
	int sh_tk = 0, sc_tk = 0;
	Table tb_nhap_lc(9, 13, vt_hang_tklc, vt_cot_tklc, 0);
	tb_nhap_lc.Set_danhmuc(danhmuc_hang_tk, danhmuc_cot_tk);
	tb_nhap_lc.CreatTable(khtklc, sh_tk, sc_tk);
	Show_point(true);
	gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
	
	string str;
		while (1)
		{
			char kk = _getch();
			Show_point(false);
			
			if (30 < kk && kk < 122)
			{
				str.push_back(kk);
				gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
				cout << str;
			}

			if (kk == 8)
			{
				if (!str.empty())
				{
					str.pop_back();
				}
				for (size_t i = 0; i < str.length() + 2; i++)
				{
					cout << " ";
				}
				gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
				cout << str;
			}

			Show_point(true);

			if (kk == 13)
			{
				break;
			}
		}
	
		str = Xoa_khoang_trang_thua(str);
		str = (str);
		gotoxy(38, 13 + 60 - 5);
		cout << "Trang " << vt_trang << "/" << sl_trang << endl;
	
		Show_point(false);
		fstream f;
		f.open(qlhd_file_name, ios::in);
		string line, str_dt[8], tt_data = " ";
		int count_line = 1, count_vtdt = 0;
		while (getline(f, line))
		{
			if (line.length() > 1)
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
				tt_str = (str_dt[luachon_tk]);

				size_t x = tt_str.find(str);
				if (x != string::npos)
				{
					kht_tk[count_line][0].SetNoiDung(to_string(count_line));
					kht_tk[count_line][0].AddNoidung();
					for (int i = 0; i < 7; i++)
					{
						kht_tk[count_line][i + 1].SetNoiDung(str_dt[i]);
						kht_tk[count_line][i + 1].AddNoidung();
					}
					count_line++;
				}
			}
		}
		f.close();
    }
    kk = _getch();
}

}
void Lichsu_luutru(){
		char kk = 13;
	while (1){
		if (kk == 27) return;
		if (kk == 13){
	
	drawKhungGiaoDien("LICH SU LUU TRU");

    #define sl_tk 2

	int vt_trang = 1, sl_trang = 1;
	

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Don gia", "Ma KH" , 
									"Ho ten", "Ngay thue", "Ngay tra", "Thanh tien"};
	int vt_cot[10] = { 7, 14, 14, 14, 25, 16, 16, 18 };
	int vt_hang[15] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

	Khunghienthi kht_tk[50][50];

	Table tb2(15, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht_tk);
	
	int luachon_tk = 0;
	string str;
		
		gotoxy(38, 13 + 60 - 5);
		cout << "Trang " << vt_trang << "/" << sl_trang << endl;
	
		Show_point(false);
		fstream f;
		f.open(qlhd_file_name, ios::in);
		string line, str_dt[8], tt_data = " ";
		int count_line = 1, count_vtdt = 0;
		while (getline(f, line))
		{
			if (line.length() > 1)
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
				tt_str = (str_dt[luachon_tk]);

				size_t x = tt_str.find(str);
				if (x != string::npos)
				{
					kht_tk[count_line][0].SetNoiDung(to_string(count_line));
					kht_tk[count_line][0].AddNoidung();
					for (int i = 0; i < 7; i++)
					{
						kht_tk[count_line][i + 1].SetNoiDung(str_dt[i]);
						kht_tk[count_line][i + 1].AddNoidung();
					}
					count_line++;
				}
			}
		}
		f.close();
    }
    kk = _getch();
}

}