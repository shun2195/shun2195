#include "chucnangphu.h"

bool KiemTraTen(string a) {
    char *hoten = (char*)a.c_str();
    for (size_t i = 0; i < strlen(hoten); i++) {
        if (hoten[i] == ' ') {
            continue;
        }
        if (!((hoten[i] >= 'A' && hoten[i] <= 'Z') || (hoten[i] >= 'a' && hoten[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}


void ThongBaoNhapNhay(string s, int maunen, int mauchu, int cot, int hang) {
	do {
		setColor(maunen, mauchu);
		gotoxy(cot, hang); cout << s;
		Sleep(700);
		gotoxy(cot, hang);
		for (size_t i = 0; i < s.length(); i++) {
			cout << " ";
		}
		Sleep(300);
	} while (!_kbhit());
	getche();
	gotoxy(cot, hang);
	for (size_t i = 0; i < s.length(); i++) {
		cout << " ";
	}
}

void BangThongBaoLoi(string noidungloi) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 40; j++) {
			gotoxy(24 + j, 3 + i);
			SetBGColor(14);
			cout << " ";
			if (i == 1) {
				if (j == 32) {
					textcolor(12);
					gotoxy(40, 3 + i);
					cout << char(127) << " CANH BAO";
				}
				else {
					if (j != 39) {
						if (j == 0) {
							gotoxy(24, 3 + i);
							cout << char(186);
						}
						cout << " ";
					}
					else {
						gotoxy(64, 3 + i);
						cout << char(186);
					}
				}
			}
			if (i == 0 || i == 3) {
				textcolor(0);
				gotoxy(24 + j, 3 + i);
				cout << char(205);
				if (i == 0) {
					if (j == 0) {
						gotoxy(24 + j, 3 + i);
						cout << char(201);
					}
					else if (j == 39) {
						cout << char(187);
					}
				}
				else if (i == 3) {
					if (j == 0) {
						gotoxy(24 + j, 3 + i);
						cout << char(200);
					}
					else if (j == 39) {
						cout << char(188);
					}
				}
			}
			if (i == 2) {
				if (j == 0 || j == 39) {
					gotoxy(24 + j, 3 + i);
					if (j == 39) {
						gotoxy(64, 3 + i);
					}
					cout << char(186);
				}
			}
			gotoxy(26, 5);
			textcolor(0);
			cout << noidungloi;
		}
	}
	Sleep(1500);
}

void XoaBangThongBaoLoi() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 41; j++) {
			gotoxy(24 + j, 3 + i);
			SetBGColor(0);
			cout << " ";
		}
	}
	SetBGColor(8);
	textcolor(0);
}

void KhungHinh(int y, int x, int w, int h) {
	gotoxy(y, x);
	SetBGColor(BLACK);
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
	gotoxy(y+1, x);
	for (int i = 1; i < h - 1; i++)
	{
		gotoxy(y + i, x);                // '│'
		cout << char(179);
		gotoxy(y +i, x + w - 1);
		cout << char(179);            // '│'
	}

	gotoxy(y+h-1, x);
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
	SetBGColor(0);
	gotoxy(x + 1, y + 1);
}

void XoaMang(int y, int x, int h, int w, int color) {
	Sleep(500);
	gotoxy(y, x);
	SetBGColor(color);
	for (int j = y; j < y+ h; j++) {
	     for (int i = x; i < x + w; i++) {		
			gotoxy(j, i); cout << " ";
		}
	}
}

bool KiemTraNhapSoNguyen(char a[], int &MaKH) {
	for (size_t i = 0; i < strlen(a); i++) {
		if (a[i] < '0' || a[i] > '9') {
			return false;
		}
	}
	MaKH = atoi(a);
	return true;
}

