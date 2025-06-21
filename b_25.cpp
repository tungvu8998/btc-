#include <iostream>
#include <vector>
using namespace std;

//	==== Bai 25: Bien doi day so
void BienDoiDaySo() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int i = 0, j = n - 1;
        int count = 0;

        while (i < j) {
            if (a[i] == a[j]) {
                i++;
                j--;
            } else if (a[i] < a[j]) {
                a[i + 1] += a[i]; // gop a[i] vao a[i+1]
                i++;
                count++;
            } else {
                a[j - 1] += a[j]; // gop a[j] vao a[j-1]
                j--;
                count++;
            }
        }

        cout << count << endl;
    }
}

int main() {
	BienDoiDaySo();
	return 0;
}
