#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// === Bai 46 : Danh sach danh nghiep nhan sinh vien thuc tap 1
// Lop doanh nghiep
class DoanhNghiep {
private:
    string maDN;
    string tenDN;
    int soSV;

public:
    // Ham khoi tao doanh nghiep
    DoanhNghiep(const string& ma, const string& ten, int so)
        : maDN(ma), tenDN(ten), soSV(so) {}

    // Ham lay so sinh vien
    int getSoSV() const {
        return soSV;
    }

    // Ham lay ma doanh nghiep
    string getMaDN() const {
        return maDN;
    }

    // Ham hien thi thong tin doanh nghiep
    void hienThi() const {
        cout << maDN << " " << tenDN << " " << soSV << endl;
    }
};

// Ham nhap danh sach doanh nghiep
void nhapDanhSach(vector<DoanhNghiep>& ds, int n) {
    string ma, ten;
    int so;
    for (int i = 0; i < n; ++i) {
        getline(cin, ma);
        getline(cin, ten);
        cin >> so;
        cin.ignore(); // Bo qua dau xuong dong sau so
        ds.emplace_back(ma, ten, so);
    }
}

// Ham so sanh de sap xep doanh nghiep
bool soSanh(const DoanhNghiep& a, const DoanhNghiep& b) {
    if (a.getSoSV() != b.getSoSV())
        return a.getSoSV() > b.getSoSV(); // Giam dan theo so sinh vien
    return a.getMaDN() < b.getMaDN();     // Tang dan theo ma doanh nghiep
}

// Ham sap xep danh sach
void sapXepDanhSach(vector<DoanhNghiep>& ds) {
    sort(ds.begin(), ds.end(), soSanh);
}

// Ham in danh sach
void inDanhSach(const vector<DoanhNghiep>& ds) {
    for (const auto& dn : ds) {
        dn.hienThi();
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<DoanhNghiep> danhSach;
    nhapDanhSach(danhSach, n);

    sapXepDanhSach(danhSach);

    inDanhSach(danhSach);

    return 0;
}

