#include <iostream>

using namespace std;

	
// ==== Bai 11 : Bien doi nhi phan
void BienDoiNhiPhan() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        int A[100][100];
        bool row[100] = {false};
        bool col[100] = {false};
	
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> A[i][j];
                if (A[i][j] == 1) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

    
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (row[i] || col[j]) {
                    A[i][j] = 1;
                }
            }
        }

     
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << A[i][j];
                if (j != M - 1) cout << " ";
            }
            cout << endl;
        }
    }
}
int main() {
	BienDoiNhiPhan();
	return 0;
}
