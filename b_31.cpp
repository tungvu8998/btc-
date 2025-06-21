#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

// ==== Bai 31: Hop va giao cua hay day so 2
void GiaoCuaDaySo2() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n), B(m);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        set<int> hop;
        for (int x : A) hop.insert(x);
        for (int x : B) hop.insert(x);

        unordered_set<int> setA(A.begin(), A.end());
        set<int> giao;
        for (int x : B) {
            if (setA.count(x)) giao.insert(x); // dùng set de tránh trùng
        }

        // In hop
        for (int x : hop) cout << x << " ";
        cout << endl;

        // In giao
        for (int x : giao) cout << x << " ";
        cout << endl;
    }
}

int main() {
	GiaoCuaDaySo2();
	return 0;
}
