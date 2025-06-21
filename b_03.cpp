#include <iostream>

using namespace std;

// ==== Bai 3: Tinh tong giai thua
void BaiTinhTongGiaiThua() {
	int n;
	cin >> n;
	long long sum = 0;
	long long gt = 1;
	for (int i = 1; i <= n; ++i) {
		gt *= i;
		sum += gt;
	}
	cout << sum << endl;
}
int main() {
	BaiTinhTongGiaiThua();
	return 0;
}
