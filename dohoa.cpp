#include "dohoa.h"

void Disable_maximize()
{
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}

void Close_windows_console() 
{
	exit(0);
}

void gotoxy(short y, short x)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Vị trí x của con trỏ chuột
int wherex()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

// Vị trí y của con trỏ chuột
int wherey()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}

void textcolor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void setColor(int maunen, int mauchu)
{
	SetBGColor(maunen);
	textcolor(mauchu);
}

void Show_point(bool value)
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = value;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

Khunghienthi::Khunghienthi()
{
	this->toado_0x = 0;
	this->toado_0y = 0;
	this->chieucao = 0;
	this->chieurong = 0;
	this->maubackgound = 0;
	this->modevien = 1;
	this->noidung = "";
}

Khunghienthi::Khunghienthi(int y, int x, int h, int w, int bg, int mode_vien)
{
	this->toado_0x = x;
	this->toado_0y = y;
	this->chieucao = h;
	this->chieurong = w;
	this->maubackgound = bg;
	this->modevien = mode_vien;
}

Khunghienthi::Khunghienthi(int y, int x, int h, int w, int bg)
{
	this->toado_0x = x;
	this->toado_0y = y;
	this->chieucao = h;
	this->chieurong = w;
	this->maubackgound = bg;
	this->modevien = 1;
}

void Khunghienthi::SetToaDo(int y, int x) 
{
	this->toado_0x = x;
	this->toado_0y = y;
}

void Khunghienthi::SetKichThuoc(int h, int w)
{
	this->chieucao = h;
	this->chieurong = w;
}
void Khunghienthi::SetBackground(int color) 
{
	this->maubackgound = color;
}

void Khunghienthi::SetModeVien(int mode)
{
	this->modevien = mode;
}

void Khunghienthi::SetNoiDung(string t_noidung)
{
	this->noidung = t_noidung;
}

void Khunghienthi::DrawKhunghienthi()
{
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	int mode = this->modevien;
	int trenphai = 218;
	int trentrai = 191;
	int trenngang = 196;
	int bendung = 179;
	int duoiphai = 192;
	int duoitrai = 217;
	int duoingang = 196;

	if (mode == 0) 
	{
	    trenphai = 201;
		trentrai = 187;
		trenngang = 205;
		bendung = 186;
		duoiphai = 200;
		duoitrai = 188;
		duoingang = 205;
	};
	gotoxy(y, x);
	Show_point(false);
	SetBGColor(this->maubackgound);
	for (int i = x; i < x+w; i++) {
		if(wherex() == x && wherey() == y) {
			cout << char(trenphai);      // '┌' 201
		}
		else if (wherex() == x+w-1 && wherey() == y) {
			cout << char(trentrai);      // '┐' 187
		}
		else {
			cout << char(trenngang);      // '─'
		}
	}
	gotoxy(y + 1, x);
	for (int i = y+1; i < y+h-1; i++)
	{ 
			gotoxy(i, x); 
		    cout << char(bendung);         // '│'
			gotoxy(i, x+w-1);
			cout << char(bendung);
	}

	gotoxy(y + h - 1, x);
	for (int i = x; i < x + w; i++) {
		if (wherex() == x && wherey() == y + h - 1) {
			cout << char(duoiphai);      // '└'
		}
		else if (wherex() == x + w - 1 && wherey() == y + h - 1) {
			cout << char(duoitrai);      // '┘'
		}
		else {
			cout << char(duoingang);      // '─'
		}
	}

	XoaNoiDung(this->maubackgound);
	AddNoidung();
}

int  Khunghienthi::Get0y()
{
	int y = this->toado_0y;
	return y;
}
int  Khunghienthi::Get0x()
{
	int x =  this->toado_0x;
	return x;
}
string Khunghienthi::GetNoiDung()
{
	string str = this->noidung;
	return str;
}
void Khunghienthi::XoaNoiDung(int color)
{
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;

	SetBGColor(color);
	Show_point(false);
	for (int i = y + 1; i < y + h - 1; i++)
	{
		gotoxy(i, x + 1);
		for (int j = x + 1; j < x + w - 1; j++)
		{
			cout << " ";
		}
	}
}

void Khunghienthi::XoaAll(int color)
{
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;

	this->SetBackground(color);
	Show_point(false);
	if (h < 50 && w < 150)
	{
		for (int i = y; i < y + h; i++)
		{
			gotoxy(i, x);
			for (int j = x; j < x + w; j++)
			{
				cout << " ";
			}
		}
	}
	else
	{
		cout<<"loi doi tuong"<<endl;
	}
}

void Khunghienthi::AddNoidung()
{
	
	int x = this->toado_0x;
	int y = this->toado_0y;
	int h = this->chieucao;
	int w = this->chieurong;
	int l = this->noidung.length();
	gotoxy(y, x);
	if (l < w - 2)
	{
		gotoxy(y + h/2, x + w/2 - l/2);
		cout << this->noidung << endl;
	}
}

