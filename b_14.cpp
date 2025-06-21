#include <iostream>

using namespace std;

//	==== Bai 14: Dem so phan tu lap lai
 int freq[1000001];
void DemSoPhanTuLap() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

       

        // gan toan bo mang freq = 0
        for (int i = 0; i <= 1000000; ++i) {
            freq[i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int count = 0;
        for (int i = 0; i <= 1000000; ++i) {
            if (freq[i] > 1) count += freq[i];
        }

        cout << count << endl;
    }
}


int main() {
	DemSoPhanTuLap();
	return 0;
}
