#include <iostream>
#include <vector>
#include <string>
using namespace std;


// ==== Bai 40: Tre nhat - Gia nhat
struct Nguoi {
    string ten;
    string ngaysinh; // dd/mm/yyyy
};

// ham chuyen ngay sinh sang dang so de so sanh yyyymmdd
int ngayThanhSo(const string& s) {
    int d = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int y = stoi(s.substr(6, 4));
    return y * 10000 + m * 100 + d;
}

// ham nhap danh sach nguoi
void nhapDanhSach(vector<Nguoi>& ds, int n) {
    for (int i = 0; i < n; i++) {
        Nguoi ng;
        cin >> ng.ten >> ng.ngaysinh;
        ds.push_back(ng);
    }
}

// ham tim nguoi tre nhat va gia nhat
pair<string, string> timTreVaGia(const vector<Nguoi>& ds) {
    int idxTreNhat = 0, idxGiaNhat = 0;
    for (int i = 1; i < (int)ds.size(); i++) {
        int curr = ngayThanhSo(ds[i].ngaysinh);
        int treNhat = ngayThanhSo(ds[idxTreNhat].ngaysinh);
        int giaNhat = ngayThanhSo(ds[idxGiaNhat].ngaysinh);

        if (curr > treNhat) idxTreNhat = i;  // tre nhat: ngay sinh lon hon
        if (curr < giaNhat) idxGiaNhat = i;  // gia nhat: ngay sinh nho hon
    }
    return { ds[idxTreNhat].ten, ds[idxGiaNhat].ten };
}
int main() {
    int n; cin >> n;
    vector<Nguoi> ds;
    nhapDanhSach(ds, n);
    pair<string, string> res = timTreVaGia(ds);
    cout << res.first << "\n" << res.second << "\n";
    return 0;
}


