#include <iostream>
#include <vector>
using namespace std;


// ==== Bai 10: Quay vong day so 1
void QuayVongDaySo() {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n); 
		for (int i = 0; i < n ;i++) {
			cin >> a[i] ;
		}
		for (int i = d; i < n; i++) {
			cout << a[i] << " ";
		}
		for (int i = 0; i < d; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	QuayVongDaySo();
	return 0;
}
