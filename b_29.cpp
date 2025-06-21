#include <iostream>
#include <algorithm>
using namespace std;


//	Bai 29: tach chu so
void TachChuSo() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string s;
        getline(cin, s);

        string letters;
        int sum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                sum += c - '0';
            } else if (isupper(c)) {
                letters += c;
            }
        }

        sort(letters.begin(), letters.end());
        cout << letters << sum << endl;
    }
}

int main() {
	TachChuSo();
	return 0;
}
