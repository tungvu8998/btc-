#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ==== Bai 32: Sap xep xen ke 2
void SapXepXenKe() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];

        sort(A.begin(), A.end());

        vector<int> result;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l != r) {
                result.push_back(A[r--]);
                result.push_back(A[l++]);
            } else {
                result.push_back(A[l++]); // ph?n t? gi?a n?u n l?
            }
        }

        for (int x : result) cout << x << " ";
        cout << endl;
    }
}

int main() {
	SapXepXenKe();
	return 0;
}
