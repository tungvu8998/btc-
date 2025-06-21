#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long min = LLONG_MAX;
		for (int i = 0; i < n - 1; i++) {
			long long diff = a[i + 1] - a[i];
			if (diff < min) min = diff;
		}
		cout << min << endl;
	}
	
	return 0;
}
