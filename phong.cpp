#include "phong.h"

Phong::Phong() : Ma_phong(""), Loai_phong(""), Don_gia(0), Trang_Thai("") {}

Phong::Phong(string Ma_phong, string Loai_phong, double Don_gia, string Trang_Thai, const KhachHang& kh)
    : Ma_phong(Ma_phong), Loai_phong(Loai_phong), Don_gia(Don_gia), Trang_Thai(Trang_Thai), kh(kh) {}

void Phong::Set_ma_phong(string Ma_phong){
	this->Ma_phong = Ma_phong;
}

void Phong::Set_loai_phong(string Loai_phong){
	this->Loai_phong = Loai_phong;
}

void Phong::Set_don_gia(double Don_gia){
	this->Don_gia = Don_gia;
}

void Phong::Set_trang_thai(string Trang_thai){
	this->Trang_Thai = Trang_thai;
}
	
string Phong::Get_ma_phong(){
	return this->Ma_phong;
}
	
string Phong::Get_loai_phong(){
	return this->Loai_phong;
}

double Phong::Get_don_gia(){
	return this->Don_gia;
} 
string Phong::Get_trang_thai(){
	return this->Trang_Thai;
}
string Phong::Get_ma_kh_ph(){
	return this->kh.Get_ma_kh();
}
string Phong::Get_hoten_kh_ph(){
	return this->kh.Get_hoten();
}

/************ Them phong ***************/
Khunghienthi kht_ph[50][50];
Khunghienthi lcht1_ph, lcht2_ph;
int sh_ph = 0, sc_ph = 0;
/*********** Hien thi ds **************/
Khunghienthi kht2_ph[50][50];
int sh2_ph = 0, sc2_ph = 0;
int so_luong_phong = 0, value_count = 0;
/************* sua thong tin *********/
Khunghienthi kht3_ph[50][50];
int stt_sh_ph = 0, stt_sc_ph = 0;
/*************************************/
string qlph_file_name = "Ql_tt_phong.txt";
/************************************/
void Khung_Ql_phong_Them_phong()
{
	drawKhungGiaoDien("GIAO DIEN THEM PHONG");

	string danhmuc_hang[10] = { "Ma phong:",
		                        "Loai phong:",
								"Don gia:",
								"Trang thai:",
							};
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 22, 45};
	int vt_hang[10] = {5, 5, 5, 5};
		
	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht_ph, sh_ph, sc_ph);
	
	drawXNhan_Thoat();
}

