#include "date.h"

void Thoi_Gian_Thuc(Date &x){
	time_t t = time(0);
	struct tm *now = localtime(&t);
	x.Ngay = now->tm_mday;
	x.Thang = now->tm_mon + 1;
	x.Nam = now->tm_year + 1900;
}

string Get_thoi_Gian_Thuc(){
	Date x;
	time_t t = time(0);
	struct tm *now = localtime(&t);
	x.Ngay = now->tm_mday;
	x.Thang = now->tm_mon + 1;
	x.Nam = now->tm_year + 1900;
	string str;
	str  = char(x.Ngay / 10 + 48);
	str += char(x.Ngay % 10 + 48);
	str += '/';
	str += char(x.Thang / 10 + 48);
	str += char(x.Thang % 10 + 48);
	str += '/';
	str += char(x.Nam / 1000 + 48);
	str += char((x.Nam / 100) % 10 + 48);
	str += char((x.Nam / 10)  % 10 + 48);
	str += char(x.Nam % 10 + 48);
	return str;
}

Date Suadate(string tt_date){
	Show_point(true);
	int x = wherex();
	int y = wherey();
	int x_vt[8] = { x + 0,x + 1,x + 3,x + 4,x + 6,x + 7,x + 8,x + 9 };
	char stc[10] = { ' ',' ','/',' ',' ','/',' ',' ',' ',' ' };
	int vt = 0;
	char k, kk;
	Date t_date;
	/*********************************/
	for (int i = 0; i < 10; i++)
	{
		stc[i] = tt_date.at(i);
	}
	/************************************/
	for (int i = 0; i < 10; i++)
	{
		cout << stc[i];
	}
	gotoxy(y, x);
	while (1)
	{
		k = _getch();
		if (k == -32)
		{
			kk = _getch();
			if (kk == 77) //sang phai 
			{
				vt++;
				if (vt == 8) vt = 0;
			}

			if (kk == 75) //sang trai 
			{
				vt--;
				if (vt < 0) vt = 7;
			}
			gotoxy(y, x_vt[vt]);
		}
		if (k > 47 && k < 58)
		{
			switch (vt)
			{
			case 0: stc[0] = k; break;
			case 1: stc[1] = k; break;
			case 2: stc[3] = k; break;
			case 3: stc[4] = k; break;
			case 4: stc[6] = k; break;
			case 5: stc[7] = k; break;
			case 6: stc[8] = k; break;
			case 7: stc[9] = k; break;
			}
			cout << k;
			vt++;
			if (vt == 8) vt = 0;
			gotoxy(y, x_vt[vt]);
		}
		if (k == 13)
		{
			for (int i = 0; i < 10; i++)
			{
				if (stc[i] < 45) stc[i] = '0';
			}
			t_date.Ngay = (stc[0] - 48) * 10 + (stc[1] - 48);
			t_date.Thang = (stc[3] - 48) * 10 + (stc[4] - 48);
			t_date.Nam = (stc[6] - 48) * 1000 + (stc[7] - 48) * 100 + (stc[8] - 48) * 10 + (stc[9] - 48);
			if (Kiem_Tra_Tinh_Hop_Le(t_date) == true)
			{
				break;
			}
		}
	}
	return t_date;	
}
string Suadate2(char kq, string tt_date){
		Show_point(true);
	int x = wherex();
	int y = wherey();
	int x_vt[8] = { x + 0,x + 1,x + 3,x + 4,x + 6,x + 7,x + 8,x + 9 };
	char stc[10] = { ' ',' ','/',' ',' ','/',' ',' ',' ',' ' };
	int vt = 1;
	char k, kk;
	Date t_date;
	string tx_date = "";
	/*********************************/
	gotoxy(y, x);
	for (int i = 0; i < 10; i++)
	{
		stc[i] = tt_date.at(i);
		cout << stc[i];
	}
	gotoxy(y, x);
	stc[0] = kq;
	cout << stc[0];
	/************************************/
	
	while (1)
	{
		k = _getch();
		if (k == -32)
		{
			kk = _getch();
			if (kk == 77) //sang phai 
			{
				vt++;
				if (vt == 8) vt = 0;
			}

			if (kk == 75) //sang trai 
			{
				vt--;
				if (vt < 0) vt = 7;
			}
			gotoxy(y, x_vt[vt]);
		}
		if (k > 47 && k < 58)
		{
			switch (vt)
			{
			case 0: stc[0] = k; break;
			case 1: stc[1] = k; break;
			case 2: stc[3] = k; break;
			case 3: stc[4] = k; break;
			case 4: stc[6] = k; break;
			case 5: stc[7] = k; break;
			case 6: stc[8] = k; break;
			case 7: stc[9] = k; break;
			}
			cout << k;
			vt++;
			if (vt == 8) vt = 0;
			gotoxy(y, x_vt[vt]);
		}
		if (k == 13)
		{
			for (int i = 0; i < 10; i++)
			{
				if (stc[i] < 45) stc[i] = '0';
			}
			t_date.Ngay = (stc[0] - 48) * 10 + (stc[1] - 48);
			t_date.Thang = (stc[3] - 48) * 10 + (stc[4] - 48);
			t_date.Nam = (stc[6] - 48) * 1000 + (stc[7] - 48) * 100 + (stc[8] - 48) * 10 + (stc[9] - 48);
			if (Kiem_Tra_Tinh_Hop_Le(t_date) == true)
			{
				for (int i = 0; i < 10; i++)
				{
					tx_date += stc[i];
				}
				break;
			}
		}
	}
	return tx_date;
}
string Suadate3(char kq, string tt_date){
	Show_point(true);
	int x = wherex();
	int y = wherey();
	int x_vt[8] = { x + 0,x + 1,x + 3,x + 4,x + 6,x + 7,x + 8,x + 9 };
	char stc[10] = { ' ',' ','/',' ',' ','/',' ',' ',' ',' ' };
	int vt = 1;
	char k, kk;
	Date t_date;
	string tx_date = "";
/*********************************/
	gotoxy(y, x);
	for (int i = 0; i < 10; i++){
	stc[i] = tt_date.at(i);
	cout << stc[i];
	}
	gotoxy(y, x);
	stc[0] = kq;
	cout << stc[0];
/************************************/

	while (1)
	{
	k = _getch();
	if (k == -32)
	{
		kk = _getch();
		if (kk == 77) //sang phai 
		{
			vt++;
			if (vt == 8) vt = 0;
		}

		if (kk == 75) //sang trai 
		{
			vt--;
			if (vt < 0) vt = 7;
		}
		gotoxy(y, x_vt[vt]);
	}
	if (k > 47 && k < 58)
	{
		switch (vt)
		{
		case 0: stc[0] = k; break;
		case 1: stc[1] = k; break;
		case 2: stc[3] = k; break;
		case 3: stc[4] = k; break;
		case 4: stc[6] = k; break;
		case 5: stc[7] = k; break;
		case 6: stc[8] = k; break;
		case 7: stc[9] = k; break;
		}
		cout << k;
		vt++;
		if (vt == 8) vt = 0;
		gotoxy(y, x_vt[vt]);
	}
	if (k == 13)
	{
		for (int i = 0; i < 10; i++)
		{
			if (stc[i] < 45) stc[i] = '0';
		}
		t_date.Ngay = (stc[0] - 48) * 10 + (stc[1] - 48);
		t_date.Thang = (stc[3] - 48) * 10 + (stc[4] - 48);
		t_date.Nam = (stc[6] - 48) * 1000 + (stc[7] - 48) * 100 + (stc[8] - 48) * 10 + (stc[9] - 48);
		if (Kiem_Tra_Tinh_Hop_Le_3(t_date) == true)
		{
			for (int i = 0; i < 10; i++)
			{
				tx_date += stc[i];
			}
			break;
		}
	}
}
return tx_date;
}

