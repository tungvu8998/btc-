#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// ==== Bai 34: Sap xep danh sach nhan vien
class NhanVien1 {
public:
    string maNV, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKy;

    void chuanHoaNgay(string &ngay) {
        stringstream ss(ngay);
        string d, m, y;
        getline(ss, d, '/');
        getline(ss, m, '/');
        getline(ss, y);
        if (d.size() == 1) d = "0" + d;
        if (m.size() == 1) m = "0" + m;
        ngay = d + "/" + m + "/" + y;
    }

    string getNgaySoSanh() const {
        return ngaySinh.substr(6,4) + ngaySinh.substr(3,2) + ngaySinh.substr(0,2);
    }
};

void XuLyDanhSachNhanVien1() {
    int n; 
    cin >> n;
    cin.ignore();

    vector<NhanVien1> ds(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds[i].hoTen);
        getline(cin, ds[i].gioiTinh);
        getline(cin, ds[i].ngaySinh);
        getline(cin, ds[i].diaChi);
        getline(cin, ds[i].maSoThue);
        getline(cin, ds[i].ngayKy);

        ds[i].chuanHoaNgay(ds[i].ngaySinh);
        ds[i].chuanHoaNgay(ds[i].ngayKy);

        stringstream ss;
        ss << setw(5) << setfill('0') << (i+1);
        ds[i].maNV = ss.str();
    }

    sort(ds.begin(), ds.end(), [](const NhanVien1 &a, const NhanVien1 &b){
        return a.getNgaySoSanh() < b.getNgaySoSanh();
    });

    for (const auto &nv : ds) {
        cout << nv.maNV << " " << nv.hoTen << " " << nv.gioiTinh << " " << nv.ngaySinh << " "
             << nv.diaChi << " " << nv.maSoThue << " " << nv.ngayKy << "\n";
    }
}

int main() {
	XuLyDanhSachNhanVien1();
	return 0;
}
