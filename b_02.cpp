#include <iostream>
#include <cctype>
using namespace std;

// ==== Bài 2: Viet hoa viet thuong ====
void BaiHoaThuong() {
   int t;
   cin >> t;
   while (t--) {
   	char c;
   	cin >> ws >> c;
//   	if (c >= 'a' && c <= 'z') {
//	   cout << char(c - 32) << endl;
//	} else if (c >= 'A' && c <= 'Z') {
//		cout << char(c + 32) << endl;
//	} else {
//		cout << "Invalid" << endl;
//	}
	
	if (islower(c)) cout << char(toupper(c)) << endl;
	else if(isupper(c)) cout << char(tolower(c)) << endl;
	else cout << "Invalid" << endl;
   }
}

int main() {
	BaiHoaThuong();
	return 0;
}