int Xuly_Ql_phong_Them_phong() 
{
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
    int flag_exit = 0;

	for (int i = 0; i < sh_ph; i++)
	{
		dien_x[i] = kht_ph[i][1].Get0x()+2;
		dien_y[i] = kht_ph[i][1].Get0y() + 5/2;
		str[i] = "";
	}
	Show_point(true);
    gotoxy(dien_y[0], dien_x[0]);
	
	while (!flag_exit)
	{
			Sleep(5);
			Show_point(true);
			char kk = _getch();
			//xoa thong bao
			lcht1.Doinen(0);
			lcht2.Doinen(0);
			gotoxy(33, 90);
			cout << "                           " << endl;

			if (kk == -32)
			{
				char cc = _getch();
				if (cc == 80)
				{
					tt_cnt++;
					if (tt_cnt >3 ) tt_cnt = 0;
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
				tt_cnt++;
				if (tt_cnt > 3) tt_cnt = 0;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

			}
			if (kk == 19)
			{
				int vt_lcht = 0;
				lcht1.Doinen(2);
				
				while(1)
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
							for (int i = 0; i < sh_ph; i++)
							{
								kht_ph[i][1].SetNoiDung(str[i]);
							}
							textcolor(WHITE);
							string tt_phong =   kht_ph[0][1].GetNoiDung()  + " ; "
								                  + kht_ph[1][1].GetNoiDung()  + " ; "
				                                  + kht_ph[2][1].GetNoiDung()  + " ; "
							                      + kht_ph[3][1].GetNoiDung()  + " ; \n";
							//them bien static so luong phong
							Ghifile(qlph_file_name, tt_phong);
							gotoxy(33, 90);
							cout << "Ban da luu" << endl;
							flag_exit = 1;
						}
						if (vt_lcht == 1) 
						{
							gotoxy(33, 90);
							cout << "Ban da huy" << endl;
							flag_exit = 0;
						}
						_getch();
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
	return 0;
}

void Hienthi_Ql_phong_ds()
{
	drawKhungGiaoDien("GIAO DIEN DANH SACH PHONG");
	/**********************************************************/
	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Loai phong", "Don gia",
									"Trang thai", "Ma khach hang", "Ho ten"};
	int vt_cot[10] = { 7, 14, 16, 20, 16, 21, 28 };
	int vt_hang[20] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

	
	Table tb(7, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);
	
	/******************************** Xu ly data *****************************************************/

	char c;
    int cnt_hang = 0, cnt_cot = 0;
    string str_tt_phong = "", t_data;
    int vt_trang = 1, sl_dong = 0;

	string data = Getfile("Ql_tt_phong.txt");
	while (!data.empty() && (data.back() == '\n' || data.back() == '\r' || data.back() == ' ')) {
    data.pop_back();
	}
    // Đếm số dòng trong dữ liệu
    for (size_t i = 0; i < data.length(); i++) {
        c = data.at(i);
        if (c == '\n') {
            sl_dong++;
        }
    }


    // Tính số trang
    int sl_trang = (int)(sl_dong / 14) + (sl_dong % 14 != 0);

    while (true) {
        cnt_hang = 0;
        
        tb.CreatTable(kht, sh, sc);
        // Tính dòng bắt đầu và dòng kết thúc cho trang hiện tại
        int dong_bd = (vt_trang - 1) * 14 + 1;
        int dong_kt = vt_trang * 14;
        
        // Duyệt qua từng dòng dữ liệu
        int vt_dong = 0;
        
		for (size_t i = 0; i < data.length(); i++) {
            c = data.at(i);

            if (c == '\n') {
                vt_dong++;
                
                if (vt_dong >= dong_bd && vt_dong <= dong_kt) {
                    // Chỉ hiển thị dữ liệu trong phạm vi dòng của trang
					cnt_hang++;  // Tăng chỉ số hàng
                    // Gán số thứ tự dòng
                    kht[cnt_hang][0].SetNoiDung(to_string(vt_dong));
                    kht[cnt_hang][0].AddNoidung();
					
					
                    cnt_cot = 1;
                    str_tt_phong = "";
                    
                }
            		c = ' ';
			}                
            
            if (c == ';') {
                // Khi gặp dấu ';', xử lý dữ liệu
                t_data = Xoa_khoang_trang_thua(str_tt_phong);
                if(cnt_cot < 7){
				kht[cnt_hang][cnt_cot].SetNoiDung(t_data);
               	kht[cnt_hang][cnt_cot].AddNoidung();
               	}
                cnt_cot++;
                str_tt_phong = "";
            } else {
                // Nếu không phải ký tự đặc biệt, tiếp tục thu thập dữ liệu
                str_tt_phong += c;
            }
            
        }
        // Sau khi đã đi qua hết dữ liệu của trang, hiển thị tổng dòng và trang
        gotoxy(39, 13);
        cout << "Tong:" << sl_dong << endl;
        gotoxy(38, 13 + 60 - 5);
        cout << "Trang " << vt_trang << "/" << sl_trang << endl;
		
        // Đọc phím từ người dùng
        char kk = _getch();
        if (kk == 27) {
            break; // ESC để thoát
        } else if (kk == 75) { // Mũi tên trái
			vt_trang--; // Quay lại trang trước
            if(vt_trang < 1 ) vt_trang = sl_trang;
        } else if (kk == 77) { // Mũi tên phải
            vt_trang++; // Chuyển sang trang tiếp theo
            if(vt_trang > sl_trang) vt_trang = 1;
        } else {
            continue;
        }
    }
}


void Hienthi_Timkiem_phong()
{
	drawKhungGiaoDien("GIAO DIEN TIM KIEM PHONG");
	/**********************************************************/
    #define sl_tk 2

	int vt_trang = 1, sl_trang = 1;
	
	Khunghienthi tk_htlc[sl_tk];
	string danhmuc_tk_htlc[sl_tk] = {"Tim kiem ma phong",
	                                 "Tim kiem loai phong"};
	for (int i = 0; i < sl_tk; i++)
	{
		tk_htlc[i].SetKhungHienThi(6, 13 + 114 * i / sl_tk, 3, 114 / sl_tk, 0, danhmuc_tk_htlc[i]);
		tk_htlc[i].DrawKhunghienthi();
	}
	
	gotoxy(13, 13 + 114/2  - 9/2); cout << "- KET QUA -" << endl;

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Loai phong", "Don gia",
								 "Trang thai","Ma khach hang " , "Ho ten"};
	int vt_cot[10] = { 7, 14, 16, 20, 16, 21, 28 };
	int vt_hang[20] = { 3,3,3,3,3,3,3,3,3,3,3 };

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
		gotoxy(38, 13 + 60 - 5);
		cout << "Trang " << vt_trang << "/" << sl_trang << endl;
	
		Show_point(false);
		fstream f;
		f.open(qlph_file_name, ios::in);
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
				tt_str = str_dt[luachon_tk];

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

void Thucthi_Timkiem_phong() 
{ 
	char kk = 13;
	while (1) // Kiểm tra nếu phím không phải là Esc
    {  
    	if(kk == 27) return;
        if (kk == 13) // Nếu phím Enter
            Hienthi_Timkiem_phong(); // Gọi hàm tìm kiếm phòng
        kk = _getch(); // Đọc phím tiếp theo
    }
}

Phong Maphong_Timkiem_phong(string t_maphong)
{
	Phong t_phong;
	fstream f;
	f.open(qlph_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	//int count_line = 1, 
	int count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(t_maphong);
	while (!f.eof())
	{
		getline(f, line);
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
			tt_str = (str_dt[0]);

			if (tt_str  == str)
			{
				t_phong.Set_ma_phong(str_dt[0]);
				t_phong.Set_loai_phong(str_dt[1]);
				t_phong.Set_don_gia(stod(str_dt[2]));
				t_phong.Set_trang_thai(str_dt[3]);
				
				break;
			}
		}
	}
	f.close();
	return t_phong;
}

int Xoa_phong()
{
	drawKhungGiaoDien("GIAO DIEN XOA PHONG");
	
	Phong dt_phong;
	int flag_exit = 0;
	
	Khunghienthi sx_kht[50][50];
	int sx_sh = 0, sx_sc = 0;
	
	string danhmuc_hang[10] = { "Ma phong",
									"Loai phong",
									"Don gia",
									"Trang thai",
									"Ma khach hang",
									"Ho ten"};
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 22, 45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(sx_kht, sx_sh, sx_sc);
	
	drawXoaHuy();
	//--------------
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	
    string str_ma_phong = "";
    
    for (int i = 0; i < sx_sh; i++)
	{
		dien_x[i] = sx_kht[i][1].Get0x() + 2;
		dien_y[i] = sx_kht[i][1].Get0y() + 5 / 2;
		str[i] = "";
	}
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);

	while (!flag_exit)
	{
		Show_point(true);
		char kk = _getch();
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		cout << str[tt_cnt];
		
			if (30 < kk && kk < 122)
			{
				str_ma_phong.push_back(kk);
				cout << str_ma_phong;
			}

			if (kk == 8)
			{
				if (!str_ma_phong.empty())
				{
					str_ma_phong.pop_back();
				}
				for (size_t i = 0; i < str_ma_phong.length() + 2; i++)
				{
					cout << "";
				}
				gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
				cout << str_ma_phong;
			}

			Show_point(false);

			if (kk == 13)
			{
				str_ma_phong = Xoa_khoang_trang_thua(str_ma_phong);
				dt_phong = Maphong_Timkiem_phong(str_ma_phong);
				if (dt_phong.Get_ma_phong() != " ")
				{	
					str[1] = dt_phong.Get_loai_phong();
					str[2] = dt_phong.Get_don_gia();
					str[3] = dt_phong.Get_trang_thai();
					str[4] = dt_phong.Get_ma_kh_ph();
					str[5] = dt_phong.Get_hoten_kh_ph();
					for (tt_cnt = 1; tt_cnt < sx_sh; tt_cnt++)
					{
						gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
						cout << str[tt_cnt];
					}	
				}
				else
				{
					tt_cnt++;
					if (tt_cnt > 6) tt_cnt = 1;
					gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				}
				gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
			}
			if (kk == 19)
			{
				int vt_lcht = 0;
				lcht1.Doinen(2);
				while (1)
				{
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
							if (dt_phong.Get_ma_phong() != " ")
							{
								Xoadoituongtrongfile(qlph_file_name, dt_phong.Get_ma_phong());
								gotoxy(29, 90);
								cout << "Ban da luu" << endl;
								flag_exit = 1;
							}
							else
							{
								gotoxy(29, 90);
								cout << "Khong ton tai" << endl;
								flag_exit = 0;
							}
						}
						if (vt_lcht == 1)
						{
							gotoxy(29, 90);
							cout << "Ban da huy" << endl;
							flag_exit = 0;
						}
						_getch();
						break;
					}
					if (t_kk == 27)
					{
						return 1;
					}
				}
				SetBGColor(0);
				gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
			}
			if (kk == 27)
			{
				return 1;
			}
		}
	Show_point(false);
	return 0;
}

