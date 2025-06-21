#include <iostream>
#include <cctype>
using namespace std;


// ==== Bai 16: Dau cuoi giong nhau
void DemXauConDauCuoiGiong() {
    int T;
    cin >> T;
    cin.ignore(); // loai bo ky tu xuong dong sau so T

    while (T--) {
        string s;
        getline(cin, s);

        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        long long count = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                count += freq[i]; // xau con do dai 1
                count += 1LL * freq[i] * (freq[i] - 1) / 2; // xau con bat dau va ket thuc bang ky tu do
            }
        }

        cout << count << endl;
    }
}

int main() {
	DemXauConDauCuoiGiong();
	return 0;
}