void Khunghienthi::Doinen(int color)
{
	SetBackground(color);
	XoaAll(color);
	DrawKhunghienthi();
}

Khunghienthi kht[50][50], kht1[50][50], kht2[50][50];
Khunghienthi lcht1, lcht2, lcht3, lcht4;
int sh = 0, sc = 0;
//------------------------------
void ThanhTru(int y, int x, int maunen, int mauchu, int makitu) {
	SetBGColor(maunen);
	textcolor(mauchu);
	for (int j = y; j < 25; j++) {
		gotoxy(j, x); cout << char(makitu);
	}
}

void ThanhNgang(int y, int x, int w, int maunen, int mauchu, int makitu) {
	SetBGColor(maunen);
	textcolor(mauchu);
	gotoxy(y, x);
	for (int i = x; i < x+w-2; i++) {
		cout << char(makitu);
	}
}


void KhungNho(int y, int x, int w, int h, string noidung, int bg)
{
	setColor(1, 50);
	gotoxy(y, x);
	SetBGColor(bg);
	for (int i = 0; i < w; i++) {
		if (i == 0) {
			cout << char(218);      // '┌'
		}
		else if (i == w - 1) {
			cout << char(191);      // '┐'
		}
		else {
			cout << char(196);      // '─'
		}
	}
	gotoxy(y + 1, x);
	for (int i = 1; i < h - 1; i++)
	{
		gotoxy(y + i, x);                // '│'
		cout << char(179);
		gotoxy(y + i, x + w - 1);
		cout << char(179);            // '│'
	}

	gotoxy(y + h - 1, x);
	for (int i = 0; i < w; i++) {
		if (i == 0) {
			cout << char(192);      // '└'
		}
		else if (i == w - 1) {
			cout << char(217);      // '┘'
		}
		else {
			cout << char(196);      // '─'
		}
	}
	//SetBGColor(0);
	gotoxy(y + 1, x + 1);
	for (int i = 0; i < h-2; i++) 
	{
        for (int j = 0; j < w-2; j++) 
		{
			cout << " ";
		}
		gotoxy(y + 1 + i, x + 1);
	}
	gotoxy(y + h /2, x + 10);
	cout << noidung;
}
void drawKhungGiaoDien(string tengd){
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	cout << "QUAN LY KHACH SAN SHUN-ORANGE" << endl;
    gotoxy(0 + 5 / 2, 10 + 120 / 2 - 27 / 2);
    cout << "PBL2: DO AN CO SO LAP TRINH" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - tengd.length() / 2);
	cout << tengd << endl;
	
	if(tengd == "GIAO DIEN NHAN VIEN"){
	ThanhNgang(38, 11, 120, BLACK, WHITE, char(205));
	gotoxy(39, 11 + 20);
	cout << "Cac phim dieu khien ^ v < > enter " << endl;
	}
}

void drawXoaHuy(){
	gotoxy(23, 90);
	cout << "Ban thue xoa ?" << endl;

	lcht1.SetToaDo(25, 80);
	lcht1.SetKichThuoc(3, 20);
	lcht1.SetBackground(0);
	lcht1.SetNoiDung("Xoa");
	lcht1.DrawKhunghienthi();

	lcht2.SetToaDo(25, 105);
	lcht2.SetKichThuoc(3, 20);
	lcht2.SetBackground(0);
	lcht2.SetNoiDung("Huy");
	lcht2.DrawKhunghienthi();

	gotoxy(30, 90);
	cout << "Su dung phim Ctrl+S de xoa" << endl;
	gotoxy(31, 90);
	cout << "Su dung phim Esc de thoat" << endl;
}

void drawXNhan_Thoat(){
	gotoxy(23, 90);
	cout << "Ban xac nhan hay thoat ?" << endl;

	lcht1.SetToaDo(25, 80);
	lcht1.SetKichThuoc(3,20);
	lcht1.SetBackground(0);
	lcht1.SetNoiDung("Xac Nhan");
	lcht1.DrawKhunghienthi();

	lcht2.SetToaDo(25, 105);
	lcht2.SetKichThuoc(3, 20);
	lcht2.SetBackground(0);
	lcht2.SetNoiDung("Thoat");
	lcht2.DrawKhunghienthi();

	gotoxy(30, 90);
	cout << "Su dung phim Ctrl+S de xac nhan" << endl;
	gotoxy(31, 90);
	cout << "Su dung phim Esc de thoat" << endl;
}	

Table::Table()
{
	this->toado_0x = 0;
	this->toado_0y = 0;
	this->chieucao = 1;
	this->chieurong = 1;
	this->socot = 1;
	this->sohang = 1;
	this->maubackgound = 0;
	for (int i = 0; i < 50; i++)
	{
		this->dorongcot[i] = 0;
		this->doronghang[i] = 0;
		this->tencot[i] = "";
		this->tenhang[i] = "";
	}
}

