#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==== Bai 42: Sap xep sinh vien theo lop
class SinhVien {
public:
    string ma, hoten, lop, email;

    // ham nhap
    void nhap() {
        getline(cin, ma);
        getline(cin, hoten);
        getline(cin, lop);
        getline(cin, email);
    }

    // ham xuat
    void xuat() const {
        cout << ma << " " << hoten << " " << lop << " " << email << endl;
    }

    // ham so sanh phuc vu sap xep
    bool operator < (const SinhVien& other) const {
        if (lop != other.lop) return lop < other.lop;
        return ma < other.ma;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); // bo xuong dong sau so n

    vector<SinhVien> ds(n);
    for (int i = 0; i < n; ++i) {
        ds[i].nhap();
    }

    sort(ds.begin(), ds.end());

    for (const SinhVien& sv : ds) {
        sv.xuat();
    }

    return 0;
}

