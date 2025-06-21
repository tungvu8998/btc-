#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ==== Bai 43: Sep xep sinh vien theo ma SV
// Lop luu thong tin mot sinh vien
class SinhVien {
private:
    string maSV;
    string hoTen;
    string lop;
    string email;

public:
    // Ham khoi tao co tham so
    SinhVien(const string& ma, const string& ten, const string& lop, const string& email)
        : maSV(ma), hoTen(ten), lop(lop), email(email) {}

    // Ham lay ma sinh vien
    string getMaSV() const {
        return maSV;
    }

    // Ham xuat thong tin sinh vien
    void hienThi() const {
        cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
    }
};

// Ham doc danh sach sinh vien tu dau vao
void nhapDanhSachSinhVien(vector<SinhVien>& danhSach) {
    string ma, ten, lop, email;
    while (getline(cin, ma)) {
        getline(cin, ten);
        getline(cin, lop);
        getline(cin, email);
        // Them sinh vien moi vao danh sach
        danhSach.emplace_back(ma, ten, lop, email);
    }
}

// Ham so sanh de sap xep theo ma sinh vien
bool soSanhTheoMa(const SinhVien& a, const SinhVien& b) {
    return a.getMaSV() < b.getMaSV();
}

// Ham sap xep danh sach sinh vien theo ma
void sapXepDanhSach(vector<SinhVien>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), soSanhTheoMa);
}

// Ham in danh sach sinh vien
void inDanhSach(const vector<SinhVien>& danhSach) {
    for (const auto& sv : danhSach) {
        sv.hienThi();
    }
}
int main() {
    vector<SinhVien> ds;
    nhapDanhSachSinhVien(ds);
    sapXepDanhSach(ds);
    inDanhSach(ds);
    return 0;
}

