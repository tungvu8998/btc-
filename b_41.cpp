#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int dem = 0;

// ==== Bai 41: Danh sach doi tuong sinh vien
class NhanVien {
private:
    string ma, ten, gioitinh, ngaysinh, diachi, maso, ngayky;

public:
    // ham tao tu dong sinh ma nhan vien
    NhanVien() {
        ++dem;
        ma = string(5 - to_string(dem).length(), '0') + to_string(dem);
    }

    // chong toan tu nhap
    friend istream& operator >> (istream& in, NhanVien& nv) {
        getline(in, nv.ten);
        getline(in, nv.gioitinh);
        getline(in, nv.ngaysinh);
        getline(in, nv.diachi);
        getline(in, nv.maso);
        getline(in, nv.ngayky);
        return in;
    }

    // chong toan tu xuat
    friend ostream& operator << (ostream& out, const NhanVien& nv) {
        out << nv.ma << " " << nv.ten << " " << nv.gioitinh << " "
            << nv.ngaysinh << " " << nv.diachi << " "
            << nv.maso << " " << nv.ngayky;
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); // loai bo ky tu xuong dong sau so n

    vector<NhanVien> ds(n);
    for (int i = 0; i < n; ++i) {
        cin >> ds[i];
    }

    for (const NhanVien& nv : ds) {
        cout << nv << endl;
    }

    return 0;
}