void BangLuaChon(int y, int x, string noidung, bool &btn_Co) {
	SetBGColor(9);
	textcolor(15);
	gotoxy(y,x);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 32; j++) {
			cout << " ";
		}
		gotoxy (y + 1 + i, x);
	}
	gotoxy(y, x);
	for (int i = 0; i < 32; i++) {
		if (i == 0) {
			cout << char(201);
		}
		else if (i == 31) {
			cout << char(187);
		}
		else {
			cout << char(205);
		}
	}
	for (int i = 0; i < 4; i++) {
		gotoxy( y + i + 1, x);
		cout << char(186);
		gotoxy(y + i + 1, x + 31);
		cout << char(186);
	}
	gotoxy( y + 5, x);
	for (int i = 0; i < 32; i++) {
		if (i == 0) {
			cout << char(200);
		}
		else if (i == 31) {
			cout << char(188);
		}
		else {
			cout << char(205);
		}
	}
	gotoxy(y + 1, x + 1);
	cout << noidung;
	unsigned char yes[3][13] = { 
    { 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, ' ', ' ' },
    { 179, ' ', ' ', ' ', 'C', 'o', ' ', ' ', ' ', ' ', 179, ' ', ' ' },
    { 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, ' ', ' ' }
	};

	unsigned char no[3][13] = { 
    { ' ', 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, ' ' },
    { ' ', 179, ' ', ' ', 'K', 'h', 'o', 'n', 'g', ' ', ' ', 179, ' ' },
    { ' ', 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, ' ' }
	};

	gotoxy(y + 2, x + 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 13; j++) {
			cout << yes[i][j];
		}
		gotoxy(y + 3 + i, x + 3);
	}
	gotoxy(y + 2, x + 16);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 13; j++) {
			cout << no[i][j];
		}
		gotoxy(y + 3 + i, x + 16);
	}
	gotoxy(y + 3, x + 7);
	textcolor(0);
	cout << "Co";
	int plagS = 0;
	while (1) {
		while (!_kbhit())
		{
			Sleep(100);
		}
		char kk = _getch();
		if (kk == -32) {                 //
			char cc = _getch();            
			if (cc == 75 && plagS == 0) {
				//gotoxy(8, 32);
				gotoxy(y + 3, x + 7);
				textcolor(15);
				cout << "Co";
				//gotoxy(8, 45);
				gotoxy(y + 3, x + 7+13);
				plagS = 1;
				textcolor(0);
				cout << "Khong";
			}
			if (cc == 77 && plagS == 1) {
				//gotoxy(8, 45);
				gotoxy(y + 3, x + 7 + 13);
				textcolor(15);
				cout << "Khong";
				//gotoxy(8, 32);
				gotoxy(y + 3, x + 7);
				plagS = 0;
				textcolor(0);
				cout << "Co";
			}
		}
		 if (kk == 13) {
			if (plagS == 0) {
				btn_Co = true;
				break;
			}
			else break;
		}
	}
}

void KhungNhapMakhachhang(int y, int x) {
	gotoxy(y, x);
	textcolor(12);
	SetBGColor(1);
	for (int i = 0; i < 30; i++) {
		if (i == 0) {
			cout << char(201);
		}
		else if (i == 29) {
			cout << char(187);
		}
		else {
			cout << char(205);
		}
	}
	for (int i = 1; i < 4; i++) {
		gotoxy(y + i, x);
		cout << char(186);
		gotoxy(y + i, x + 29);
		cout << char(186);
	}
	gotoxy(y + 4, x);
	for (int i = 0; i < 30; i++) {
		if (i == 0) {
			cout << char(200);
		}
		else if (i == 29) {
			cout << char(188);
		}
		else {
			cout << char(205);
		}
	}
	textcolor(14);
	gotoxy(y + 1, x + 1); cout << "                            ";
	gotoxy(y + 2, x + 1); cout << " Ma khach hang   ";
	SetBGColor(7);
	gotoxy(y + 2, x + 14); cout << "              ";
	SetBGColor(1);
	gotoxy(y + 2, x + 27); cout << "  ";
	gotoxy(y + 3, x + 1); cout << "                            ";
	gotoxy(y + 2, x + 15);
}

void Ghifile(string name_file, string data)
{
	fstream f;
	f.open(name_file, ios::app);

	f << data;

	f.close();
}

string Getfile(string name_file)
{
	fstream f;
	f.open(name_file, ios::in);

	string line;
	string data;
	while (!f.eof())
	{
		getline(f, line);
		data = data + "\n" + line;
	}
	f.close();
	return data;
}

void Docfile(int y, int x, string name_file) 
{
	int vt_dong = y;

	fstream f;
	f.open(name_file, ios::in);

	string line;
	while (!f.eof())
	{
		getline(f, line);
		vt_dong++;
		gotoxy(vt_dong, x);
		cout << line <<endl;
	}
	f.close();
}


void Xoadoituongtrongfile(string name_file, string tk)
{
	fstream f;
	f.open(name_file, ios::in);

	string line;
	string data;
	tk = Chuyenchuhoathanhchuthuong(tk);
	while (!f.eof())
	{
		getline(f, line);
		line = Chuyenchuhoathanhchuthuong(line);
		int x = line.find(tk);
		if (x < 0)
		{
            data += line + "\n";
		}
	}
    f.close();

	f.open(name_file, ios::out);
	f << data;
	f.close();
}

