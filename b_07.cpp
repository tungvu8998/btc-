#include <iostream>

using namespace std;

// ===== Bai 7: Bai uoc so nguyen to
void BaiUocSoNguyenTo() {
	int t; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) cout << i << " ";
			while (n % i == 0) {
				n /= i;
			}
		}
		if (n > 1) cout << n;
		cout << endl;
	}
}


int main() {
	BaiUocSoNguyenTo();
	return 0;
}
