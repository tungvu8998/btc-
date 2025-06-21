#include <iostream>
#include <fstream>
using namespace std;

//	==== Bai 23: Sao chep tep tin
void SaoChepTepTin() {
    ifstream fin("PTIT.in.txt");
    ofstream fout("PTIT.out.txt");

    if (!fin.is_open()) {
        cout << "Khong mo duoc file PTIT.in\n";
        return;
    }
    if (!fout.is_open()) {
        cout << "Khong mo duoc file PTIT.out\n";
        return;
    }

    string line;
    while (getline(fin, line)) {
        fout << line << "\n";
    }

    fin.close();
    fout.close();
}


int main() {
	SaoChepTepTin();
	return 0;
}
