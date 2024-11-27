#include "nhanvien.h"
using namespace std;

NhanVien::NhanVien(){}
NhanVien::NhanVien(string ma_nv, string ten_nv, Date ngay_sinh, string sdt, string gioiTinh, string taiKhoan, string matKhau) 
    : ma_nv(ma_nv), ten_nv(ten_nv), ngay_sinh(ngay_sinh), SDT(sdt), GioiTinh(gioiTinh), taiKhoan(taiKhoan), matKhau(matKhau) {}

void NhanVien::Set_ma_nv(string ma_nv) {	this->ma_nv = ma_nv; }
string NhanVien::Get_ma_nv() {	return ma_nv; }

void NhanVien::Set_ten_nv(string ten_nv) {	this->ten_nv = ten_nv; }
string NhanVien::Get_ten_nv() {	return ten_nv; }

void NhanVien::Set_ngay_sinh(Date ngay_sinh) { this->ngay_sinh = ngay_sinh; }
Date NhanVien::Get_ngay_sinh() { return ngay_sinh; }

void NhanVien::Set_SDT(string SDT) { this->SDT = SDT; }
string NhanVien::Get_SDT() { return SDT; }

void NhanVien::Set_GioiTinh(string GioiTinh) {
    this->GioiTinh = GioiTinh;
}

string NhanVien::Get_GioiTinh() {
    return GioiTinh;
}

void NhanVien::Set_taiKhoan(string taiKhoan) {
    this->taiKhoan = taiKhoan;
}

string NhanVien::Get_taiKhoan() {
    return taiKhoan;
}

void NhanVien::Set_matKhau(string matKhau) {
    this->matKhau = matKhau;
}

string NhanVien::Get_matKhau() {
    return matKhau;
}

bool NhanVien:: kiemTraDangNhap(const string& taiKhoan, const string& matKhau) const {
    return (this->taiKhoan  == taiKhoan && this->matKhau == matKhau);
}

/************ khung dang nhap   ***************/
Khunghienthi kht_nv[50][50];
Khunghienthi lcht1_nv, lcht2_nv;
int sh_nv = 0, sc_nv = 0;

Khunghienthi kht2_nv[50][50];
int sh2_nv = 0, sc2_nv = 0;

Khunghienthi kht3_nv[50][50];
int stt_sh_nv = 0, stt_sc_nv = 0;

string qlnv_file_name = "Ql_tt_nv.txt";
/************************************/

#define MAX_NV 100  // Giả sử có tối đa 100 nhân viên

string TaoMaNV(const string& ten, const string& sdt) {
    string maNV = "NV_";
    
    // Lấy chữ cái đầu của mỗi từ trong tên và viết hoa
    bool newWord = true;  // Cờ đánh dấu bắt đầu của một từ
    for (size_t i = 0; i < ten.length(); ++i) {
        if (newWord && ten[i] != ' ') {
            // Chuyển chữ cái đầu thành chữ hoa mà không dùng cctype
            if (ten[i] >= 'a' && ten[i] <= 'z') {
                maNV += ten[i] - 'a' + 'A';  // Chuyển từ chữ thường sang chữ hoa
            } else {
                maNV += ten[i];  // Nếu đã là chữ hoa thì thêm trực tiếp
            }
            newWord = false;  // Đánh dấu không phải là chữ cái đầu của từ nữa
        }
        if (ten[i] == ' ') {
            newWord = true;  // Đánh dấu bắt đầu của từ mới
        }
    }
    
    // Thêm 3 chữ số cuối của số điện thoại nếu có
    if (sdt.length() >= 3) {
        maNV += sdt.substr(sdt.length() - 3);  // Lấy 3 chữ số cuối của số điện thoại
    }

    return maNV;
}

bool XuLyQuenMK(const string& TK, const string& SDT){
	NhanVien dt_nv;
	dt_nv = Tim_kiem_nv(TK);
	if (dt_nv.Get_taiKhoan() != "" && dt_nv.Get_SDT() == SDT) {
        return true;  // Nếu hợp lệ
    }
    return false;  // Nếu không hợp lệ
}
bool xacNhanMK(const string& MK1, const string& MK2){
	return MK1 == MK2;
}
// Hàm đọc dữ liệu nhân viên từ file
void docfileNV(NhanVien*& ds_nv) {
    ifstream file("Ql_tt_nv.txt");
    if (!file) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    string line;
    int index = 0;
    while (getline(file, line)) {
        if (index >= MAX_NV) break; // Kiểm tra nếu vượt quá số lượng nhân viên tối đa

        stringstream ss(line);
        string temp[7]; // Mảng tạm để chứa các giá trị đọc được từ file

        // Sử dụng vòng lặp for để lấy 7 giá trị tách bởi dấu ';'
        for (int i = 0; i < 7; i++) {
            getline(ss, temp[i], ';');
        }
		ds_nv[index] = NhanVien(temp[0], temp[1], chuyen_str_to_date(temp[2]), temp[3], temp[4], temp[5], temp[6]);
        index++;  // Tăng chỉ số sau khi thêm nhân viên
    }
    file.close();
}

bool xuLyDangNhap(NhanVien*& ds_nv , string username, string password) {
	
    for (int i = 0; i < 10; i++) {
        if (ds_nv[i].taiKhoan == username) {
            if (ds_nv[i].matKhau == password) {
            	// Đúng mật khẩu
                return true;
            } else {
                // Sai mật khẩu
                gotoxy(20,50);
                cout << "Mat khau khong dung!" << endl;
                return false;
            }
        }																																												
	}
	gotoxy(20,50);
	cout << "Khong tim thay tai khoan!"<<endl;
    return false;
	
}

NhanVien Tim_kiem_nv(string tk_nv){
	NhanVien t_nv;
	fstream f;
	f.open(qlnv_file_name, ios::in);
	string line, str_dt[8], tt_data = " ";
	//int count_line = 1, 
	int count_vtdt = 0;
	string str = Xoa_khoang_trang_thua(tk_nv);
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
			tt_str = Chuyenchuhoathanhchuthuong(str_dt[5]);

			if (tt_str  == str)
			{
				t_nv.Set_ma_nv(str_dt[0]);
				t_nv.Set_ten_nv(str_dt[1]);
				t_nv.Set_ngay_sinh( chuyen_str_to_date(str_dt[2]));
				t_nv.Set_SDT(str_dt[3]);
				t_nv.Set_GioiTinh(str_dt[4]);
				t_nv.Set_taiKhoan(str_dt[5]);
				t_nv.Set_matKhau(str_dt[6]); 
				break;
			}
		}
	}
	f.close();
	return t_nv;
}
