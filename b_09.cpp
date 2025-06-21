#include <iostream>
#include <vector>
using namespace std;

// ==== Bai 9 : So nho nhat chua xuat hien
void SoNhoNhat() {
	int t;
	cin >>t ;
	while (t--) {
		int n;
		cin >> n;
		vector <bool>  arr(n + 2, false);
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			if (x > 0 && x < n + 1) {
				arr[x] = true;
			}
		}
		for (int i = 1; i < n; i++) {
			if (!arr[i]) {
				cout << i << endl;
				break;
			}
		}
	}
}

int main() {
	SoNhoNhat();
	return 0;
}
