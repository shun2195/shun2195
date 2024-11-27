#include "khachhang.h"

KhachHang::KhachHang(){
	this->Ma_khachhang = "";
	this->Hoten = "";
	this->Ngaysinh.Set_ngay(1);
	this->Ngaysinh.Set_thang(1);
	this->Ngaysinh.Set_nam(1900);
	this->SDT ="";
	this->Gioitinh = "";
	this->Trangthai = "";
	this->Sokhach = 1;
}
		
KhachHang::KhachHang(string Ma_kh, string Hoten, Date Ngaysinh, 
                     string SDT, string Gioitinh, string Trangthai, int Sokhach)
    : Ma_khachhang(Ma_kh), Hoten(Hoten), Ngaysinh(Ngaysinh), SDT(SDT), 
      Gioitinh(Gioitinh), Trangthai(Trangthai), Sokhach(Sokhach) {}

string TaoMaKhachHang(const string& ten, const string& sdt) {
	string maKH;
    // Lấy chữ cái đầu của mỗi từ trong tên và viết hoa
    bool newWord = true;  // Cờ đánh dấu bắt đầu của một từ
    for (size_t i = 0; i < ten.length(); ++i) {
        if (newWord && ten[i] != ' ') {
            if (ten[i] >= 'a' && ten[i] <= 'z') {
                maKH += ten[i] - 'a' + 'A';  // Chuyển từ chữ thường sang chữ hoa
            } else {
                maKH += ten[i];  // Nếu đã là chữ hoa thì thêm trực tiếp
            }
            newWord = false;  // Đánh dấu không phải là chữ cái đầu của từ nữa
        }
        if (ten[i] == ' ') {
            newWord = true;  // Đánh dấu bắt đầu của từ mới
        }
    }
    
    // Thêm 3 chữ số cuối của số điện thoại nếu có
    if (sdt.length() >= 3) {
        maKH += sdt.substr(sdt.length() - 3);  // Lấy 3 chữ số cuối của số điện thoại
    }

    return maKH;
}
void KhachHang::Set_ma_kh(string Ma_kh){
	this->Ma_khachhang = Ma_kh;
}

void KhachHang::Set_hoten(string Hoten){
	this->Hoten = Hoten;
}

void KhachHang::Set_sdt(string SDT){
	this->SDT = SDT;
}

void KhachHang::Set_gioitinh(string Gioitinh){
	this->Gioitinh = Gioitinh;
}

void KhachHang::Set_trangthai(string Trangthai){
	this->Trangthai = Trangthai;
}

void KhachHang::Set_ngaysinh(Date Ngaysinh){
	this->Ngaysinh = Ngaysinh;
}

string KhachHang::Get_ma_kh(){
	return this->Ma_khachhang;
}

string KhachHang::Get_hoten(){
	return this->Hoten;
}

string KhachHang::Get_sdt(){
	return this->SDT;
}

string KhachHang::Get_gioitinh(){
	return this->Gioitinh;
}

string KhachHang::Get_trangthai(){
	return this->Trangthai;
}

Date KhachHang::Get_ngaysinh(){
	return this->Ngaysinh;
}

/************ Them khach hang ***************/
Khunghienthi kht_kh[50][50];
Khunghienthi lcht1_kh, lcht2_kh;
int sh_kh = 0, sc_kh = 0;
/*********** Hien thi ds **************/
Khunghienthi kht2_kh[50][50];
int sh2_kh = 0, sc2_kh = 0;
/*********** Sua thong tin **************/
Khunghienthi kht3_kh[50][50];
int sh3_kh = 0, sc3_kh = 0;
int stt_sh_kh = 6, stt_sc_kh = 0;
/**************************************/
string  qlkh_file_name = "Ql_tt_khachhang.txt";
/**************************************/

void Khung_Ql_phong_Them_khachhang()
{
	drawKhungGiaoDien("GIAO DIEN THEM KHACH HANG");

	string danhmuc_hang[10] = { "Ma so: ",
									 "Ho ten: ",
									 "Ngay sinh: ",
									 "Gioi tinh: ",
									 "So dien thoai: ",
									};
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20, 45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5 };

	// Tạo bảng với thông tin khai báo ban đầu
	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht_kh, sh_kh, sc_kh);

	drawXNhan_Thoat();
}

