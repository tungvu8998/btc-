#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;


// ==== Bai 36: Danh sach sinh vien 3
struct SinhVien {
    string ma;
    string hoten;
    string ngaysinh;
    string lop;
    float gpa;
};

// ham chuan hoa ho ten
string chuanHoaHoTen(string s) {
    string res = "";
    int n = (int)s.size();
    vector<string> words;
    string word = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') word += s[i];
        else if (!word.empty()) {
            words.push_back(word);
            word = "";
        }
    }
    if (!word.empty()) words.push_back(word);

    for (int i = 0; i < (int)words.size(); i++) {
        string& w = words[i];
        for (auto& c : w) c = tolower(c);
        w[0] = toupper(w[0]);
        res += w;
        if (i != (int)words.size() - 1) res += " ";
    }
    return res;
}

// ham chuan hoa ngay sinh dd/mm/yyyy
string chuanHoaNgaySinh(string s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    if (d.size() == 1) d = "0" + d;
    if (m.size() == 1) m = "0" + m;

    return d + "/" + m + "/" + y;
}

// ham tao ma sinh vien
string taoMaSV(int idx) {
    ostringstream oss;
    oss << "B20DCCN";
    oss << setw(3) << setfill('0') << idx;
    return oss.str();
}

// ham nhap danh sach sinh vien
void nhapSinhVien(vector<SinhVien>& ds, int n) {
    for (int i = 1; i <= n; i++) {
        SinhVien sv;
        sv.ma = taoMaSV(i);

        string hoten, lop, ngaysinh;
        float gpa;

        cin.ignore();
        getline(cin, hoten);
        getline(cin, lop);
        getline(cin, ngaysinh);
        cin >> gpa;

        sv.hoten = chuanHoaHoTen(hoten);
        sv.lop = lop;
        sv.ngaysinh = chuanHoaNgaySinh(ngaysinh);
        sv.gpa = gpa;

        ds.push_back(sv);
    }
}

// ham sap xep theo gpa giam dan
void sapXepGPA(vector<SinhVien>& ds) {
    sort(ds.begin(), ds.end(), [](const SinhVien& a, const SinhVien& b) {
        return a.gpa > b.gpa;
    });
}

// ham in danh sach sinh vien
void inSinhVien(const vector<SinhVien>& ds) {
    for (const SinhVien& sv : ds) {
        cout << sv.ma << " " << sv.hoten << " " << sv.lop << " " << sv.ngaysinh << " ";
        cout << fixed << setprecision(2) << sv.gpa << "\n";
    }
}
int main() {
    int N; cin >> N;
    vector<SinhVien> ds;
    nhapSinhVien(ds, N);
    sapXepGPA(ds);
    inSinhVien(ds);
    return 0;
}

