#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// ==== Bai 48: So khac nhau trong file
// Ham doc file va dem so lan xuat hien cac so
void demSoLanXuatHien(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file " << filename << endl;
        return;
    }

    // Mang dem so lan xuat hien, vi so nho hon 1000
    vector<int> dem(1000, 0);
    int x;

    // Doc tung so trong file va dem
    while (fin >> x) {
        if (x > 0 && x < 1000) {
            dem[x]++;
        }
    }
    fin.close();

    // In ra cac so va so lan xuat hien theo thu tu tang dan
    for (int i = 1; i < 1000; ++i) {
        if (dem[i] > 0) {
            cout << i << " " << dem[i] << endl;
        }
    }
}
int main() {
    demSoLanXuatHien("DATA.in.txt");
    return 0;
}