void Suadoitrangthaiphong(string file_name, string t_maso, string t_trang_thai,  string t_ma_kh, string t_hoten)
{
	t_maso = Chuyenchuhoathanhchuthuong(t_maso);

	fstream f;
	f.open(file_name, ios::in);
	string line;
	string data;
	while (!f.eof())
	{
		getline(f, line);
		string t_line  = Chuyenchuhoathanhchuthuong(line);
		int x = t_line.find(t_maso);
		if (x >= 0)
		{
			int doan[10];
			int cnt_phay = 0;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					doan[cnt_phay] = i;
					cnt_phay++;
				}
			}
			if (cnt_phay >= 4) {
                line = line.substr(0, doan[2] + 1) + " " + t_trang_thai + " ;" + t_ma_kh + " ;" + t_hoten + " ;";
            }
		}
		data += (line + "\n");
		
	}
	f.close();
    
	f.open(file_name, ios::out);
	f << data;
	f.close();
}

void Suadoitrangthaikhachhang(string file_name, string t_maso, string t_trang_thai)
{
	t_maso = Chuyenchuhoathanhchuthuong(t_maso);

	fstream f;
	f.open(file_name, ios::in);
	string line;
	string data;
	while (!f.eof())
	{
		getline(f, line);
		string t_line = Chuyenchuhoathanhchuthuong(line);
		int x = t_line.find(t_maso);
		if (x >= 0)
		{
			int doan[10];
			int cnt_phay = 0;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					doan[cnt_phay] = i;
					cnt_phay++;
				}
			}
			line = line.substr(0, doan[2] + 1) + " " + t_trang_thai + " ;";
		}
		data += (line + "\n");

	}
	f.close();

	f.open(file_name, ios::out);
	f << data;
	f.close();
}

string Get_trangthaiphong(string file_name, string t_maso)
{
	t_maso = Chuyenchuhoathanhchuthuong(t_maso);

	fstream f;
	f.open(file_name, ios::in);
	string line;
	string data;
	while (!f.eof())
	{
		getline(f, line);
		string t_line = Chuyenchuhoathanhchuthuong(line);
		int x = t_line.find(t_maso);
		if (x >= 0)
		{
			int doan[10];
			int cnt_phay = 0;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					doan[cnt_phay] = i;
					cnt_phay++;
				}
			}
			if (cnt_phay >= 5){
			data = line.substr(doan[2] + 1, doan[3] - doan[2] - 1);
			break;
			}	
		}
	}
	f.close();
	return Xoa_khoang_trang_thua(data);
}
string Get_trangthaikhachhang(string file_name, string t_maso)
{
	t_maso = Chuyenchuhoathanhchuthuong(t_maso);

	fstream f;
	f.open(file_name, ios::in);
	string line;
	string data;
	while (!f.eof())
	{
		getline(f, line);
		string t_line = Chuyenchuhoathanhchuthuong(line);
		int x = t_line.find(t_maso);
		if (x >= 0)
		{
			int doan[10];
			int cnt_phay = 0;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line.at(i) == ';')
				{
					doan[cnt_phay] = i;
					cnt_phay++;
				}
			}
			data = line.substr( doan[cnt_phay - 2] + 1, doan[cnt_phay - 1] - doan[cnt_phay - 2] - 1);
		}
	}
	f.close();
	return Xoa_khoang_trang_thua(data);
}

string Xoa_khoang_trang_dau_cuoi(string data)
{
	if (data.empty())  return "";
	char c;
	string str = "";
	size_t c_frist = 0, c_last = data.length() - 1;

	c = 0;
	while(c < 50)
	{
		c = data.at(c_frist);
		c_frist++;
	}

	c = 0;
	while (c < 50)
	{
		c = data.at(c_last);
		c_last--;
	}

	for (size_t i = c_frist - 1; i < c_last+2; i++) 
	{
		str += data.at(i);
	}
	return str;
}

string Xoa_khoang_trang_giua(string data)
{
	if (data.empty())  return "";

	char c1,c2;
	string str = "";
	//int cnt_kt = 0;
	str += data.at(0);
	for (size_t i = 1; i < data.length(); i++)
	{
		c1 = data.at(i-1);
		c2 = data.at(i);
		if (c1 == ' ' && c2 == ' ') {}
		else str += c2;
	}
	return str;
}

string Xoa_khoang_trang_thua(string t_data) 
{
	if (t_data.empty()) return ""; 
	string str, data;
	char c;
	data = Xoa_khoang_trang_giua(t_data);
	for (size_t i = 0; i < data.length(); i++)
	{
		c = data.at(i);
		if (i == 0 && c == ' ') {}
		else if (i == data.length() - 1 && c == ' ') {}
		else str += c;
	}
	return str;
}

string Chuyenchuhoathanhchuthuong(string str)
{
	string data = "";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (65 < str.at(i) && str.at(i) < 90)
			data += (str.at(i) + 32);
		else
			data += str.at(i);
	}
	return data;
}
