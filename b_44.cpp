#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// ==== Bai 44: Liet ke sinh vien theo nganh
// Lop luu thong tin mot sinh vien
class SinhVien {
private:
    string maSV;
    string hoTen;
    string lop;
    string email;

public:
    // Ham khoi tao sinh vien
    SinhVien(const string& ma, const string& ten, const string& lop, const string& email)
        : maSV(ma), hoTen(ten), lop(lop), email(email) {}

    // Ham tra ve ma sinh vien
    string getMaSV() const {
        return maSV;
    }

    // Ham tra ve lop
    string getLop() const {
        return lop;
    }

    // Ham tra ve 4 ky tu nganh trong ma sinh vien
    string getNganhCode() const {
        return maSV.substr(3, 4);
    }

    // Ham hien thi thong tin sinh vien
    void hienThi() const {
        cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
    }
};

// Ham nhap danh sach sinh vien
void nhapDanhSachSinhVien(vector<SinhVien>& danhSach, int soLuong) {
    string ma, ten, lop, email;
    for (int i = 0; i < soLuong; ++i) {
        getline(cin, ma);
        getline(cin, ten);
        getline(cin, lop);
        getline(cin, email);
        danhSach.emplace_back(ma, ten, lop, email);
    }
}

// Ham xu ly va liet ke sinh vien theo tung truy van nganh
void lietKeTheoNganh(const vector<SinhVien>& danhSach, const vector<string>& truyVan) {
    // Map ma nganh voi ten nganh de so sanh
    unordered_map<string, string> maNganh = {
        {"DCKT", "Ke toan"},
        {"DCCN", "Cong nghe thong tin"},
        {"DCAT", "An toan thong tin"},
        {"DCVT", "Vien thong"},
        {"DCDT", "Dien tu"}
    };

    for (const string& nganh : truyVan) {
        cout << "DANH SACH SINH VIEN NGANH " << nganh << ":" << endl;
        for (const auto& sv : danhSach) {
            string code = sv.getNganhCode();

            // Bo qua sinh vien lop bat dau bang 'E' neu nganh la CNTT hoac ATTT
            if ((nganh == "Cong nghe thong tin" && code == "DCCN" && sv.getLop()[0] != 'E') ||
                (nganh == "An toan thong tin" && code == "DCAT" && sv.getLop()[0] != 'E') ||
                (nganh == "Ke toan" && code == "DCKT") ||
                (nganh == "Vien thong" && code == "DCVT") ||
                (nganh == "Dien tu" && code == "DCDT")) {
                sv.hienThi();
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    cin.ignore(); // Bo dong xuong sau khi nhap so

    vector<SinhVien> danhSach;
    nhapDanhSachSinhVien(danhSach, n);

    int q;
    cin >> q;
    cin.ignore();

    vector<string> truyVan(q);
    for (int i = 0; i < q; ++i) {
        getline(cin, truyVan[i]);
    }

    lietKeTheoNganh(danhSach, truyVan);

    return 0;
}

