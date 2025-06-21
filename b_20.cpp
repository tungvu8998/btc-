#include <iostream>

using namespace std;


// ==== Bai 20: Nhap nhan vien
struct NhanVien {
    string maNV = "00001";  
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string diaChi;
    string maSoThue;
    string ngayKyHD;
};

void nhapNhanVien(NhanVien &nv) {
    getline(cin, nv.hoTen);
    getline(cin, nv.gioiTinh);
    getline(cin, nv.ngaySinh);
    getline(cin, nv.diaChi);
    getline(cin, nv.maSoThue);
    getline(cin, nv.ngayKyHD);
}

void inNhanVien(const NhanVien &nv) {
    cout << nv.maNV << " "
         << nv.hoTen << " "
         << nv.gioiTinh << " "
         << nv.ngaySinh << " "
         << nv.diaChi << " "
         << nv.maSoThue << " "
         << nv.ngayKyHD << "\n";
}

int main() {
	
  NhanVien nv;
  nhapNhanVien(nv);
  inNhanVien(nv);

	return 0;
}
