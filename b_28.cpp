#include <iostream>

using namespace std;

//	Bai 28 : Tong so trong xau
int tongSoTrongXau(const string& s) {
    long long sum = 0;
    int current = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current = current * 10 + (c - '0');
        } else {
            sum += current;
            current = 0;
        }
    }
    sum += current;
    return sum;
}

void TongSoTrongXau() {
    int T;
    cin >> T;
    cin.ignore(); // bo dòng newline sau T
    while (T--) {
        string s;
        getline(cin, s);
        cout << tongSoTrongXau(s) << endl;
    }
}


int main() {
	TongSoTrongXau();
	return 0;
}
