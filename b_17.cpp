#include <iostream>
#include <cctype>
using namespace std;

//	==== Bai 17: Loai bo nguyen am
void LoaiBoNguyenAm() {
    string s;
    cin >> s;

    // Duyet tung ky tu
    for (char c : s) {
        c = tolower(c); // chuyen thanh chu thuong

        // Neu khong phai nguyen am thi in ra .<ky tu>
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') {
            cout << '.' << c;
        }
    }
    cout << endl;
}

int main() {
	LoaiBoNguyenAm();
	return 0;
}