Table::Table(int y, int x,int *t_temp_vthang, int *t_temp_vtcot, int bg)
{
	//int t_drc = 0,
	int t_sh = 0, t_sc = 0, h = 0, w = 0;
	int *temp_vthang = t_temp_vthang;
	int *temp_vtcot = t_temp_vtcot;
	this->toado_0x = x;
	this->toado_0y = y;
	
	while (*temp_vthang > 0) 
	{
	
		h += *temp_vthang;
        this->doronghang[t_sh] = *temp_vthang;
	    t_sh++;
		temp_vthang++;
	}

	while (*temp_vtcot > 0)
	{
		
		w += *temp_vtcot;
		this->dorongcot[t_sc] = *temp_vtcot;
		t_sc++;
		temp_vtcot++;
	}

	this->socot = t_sc;
	this->sohang = t_sh;
	this->chieurong = w;
	this->chieucao = h;

	for (int i = 0; i < 50; i++)
	{
		this->tencot[i] = "";
		this->tenhang[i] = "";
	}
	this->maubackgound = bg;
}

void Table::Set_danhmuc(string *dm_ten_hang, string *dm_ten_cot)
{
	for (int j = 0; j < this->socot; j++)
	{
		this->tencot[j] = dm_ten_cot[j];
	}

	for (int i = 0; i < this->sohang; i++)
	{
		this->tenhang[i] = dm_ten_hang[i];
	}
}

void Table::CreatTable(Khunghienthi kht[50][50], int &sh, int &sc)
{
	int x = this->toado_0x;
	int y = this->toado_0y;

	sc = this->socot;
	sh = this->sohang;

	Show_point(false);
	for (int j = 0; j < sh; j++)
	{
		for (int i = 0; i < sc; i++)
		{
			kht[j][i].SetToaDo(y, x);
			kht[j][i].SetKichThuoc(this->doronghang[j], this->dorongcot[i]);
			kht[j][i].SetBackground(this->maubackgound);
			kht[j][i].SetNoiDung("");
			if (j == 0) kht[j][i].SetNoiDung(this->tencot[i]);
			if (i == 0) kht[j][i].SetNoiDung(this->tenhang[j]);
			kht[j][i].DrawKhunghienthi();
			if (i > 0)
			{
				gotoxy(y, x);
				cout << char(194);
				gotoxy(y + this->doronghang[j] - 1, x);
				cout << char(193);
			}

			if (i == 0 && j > 0)
			{
				gotoxy(y, x);
				cout << char(195);
			}

			if (i == sc - 1 && j > 0)
			{
				gotoxy(y, x + dorongcot[i] - 1);
				cout << char(180);
			}

			if (j > 0 && i > 0)
			{
				gotoxy(y, x);
				cout << char(197);
			}
			x += this->dorongcot[i] - 1;
		}
		x = this->toado_0x;
		y += this->doronghang[j] - 1;

	}
}

void Table::CreatTable(Khunghienthi kht[50][50])
{
	int x = this->toado_0x;
	int y = this->toado_0y;

	int sc = this->socot;
	int sh = this->sohang;

	Show_point(false);
	for (int j = 0; j < sh; j++)
	{
		for (int i = 0; i < sc; i++)
		{
			kht[j][i].SetToaDo(y, x);
			kht[j][i].SetKichThuoc(this->doronghang[j], this->dorongcot[i]);
			kht[j][i].SetBackground(this->maubackgound);
			kht[j][i].SetNoiDung("");
			if (j == 0) kht[j][i].SetNoiDung(this->tencot[i]);
			if (i == 0) kht[j][i].SetNoiDung(this->tenhang[j]);
			kht[j][i].DrawKhunghienthi();
			if (i > 0)
			{
				gotoxy(y, x);
				cout << char(194);
				gotoxy(y + this->doronghang[j] - 1, x);
				cout << char(193);
			}

			if (i == 0 && j > 0)
			{
				gotoxy(y, x);
				cout << char(195);
			}

			if (i == sc - 1 && j > 0)
			{
				gotoxy(y, x + dorongcot[i] - 1);
				cout << char(180);
			}

			if (j > 0 && i > 0)
			{
				gotoxy(y, x);
				cout << char(197);
			}
			x += this->dorongcot[i] - 1;
		}
		x = this->toado_0x;
		y += this->doronghang[j] - 1;

	}
}
void Table::ClearTable(Khunghienthi kht[50][50], int& sh, int& sc){
	sc = this->socot;
	sh = this->sohang;
	for(int j = 0; j < sc; j++){
		for(int i = 0; i < sh; i++){
			kht[i][j].XoaNoiDung(0);
		}
	}
}