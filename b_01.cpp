#include <iostream>

using namespace std;

// ==== Bài 1: Tinh tong 1 den N ====
void BaiTinhTong() {
   int t;
   cin >> t;
   while (t--) {
		long long n;
		cin >> n;
		long long sum = n * (n + 1)/2;
		cout << sum << endl;
   }
}

int main() {
	BaiTinhTong();
	return 0;
}
