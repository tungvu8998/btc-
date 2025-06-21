#include <iostream>

using namespace std;


// ==== Bai 5: bai so may man
void BaiSoMayMan() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		if (n % 100 == 86) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
}
}
int main() {
	BaiSoMayMan();
	return 0;
}
