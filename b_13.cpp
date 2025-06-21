#include <iostream>
#include <algorithm>
using namespace std;

// ==== Bai 13: Liet ke so khac nhau
void LietKeSoKhacNhau() {
	int n;
	cin >> n;
	int a[100];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[0] << " ";
	
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i+1]) {
			cout << a[i] << " ";
		}
    }
    cout << endl;
}

int main() {
	LietKeSoKhacNhau();
	return 0;
}
