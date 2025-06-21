#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//  ==== Bai 18: Sap xep chu so
void SapXepChuSo() {
     int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> digitSet;

        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            if (x == 0) {
                digitSet.insert(0);
            } else {
                while (x > 0) {
                    digitSet.insert(x % 10);
                    x /= 10;
                }
            }
        }

        // Dua set sang vector de sap xep
        vector<int> digits(digitSet.begin(), digitSet.end());
        sort(digits.begin(), digits.end());

        for (int d : digits) {
            cout << d << " ";
        }
        cout << endl;
    }
}

int main() {
	SapXepChuSo();
	return 0;
}
