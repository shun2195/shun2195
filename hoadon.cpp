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
	                                 "Tim kiem theo ma khach hang"};
	for (int i = 0; i < sl_tk; i++)
	{
		tk_htlc[i].SetKhungHienThi(6, 13+ 114 * i / sl_tk, 3, 114 / sl_tk, 0, danhmuc_tk_htlc[i]);
		tk_htlc[i].DrawKhunghienthi();
	}
	
	gotoxy(13, 13 + 114/2  - 9/2); cout << "- KET QUA -" << endl;

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Ma KH" , 
									"Ho ten", "Ngay thue", "Ngay tra", "Thanh tien"};
	int vt_cot[10] = { 7, 16, 16, 27, 18, 18, 20 };
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


void Hoadon_theongay() {
    char kk = 13;
    while (1) {
        if (kk == 27) return;
        if (kk == 13) {
            drawKhungGiaoDien("GIAO DIEN HOA DON THEO NGAY ");

            #define sl_tk 2

            int vt_trang = 1, sl_trang = 1;

            Khunghienthi tk_htlc[sl_tk];
            string danhmuc_tk_htlc[sl_tk] = {"Tim kiem theo ngay thue", "Tim kiem theo ngay tra"};
            for (int i = 0; i < sl_tk; i++) {
                tk_htlc[i].SetKhungHienThi(6, 13 + 114 * i / sl_tk, 3, 114 / sl_tk, 0, danhmuc_tk_htlc[i]);
                tk_htlc[i].DrawKhunghienthi();
            }

            gotoxy(13, 13 + 114 / 2 - 9 / 2);
            cout << "- KET QUA -" << endl;

            string danhmuc_hang[20] = {"Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," "};
            string danhmuc_cot[10] = {"Stt", "Ma phong", "Ma KH", "Ho ten", "Ngay thue", "Ngay tra", "Thanh tien"};
            int vt_cot[10] = {7, 16, 16, 27, 18, 18, 20};
            int vt_hang[15] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

            Khunghienthi kht_tk[50][50];

            Table tb2(15, 12, vt_hang, vt_cot, 0);
            tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
            tb2.CreatTable(kht_tk);

            textcolor(WHITE);

            int luachon_tk = 0;
            tk_htlc[luachon_tk].Doinen(2);

            while (1) {
                Show_point(false);
                char t_kk = _getch();
                if (t_kk == -32) {
                    char t_cc = _getch();
                    if (t_cc == 75) {
                        tk_htlc[luachon_tk].Doinen(0);
                        luachon_tk--;
                        if (luachon_tk < 0) luachon_tk = sl_tk - 1;
                        tk_htlc[luachon_tk].Doinen(2);
                    }
                    if (t_cc == 77) {
                        tk_htlc[luachon_tk].Doinen(0);
                        luachon_tk++;
                        if (luachon_tk == sl_tk) luachon_tk = 0;
                        tk_htlc[luachon_tk].Doinen(2);
                    }
                }
                if (t_kk == 13) {
                    break;
                }
            }

            int vt_cot_tklc[10] = {38 , 77};
            int vt_hang_tklc[10] = {3};

            string danhmuc_hang_tk[10] = {danhmuc_tk_htlc[luachon_tk]};
            string danhmuc_cot_tk[10] = {" ", " "};

            Khunghienthi khtklc[50][50];
            int sh_tk = 0, sc_tk = 0;
            Table tb_nhap_lc(9, 13, vt_hang_tklc, vt_cot_tklc, 0);
            tb_nhap_lc.Set_danhmuc(danhmuc_hang_tk, danhmuc_cot_tk);
            tb_nhap_lc.CreatTable(khtklc, sh_tk, sc_tk);
            Show_point(true);
            gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);

            string str;
            while (1) {
                char kk = _getch();
                Show_point(false);

                if (30 < kk && kk < 122) {
                    str.push_back(kk);
                    gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
                    cout << str;
                }

                if (kk == 8) {
                    if (!str.empty()) {
                        str.pop_back();
                    }
                    for (size_t i = 0; i < str.length() + 2; i++) {
                        cout << " ";
                    }
                    gotoxy(khtklc[0][1].Get0y() + 3 / 2, khtklc[0][1].Get0x() + 2);
                    cout << str;
                }

                Show_point(true);

                if (kk == 13) {
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
            while (getline(f, line)) {
                if (line.length() > 1) {
                    tt_data = " ";
                    count_vtdt = 0;
                    for (size_t i = 0; i < line.length(); i++) {
                        if (line.at(i) == ';') {
                            str_dt[count_vtdt] = Xoa_khoang_trang_thua(tt_data);
                            count_vtdt++;
                            tt_data = " ";
                        } else tt_data += line.at(i);
                    }
                    string ngayThue = str_dt[3]; 
            		string ngayTra = str_dt[4];
            
            		// Nếu chuỗi tìm kiếm phù hợp với ngày thuê hoặc ngày trả, thêm vào bảng kết quả
            		if ( luachon_tk == 0 && ngayThue.find(str) != string::npos ) {
                		kht_tk[count_line][0].SetNoiDung(to_string(count_line)); // Số thứ tự
                		kht_tk[count_line][0].AddNoidung();
                		for (int i = 0; i < 7; i++) { // Thêm dữ liệu vào bảng
                    		kht_tk[count_line][i + 1].SetNoiDung(str_dt[i]);
                    		kht_tk[count_line][i + 1].AddNoidung();
                		}
                	count_line++;
                    }else if ( luachon_tk == 1 && ngayTra.find(str) != string::npos ) {
                		kht_tk[count_line][0].SetNoiDung(to_string(count_line)); // Số thứ tự
                		kht_tk[count_line][0].AddNoidung();
                		for (int i = 0; i < 7; i++) { // Thêm dữ liệu vào bảng
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
	
	drawKhungGiaoDien("LICH SU LUU TRU");

	string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " " };
	string danhmuc_cot[10] = { "Stt", "Ma phong", "Ma KH" , 
									"Ho ten", "Ngay thue", "Ngay tra", "Thanh tien"};
	int vt_cot[10] = { 7, 16, 16, 27, 18, 18, 20 };
	int vt_hang[20] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 , 3 };

	Khunghienthi kht[50][50];

	Table tb(7, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh , sc);
	
	char c;
    int cnt_hang = 0, cnt_cot = 0;
    string str_tt_hd = "", t_data;
    int value_count_ph = 0;
    int vt_trang = 1, sl_dong = 0;
	string data = Getfile("Ql_tt_hoadon.txt");
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
                    str_tt_hd = "";
                    
                }
            		c = ' ';
			}                
            
            if (c == ';') {
                // Khi gặp dấu ';', xử lý dữ liệu
                t_data = Xoa_khoang_trang_thua(str_tt_hd);
                if(cnt_cot < 8){
				kht[cnt_hang][cnt_cot].SetNoiDung(t_data);
               	kht[cnt_hang][cnt_cot].AddNoidung();
               	}
                cnt_cot++;
                str_tt_hd = "";
            } else {
                // Nếu không phải ký tự đặc biệt, tiếp tục thu thập dữ liệu
                str_tt_hd += c;
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