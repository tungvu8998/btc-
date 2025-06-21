#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;


// ==== Bai 45: Tim kiem giang vien
// Lop giang vien
class GiangVien {
private:
    string maGV;
    string hoTen;
    string boMon;

public:
    // Ham khoi tao co tham so va ma tu dong
    GiangVien(int stt, const string& ten, const string& boMonGoc) {
        stringstream ss;
        ss << "GV" << setfill('0') << setw(2) << stt;
        maGV = ss.str();
        hoTen = ten;
        boMon = vietTatBoMon(boMonGoc);
    }

    // Ham viet tat bo mon tu cac chu cai dau
    string vietTatBoMon(const string& s) {
        stringstream ss(s);
        string tu, ketQua = "";
        while (ss >> tu) {
            ketQua += toupper(tu[0]);
        }
        return ketQua;
    }

    // Ham lay ho ten
    string getHoTen() const {
        return hoTen;
    }

    // Ham hien thi thong tin giang vien
    void hienThi() const {
        cout << maGV << " " << hoTen << " " << boMon << endl;
    }
};

// Ham chuyen xau ve dang chu thuong
string chuyenVeThuong(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Ham nhap danh sach giang vien
void nhapDanhSachGiangVien(vector<GiangVien>& ds, int soLuong) {
    string ten, boMon;
    for (int i = 1; i <= soLuong; ++i) {
        getline(cin, ten);
        getline(cin, boMon);
        ds.emplace_back(i, ten, boMon);
    }
}

// Ham xu ly cac truy van tim kiem theo tu khoa
void timKiemGiangVien(const vector<GiangVien>& ds, const vector<string>& tuKhoa) {
    for (const auto& tu : tuKhoa) {
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << tu << ":" << endl;
        string key = chuyenVeThuong(tu);
        for (const auto& gv : ds) {
            string tenThuong = chuyenVeThuong(gv.getHoTen());
            if (tenThuong.find(key) != string::npos) {
                gv.hienThi();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<GiangVien> danhSach;
    nhapDanhSachGiangVien(danhSach, n);

    int q;
    cin >> q;
    cin.ignore();

    vector<string> tuKhoa(q);
    for (int i = 0; i < q; ++i) {
        getline(cin, tuKhoa[i]);
    }

    timKiemGiangVien(danhSach, tuKhoa);

    return 0;
}


