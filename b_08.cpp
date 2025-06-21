#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ==== Bai 8: So co 3 uoc
bool SoNguyenTo(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void BaiSoCoBaUoc() {
   	int t;
   	cin >> t;
   	while (t--) { 
		int n; 
		cin >> n;
		for (int i = 2; i * i <= n; i++) {
			if (SoNguyenTo(i)) cout << i*i << " ";
		}   
	}
	cout << endl;
}

int main() {
	BaiSoCoBaUoc();
	return 0;
}
