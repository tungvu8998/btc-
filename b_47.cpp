#include <iostream>
#include <string>
#include <stack>

using namespace std;


// ==== Bai 47: Loai bo 100
// Ham tim do dai lon nhat xau con bi loai bo
int timDoDaiLonNhat(string s) {
    stack<char> st;
    int maxLen = 0;          // Do dai lon nhat xau bi loai bo lien tiep
    int currLen = 0;         // Do dai xau bi loai bo hien tai lien tiep

    for (char c : s) {
        st.push(c);

        // Kiem tra xau cuoi tren stack co phai "100"
        if (st.size() >= 3) {
            char c3 = st.top(); st.pop();
            char c2 = st.top(); st.pop();
            char c1 = st.top(); st.pop();

            // Neu la "100" thi loai bo va tang do dai hien tai
            if (c1 == '1' && c2 == '0' && c3 == '0') {
                currLen += 3; // Loai bo 3 ky tu
            } else {
                // Ko phai "100" thi push lai cac ky tu ve stack
                st.push(c1);
                st.push(c2);
                st.push(c3);

                // Ket thuc xau bi loai bo lien tiep, cap nhat maxLen
                if (currLen > 0) {
                    if (currLen > maxLen) maxLen = currLen;
                    currLen = 0;
                }
            }
        } else {
            // Khi chua du 3 ky tu, neu currLen > 0 thi reset
            if (currLen > 0) {
                if (currLen > maxLen) maxLen = currLen;
                currLen = 0;
            }
        }
    }
    // Ket thuc duyet chuoi, cap nhat maxLen lan cuoi neu can
    if (currLen > maxLen) maxLen = currLen;

    return maxLen;
}
int main() {
    int T; 
    cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);
        cout << timDoDaiLonNhat(s) << "\n";
    }
    return 0;
}

