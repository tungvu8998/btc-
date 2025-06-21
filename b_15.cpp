#include <iostream>

using namespace std;

// === Bai 15: Tim so nho nhat lon nhat
string findMin(int m, int s) {
    if (s == 0) return (m == 1) ? "0" : "-1";
    if (s > 9 * m) return "-1";

    string res(m, '0');
    int sum = s;

    for (int i = 0; i < m; ++i) {
        for (int d = (i == 0 ? 1 : 0); d <= 9; ++d) {
            int max_possible = 9 * (m - i - 1);
            if (sum - d <= max_possible && sum - d >= 0) {
                res[i] = d + '0';
                sum -= d;
                break;
            }
        }
    }
    return res;
}

string findMax(int m, int s) {
    if (s == 0) return (m == 1) ? "0" : "-1";
    if (s > 9 * m) return "-1";

    string res(m, '0');
    int sum = s;

    for (int i = 0; i < m; ++i) {
        // th? t? 9 xu?ng 0
        for (int d = 9; d >= 0; --d) {
            if (sum - d >= 0) {
                res[i] = d + '0';
                sum -= d;
                break;
            }
        }
    }
    return res;
}
void TimMinMax () {
	 int m, s;
    cin >> m >> s;

    string minNum = findMin(m, s);
    string maxNum = findMax(m, s);

    if (minNum == "-1" || maxNum == "-1")
        cout << "-1 -1\n";
    else
        cout << minNum << " " << maxNum << "\n";

}
int main() {
	TimMinMax();
	return 0;
}