int Xuly_Ql_phong_Them_khachhang()
{
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 1;
	string str[50];
	int flag_exit = 0;
	Date t_date;

	// Khởi tạo tọa độ cho các trường nhập liệu
	for (int i = 1; i < sh_kh; i++)
	{
		dien_x[i] = kht_kh[i][1].Get0x() + 2;
		dien_y[i] = kht_kh[i][1].Get0y() + 5 / 2;
		str[i] = "";
	}
	str[2] = "  /  /    ";  // Định dạng ngày sinh
	gotoxy(dien_y[2], dien_x[2]);
	cout << str[2];
	Show_point(true);
	gotoxy(dien_y[1], dien_x[1]);

	while (!flag_exit)
	{
		Show_point(true);
		char kk = _getch();

		// Xóa thông báo
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(33, 90);
		cout << "                           " << endl;

		// Xử lý phím điều hướng
		if (kk == -32)
		{
			char cc = _getch();
			if (cc == 80)  // Phím mũi tên xuống
			{
				tt_cnt++;
				if (tt_cnt > 4) tt_cnt = 1;
			}
			if (cc == 72)  // Phím mũi tên lên
			{
				tt_cnt--;
				if (tt_cnt < 1) tt_cnt = 4;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}

		// Xử lý nhập ký tự
		if (30 < kk && kk < 122)
		{
			if (tt_cnt != 2)  // Không cho nhập ở trường "Ngày sinh"
			{
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				cout << str[tt_cnt];
				Show_point(true);               
			}
			else{  // Xử lý định dạng ngày tháng
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				str[2] = Suadate2(kk, str[2]);
				tt_cnt++;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
		}
		
		// Xử lý phím xóa (Backspace)
		if (kk == 8)
		{
			if (!str[tt_cnt].empty())
			{
				str[tt_cnt].pop_back();  // Xóa ký tự cuối cùng
			}
			Show_point(false);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			for (size_t i = 1; i < str[tt_cnt].length() + 2; i++)
			{
				cout << "";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		// Xử lý phím Enter
		if (kk == 13)
		{
			tt_cnt++;
			if (tt_cnt > 4) tt_cnt = 1;
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}

		// Xử lý lưu và hủy (Ctrl + S)
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
					if (t_cc == 75 || t_cc == 77)  // Xử lý di chuyển giữa Save và Cancel
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

				// Xử lý khi nhấn Enter
				if (t_kk == 13)
				{
					if (vt_lcht == 0)  // Lưu thông tin
					{	
						for(int i = 1; i < sh_kh; i++){
							kht_kh[i][1].SetNoiDung(str[i]);
						}
						textcolor(WHITE);						
						string makh = TaoMaKhachHang(kht_kh[1][1].GetNoiDung(), kht_kh[4][1].GetNoiDung());
            			// Lưu mã khách hàng vào bảng thông tin
               			kht_kh[0][1].SetNoiDung(makh);
                		kht_kh[0][1].AddNoidung();
                		
						string tt_khachhang = kht_kh[0][1].GetNoiDung()  + " ; "
												+ kht_kh[1][1].GetNoiDung() + " ; "
												+ kht_kh[2][1].GetNoiDung() + " ; "
												+ kht_kh[3][1].GetNoiDung() + " ; "
												+ kht_kh[4][1].GetNoiDung() + " ;\n";
			
						// Ghi thông tin vào file
						Ghifile(qlkh_file_name, tt_khachhang);
						gotoxy(33, 90);
						cout << "Ban da luu" << endl;
						flag_exit = 1;
					}
					if (vt_lcht == 1)  // Hủy thao tác
					{
						gotoxy(33, 90);
						cout << "Ban da huy" << endl;
						flag_exit = 0;
					}
					_getch();
					break;
				}
				if (t_kk == 27)  // Phím ESC
				{
					return 1;
				}
			}
			SetBGColor(0);
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}

		if (kk == 27)  // Phím ESC
		{
			return 1;
		}
	}
	return 0;
}

void Hienthi_Ql_khachhang_ds() {
    drawKhungGiaoDien("GIAO DIEN DANH SACH KHACH HANG");

    string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
    string danhmuc_cot[10] = { "Stt", "Ma so", "Ho ten", "Ngay sinh", "Gioi tinh", "So dien thoai" };
    int vt_cot[10] = { 7, 22, 32, 20, 18, 22 };
    int vt_hang[15] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

    string data = Getfile("Ql_tt_khachhang.txt");

    Table tb2(7, 12, vt_hang, vt_cot, 0);
    tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
    tb2.CreatTable(kht2_kh, sh2_kh, sc2_kh);

    /******************************** Xu ly data *****************************************************/
    char c;
    int cnt_hang = 0, cnt_cot = 0;
    string str_tt_kh = "", t_data;
    int value_count_kh = 0;
    int vt_trang = 1, sl_dong = 0;

    // Đếm số dòng trong dữ liệu
    for (size_t i = 0; i < data.length(); i++) {
        c = data.at(i);
        if (c == '\n') {
            sl_dong++;
        }
    }

    // Tính số trang
    int sl_trang = (sl_dong / 14) + (sl_dong % 14 != 0);

    while (true) {
        cnt_hang = 0;
        value_count_kh = (vt_trang - 1) * 14 ;  // Dòng bắt đầu cho trang
        
        tb2.CreatTable(kht2_kh, sh2_kh, sc2_kh);
        // Tính dòng bắt đầu và dòng kết thúc cho trang hiện tại
        int dong_bd = (vt_trang - 1) * 14;
        int dong_kt = vt_trang * 14;

        // Duyệt qua từng dòng dữ liệu
        int vt_dong = 0;
        for (size_t i = 0; i < data.length(); i++) {
            c = data.at(i);

            if (c == '\n') {
                vt_dong++;

                if (vt_dong >= dong_bd && vt_dong <= dong_kt && vt_dong < sl_dong) {
                    // Chỉ hiển thị dữ liệu trong phạm vi dòng của trang
                    value_count_kh++;  // Tăng giá trị số thứ tự
                    cnt_hang++;  // Tăng chỉ số hàng

                    // Gán số thứ tự dòng
                    kht2_kh[cnt_hang][0].SetNoiDung(to_string(value_count_kh));
                    kht2_kh[cnt_hang][0].AddNoidung();

                    cnt_cot = 1;
                    str_tt_kh = "";
                }

                c = ' ';
            }

            if (c == ';') {
                // Khi gặp dấu ';', xử lý dữ liệu
                t_data = Xoa_khoang_trang_thua(str_tt_kh);
                kht2_kh[cnt_hang][cnt_cot].SetNoiDung(t_data);
                kht2_kh[cnt_hang][cnt_cot].AddNoidung();
                cnt_cot++;
                str_tt_kh = "";
            } else {
                // Nếu không phải ký tự đặc biệt, tiếp tục thu thập dữ liệu
                str_tt_kh += c;
            }
        }
		kht2_kh[cnt_hang][0].SetNoiDung(to_string(value_count_kh));
		
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

void Hien_thi_timkiem_khachhang()
{
	drawKhungGiaoDien("GIAO DIEN TIM KIEM KHACH HANG");

	#define sl_tk 3

	int vt_trang = 1, sl_trang = 1;
	Khunghienthi tk_htlc[sl_tk];
	string danhmuc_tk_htlc[sl_tk] = { "Tim kiem ma khach hang",
										   "Tim kiem ho ten",
										   "Tim kiem SDT" };
	for (int i = 0; i < sl_tk; i++)
	{
		tk_htlc[i].SetToaDo(6, 13 + 114 * i / sl_tk);
		tk_htlc[i].SetKichThuoc(3, 114 / sl_tk);
		tk_htlc[i].SetBackground(0);
		tk_htlc[i].SetNoiDung(danhmuc_tk_htlc[i]);
		tk_htlc[i].DrawKhunghienthi();
	}

	gotoxy(13, 13 + 60 - 7 / 2); cout << "KET QUA" << endl;

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "Stt", "Ma so","Ho ten", "Ngay sinh", "Gioi tinh",
									"So dien thoai"};
	int vt_cot[10] = {  7, 22, 32, 20, 18, 22  };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3, 3 };

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
		if (t_kk == 13)
		{
			break;
		}
	}

	Khunghienthi khtklc[50][50];
	int vt_cot_tklc[10] = { 114 / sl_tk, 114 - 114 / sl_tk + sl_tk - 2 };
	int vt_hang_tklc[10] = { 3 };
	string danhmuc_hang_tk[1] = { danhmuc_tk_htlc[luachon_tk] };
	string danhmuc_cot_tk[2] = { danhmuc_tk_htlc[luachon_tk], " " };
	Table tb_nhap_lc(9, 13, vt_hang_tklc, vt_cot_tklc, 0);
	tb_nhap_lc.Set_danhmuc(danhmuc_hang_tk, danhmuc_cot_tk);
	tb_nhap_lc.CreatTable(khtklc);

	Show_point(true);
	gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
	string str;
	while (1)
	{
		//Show_point(false);
		char kk = _getch();
		Show_point(false);
		gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
		if (30 < kk && kk < 122)
		{
			str.push_back(kk);
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
	str = Chuyenchuhoathanhchuthuong(str);

	gotoxy(38, 13 + 60 - 5);
	cout << "Trang " << vt_trang << "/" << sl_trang << endl;
	/************************************************************************/
	Show_point(false);
	fstream f;
	f.open(qlkh_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	int count_line = 1, count_vtdt = 0;
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

			if(luachon_tk != 2)
			    tt_str = Chuyenchuhoathanhchuthuong(str_dt[luachon_tk]);
			else 
				tt_str = Chuyenchuhoathanhchuthuong(str_dt[4]);

			int x = tt_str.find(str);
			if (x >= 0)
			{
				kht_tk[count_line][0].SetNoiDung(to_string(count_line));
				kht_tk[count_line][0].AddNoidung();
				for (int i = 0; i < 6; i++)
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

void Thucthi_Timkiem_khachhang()
{
	char kk = 13;
	while (1)
	{
		if (kk == 27) return;
		if (kk == 13)
			Hien_thi_timkiem_khachhang();
		kk = _getch();
	}
}

KhachHang Tim_kiem_ma_kh(string t_makh)
{
	KhachHang dt_khachhang;
	fstream f;
	f.open(qlkh_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	//int count_line = 1,
	int count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(t_makh);
	str = Chuyenchuhoathanhchuthuong(str);
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
			tt_str = Chuyenchuhoathanhchuthuong(str_dt[0]);

			if (tt_str == str)
			{
				dt_khachhang.Set_ma_kh(str_dt[0]);
				dt_khachhang.Set_hoten(str_dt[1]);
				dt_khachhang.Set_ngaysinh(chuyen_str_to_date(str_dt[2]));
				dt_khachhang.Set_gioitinh(str_dt[3]);
				dt_khachhang.Set_sdt(str_dt[4]);
				break;
			}
		}
	}
	f.close();
	return dt_khachhang;
}

int Xoa_khachhang() 
{
	drawKhungGiaoDien("GIAO DIEN XOA KHACH HANG");

	KhachHang dt_khachhang;
	int flag_exit = 0;
	Khunghienthi xs_lcht1, xs_lcht2;
	
	Khunghienthi sx_kht[50][50];
	int sx_sh = 0, sx_sc = 0;
	string danhmuc_hang[10] = { "Ma so khach hang",
								"Ho ten",
								"Ngay sinh",
								"Gioi tinh",
								"So dien thoai"};
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 25, 40 };
	int vt_hang[10] = { 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(sx_kht, sx_sh, sx_sc);

	drawXoaHuy();
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	
	string str_ma_kh = " ";

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
			str_ma_kh.push_back(kk);
			cout << str_ma_kh;
		}

		if (kk == 8)
		{
			if (!str_ma_kh.empty())
			{
				str_ma_kh.pop_back();
			}
			for (size_t i = 0; i < str_ma_kh.length() + 2; i++)
			{
				cout << "";
			}
			gotoxy(sx_kht[0][1].Get0y() + 2, sx_kht[0][1].Get0x() + 3);
			cout << str_ma_kh;
		}

		Show_point(false);

		if (kk == 13)
		{
			str_ma_kh = Xoa_khoang_trang_thua(str_ma_kh);
			dt_khachhang = Tim_kiem_ma_kh(str_ma_kh);
			if (dt_khachhang.Get_ma_kh() != " ")
			{
				str[1] = dt_khachhang.Get_hoten();
				str[2] = chuyen_date_to_str(dt_khachhang.Get_ngaysinh());
				str[3] = dt_khachhang.Get_gioitinh();
				str[4] = dt_khachhang.Get_sdt();
				for (tt_cnt = 1; tt_cnt < sx_sh; tt_cnt++)
					{
						gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
						cout << str[tt_cnt];
					}
			}
			else
			{
				tt_cnt++;
				if (tt_cnt > 5) tt_cnt = 1;
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
						if (dt_khachhang.Get_ma_kh() != " ")
						{
							Xoadoituongtrongfile(qlkh_file_name, dt_khachhang.Get_ma_kh());
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

void Sua_thongtin_khachhang()
{
	drawKhungGiaoDien("GIAO DIEN SUA THONG TIN KHACH HANG");
	
	KhachHang dt_kh;
	Khunghienthi stt_lcht1, stt_lcht2;
	string danhmuc_hang[10] = { "Ma khach hang:",
									 "Ho ten:",
									 "Ngay sinh:",
									 "Gioi tinh:",
									 "So dien thoai:"
									  };
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20, 45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht3_kh, sh3_kh, sc3_kh);

	drawXNhan_Thoat();
	/*******************************************************/
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0, step = 0;
	for (int i = 0; i < stt_sh_kh; i++)
	{
		dien_x[i] = kht3_kh[i][1].Get0x() + 2;
		dien_y[i] = kht3_kh[i][1].Get0y() + 5 / 2;
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
					if (tt_cnt > 5) tt_cnt = 1;
				}
				if (cc == 72)
				{
					tt_cnt--;
					if (tt_cnt < 1) tt_cnt = 5;
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
				string str_ma_kh = Xoa_khoang_trang_thua(str[0]);
				dt_kh = Tim_kiem_ma_kh(str_ma_kh);
				if (dt_kh.Get_ma_kh() != " ")
				{
					str[0] = dt_kh.Get_ma_kh();
					str[1] = dt_kh.Get_hoten();
					str[2] = chuyen_date_to_str(dt_kh.Get_ngaysinh());
					str[3] = dt_kh.Get_gioitinh();
					str[4] = dt_kh.Get_sdt();
					
					for (tt_cnt = 1; tt_cnt < stt_sh_kh; tt_cnt++)
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
			stt_lcht1.Doinen(2);

			while (1)
			{
				Show_point(false);
				char t_kk = _getch();
				string tt_kh = "";
				if (t_kk == -32)
				{
					char t_cc = _getch();
					if (t_cc == 75 || t_cc == 77)
					{
						if (vt_lcht == 0)
						{
							vt_lcht = 1;
							lcht1.Doinen(0);
							stt_lcht2.Doinen(2);
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
						for (int i = 0; i < stt_sh_kh; i++)
						{
							tt_kh += (str[i] + " ; ");
						}
						tt_kh += "\n";
						textcolor(WHITE);
						Xoadoituongtrongfile(qlkh_file_name, dt_kh.Get_ma_kh());
						Ghifile(qlkh_file_name, tt_kh);
						gotoxy(33, 90);
						cout << "Ban da luu" << endl;
						flag_exit = 1;
					}
				    if (vt_lcht == 1)
					{
						gotoxy(33, 90);
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