void Sua_thongtin_phong()
{
	drawKhungGiaoDien("GIAO DIEN SUA THONG TIN PHONG");
	
	Phong dt_phong;
	string danhmuc_hang[10] = { "Ma phong",
									"Loai phong",
									"Don gia",
									"Trang thai",
									"Ma khach hang",
									"Ho ten"};
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 22, 45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht3_ph, stt_sh_ph, stt_sc_ph);

	drawXNhan_Thoat();
	
	/*******************************************************/
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0, step = 0;
	
	for (int i = 0; i < stt_sh_ph; i++)
	{
		dien_x[i] = kht3_ph[i][1].Get0x() + 2;
		dien_y[i] = kht3_ph[i][1].Get0y() + 5 / 2;
		str[i] = "";
	}
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);
	while (!flag_exit)
	{
		Show_point(true);
		gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		cout << str[tt_cnt];

		char kk = _getch();
		//xoa thong bao
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(33, 90);
		cout << "                           " << endl;
		
		if (kk == -32 && step != 0)
		{
			char cc = _getch();
			{
				if (cc == 80)
				{
					tt_cnt++;
					if (tt_cnt > 6) tt_cnt = 1;
				}
				if (cc == 72)
				{
					tt_cnt--;
					if (tt_cnt < 1) tt_cnt = 6;
				}
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
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
			if (step == 0)
			{
				string str_ma_phong = Xoa_khoang_trang_thua(str[0]);
				dt_phong = Maphong_Timkiem_phong(str_ma_phong);
				if (dt_phong.Get_ma_phong() != " ")
				{
					str[0] = dt_phong.Get_ma_phong();
					str[1] = dt_phong.Get_loai_phong();
					str[2] = dt_phong.Get_don_gia();
					str[3] = dt_phong.Get_trang_thai();
					
					
					for (tt_cnt = 1; tt_cnt < stt_sh_ph; tt_cnt++)
					{
						gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
						cout << str[tt_cnt];
					}
					step = 1;
				}
			}
			else {
				tt_cnt++;
				if (tt_cnt > 6) tt_cnt = 1;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
		}

		if (kk == 19 && step != 0)
		{
			int vt_lcht = 0;
			lcht1.Doinen(2);

			while (1)
			{
				Show_point(false);
				char t_kk = _getch();
				string tt_phong = "";
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
						for (int i = 0; i < stt_sh_ph; i++)
						{
							tt_phong += (str[i] + " ; ");
						}
						tt_phong += "\n";
						textcolor(WHITE);
						Xoadoituongtrongfile(qlph_file_name, dt_phong.Get_ma_phong());
						Ghifile(qlph_file_name, tt_phong);
						gotoxy(29, 90);
						cout << "Ban da luu" << endl;
						flag_exit = 1;
					}
				    if (vt_lcht == 1)
					{
						gotoxy(29, 90);
						cout << "Ban da huy" << endl;
						step = 0;
						for (tt_cnt = 6; tt_cnt > 0; tt_cnt--)
						{
							str[tt_cnt] = "";
							gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
							cout << "                                       ";
						}

						flag_exit = 0;
					}
						_getch();
						break;
				}

				if (t_kk == 27)
				{
					flag_exit = 1;
					break;
				}
				SetBGColor(0);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

			}
		}

		if (kk == 27)
		{
			flag_exit = 1;
			break;
		}
	}
}