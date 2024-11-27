#include <iostream>
#include <windows.h>
#include "chucnangchinh.h"

using namespace std;

#define MAX_TRY 5


int main()
{
	//1111111111
	int t_exit = 0;
	int lua_chon = 0;
	Show_point(false);
	Disable_maximize();
	int count = 0;
	bool dangNhapThanhCong = false;  // Biến kiểm soát trạng thái đăng nhập
	
	while (1){
		while (count < MAX_TRY && !dangNhapThanhCong)
		{	
			dangNhapThanhCong = Create_login();	
	    	if(!dangNhapThanhCong) count++;
	    	
		}	
		// Thoát khỏi vòng lặp chính, kiểm tra trạng thái đăng nhập
		
		if (!dangNhapThanhCong) {
			gotoxy(23,50);
		    cout << "Chuong trinh ket thuc do qua nhieu lan dang nhap sai!" << endl;
		    _getch();
		    break;
		}
		
	    Create_main(lua_chon);  // Chuyển đến màn hình chính sau khi đăng nhập thành công
	    SetBGColor(0);
		system("cls");
		switch (lua_chon)
		{
		case 5:                     //1.1 Tim kiem phong
			Thucthi_Timkiem_phong();
			break;
		case 6:                     //1.2 Them phong
			while (1)
				{
					Khung_Ql_phong_Them_phong();
					if(Xuly_Ql_phong_Them_phong())
					   
                    break;
				}
			
			break;
		case 7:                    //1.3 Sua thong tin phong
			Sua_thongtin_phong();	
				break;
		case 8:                    //1.4 Xoa phong
			t_exit = 0;
			while (!t_exit)
			{
				t_exit = Xoa_phong();
			}
			break;	
		case 9:                  //1.5 Ds phong
			Hienthi_Ql_phong_ds();
			break;
		case 11:                  //2.1 Tim kiem khach hang
			Thucthi_Timkiem_khachhang();
			break;
		case 12:                  //2.2 Them khach hang
			while (1)
			{
				Khung_Ql_phong_Them_khachhang();
				if (Xuly_Ql_phong_Them_khachhang())

					break;
			}
			break;
		case 13:                  //2.3 Sua thong tin khach hang
			Sua_thongtin_khachhang();
			break;
		case 14:                 //2.4 Xoa khach hang
			t_exit = 0;
			while (!t_exit)
			{
				t_exit = Xoa_khachhang();
			}
			break;
		case 15:                 //2.5 Danh phong khach hang
			Hienthi_Ql_khachhang_ds();
			break;
		case 17:                  //3.1 Dat phong
			while (1)
			{
				Khung_Ql_dat_phong();
				if (Xuly_Ql_dat_phong())

				break;
			}
			break;
		case 18:                 //3.2 Tra phong		
			while (1)
			{
				Khung_Ql_tra_phong();
				if (Xuly_Ql_tra_phong())

					break;
			}
			break;
		case 20:                 //4.1 Hoa don theo phong
			Hoadon_theophongkh();
			break;
		case 21:                //4.2 Hoa don theo ngay
			Hoadon_theongay();
			break;
		case 22:                //4.3 Lich su lua tru
			Lichsu_luutru();
			break;
		case 100:              
			dangNhapThanhCong=false;
			break;
		}
		SetBGColor(0);
		system("cls");
	}
	system("pause");
	return 0;
	
}