Date::Date(): Ngay(1), Thang(1), Nam(1970) {}
Date::Date(int Ngay, int Thang, int Nam) : Ngay(Ngay), Thang(Thang), Nam(Nam){}
		
void Date::Set_ngay(int Ngay){
	this->Ngay = Ngay;
}
void Date::Set_thang(int Thang){
	this->Thang = Thang;	 
}
void Date::Set_nam(int Nam){
	this->Nam = Nam; 
}
		
int Date::Get_ngay(){
	return this->Ngay; 
}
int Date::Get_thang(){
	return this->Thang;	
}
int Date::Get_nam(){
	return this->Nam;
}
		
Date Nhapdate(){
	Show_point(true);
int x = wherex();
int y = wherey();
int x_vt[8] = {x+0,x+1,x+3,x+4,x+6,x+7,x+8,x+9};
char stc[10] = { ' ', ' ', '/', ' ', ' ', '/', ' ', ' ', ' ', ' ' };
int vt = 0;
char k, kk;
Date t_date;
for (int i = 0; i < 8; i++) 
{
	cout << stc[i];
}
gotoxy(y, x);
while (1) 
{
	k = _getch();
	if (k == -32) 
	{
	    kk = _getch();
		if (kk == 77) //sang phai 
		{
			vt++;
			if (vt == 8) vt = 0;
		}
			
		if (kk == 75) //sang trai 
		{
			vt--;
			if (vt < 0) vt = 7;
		}
		gotoxy(y, x_vt[vt]);
	}
	if( k > 47 && k < 58)
	{
		switch (vt) 
		{
		case 0: stc[0] = k; break;
		case 1: stc[1] = k; break;
		case 2: stc[3] = k; break;
		case 3: stc[4] = k; break;
		case 4: stc[6] = k; break;
		case 5: stc[7] = k; break;
		case 6: stc[8] = k; break;
		case 7: stc[9] = k; break;
		}
		cout << k;
		vt++;
		if (vt == 8) vt = 0;
		gotoxy(y, x_vt[vt]);
	}
	if (k == 13)
	{
		for (int i = 0; i < 10; i++)
		{
			if (stc[i] < 45) stc[i] = '0';
		}
		t_date.Ngay = (stc[0] - 48) * 10 + (stc[1] - 48);
	    t_date.Thang = (stc[3] - 48) * 10 + (stc[4] - 48);
	    t_date.Nam = (stc[6] - 48) * 1000 + (stc[7] - 48) * 100 + (stc[8] - 48) * 10 + (stc[9] - 48);
		if (Kiem_Tra_Tinh_Hop_Le(t_date) == true)
		{
			break;
	    }
	}
}
return t_date;
}

