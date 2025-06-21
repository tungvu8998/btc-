#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// ==== Bai 3: Danh sach sinh vien
class SinhVien {
private:
    string id, name, lop, dob;
    float gpa;

    string chuanHoaNgay(string d) {
        stringstream ss(d);
        string day, month, year;
        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year);
        if (day.length() == 1) day = "0" + day;
        if (month.length() == 1) month = "0" + month;
        return day + "/" + month + "/" + year;
    }

public:
    static int dem;

    void nhap() {
        getline(cin, name);
        getline(cin, lop);
        string ngay;
        getline(cin, ngay);
        dob = chuanHoaNgay(ngay);
        cin >> gpa;
        cin.ignore();
        stringstream ss;
        ss << "B20DCCN" << setw(3) << setfill('0') << dem++;
        id = ss.str();
    }

    void in() {
        cout << id << " " << name << " " << lop << " " << dob << " " << fixed << setprecision(2) << gpa << endl;
    }
};

int SinhVien::dem = 1;

void XuLyDanhSachSinhVien() {
    int N;
    cin >> N;
    cin.ignore();
    vector<SinhVien> ds(N);
    for (int i = 0; i < N; ++i) {
        ds[i].nhap();
    }
    for (int i = 0; i < N; ++i) {
        ds[i].in();
    }
}
int main() {
	XuLyDanhSachSinhVien();
	return 0;
}
