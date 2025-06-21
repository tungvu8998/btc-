#include <iostream>
#include <vector>
#include <set>
using namespace std;

// ==== Bai 30: Hop va giao cua hai day so 1
void HopGiaoCuaHaiDay1() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n), B(m);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        set<int> unionSet;
        vector<int> intersection;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (A[i] < B[j]) {
                unionSet.insert(A[i++]);
            } else if (A[i] > B[j]) {
                unionSet.insert(B[j++]);
            } else {
                unionSet.insert(A[i]);
                intersection.push_back(A[i]);
                i++;
                j++;
            }
        }

        while (i < n) unionSet.insert(A[i++]);
        while (j < m) unionSet.insert(B[j++]);

        // In h?p
        for (int x : unionSet) cout << x << " ";
        cout << endl;

        // In giao
        for (int x : intersection) cout << x << " ";
        cout << endl;
    }
}


int main() {
	HopGiaoCuaHaiDay1();
	return 0;
}
