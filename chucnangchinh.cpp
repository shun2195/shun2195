#include "chucnangchinh.h"

int Create_login(){
	
	drawKhungGiaoDien("GIAO DIEN DANG NHAP");
	
	NhanVien *ds_nv = new NhanVien[10]; // Mảng chứa danh sách nhân viên
	docfileNV(ds_nv);
	
		string danhmuc_hang[10] = { "Tai khoan: ",
		                       		"Mat khau: ",
							};
		string danhmuc_cot[10] = { "", " " };
		int vt_cot[10] = { 15,50};
		int vt_hang[10] = {5, 5};
			
		Table tb(10, 40, vt_hang, vt_cot, 0);
		tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
		tb.CreatTable(kht, sh, sc);

		lcht1.SetKhungHienThi(24, 45, 3, 20, 0, "Xac nhan");
		lcht1.DrawKhunghienthi();

		lcht2.SetKhungHienThi(24, 75, 3, 25, 0, "Quen mat khau");
		lcht2.DrawKhunghienthi();
		
		lcht3.SetKhungHienThi(28, 45, 3, 55, 0, "Tao tai khoan");
		lcht3.DrawKhunghienthi();
		
		lcht4.SetKhungHienThi(38, 120, 3, 10, 0, "Thoat");
		lcht4.DrawKhunghienthi();
					
		gotoxy(32, 50);
		cout << "Su dung phim Ctrl+S de xac nhan" << endl;
		gotoxy(33, 50);
		cout << "Su dung phim Ctrl+R neu quen mat khau" << endl;
		gotoxy(34,50);
		cout << "Su dung phim Ctrl+N de tao tai khoan" << endl;
		gotoxy(35,50);
		cout << "Su dung phim Esc de thoat" << endl;
		// Nhập tài khoản và mật khẩu
	    	string username, password;
	    
			int dien_x[50];
			int dien_y[50];
			int tt_cnt = 0;
			string str[50];
			int flag_exit = 0;
			
			for (int i = 0; i < sh; i++)
			{
				dien_x[i] = kht[i][1].Get0x()+2;
				dien_y[i] = kht[i][1].Get0y() + 5/2;
				str[i] = "";
			}
			Show_point(true);
    		gotoxy(dien_y[0], dien_x[0]);
		
			while (!flag_exit)
			{
				Sleep(5);
				Show_point(true);
				char kk = _getch();
			
				lcht1.Doinen(0);
				lcht2.Doinen(0);
				
				if (kk == -32)
				{
					char cc = _getch();
					if (cc == 80)
					{
						tt_cnt++;
						if (tt_cnt > 1) tt_cnt = 0;
					}
					if (cc == 72)
					{
						tt_cnt--;
						if (tt_cnt < 0) tt_cnt = 1;
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
					if (tt_cnt > 1) tt_cnt = 0;
					gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

				}
				if (kk == 14)
				{
					while(true){
						if(Create_account())
							return 0;
					}
				}
				if (kk == 18)
				{
					while(true){
						if(Create_quen_mk())
							return 0;
					}
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
						else if (t_kk == 13) 
						{
							if (vt_lcht == 0) 
							{
								username = str[0];
								password = str[1];

								if (xuLyDangNhap(ds_nv, username, password)) 
								{
		    						gotoxy(21,50);
	    	    					cout << "Dang nhap thanh cong!" << endl;
	    	    					_getch();
	    	    					return 1;
	    						} else {
	        						gotoxy(21,50);
	        						cout << "Dang nhap that bai!" << endl;
	       			 				gotoxy(22,50);
	        						cout << "Vui long dang nhap lai!" << endl;
	        						flag_exit = 0;
	        						_getch();
	        						
	    						}
							}
							if (vt_lcht == 1) 
							{
								gotoxy(33, 90);
								cout << "Ban da huy" << endl;
								_getch();
							}
							XoaMang(20,50,3,40,0);
					    	break;
						}
						if (t_kk == 27)
						{
							Sleep(1000);
							exit(0);
						}
					}
					SetBGColor(0);
					gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				}
				if (kk == 27)
				{
					Sleep(1000);
					exit(0);
				}
			}
	return 0;
}

