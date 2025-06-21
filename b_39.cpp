#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct SinhVien {
    string ma;
    string hoten;
    string lop;
    float diem1, diem2, diem3;
};

// ham nhap danh sach sinh vien
void nhapSinhVien(vector<SinhVien>& ds, int n) {
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        getline(cin, sv.ma);
        getline(cin, sv.hoten);
        getline(cin, sv.lop);
        cin >> sv.diem1 >> sv.diem2 >> sv.diem3;
        cin.ignore();
        ds.push_back(sv);
    }
}

// ham sap xep theo ho ten tang dan (tu dien)
void sapXepTheoHoTen(vector<SinhVien>& ds) {
    sort(ds.begin(), ds.end(), [](const SinhVien& a, const SinhVien& b) {
        return a.hoten < b.hoten;
    });
}

// ham in danh sach sinh vien
void inDanhSach(const vector<SinhVien>& ds) {
    int idx = 1;
    for (const SinhVien& sv : ds) {
        cout << idx << " " << sv.ma << " " << sv.hoten << " " << sv.lop << " ";
        cout << fixed << setprecision(1);
        cout << sv.diem1 << " " << sv.diem2 << " " << sv.diem3 << "\n";
        idx++;
    }
}
int main() {
    int n; cin >> n;
    cin.ignore();
    vector<SinhVien> ds;
    nhapSinhVien(ds, n);
    sapXepTheoHoTen(ds);
    inDanhSach(ds);
    return 0;
}

