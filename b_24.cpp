#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//	====  Bai 24: Quay ma tran
void QuayMaTran() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        
        // nhap ma tran
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        // tao vector chua ket qua sau khi quay
        vector<vector<int>> res(n, vector<int>(m));

        while (top <= bottom && left <= right) {
            // luu cac phan tu cua vong hien tai vao vector temp
            vector<int> temp;

            // tren
            for (int j = left; j <= right; ++j) temp.push_back(a[top][j]);
            // phai
            for (int i = top + 1; i <= bottom; ++i) temp.push_back(a[i][right]);
            // duoi
            if (top < bottom)
                for (int j = right - 1; j >= left; --j) temp.push_back(a[bottom][j]);
            // trai
            if (left < right)
                for (int i = bottom - 1; i > top; --i) temp.push_back(a[i][left]);

            // quay vong temp
            int len = temp.size();
            rotate(temp.begin(), temp.end() - 1, temp.end());

            // gan lai vao ma tran ket qua
            int idx = 0;
            for (int j = left; j <= right; ++j) res[top][j] = temp[idx++];
            for (int i = top + 1; i <= bottom; ++i) res[i][right] = temp[idx++];
            if (top < bottom)
                for (int j = right - 1; j >= left; --j) res[bottom][j] = temp[idx++];
            if (left < right)
                for (int i = bottom - 1; i > top; --i) res[i][left] = temp[idx++];

            top++; bottom--;
            left++; right--;
        }

        // in ket qua theo tung dong
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << res[i][j] << " ";
        cout << endl;
    }
};

int main() {
	QuayMaTran();
	return 0;
}
