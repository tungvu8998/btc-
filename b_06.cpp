#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ==== Bai 6: Bai so nguyen to

bool laSoNguyenTo(int n) {
	if(n < 2) return false;
	int can = sqrt(n);
	for (int i = 2; i <= can; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if(laSoNguyenTo(i)) cout << i << " ";
	}
	cout << endl;
	return 0;
}
