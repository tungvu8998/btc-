#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

// Ham chuyen chuoi ve chu thuong
string chuyenVeThuong(string s) {
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

// Ham doc file, liet ke tu khac nhau
void lietKeTuKhacNhau(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file " << filename << endl;
        return;
    }

    set<string> tuSet;
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            word = chuyenVeThuong(word);
            tuSet.insert(word);
        }
    }
    fin.close();

    // In ra cac tu khac nhau theo thu tu tu dien
    for (const string& w : tuSet) {
        cout << w << endl;
    }
}

int main() {
    lietKeTuKhacNhau("VANBAN.in.txt");
    return 0;
}

