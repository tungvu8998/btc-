#include <iostream>

using namespace std;

//	==== Bai 12: Biên cua ma tran 
void BienCuaMaTran() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[100][100];

       
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
        }

      
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                    cout << A[i][j] << " ";
                } else {
                    cout << "  "; 
                }
            }
            cout << endl;
        }
    }
}

int main() {
	BienCuaMaTran();
	return 0;
}