int Tinh_songay(Date ngay_thue, Date ngay_tra){
	int ngay_trong_thang[13] = {0,
                             31,28,31,30,31,30,
                             31,31,30,31,30,31};
                             
    double tong_thue = ngay_thue.Nam * 365 + ngay_thue.Ngay;
    for(int i = 1; i < ngay_thue.Thang; i++){
        tong_thue += ngay_trong_thang[i];
    }
    
    double tong_tra = ngay_tra.Nam * 365 + ngay_tra.Ngay;
    for(int i = 1; i < ngay_tra.Thang; i++){
        tong_tra += ngay_trong_thang[i];
    }
    
    return (tong_tra - tong_thue);    
}

void Doc_File_Ngay_Thang_Nam(ifstream& file, Date &x){
	file >> x.Ngay;
	file.seekg(1, ios::cur);
	file >> x.Thang;
	file.seekg(1, ios::cur);
	file >> x.Nam;
	file.seekg(2, ios::cur);
}
void Ghi_File_Ngay_Thang_Nam(ofstream& file, Date x){
	file << x.Ngay<< "/" << x.Thang << "/" << x.Nam;
}
bool Kiem_Tra_Tinh_Hop_Le(Date x){
	// hàm lấy thời gian thực từ hệ thống máy tính
	time_t t = time(0);
	struct tm *now = localtime(&t);
	// kiểm tra tính đúng của ngày tháng năm
	if (x.Ngay < 0 || x.Ngay > 31){
		return false;
	}
	if (x.Thang < 0 || x.Thang > 12){
		return false;
	}
if (x.Nam < 1900)
{
	return false;
}
// kiểm tra xem ngày tháng năm nhập vào có nhỏ hơn ngày tháng năm hiện tại không
if (x.Nam > now->tm_year + 1900)
{
	return false;
}
else if (x.Nam == now->tm_year + 1900)
{
	if (x.Thang > now->tm_mon + 1)
	{
		return false;
	}
	else if (x.Thang == now->tm_mon + 1)
	{
		if (x.Ngay > now->tm_mday)
		{
			return false;
		}
	}
}

// kiểm tra số ngày của từng tháng tương ứng
if (x.Thang == 4 || x.Thang == 6 || x.Thang == 9 || x.Thang == 11)
{
	if (x.Ngay > 30)
	{
		return false;
	}
}
else if (x.Thang == 2)
{
	if (Kiem_Tra_Nam_Nhuan(x.Nam) == true)
	{
		if (x.Ngay > 29)
		{
			return false;
		}
	}
	else
	{
		if (x.Ngay > 28)
		{
			return false;
		}
	}
}
else
{
	if (x.Ngay > 31)
	{
		return false;
	}
}
return true; // ngày tháng năm đều hợp lệ
}
// hàm kiểm tra tính hợp lệ của ngày tháng năm nhập vào
bool Kiem_Tra_Tinh_Hop_Le_3(Date x){
	// hàm lấy thời gian thực từ hệ thống máy tính
	time_t t = time(0);
	struct tm *now = localtime(&t);
	// kiểm tra tính đúng của ngày tháng năm
	if (x.Ngay < 0 || x.Ngay > 31){
	return false;
	}
	if (x.Thang < 0 || x.Thang > 12)
	{
	return false;
	}
	if (x.Nam < 1900)
	{
	return false;
	}
	// kiểm tra xem ngày tháng năm nhập vào có nhỏ hơn ngày tháng năm hiện tại không
	if (x.Nam < now->tm_year + 1900)
	{
	return false;
	}
else if (x.Nam == now->tm_year + 1900)
{
	if (x.Thang < now->tm_mon + 1)
	{
		return false;
	}
	else if (x.Thang == now->tm_mon + 1)
	{
		if (x.Ngay < now->tm_mday)
		{
			return false;
		}
	}
}

// kiểm tra số ngày của từng tháng tương ứng
if (x.Thang == 4 || x.Thang == 6 || x.Thang == 9 || x.Thang == 11)
{
	if (x.Ngay > 30)
	{
		return false;
	}
}
else if (x.Thang == 2)
{
	if (Kiem_Tra_Nam_Nhuan(x.Nam) == true)
	{
		if (x.Ngay > 29)
		{
			return false;
		}
	}
	else
	{
		if (x.Ngay > 28)
		{
			return false;
		}
	}
}
else
{
	if (x.Ngay > 31)
	{
		return false;
	}
}
return true; // ngày tháng năm đều hợp lệ
}
bool Kiem_Tra_Nam_Nhuan(int Nam){
 // hàm kiểm tra năm nhuận
	if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
{
	return true;
}
return false;
}
bool Kiem_quahan(Date x){
	Date tg_now;
Thoi_Gian_Thuc(tg_now);
if (x.Nam > tg_now.Nam)
	return 1;
else if (x.Nam < tg_now.Nam)
	return 0;
	
if (x.Thang > tg_now.Thang)
	return 1;
else if (x.Thang < tg_now.Thang)
	return 0;

if (x.Ngay > tg_now.Ngay)
	return 1;
	
return 0;
}
Date chuyen_str_to_date(string str_date){
	Date t_date;
	char stc[10];
	str_date = Xoa_khoang_trang_thua(str_date);
	if (!str_date.empty())
	{
	for (size_t i = 0; i < str_date.length(); i++)
	{
		stc[i] = str_date.at(i);
	}
	t_date.Ngay =  (stc[0] - 48) * 10 + (stc[1] - 48);
	t_date.Thang = (stc[3] - 48) * 10 + (stc[4] - 48);
	t_date.Nam =   (stc[6] - 48) * 1000 + (stc[7] - 48) * 100 + (stc[8] - 48) * 10 + (stc[9] - 48);
	
}
else
{
	t_date.Ngay = 1;
	t_date.Thang = 1;
	t_date.Nam =  1970;
}
return t_date;
}
string chuyen_date_to_str(Date x){
	string str;
	str =  char(x.Ngay / 10 + 48);
	str += char(x.Ngay % 10 + 48);
	str += '/';
	str += char(x.Thang / 10 + 48);
	str += char(x.Thang % 10 + 48);
	str += '/';
	str += char(x.Nam / 1000 + 48);
	str += char((x.Nam / 100) % 10 + 48);
	str += char((x.Nam / 10) % 10 + 48);
	str += char(x.Nam % 10 + 48);
	return str;
}