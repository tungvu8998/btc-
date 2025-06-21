#include <iostream>

using namespace std;


// ==== Bai 4: Can bang chan le
void BaiCanBangChanLe() {
	int n;
	cin >> n;
	if (n <= 1 || n >= 7 || n % 2 != 0) {
		cout << "So nhap khong hop le" << endl;
		return;
	}
	int count = 0;
	int start = 1;
	for (int i = 1; i < n; i++) 
		start *= 10;
	int end = start * 10;
	
	for (int i = start; i < end; i++) {
		int temp = i;
		int even = 0, odd = 0;
		while (temp > 0) {
			int digit = temp % 10;
			if (digit % 2 == 0) {
				even++;
			} else {
				odd++;
			}
			temp /= 10;
		}
		if (even == odd) {
			cout << i << " ";
			count++;
			if (count % 10 == 0) cout << endl;
		}
	}
	if (count % 10 != 0) cout << endl;
}
int main() {
	BaiCanBangChanLe();
	return 0;
}
