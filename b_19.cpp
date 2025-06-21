#include <iostream>
#include <iomanip>

using namespace std;


// ===	Bai 19: Nhap thi sinh
struct ThiSinh {
    string hoTen;
    string ngaySinh;
    float diem1, diem2, diem3;

    float tongDiem() const {
        return diem1 + diem2 + diem3;
    }
};

// Ham nhap thong tin thi sinh
void NhapThiSinh(ThiSinh &ts) {
    getline(cin, ts.hoTen);
    getline(cin, ts.ngaySinh);
    cin >> ts.diem1 >> ts.diem2 >> ts.diem3;
    cin.ignore(); 
}

// Ham xuat thong tin thi sinh
void XuatThiSinh(const ThiSinh &ts) {
    cout << ts.hoTen << " " << ts.ngaySinh << " ";
    cout << fixed << setprecision(1) << ts.tongDiem() << "\n";
}

int main() {
	ThiSinh ts;
	NhapThiSinh(ts);
	XuatThiSinh(ts);
	return 0;
}