void Create_main(int &lua_chon)
{
	drawKhungGiaoDien("GIAO DIEN CHINH");
	
	string danhmuc[28] = { " 1.  Quan ly phong                  ",        // 0  ----
						   " 2.  Quan ly khach hang             ",        // 1
						   " 3.  Quan ly thanh toan             ",        // 2
						   " 4.  Thong ke hoa don               ",        // 3
						   " 5.  Thong ke doanh thu             ",        // 4
						   " 6.  Dang xuat                      ",        // 5  ****
							   " 1.1  Tim kiem phong            ",        // 6  ----
							   " 1.2  Them phong                ",        // 7
							   " 1.3  Sua thong tin phong       ",        // 8
							   " 1.4  Xoa phong                 ",        // 9
							   " 1.5  Danh sach phong           ",        // 10
							   " 1.6  Tro lai                   ",        // 11 ****
							   " 2.1  Tim kiem khach hang       ",        // 12 -----
							   " 2.2  Them khach hang           ",        // 13
							   " 2.3  Sua thong tin khach hang  ",        // 14
							   " 2.4  Xoa khach hang            ",        // 15
							   " 2.5  Danh sach khach hang      ",        // 16
							   " 2.6  Tro lai                   ",        // 17 *****
							   " 3.1  Dat phong                 ",        // 18 ----
							   " 3.2  Tra phong                 ",        // 19
							   " 3.3  Tro lai                   ",        // 20 ****
							   " 4.1  Hoa don theo phong / KH   ",        // 21 -----
							   " 4.2  Hoa don theo ngay         ",        // 22
							   " 4.3  Lich su luu tru           ",        // 23
							   " 4.4  Tro lai                   ",        // 24 ****
							   " 5.1  Doanh thu theo phong      ",        // 25 ----
							   " 5.2  Doanh thu theo thang      ",        // 26
							   " 5.3  Tro lai                   ",        // 27 ****
	};

	Docfile(10, 80, "gui_main.txt");

	Show_point(FALSE);
	Khunghienthi ht_main[28];
	for (int i = 0; i < 6 ; i++)
	{
		ht_main[i].SetKhungHienThi(6 + i * 5, 13, 5, 60, 0, danhmuc[i]);
		ht_main[i].DrawKhunghienthi();
	}
	for (int i = 6; i < 12; i++)
	{
		ht_main[i].SetKhungHienThi(6 + (i - 6) * 4, 80, 4, 45, 0, danhmuc[i]);
	}
	for (int i = 12; i < 18; i++)
	{
		ht_main[i].SetKhungHienThi(6 + (i - 12) * 4, 80, 4, 45, 0, danhmuc[i]);
	}
	for (int i = 18; i < 21; i++)
	{
		ht_main[i].SetKhungHienThi(6 + (i - 18) * 4, 80, 4, 45, 0, danhmuc[i]);
	}
	for (int i = 21; i < 25; i++)
	{
		ht_main[i].SetKhungHienThi(6 + (i - 21) * 4, 80, 4, 45, 0, danhmuc[i]);
	}
	for (int i = 25; i < 28; i++)
	{
		ht_main[i].SetKhungHienThi(6 + (i - 25) * 4, 80, 4, 45, 0, danhmuc[i]);
	}

	int vt_func0 = 5, vt_func1 = 0;
	int lop = 0;
	while (1) {
		gotoxy(7, 11);
		Sleep(50);
		char kk = _getch();
		if (kk == -32) {
			char cc = _getch();
			if (lop == 0)
				XoaMang(6, 75, 32, 52, 0);
			if (cc == 72)
			{
				if (lop == 0)
				{
					ht_main[vt_func0].Doinen(0);
					vt_func0--;
					if (vt_func0 < 0) vt_func0 = 5;
					ht_main[vt_func0].Doinen(1);
				}
				else
				{
					if (vt_func0 == 0)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 6) vt_func1 = 11;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 1)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 12) vt_func1 = 17;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 2)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 18) vt_func1 = 20;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 3)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 21) vt_func1 = 24;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 4)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 25) vt_func1 = 28;
						ht_main[vt_func1].Doinen(1);
					}
				}
			}

			if (cc == 80)
			{
				if (lop == 0)
				{
					ht_main[vt_func0].Doinen(0);
					vt_func0++;
					if (vt_func0 == 6) vt_func0 = 0;
					ht_main[vt_func0].Doinen(1);
				}
				else
				{
					if (vt_func0 == 0)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 11) vt_func1 = 6;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 1)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 17) vt_func1 = 12;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 2)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 2) vt_func1 = 18;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 3)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 24) vt_func1 = 21;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 4)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 28) vt_func1 = 25;
						ht_main[vt_func1].Doinen(1);
					}
				}
			}

			if (lop == 0)
			{
				if (vt_func0 == 0)
				{
					vt_func1 = 6;
					for (int i = 6; i < 12; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 1)
				{
					vt_func1 = 12;
					for (int i = 12; i < 18; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 2)
				{
					vt_func1 = 18;
					for (int i = 18; i < 21; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 3)
				{
					vt_func1 = 21;
					for (int i = 21; i < 25; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 4){
					vt_func1 = 25;
					for (int i = 25; i < 28; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 5)
				{
					SetBGColor(0);
					Docfile(10, 80, "gui_main.txt");
				}
			}
		}

		if (kk == 13)
		{
			if (lop == 0)
			{
				lop = 1;
				if (vt_func0 == 5)
				{
					lua_chon = 100;
					break;
				}
				else
					ht_main[vt_func1].Doinen(1);
			}
			else
			{
				lop = 0;
				if (vt_func1 == 11 || vt_func1 == 17 || vt_func1 == 20 || vt_func1 == 24 || vt_func1 == 27)
				{
					ht_main[vt_func1].Doinen(0);
				}
				else
				{
					gotoxy(0, 0);
					lua_chon = vt_func1;
					break;
				}
			}
		}
	}
}

int Create_account(){
	drawKhungGiaoDien("GIAO DIEN TAO TAI KHOAN");
	
	NhanVien *ds_nv = new NhanVien[10]; // Mảng chứa danh sách nhân viên
	docfileNV(ds_nv);
	
	string danhmuc_hang[10] = { "Ho va ten",
								"Ngay sinh",
								"SDT",
								"Gioi tinh",
								"Tai khoan moi",
	                       		"Mat khau",
	                       		"Nhap lai mat khau"
								};
	string danhmuc_cot[10] = { "", " "};
	int vt_cot[10] = {25, 40};
	int vt_hang[10] = {5, 5, 5, 5, 5, 5, 5  };
	
	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);
	
	drawXNhan_Thoat();
	
	// Nhập tài khoản và mật khẩu
    string username, password;
	
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0;
	Date t_date;

	// Khởi tạo tọa độ cho các trường nhập liệu
	for (int i = 0; i < sh; i++)
	{
		dien_x[i] = kht[i][1].Get0x() + 2;
		dien_y[i] = kht[i][1].Get0y() + 5 / 2;
		str[i] = "";
	}
	str[1] = "  /  /    ";  // Định dạng ngày sinh
	gotoxy(dien_y[1], dien_x[1]);
	cout << str[1];
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);

	while (!flag_exit)
	{
		Show_point(true);
		char kk = _getch();

		// Xóa thông báo
		lcht1.Doinen(0);
		lcht2.Doinen(0);
		gotoxy(15,90);
		cout << "                           " << endl;
        gotoxy(16,90);
        cout << "                           " << endl;
		gotoxy(33, 90);
		cout << "                           " << endl;

		// Xử lý phím điều hướng
		if (kk == -32)
		{
			char cc = _getch();
			if (cc == 80)  // Phím mũi tên xuống
			{
				tt_cnt++;
				if (tt_cnt > 6) tt_cnt = 0;
			}
			if (cc == 72)  // Phím mũi tên lên
			{
				tt_cnt--;
				if (tt_cnt < 0) tt_cnt = 6;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}

		// Xử lý nhập ký tự
		if (30 < kk && kk < 122)
		{
			if (tt_cnt != 1)  // Không cho nhập ở trường "Ngày sinh"
			{
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				cout << str[tt_cnt];
				Show_point(true);               
			}
			else{  // Xử lý định dạng ngày tháng
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				str[1] = Suadate2(kk, str[1]);
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
			for (size_t i = 0; i < str[tt_cnt].length() + 2; i++)
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
			if (tt_cnt > 6) tt_cnt = 0;
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
						for(int i = 0; i < sh; i++){
							kht[i][1].SetNoiDung(str[i]);
						}
						textcolor(WHITE);
                		if(xacNhanMK(str[5], str[6])){
                			string tt_nv = TaoMaNV(str[0], str[2]) + ";"
												+ kht[0][1].GetNoiDung() + ";"
												+ kht[1][1].GetNoiDung() + ";"
												+ kht[2][1].GetNoiDung() + ";"
												+ kht[3][1].GetNoiDung() + ";"
												+ kht[4][1].GetNoiDung() + ";"
												+ kht[5][1].GetNoiDung() + ";\n";
			
							// Ghi thông tin vào file
							Ghifile(qlnv_file_name, tt_nv);
							gotoxy(33, 90);
							cout << "Ban da xac nhan" << endl;
							flag_exit = 1;
						}else{
                			gotoxy(15,90);
                			cout << "Mat khau khong trung khop!";
                			gotoxy(16,90);
                			cout << "Xin vui long nhap lai";
                			flag_exit = 0;
                			_getch();
						}
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

int Create_quen_mk(){
	drawKhungGiaoDien("GIAO DIEN QUEN MAT KHAU");
	
	NhanVien dt_nv;
	string danhmuc_hang [10] = { "Tai khoan",
									"So dien thoai",
									"Mat khau moi",
									"Nhap lai mat khau moi"
								};						
	string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 25, 40 };
	int vt_hang[10] = { 5, 5, 5, 5 };

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);
	
	
	drawXNhan_Thoat();
	
	//-----------------------------------//
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	string str[50];
	int flag_exit = 0, step = 0;
	
	for (int i = 0; i < sh; i++)
	{
		dien_x[i] = kht[i][1].Get0x() + 2;
		dien_y[i] = kht[i][1].Get0y() + 5 / 2;
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
		
		if (kk == -32)
		{
			char cc = _getch();
			{
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
				cout << "";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 13)
		{
			if (step == 0)
			{
				string str_tk_nv = Xoa_khoang_trang_thua(str[0]);
				dt_nv = Tim_kiem_nv(str_tk_nv);
				
                // Gọi hàm XuLyQuenMK để xác nhận tài khoản và số điện thoại
                if (XuLyQuenMK(str[0], str[1])) {
                    str[0] = dt_nv.Get_taiKhoan();
                    str[1] = dt_nv.Get_SDT();
                    for (tt_cnt = 0; tt_cnt < sh; tt_cnt++)
					{
						gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
						cout << str[tt_cnt];
					}
                    step = 1;  // Chuyển sang bước tiếp theo (nhập mật khẩu mới)
                    
                } else {
                    gotoxy(33, 90);
                    cout << "Tai khoan hoac so dien thoai sai!" << endl;
                }
			}
			else {
				tt_cnt++;
				if (tt_cnt > 3) tt_cnt = 0;
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
				string tt_nv = "";
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
						for (int i = 0; i < sh; i++)
						{
							tt_nv += (str[i] + " ; ");
						}
						tt_nv += "\n";
						textcolor(WHITE);
						Xoadoituongtrongfile(qlnv_file_name, dt_nv.Get_taiKhoan());
						Ghifile(qlnv_file_name, tt_nv);
						gotoxy(29, 90);
						cout << "Ban da luu" << endl;
						flag_exit = 1;
					}
				    if (vt_lcht == 1)
					{
						gotoxy(29, 90);
						cout << "Ban da huy" << endl;
						step = 0;
						for (tt_cnt = 3; tt_cnt > 0; tt_cnt--)
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
	return 0;
}
