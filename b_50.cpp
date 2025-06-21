#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;


// === Bai 50: Hop va giao cua 2 file van ban
// Chuyen chuoi ve chu thuong
string toLowerStr(const string& s) {
    string res = s;
    for (char& c : res) c = tolower(c);
    return res;
}

// Doc cac tu trong file va tra ve set tu khac nhau
set<string> docTuTuFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file " << filename << endl;
        return {};
    }
    set<string> tuSet;
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            word = toLowerStr(word);
            tuSet.insert(word);
        }
    }
    fin.close();
    return tuSet;
}

// In ra set cac tu cach nhau 1 khoang trang
void inSet(const set<string>& s) {
    bool first = true;
    for (const string& w : s) {
        if (!first) cout << " ";
        cout << w;
        first = false;
    }
    cout << "\n";
}

int main() {
    set<string> set1 = docTuTuFile("DATA1.in.txt");
    set<string> set2 = docTuTuFile("DATA2.in.txt");

    // Tinh hop
    set<string> hop = set1;
    hop.insert(set2.begin(), set2.end());

    // Tinh giao
    set<string> giao;
    for (const string& w : set1) {
        if (set2.count(w)) {
            giao.insert(w);
        }
    }

    // In ket qua
    inSet(hop);
    inSet(giao);

    return 0;
}

