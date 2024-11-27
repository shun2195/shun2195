#ifndef DOHOA_H
#define DOHOA_H

#include <iostream>
#include <string>
#include <conio.h>
#include <tchar.h> 
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

// Cac HotKey
// Quay con tro ve 1 don vi char
#define BACKSPACE 8		// Xoa 1 ki tu
#define ENTER 13 		// OK
#define ESC  27			// thoat truc tiep va ve Menu chinh

#define KEY_UP 72		// Di len
#define KEY_DOWN 80		// Di xuong
#define KEY_LEFT 75		// Di qua tra
#define KEY_RIGHT 77	// Di qua phai 

#define KEY_F2 60		// Luu
#define KEY_F3 61		// Xoa
#define KEY_F4 62		// Hieu chinh
#define KEY_F9 67		//  Tim kiem
#define KEY_F10 68		// Save

#define PAGE_DOWN 81	// Cuon page xuong duoi
#define PAGE_UP 73		// Cuon page len tren

#define SPACE  32		// Khoang trang
#define TAB 9			// Tro ve

// thay unsigned int thanh uint
typedef unsigned int uint;

// ma mau
#define AQUA 3
#define PURPLE 5
#define LIGHT_AQUA 11
#define LIGHT_YELLOW 14
#define LIGHT_GREEN 10 
#define BLACK 0
#define WHITE 7
#define GREEN 2
#define BRIGHT_WHITE 15
#define BLUE 1
#define LIGHT_RED 12
#define LIGHT_ORANGE 78

// size man hinh
#define GWIDTH 120
#define GHEIGHT 36

void Disable_maximize();
void Close_windows_console();
void gotoxy(short y, short x);
int wherex(void);
int wherey(void);
void textcolor(WORD color);
void SetBGColor(WORD color);
void setColor(int maunen, int mauchu);
void Show_point(bool value);

class Khunghienthi
{
private:
	int toado_0x;
	int toado_0y;
	int chieucao;
	int chieurong;
	int modevien;
	int maubackgound;
	string noidung;
public:
	Khunghienthi();
	Khunghienthi(int y, int x, int h, int w, int bg, int mode_vien);
	Khunghienthi(int y, int x, int h, int w, int bg);
	
	void SetToaDo(int ,int );
	void SetKichThuoc(int ,int );
	void SetModeVien(int );
	void SetBackground(int );
	void SetNoiDung(string);
	void SetKhungHienThi( int, int, int, int, int, string);
	int  Get0y();
	int  Get0x();
	string GetNoiDung();
	void DrawKhunghienthi();
	void XoaNoiDung(int );
	void XoaAll(int );

	void AddNoidung();
	void Doinen(int );
};

extern Khunghienthi kht[50][50], kht1[50][50], kht2[50][50];
extern Khunghienthi lcht1, lcht2, lcht3, lcht4;
extern int sh , sc ;
//------------------

void ThanhTru(int y, int x, int maunen, int mauchu, int makitu);
void ThanhNgang(int y, int x, int w, int maunen, int mauchu, int makitu);
void KhungNho(int y, int x, int w, int h, string noidung , int bg);
void drawKhungGiaoDien(string tengd);
void drawXoaHuy();
void drawXNhan_Thoat();

class Table
{
private:
	int toado_0x;
	int toado_0y;
	int chieucao;
	int chieurong;
	int sohang;
	int socot;
	int dorongcot[50];
	int doronghang[50];
	int maubackgound;
	string tencot [50];
	string tenhang[50];
public:
	Table();
	Table(int y, int x,int *t_vthang, int *t_vtcot, int bg);
	void Set_danhmuc(string *dm_ten_hang, string *dm_ten_cot);
	void CreatTable(Khunghienthi kht[50][50], int& sh, int& sc);
	void CreatTable(Khunghienthi kht[50][50]);
	void ClearTable(Khunghienthi kht[50][50], int& sh, int& sc);
};

#endif