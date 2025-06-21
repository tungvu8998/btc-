#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

// ==== Bai 37: Sap xep danh sach nhan vien
struct NhanVien {
    string ma;
    string hoten;
    string gioitinh;
    string ngaysinh;
    string diachi;
    string masothue;
    string ngaykyhopdong;
};

// ham tao ma nhan vien tu index bat dau tu 1
string taoMaNV(int idx) {
    ostringstream oss;
    oss << setw(5) << setfill('0') << idx;
    return oss.str();
}

// ham chuan hoa ngay sinh hoac ngay ky hop dong theo dd/mm/yyyy
string chuanHoaNgay(string s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);
    if (d.size() == 1) d = "0" + d;
    if (m.size() == 1) m = "0" + m;
    return d + "/" + m + "/" + y;
}

// ham chuyen ngay sinh sang dang so nguyen de so sanh
// vd: dd/mm/yyyy -> yyyymmdd (int)
int ngayThanhSo(const string& s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);
    return stoi(y) * 10000 + stoi(m) * 100 + stoi(d);
}

// ham nhap danh sach nhan vien
void nhapNhanVien(vector<NhanVien>& ds, int n) {
    for (int i = 1; i <= n; i++) {
        NhanVien nv;
        nv.ma = taoMaNV(i);

        getline(cin, nv.hoten);
        getline(cin, nv.gioitinh);
        string ngsinh;
        getline(cin, ngsinh);
        nv.ngaysinh = chuanHoaNgay(ngsinh);
        getline(cin, nv.diachi);
        getline(cin, nv.masothue);
        string ngayky;
        getline(cin, ngayky);
        nv.ngaykyhopdong = chuanHoaNgay(ngayky);

        ds.push_back(nv);
    }
}

// ham sap xep theo ngay sinh tu gia nhat den tre nhat
void sapXepTheoNgaySinh(vector<NhanVien>& ds) {
    sort(ds.begin(), ds.end(), [](const NhanVien& a, const NhanVien& b) {
        return ngayThanhSo(a.ngaysinh) < ngayThanhSo(b.ngaysinh);
    });
}

// ham in danh sach nhan vien
void inNhanVien(const vector<NhanVien>& ds) {
    for (const NhanVien& nv : ds) {
        cout << nv.ma << " " << nv.hoten << " " << nv.gioitinh << " " << nv.ngaysinh << " "
             << nv.diachi << " " << nv.masothue << " " << nv.ngaykyhopdong << "\n";
    }
}
int main() {
    int N; cin >> N;
    cin.ignore();
    vector<NhanVien> ds;
    nhapNhanVien(ds, N);
    sapXepTheoNgaySinh(ds);
    inNhanVien(ds);
    return 0;
}

