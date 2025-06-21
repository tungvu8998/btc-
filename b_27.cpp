#include <iostream>

using namespace std;

//	=== Bai 27 : Doi so chu so
string findMaxLessThanN(string s) {
    int n = s.length();
    int idx = -1;

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] > s[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return "-1";  

    int maxIdx = -1;
    char maxChar = '0';

    for (int i = idx + 1; i < n; ++i) {
        if (s[i] < s[idx]) {
            if (s[i] >= maxChar) {
                maxChar = s[i];
                maxIdx = i;
            }
        }
    }

    if (maxIdx == -1) return "-1";

    swap(s[idx], s[maxIdx]);
    if (s[0] == '0') return "-1";

    return s;
}

void DoiSoChuSo() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << findMaxLessThanN(s) << endl;
    }
}

int main() {
	DoiSoChuSo();
	return 0;
}
