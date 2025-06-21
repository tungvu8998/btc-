#include <iostream>
#include <vector>
using namespace std;

//	=== Bai 26: Cua so truot
void CuaSoTruot() {
       int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int M;
    cin >> M;

    vector<vector<int>> B(M, vector<int>(M));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    vector<vector<int>> result(N, vector<int>(N, 0));  

    for (int i = 0; i < N; i += M) {
        for (int j = 0; j < N; j += M) {
            int sum = 0;
            for (int u = 0; u < M; u++) {
                for (int v = 0; v < M; v++) {
                    sum += A[i + u][j + v] * B[u][v];
                }
            }
            result[i][j] = sum;  
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

}
int main() {
	CuaSoTruot();
	return 0;
}
