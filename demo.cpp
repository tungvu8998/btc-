#include <iostream>
#include <cctype>
#include <vector>
#include <cmath>
#include <algorithm> // Required for std::sort, std::rotate and LLONG_MAX, std::transform
#include <set>       // Required for std::set
#include <unordered_set> // Required for std::unordered_set
#include <string>    // Required for std::string
#include <iomanip>   // Required for std::fixed and std::setprecision, std::setw, std::setfill
#include <fstream>   // Required for file operations (ifstream, ofstream)
#include <climits>   // Required for LLONG_MAX
#include <sstream>   // Required for stringstream
#include <unordered_map> // Required for std::unordered_map
#include <stack>     // Required for std::stack

using namespace std;

// ==== Bài 1: Tinh tong 1 den N ====
void BaiTinhTong() {
   int t;
   cin >> t;
   while (t--) {
		long long n;
		cin >> n;
		long long sum = n * (n + 1)/2;
		cout << sum << endl;
   }
}

// ==== Bài 2: Viet hoa viet thuong ====
void BaiHoaThuong() {
   int t;
   cin >> t;
   while (t--) {
   	char c;
   	cin >> ws >> c;
	
	if (islower(c)) cout << char(toupper(c)) << endl;
	else if(isupper(c)) cout << char(tolower(c)) << endl;
	else cout << "Invalid" << endl;
   }
}

// ==== Bai 3: Tinh tong giai thua
void BaiTinhTongGiaiThua() {
	int n;
	cin >> n;
	long long sum = 0;
	long long gt = 1;
	for (int i = 1; i <= n; ++i) {
		gt *= i;
		sum += gt;
	}
	cout << sum << endl;
}

// ==== Bai 4: Can bang chan le
void BaiCanBangChanLe() {
	int n;
	cin >> n;
	if (n <= 1 || n >= 7 || n % 2 != 0) {
		cout << "So nhap khong hop le" << endl;
		return;
	}
	int count = 0;
	int start = 1;
	for (int i = 1; i < n; i++) 
		start *= 10;
	int end = start * 10;
	
	for (int i = start; i < end; i++) {
		int temp = i;
		int even = 0, odd = 0;
		while (temp > 0) {
			int digit = temp % 10;
			if (digit % 2 == 0) {
				even++;
			} else {
				odd++;
			}
			temp /= 10;
		}
		if (even == odd) {
			cout << i << " ";
			count++;
			if (count % 10 == 0) cout << endl;
		}
	}
	if (count % 10 != 0) cout << endl;
}

// ==== Bai 5: bai so may man
void BaiSoMayMan() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		if (n % 100 == 86) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
    }
}

// ==== Bai 6: Bai so nguyen to
bool laSoNguyenTo(int n) {
	if(n < 2) return false;
	int can = sqrt(n);
	for (int i = 2; i <= can; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void BaiSoNguyenToMain() { // Renamed to avoid conflict with `main`
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if(laSoNguyenTo(i)) cout << i << " ";
	}
	cout << endl;
}

// ===== Bai 7: Bai uoc so nguyen to
void BaiUocSoNguyenTo() {
	int t; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) cout << i << " ";
			while (n % i == 0) {
				n /= i;
			}
		}
		if (n > 1) cout << n;
		cout << endl;
	}
}

// ==== Bai 8: So co 3 uoc
bool SoNguyenTo(int n) { // Duplicate of laSoNguyenTo, keeping for original context
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void BaiSoCoBaUoc() {
   	int t;
   	cin >> t;
   	while (t--) { 
		int n; 
		cin >> n;
		for (int i = 2; i * i <= n; i++) {
			if (SoNguyenTo(i)) cout << i*i << " ";
		}   
	}
	cout << endl;
}

// ==== Bai 8+: Tim so nho nhat
void BaiTimSoNhoNhat() { // Renamed from main in b_08+.cpp
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
		long long min_diff = LLONG_MAX; // Changed variable name to avoid conflict with potential 'min' function
		for (int i = 0; i < n - 1; i++) {
			long long diff = a[i + 1] - a[i];
			if (diff < min_diff) min_diff = diff;
		}
		cout << min_diff << endl;
	}
}

// ==== Bai 9 : So nho nhat chua xuat hien
void SoNhoNhat() {
	int t;
	cin >>t ;
	while (t--) {
		int n;
		cin >> n;
		vector <bool>  arr(n + 2, false);
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			if (x > 0 && x < n + 1) {
				arr[x] = true;
			}
		}
		for (int i = 1; i < n; i++) {
			if (!arr[i]) {
				cout << i << endl;
				break;
			}
		}
	}
}

// ==== Bai 10: Quay vong day so 1
void QuayVongDaySo() {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n); 
		for (int i = 0; i < n ;i++) {
			cin >> a[i] ;
		}
		for (int i = d; i < n; i++) {
			cout << a[i] << " ";
		}
		for (int i = 0; i < d; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

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

// ==== Bai 13: Liet ke so khac nhau
void LietKeSoKhacNhau() {
	int n;
	cin >> n;
	int a[100];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[0] << " ";
	
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i-1]) { // Corrected condition to compare with previous element
			cout << a[i] << " ";
		}
    }
    cout << endl;
}

//	==== Bai 14: Dem so phan tu lap lai
int freq_global[1000001]; // Renamed global freq array to avoid potential conflict if another freq array is declared
void DemSoPhanTuLap() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        // gan toan b? mang freq = 0
        for (int i = 0; i <= 1000000; ++i) {
            freq_global[i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            freq_global[x]++;
        }

        int count = 0;
        for (int i = 0; i <= 1000000; ++i) {
            if (freq_global[i] > 1) count += freq_global[i];
        }

        cout << count << endl;
    }
}

// === Bai 15: Tim so nho nhat lon nhat
string findMin(int m, int s) {
    if (s == 0) return (m == 1) ? "0" : "-1";
    if (s > 9 * m) return "-1";

    string res(m, '0');
    int sum = s;

    for (int i = 0; i < m; ++i) {
        for (int d = (i == 0 ? 1 : 0); d <= 9; ++d) {
            int max_possible = 9 * (m - i - 1);
            if (sum - d <= max_possible && sum - d >= 0) {
                res[i] = d + '0';
                sum -= d;
                break;
            }
        }
    }
    return res;
}

string findMax(int m, int s) {
    if (s == 0) return (m == 1) ? "0" : "-1";
    if (s > 9 * m) return "-1";

    string res(m, '0');
    int sum = s;

    for (int i = 0; i < m; ++i) {
        // th? t? 9 xu?ng 0
        for (int d = 9; d >= 0; --d) {
            if (sum - d >= 0) {
                res[i] = d + '0';
                sum -= d;
                break;
            }
        }
    }
    return res;
}
void TimMinMax () {
	 int m, s;
    cin >> m >> s;

    string minNum = findMin(m, s);
    string maxNum = findMax(m, s);

    if (minNum == "-1" || maxNum == "-1")
        cout << "-1 -1\n";
    else
        cout << minNum << " " << maxNum << "\n";

}

// ==== Bai 16: Dau cuoi giong nhau
void DemXauConDauCuoiGiong() {
    int T;
    cin >> T;
    cin.ignore(); // loai bo ky tu xuong dong sau so T

    while (T--) {
        string s;
        getline(cin, s);

        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        long long count = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                count += freq[i]; // xau con do dai 1
                count += 1LL * freq[i] * (freq[i] - 1) / 2; // xau con bat dau va ket thuc bang ky tu do
            }
        }

        cout << count << endl;
    }
}

//	==== Bai 17: Loai bo nguyen am
void LoaiBoNguyenAm() {
    string s;
    cin >> s;

    // Duyet tung ky tu
    for (char c : s) {
        c = tolower(c); // chuyen thanh chu thuong

        // Neu khong phai nguyen am thi in ra .<ky tu>
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') {
            cout << '.' << c;
        }
    }
    cout << endl;
}

//  ==== Bai 18: Sap xep chu so
void SapXepChuSo() {
     int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> digitSet;

        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            if (x == 0) {
                digitSet.insert(0);
            } else {
                while (x > 0) {
                    digitSet.insert(x % 10);
                    x /= 10;
                }
            }
        }

        // Dua set sang vector de sap xep
        vector<int> digits(digitSet.begin(), digitSet.end());
        sort(digits.begin(), digits.end());

        for (int d : digits) {
            cout << d << " ";
        }
        cout << endl;
    }
}

// ===	Bai 19: Nhap thi sinh
struct ThiSinh {
    string hoTen;
    string ngaySinh;
    float diem1, diem2, diem3;

    float tongDiem() const {
        return diem1 + diem2 + diem3;
    }
};

// Ham nhap thong tin thi sinh
void NhapThiSinh(ThiSinh &ts) {
    getline(cin, ts.hoTen);
    getline(cin, ts.ngaySinh);
    cin >> ts.diem1 >> ts.diem2 >> ts.diem3;
    cin.ignore(); 
}

// Ham xuat thong tin thi sinh
void XuatThiSinh(const ThiSinh &ts) {
    cout << ts.hoTen << " " << ts.ngaySinh << " ";
    cout << fixed << setprecision(1) << ts.tongDiem() << "\n";
}

// ==== Bai 20: Nhap nhan vien
struct NhanVien20 { // Renamed struct to avoid conflict
    string maNV = "00001";  
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string diaChi;
    string maSoThue;
    string ngayKyHD;
};

void nhapNhanVien20(NhanVien20 &nv) { // Renamed function
    getline(cin, nv.hoTen);
    getline(cin, nv.gioiTinh);
    getline(cin, nv.ngaySinh);
    getline(cin, nv.diaChi);
    getline(cin, nv.maSoThue);
    getline(cin, nv.ngayKyHD);
}

void inNhanVien20(const NhanVien20 &nv) { // Renamed function
    cout << nv.maNV << " "
         << nv.hoTen << " "
         << nv.gioiTinh << " "
         << nv.ngaySinh << " "
         << nv.diaChi << " "
         << nv.maSoThue << " "
         << nv.ngayKyHD << "\n";
}

// === Bai 21+22: Phan so toi giam va tinh tong tuong doi 2 phan so
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
// This PhanSo class is for Bai 21 (toiGian)
class PhanSo21 {
private:
    ll tu;
    ll mau;

public:
    PhanSo21(ll t = 0, ll m = 1) {
        tu = t;
        mau = m;
    }

    void nhap() {
        cin >> tu >> mau;
    }

    void toiGian() {
        ll u = gcd(tu, mau);
        tu /= u;
        mau /= u;
        if (mau < 0) {   
            mau = -mau;
            tu = -tu;
        }
    }
    
    void in() {
        cout << tu << "/" << mau << "\n";
    }
};

// This PhanSo class is for Bai 22 (cong)
class PhanSo22 {
private:
    ll tu;
    ll mau;

public:
    PhanSo22(ll t = 0, ll m = 1) {
        tu = t;
        mau = m;
    }

    void nhap() {
        cin >> tu >> mau;
    }

    void toiGian() {
        ll u = gcd(tu, mau);
        tu /= u;
        mau /= u;
        if (mau < 0) {   
            mau = -mau;
            tu = -tu;
        }
    }
    PhanSo22 cong(const PhanSo22& other) {
        ll t = tu * other.mau + mau * other.tu;
        ll m = mau * other.mau;
        PhanSo22 res(t, m);
        res.toiGian();
        return res;
    }

    void in() {
        cout << tu << "/" << mau << "\n";
    }
};

//	==== Bai 23: Sao chep tep tin
void SaoChepTepTin() {
    ifstream fin("PTIT.in.txt");
    ofstream fout("PTIT.out.txt");

    if (!fin.is_open()) {
        cout << "Khong mo duoc file PTIT.in\n";
        return;
    }
    if (!fout.is_open()) {
        cout << "Khong mo duoc file PTIT.out\n";
        return;
    }

    string line;
    while (getline(fin, line)) {
        fout << line << "\n";
    }

    fin.close();
    fout.close();
}

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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}

//	==== Bai 25: Bien doi day so
void BienDoiDaySo() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int i = 0, j = n - 1;
        int count = 0;

        while (i < j) {
            if (a[i] == a[j]) {
                i++;
                j--;
            } else if (a[i] < a[j]) {
                a[i + 1] += a[i]; // gop a[i] vao a[i+1]
                i++;
                count++;
            } else {
                a[j - 1] += a[j]; // gop a[j] vao a[j-1]
                j--;
                count++;
            }
        }

        cout << count << endl;
    }
}

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

//	=== Bai 27 : Doi so chu so
string findMaxLessThanN(string s) {
    int n = s.length();
    int idx = -1;

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] > s[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return "-1";  

    int maxIdx = -1;
    char maxChar = '0';

    for (int i = idx + 1; i < n; ++i) {
        if (s[i] < s[idx]) {
            if (s[i] >= maxChar) {
                maxChar = s[i];
                maxIdx = i;
            }
        }
    }

    if (maxIdx == -1) return "-1";

    swap(s[idx], s[maxIdx]);
    if (s[0] == '0') return "-1";

    return s;
}

void DoiSoChuSo() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << findMaxLessThanN(s) << endl;
    }
}

//	Bai 28 : Tong so trong xau
int tongSoTrongXau(const string& s) {
    long long sum = 0;
    int current = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current = current * 10 + (c - '0');
        } else {
            sum += current;
            current = 0;
        }
    }
    sum += current;
    return sum;
}

void TongSoTrongXau() {
    int T;
    cin >> T;
    cin.ignore(); // bo dòng newline sau T
    while (T--) {
        string s;
        getline(cin, s);
        cout << tongSoTrongXau(s) << endl;
    }
}

//	Bai 29: tach chu so
void TachChuSo() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string s;
        getline(cin, s);

        string letters;
        int sum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                sum += c - '0';
            } else if (isupper(c)) {
                letters += c;
            }
        }

        sort(letters.begin(), letters.end());
        cout << letters << sum << endl;
    }
}

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
        sort(A.begin(), A.end()); // Ensure arrays are sorted for merging logic
        sort(B.begin(), B.end()); // Ensure arrays are sorted for merging logic

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

// ==== Bai 33: Danh sach sinh vien
class SinhVien33 {
private:
    string id, name, lop, dob;
    float gpa;

    string chuanHoaNgay(string d) {
        stringstream ss(d);
        string day, month, year;
        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year);
        if (day.length() == 1) day = "0" + day;
        if (month.length() == 1) month = "0" + month;
        return day + "/" + month + "/" + year;
    }

public:
    static int dem;

    void nhap() {
        getline(cin, name);
        getline(cin, lop);
        string ngay;
        getline(cin, ngay);
        dob = chuanHoaNgay(ngay);
        cin >> gpa;
        cin.ignore();
        stringstream ss;
        ss << "B20DCCN" << setw(3) << setfill('0') << dem++;
        id = ss.str();
    }

    void in() {
        cout << id << " " << name << " " << lop << " " << dob << " " << fixed << setprecision(2) << gpa << endl;
    }
};

int SinhVien33::dem = 1;

void XuLyDanhSachSinhVien33() {
    int N;
    cin >> N;
    cin.ignore();
    vector<SinhVien33> ds(N);
    for (int i = 0; i < N; ++i) {
        ds[i].nhap();
    }
    for (int i = 0; i < N; ++i) {
        ds[i].in();
    }
}

// ==== Bai 34: Sap xep danh sach nhan vien
class NhanVien34 {
public:
    string maNV, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKy;

    void chuanHoaNgay(string &ngay) {
        stringstream ss(ngay);
        string d, m, y;
        getline(ss, d, '/');
        getline(ss, m, '/');
        getline(ss, y);
        if (d.size() == 1) d = "0" + d;
        if (m.size() == 1) m = "0" + m;
        ngay = d + "/" + m + "/" + y;
    }

    string getNgaySoSanh() const {
        return ngaySinh.substr(6,4) + ngaySinh.substr(3,2) + ngaySinh.substr(0,2);
    }
};

void XuLyDanhSachNhanVien34() {
    int n; 
    cin >> n;
    cin.ignore();

    vector<NhanVien34> ds(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds[i].hoTen);
        getline(cin, ds[i].gioiTinh);
        getline(cin, ds[i].ngaySinh);
        getline(cin, ds[i].diaChi);
        getline(cin, ds[i].maSoThue);
        getline(cin, ds[i].ngayKy);

        ds[i].chuanHoaNgay(ds[i].ngaySinh);
        ds[i].chuanHoaNgay(ds[i].ngayKy);

        stringstream ss;
        ss << setw(5) << setfill('0') << (i+1);
        ds[i].maNV = ss.str();
    }

    sort(ds.begin(), ds.end(), [](const NhanVien34 &a, const NhanVien34 &b){
        return a.getNgaySoSanh() < b.getNgaySoSanh();
    });

    for (const auto &nv : ds) {
        cout << nv.maNV << " " << nv.hoTen << " " << nv.gioiTinh << " " << nv.ngaySinh << " "
             << nv.diaChi << " " << nv.maSoThue << " " << nv.ngayKy << "\n";
    }
}

//	==== Bai 35: Danh sach sinh vien 2
struct SinhVien35 {
    string ma;
    string hoten;
    string lop;
    string ngaysinh;
    float gpa;
};

// ham chuan hoa ho ten
string chuanHoaHoTen35(string s) {
    string res = "";
    // xoa khoang trang dau cuoi va nhieu khoang trang giua
    int n = (int)s.size();
    vector<string> words;
    string word = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') word += s[i];
        else if (!word.empty()) {
            words.push_back(word);
            word = "";
        }
    }
    if (!word.empty()) words.push_back(word);

    for (int i = 0; i < (int)words.size(); i++) {
        string& w = words[i];
        for (auto& c : w) c = tolower(c);
        w[0] = toupper(w[0]);
        res += w;
        if (i != (int)words.size() - 1) res += " ";
    }
    return res;
}

// ham chuan hoa ngay sinh
string chuanHoaNgaySinh35(string s) {
    // cat chuoi theo dau '/'
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    if (d.size() == 1) d = "0" + d;
    if (m.size() == 1) m = "0" + m;

    return d + "/" + m + "/" + y;
}

// ham tao ma sinh vien tu index bat dau tu 1
string taoMaSV35(int idx) {
    ostringstream oss;
    oss << "B20DCCN";
    oss << setw(3) << setfill('0') << idx;
    return oss.str();
}

// ham nhap danh sach sinh vien
void nhapSinhVien35(vector<SinhVien35>& ds, int n) {
    for (int i = 1; i <= n; i++) {
        SinhVien35 sv;
        sv.ma = taoMaSV35(i);

        string hoten, lop, ngaysinh;
        float gpa;

        cin.ignore();
        getline(cin, hoten);
        getline(cin, lop);
        getline(cin, ngaysinh);
        cin >> gpa;

        sv.hoten = chuanHoaHoTen35(hoten);
        sv.lop = lop;
        sv.ngaysinh = chuanHoaNgaySinh35(ngaysinh);
        sv.gpa = gpa;

        ds.push_back(sv);
    }
}

// ham in danh sach sinh vien
void inSinhVien35(const vector<SinhVien35>& ds) {
    for (const SinhVien35& sv : ds) {
        cout << sv.ma << " " << sv.hoten << " " << sv.lop << " " << sv.ngaysinh << " ";
        cout << fixed << setprecision(2) << sv.gpa << "\n";
    }
}

// ==== Bai 36: Danh sach sinh vien 3
struct SinhVien36 {
    string ma;
    string hoten;
    string ngaysinh;
    string lop;
    float gpa;
};

// ham chuan hoa ho ten
string chuanHoaHoTen36(string s) {
    string res = "";
    int n = (int)s.size();
    vector<string> words;
    string word = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') word += s[i];
        else if (!word.empty()) {
            words.push_back(word);
            word = "";
        }
    }
    if (!word.empty()) words.push_back(word);

    for (int i = 0; i < (int)words.size(); i++) {
        string& w = words[i];
        for (auto& c : w) c = tolower(c);
        w[0] = toupper(w[0]);
        res += w;
        if (i != (int)words.size() - 1) res += " ";
    }
    return res;
}

// ham chuan hoa ngay sinh dd/mm/yyyy
string chuanHoaNgaySinh36(string s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    if (d.size() == 1) d = "0" + d;
    if (m.size() == 1) m = "0" + m;

    return d + "/" + m + "/" + y;
}

// ham tao ma sinh vien
string taoMaSV36(int idx) {
    ostringstream oss;
    oss << "B20DCCN";
    oss << setw(3) << setfill('0') << idx;
    return oss.str();
}

// ham nhap danh sach sinh vien
void nhapSinhVien36(vector<SinhVien36>& ds, int n) {
    for (int i = 1; i <= n; i++) {
        SinhVien36 sv;
        sv.ma = taoMaSV36(i);

        string hoten, lop, ngaysinh;
        float gpa;

        cin.ignore();
        getline(cin, hoten);
        getline(cin, lop);
        getline(cin, ngaysinh);
        cin >> gpa;

        sv.hoten = chuanHoaHoTen36(hoten);
        sv.lop = lop;
        sv.ngaysinh = chuanHoaNgaySinh36(ngaysinh);
        sv.gpa = gpa;

        ds.push_back(sv);
    }
}

// ham sap xep theo gpa giam dan
void sapXepGPA36(vector<SinhVien36>& ds) {
    sort(ds.begin(), ds.end(), [](const SinhVien36& a, const SinhVien36& b) {
        return a.gpa > b.gpa;
    });
}

// ham in danh sach sinh vien
void inSinhVien36(const vector<SinhVien36>& ds) {
    for (const SinhVien36& sv : ds) {
        cout << sv.ma << " " << sv.hoten << " " << sv.lop << " " << sv.ngaysinh << " ";
        cout << fixed << setprecision(2) << sv.gpa << "\n";
    }
}

// ==== Bai 37: Sap xep danh sach nhan vien
struct NhanVien37 {
    string ma;
    string hoten;
    string gioitinh;
    string ngaysinh;
    string diachi;
    string masothue;
    string ngaykyhopdong;
};

// ham tao ma nhan vien tu index bat dau tu 1
string taoMaNV37(int idx) {
    ostringstream oss;
    oss << setw(5) << setfill('0') << idx;
    return oss.str();
}

// ham chuan hoa ngay sinh hoac ngay ky hop dong theo dd/mm/yyyy
string chuanHoaNgay37(string s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);
    if (d.size() == 1) d = "0" + d;
    if (m.size() == 1) m = "0" + m;
    return d + "/" + m + "/" + y;
}

// ham chuyen ngay sinh sang dang so nguyen de so sanh
// vd: dd/mm/yyyy -> yyyymmdd (int)
int ngayThanhSo37(const string& s) {
    stringstream ss(s);
    string d, m, y;
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);
    return stoi(y) * 10000 + stoi(m) * 100 + stoi(d);
}

// ham nhap danh sach nhan vien
void nhapNhanVien37(vector<NhanVien37>& ds, int n) {
    for (int i = 1; i <= n; i++) {
        NhanVien37 nv;
        nv.ma = taoMaNV37(i);

        getline(cin, nv.hoten);
        getline(cin, nv.gioitinh);
        string ngsinh;
        getline(cin, ngsinh);
        nv.ngaysinh = chuanHoaNgay37(ngsinh);
        getline(cin, nv.diachi);
        getline(cin, nv.masothue);
        string ngayky;
        getline(cin, ngayky);
        nv.ngaykyhopdong = chuanHoaNgay37(ngayky);

        ds.push_back(nv);
    }
}

// ham sap xep theo ngay sinh tu gia nhat den tre nhat
void sapXepTheoNgaySinh37(vector<NhanVien37>& ds) {
    sort(ds.begin(), ds.end(), [](const NhanVien37& a, const NhanVien37& b) {
        return ngayThanhSo37(a.ngaysinh) < ngayThanhSo37(b.ngaysinh);
    });
}

// ham in danh sach nhan vien
void inNhanVien37(const vector<NhanVien37>& ds) {
    for (const NhanVien37& nv : ds) {
        cout << nv.ma << " " << nv.hoten << " " << nv.gioitinh << " " << nv.ngaysinh << " "
             << nv.diachi << " " << nv.masothue << " " << nv.ngaykyhopdong << "\n";
    }
}

// ==== Bai 38: Bang diem thanh phan 1
struct SinhVien38 {
    string ma;
    string hoten;
    string lop;
    float diem1, diem2, diem3;
};

// ham nhap danh sach sinh vien
void nhapSinhVien38(vector<SinhVien38>& ds, int n) {
    for (int i = 0; i < n; i++) {
        SinhVien38 sv;
        getline(cin, sv.ma);
        getline(cin, sv.hoten);
        getline(cin, sv.lop);
        cin >> sv.diem1 >> sv.diem2 >> sv.diem3;
        cin.ignore();
        ds.push_back(sv);
    }
}

// ham sap xep theo ma sv tang dan (tu dien)
void sapXepTheoMaSV38(vector<SinhVien38>& ds) {
    sort(ds.begin(), ds.end(), [](const SinhVien38& a, const SinhVien38& b) {
        return a.ma < b.ma;
    });
}

// ham in danh sach sinh vien
void inDanhSach38(const vector<SinhVien38>& ds) {
    int idx = 1;
    for (const SinhVien38& sv : ds) {
        cout << idx << " " << sv.ma << " " << sv.hoten << " " << sv.lop << " ";
        cout << fixed << setprecision(1);
        cout << sv.diem1 << " " << sv.diem2 << " " << sv.diem3 << "\n";
        idx++;
    }
}

// Bai 39: Sap xep danh sach nhan vien
struct SinhVien39 {
    string ma;
    string hoten;
    string lop;
    float diem1, diem2, diem3;
};

// ham nhap danh sach sinh vien
void nhapSinhVien39(vector<SinhVien39>& ds, int n) {
    for (int i = 0; i < n; i++) {
        SinhVien39 sv;
        getline(cin, sv.ma);
        getline(cin, sv.hoten);
        getline(cin, sv.lop);
        cin >> sv.diem1 >> sv.diem2 >> sv.diem3;
        cin.ignore();
        ds.push_back(sv);
    }
}

// ham sap xep theo ho ten tang dan (tu dien)
void sapXepTheoHoTen39(vector<SinhVien39>& ds) {
    sort(ds.begin(), ds.end(), [](const SinhVien39& a, const SinhVien39& b) {
        return a.hoten < b.hoten;
    });
}

// ham in danh sach sinh vien
void inDanhSach39(const vector<SinhVien39>& ds) {
    int idx = 1;
    for (const SinhVien39& sv : ds) {
        cout << idx << " " << sv.ma << " " << sv.hoten << " " << sv.lop << " ";
        cout << fixed << setprecision(1);
        cout << sv.diem1 << " " << sv.diem2 << " " << sv.diem3 << "\n";
        idx++;
    }
}

// ==== Bai 40: Tre nhat - Gia nhat
struct Nguoi40 { // Renamed struct
    string ten;
    string ngaysinh; // dd/mm/yyyy
};

// ham chuyen ngay sinh sang dang so de so sanh yyyymmdd
int ngayThanhSo40(const string& s) { // Renamed function
    int d = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int y = stoi(s.substr(6, 4));
    return y * 10000 + m * 100 + d;
}

// ham nhap danh sach nguoi
void nhapDanhSach40(vector<Nguoi40>& ds, int n) { // Renamed function
    for (int i = 0; i < n; i++) {
        Nguoi40 ng;
        cin >> ng.ten >> ng.ngaysinh;
        ds.push_back(ng);
    }
}

// ham tim nguoi tre nhat va gia nhat
pair<string, string> timTreVaGia40(const vector<Nguoi40>& ds) { // Renamed function
    int idxTreNhat = 0, idxGiaNhat = 0;
    for (int i = 1; i < (int)ds.size(); i++) {
        int curr = ngayThanhSo40(ds[i].ngaysinh);
        int treNhat = ngayThanhSo40(ds[idxTreNhat].ngaysinh);
        int giaNhat = ngayThanhSo40(ds[idxGiaNhat].ngaysinh);

        if (curr > treNhat) idxTreNhat = i;  // tre nhat: ngay sinh lon hon
        if (curr < giaNhat) idxGiaNhat = i;  // gia nhat: ngay sinh nho hon
    }
    return { ds[idxTreNhat].ten, ds[idxGiaNhat].ten };
}

// ==== Bai 41: Danh sach doi tuong sinh vien (NhanVien in original)
int dem41 = 0; // Renamed global counter to avoid conflict

class NhanVien41 { // Renamed class
private:
    string ma, ten, gioitinh, ngaysinh, diachi, maso, ngayky;

public:
    // ham tao tu dong sinh ma nhan vien
    NhanVien41() {
        ++dem41;
        ma = string(5 - to_string(dem41).length(), '0') + to_string(dem41);
    }

    // chong toan tu nhap
    friend istream& operator >> (istream& in, NhanVien41& nv) {
        getline(in, nv.ten);
        getline(in, nv.gioitinh);
        getline(in, nv.ngaysinh);
        getline(in, nv.diachi);
        getline(in, nv.maso);
        getline(in, nv.ngayky);
        return in;
    }

    // chong toan tu xuat
    friend ostream& operator << (ostream& out, const NhanVien41& nv) {
        out << nv.ma << " " << nv.ten << " " << nv.gioitinh << " "
            << nv.ngaysinh << " " << nv.diachi << " "
            << nv.maso << " " << nv.ngayky;
        return out;
    }
};

void XuLyNhanVien41() { // Wrapper function for original main logic
    int n;
    cin >> n;
    cin.ignore(); // loai bo ky tu xuong dong sau so n

    vector<NhanVien41> ds(n);
    for (int i = 0; i < n; ++i) {
        cin >> ds[i];
    }

    for (const NhanVien41& nv : ds) {
        cout << nv << endl;
    }
}

// ==== Bai 42: Sap xep sinh vien theo lop
class SinhVien42 { // Renamed class
public:
    string ma, hoten, lop, email;

    // ham nhap
    void nhap() {
        getline(cin, ma);
        getline(cin, hoten);
        getline(cin, lop);
        getline(cin, email);
    }

    // ham xuat
    void xuat() const {
        cout << ma << " " << hoten << " " << lop << " " << email << endl;
    }

    // ham so sanh phuc vu sap xep
    bool operator < (const SinhVien42& other) const {
        if (lop != other.lop) return lop < other.lop;
        return ma < other.ma;
    }
};

void XuLySapXepSinhVien42() { // Wrapper function for original main logic
    int n;
    cin >> n;
    cin.ignore(); // bo xuong dong sau so n

    vector<SinhVien42> ds(n);
    for (int i = 0; i < n; ++i) {
        ds[i].nhap();
    }

    sort(ds.begin(), ds.end());

    for (const SinhVien42& sv : ds) {
        sv.xuat();
    }
}

// ==== Bai 43: Sep xep sinh vien theo ma SV
class SinhVien43 { // Renamed class
private:
    string maSV;
    string hoTen;
    string lop;
    string email;

public:
    // Ham khoi tao co tham so
    SinhVien43(const string& ma, const string& ten, const string& lop, const string& email)
        : maSV(ma), hoTen(ten), lop(lop), email(email) {}

    // Ham lay ma sinh vien
    string getMaSV() const {
        return maSV;
    }

    // Ham xuat thong tin sinh vien
    void hienThi() const {
        cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
    }
};

// Ham doc danh sach sinh vien tu dau vao
void nhapDanhSachSinhVien43(vector<SinhVien43>& danhSach) { // Renamed function
    string ma, ten, lop, email;
    while (getline(cin, ma) && !ma.empty()) { // Added check for empty line to stop reading
        getline(cin, ten);
        getline(cin, lop);
        getline(cin, email);
        // Them sinh vien moi vao danh sach
        danhSach.emplace_back(ma, ten, lop, email);
    }
}

// Ham so sanh de sap xep theo ma sinh vien
bool soSanhTheoMa43(const SinhVien43& a, const SinhVien43& b) { // Renamed function
    return a.getMaSV() < b.getMaSV();
}

// Ham sap xep danh sach sinh vien theo ma
void sapXepDanhSach43(vector<SinhVien43>& danhSach) { // Renamed function
    sort(danhSach.begin(), danhSach.end(), soSanhTheoMa43);
}

// Ham in danh sach sinh vien
void inDanhSach43(const vector<SinhVien43>& danhSach) { // Renamed function
    for (const auto& sv : danhSach) {
        sv.hienThi();
    }
}

void XuLySapXepSinhVien43() { // Wrapper for main logic
    vector<SinhVien43> ds;
    nhapDanhSachSinhVien43(ds);
    sapXepDanhSach43(ds);
    inDanhSach43(ds);
}

// ==== Bai 44: Liet ke sinh vien theo nganh
class SinhVien44 { // Renamed class
private:
    string maSV;
    string hoTen;
    string lop;
    string email;

public:
    // Ham khoi tao sinh vien
    SinhVien44(const string& ma, const string& ten, const string& lop, const string& email)
        : maSV(ma), hoTen(ten), lop(lop), email(email) {}

    // Ham tra ve ma sinh vien
    string getMaSV() const {
        return maSV;
    }

    // Ham tra ve lop
    string getLop() const {
        return lop;
    }

    // Ham tra ve 4 ky tu nganh trong ma sinh vien
    string getNganhCode() const {
        return maSV.substr(3, 4);
    }

    // Ham hien thi thong tin sinh vien
    void hienThi() const {
        cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
    }
};

// Ham nhap danh sach sinh vien
void nhapDanhSachSinhVien44(vector<SinhVien44>& danhSach, int soLuong) { // Renamed function
    string ma, ten, lop, email;
    for (int i = 0; i < soLuong; ++i) {
        getline(cin, ma);
        getline(cin, ten);
        getline(cin, lop);
        getline(cin, email);
        danhSach.emplace_back(ma, ten, lop, email);
    }
}

// Ham xu ly va liet ke sinh vien theo tung truy van nganh
void lietKeTheoNganh44(const vector<SinhVien44>& danhSach, const vector<string>& truyVan) { // Renamed function
    // Map ma nganh voi ten nganh de so sanh
    unordered_map<string, string> maNganh = { // Local map to avoid global conflict
        {"DCKT", "Ke toan"},
        {"DCCN", "Cong nghe thong tin"},
        {"DCAT", "An toan thong tin"},
        {"DCVT", "Vien thong"},
        {"DCDT", "Dien tu"}
    };

    for (const string& nganh : truyVan) {
        cout << "DANH SACH SINH VIEN NGANH " << nganh << ":" << endl;
        for (const auto& sv : danhSach) {
            string code = sv.getNganhCode();

            // Bo qua sinh vien lop bat dau bang 'E' neu nganh la CNTT hoac ATTT
            if ((nganh == "Cong nghe thong tin" && code == "DCCN" && sv.getLop()[0] != 'E') ||
                (nganh == "An toan thong tin" && code == "DCAT" && sv.getLop()[0] != 'E') ||
                (nganh == "Ke toan" && code == "DCKT") ||
                (nganh == "Vien thong" && code == "DCVT") ||
                (nganh == "Dien tu" && code == "DCDT")) {
                sv.hienThi();
            }
        }
    }
}

void XuLyLietKeSinhVien44() { // Wrapper for main logic
    int n;
    cin >> n;
    cin.ignore(); // Bo dong xuong sau khi nhap so

    vector<SinhVien44> danhSach;
    nhapDanhSachSinhVien44(danhSach, n);

    int q;
    cin >> q;
    cin.ignore();

    vector<string> truyVan(q);
    for (int i = 0; i < q; ++i) {
        getline(cin, truyVan[i]);
    }

    lietKeTheoNganh44(danhSach, truyVan);
}

// ==== Bai 45: Tim kiem giang vien
class GiangVien45 { // Renamed class
private:
    string maGV;
    string hoTen;
    string boMon;

public:
    // Ham khoi tao co tham so va ma tu dong
    GiangVien45(int stt, const string& ten, const string& boMonGoc) {
        stringstream ss;
        ss << "GV" << setfill('0') << setw(2) << stt;
        maGV = ss.str();
        hoTen = ten;
        boMon = vietTatBoMon45(boMonGoc); // Use renamed helper
    }

    // Ham viet tat bo mon tu cac chu cai dau
    string vietTatBoMon45(const string& s) { // Renamed function
        stringstream ss(s);
        string tu, ketQua = "";
        while (ss >> tu) {
            ketQua += toupper(tu[0]);
        }
        return ketQua;
    }

    // Ham lay ho ten
    string getHoTen() const {
        return hoTen;
    }

    // Ham hien thi thong tin giang vien
    void hienThi() const {
        cout << maGV << " " << hoTen << " " << boMon << endl;
    }
};

// Ham chuyen xau ve dang chu thuong
string chuyenVeThuong45(string s) { // Renamed function
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Ham nhap danh sach giang vien
void nhapDanhSachGiangVien45(vector<GiangVien45>& ds, int soLuong) { // Renamed function
    string ten, boMon;
    for (int i = 1; i <= soLuong; ++i) {
        getline(cin, ten);
        getline(cin, boMon);
        ds.emplace_back(i, ten, boMon);
    }
}

// Ham xu ly cac truy van tim kiem theo tu khoa
void timKiemGiangVien45(const vector<GiangVien45>& ds, const vector<string>& tuKhoa) { // Renamed function
    for (const auto& tu : tuKhoa) {
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << tu << ":" << endl;
        string key = chuyenVeThuong45(tu); // Use renamed helper
        for (const auto& gv : ds) {
            string tenThuong = chuyenVeThuong45(gv.getHoTen()); // Use renamed helper
            if (tenThuong.find(key) != string::npos) {
                gv.hienThi();
            }
        }
    }
}

void XuLyTimKiemGiangVien45() { // Wrapper for main logic
    int n;
    cin >> n;
    cin.ignore();

    vector<GiangVien45> danhSach;
    nhapDanhSachGiangVien45(danhSach, n);

    int q;
    cin >> q;
    cin.ignore();

    vector<string> tuKhoa(q);
    for (int i = 0; i < q; ++i) {
        getline(cin, tuKhoa[i]);
    }

    timKiemGiangVien45(danhSach, tuKhoa);
}

// === Bai 46 : Danh sach danh nghiep nhan sinh vien thuc tap 1
// Lop doanh nghiep
class DoanhNghiep46 { // Renamed class
private:
    string maDN;
    string tenDN;
    int soSV;

public:
    // Ham khoi tao doanh nghiep
    DoanhNghiep46(const string& ma, const string& ten, int so)
        : maDN(ma), tenDN(ten), soSV(so) {}

    // Ham lay so sinh vien
    int getSoSV() const {
        return soSV;
    }

    // Ham lay ma doanh nghiep
    string getMaDN() const {
        return maDN;
    }

    // Ham hien thi thong tin doanh nghiep
    void hienThi() const {
        cout << maDN << " " << tenDN << " " << soSV << endl;
    }
};

// Ham nhap danh sach doanh nghiep
void nhapDanhSach46(vector<DoanhNghiep46>& ds, int n) { // Renamed function
    string ma, ten;
    int so;
    for (int i = 0; i < n; ++i) {
        getline(cin, ma);
        getline(cin, ten);
        cin >> so;
        cin.ignore(); // Bo qua dau xuong dong sau so
        ds.emplace_back(ma, ten, so);
    }
}

// Ham so sanh de sap xep doanh nghiep
bool soSanh46(const DoanhNghiep46& a, const DoanhNghiep46& b) { // Renamed function
    if (a.getSoSV() != b.getSoSV())
        return a.getSoSV() > b.getSoSV(); // Giam dan theo so sinh vien
    return a.getMaDN() < b.getMaDN();     // Tang dan theo ma doanh nghiep
}

// Ham sap xep danh sach
void sapXepDanhSach46(vector<DoanhNghiep46>& ds) { // Renamed function
    sort(ds.begin(), ds.end(), soSanh46);
}

// Ham in danh sach
void inDanhSach46(const vector<DoanhNghiep46>& ds) { // Renamed function
    for (const auto& dn : ds) {
        dn.hienThi();
    }
}

void XuLyDoanhNghiep46() { // Wrapper for main logic
    int n;
    cin >> n;
    cin.ignore();

    vector<DoanhNghiep46> danhSach;
    nhapDanhSach46(danhSach, n);

    sapXepDanhSach46(danhSach);

    inDanhSach46(danhSach);
}


// ==== Bai 47: Loai bo 100
// Ham tim do dai lon nhat xau con bi loai bo
int timDoDaiLonNhat47(string s) { // Renamed function
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

void XuLyLoaiBo100() { // Wrapper for main logic
    int T; 
    cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);
        cout << timDoDaiLonNhat47(s) << "\n";
    }
}

// ==== Bai 48: So khac nhau trong file
// Ham doc file va dem so lan xuat hien cac so
void demSoLanXuatHien48(const string& filename) { // Renamed function
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file " << filename << endl;
        return;
    }

    // Mang dem so lan xuat hien, vi so nho hon 1000
    vector<int> dem(1000, 0);
    int x;

    // Doc tung so trong file va dem
    while (fin >> x) {
        if (x > 0 && x < 1000) {
            dem[x]++;
        }
    }
    fin.close();

    // In ra cac so va so lan xuat hien theo thu tu tang dan
    for (int i = 1; i < 1000; ++i) {
        if (dem[i] > 0) {
            cout << i << " " << dem[i] << endl;
        }
    }
}

void XuLySoKhacNhauTrongFile() { // Wrapper for main logic
    demSoLanXuatHien48("DATA.in.txt");
}

// ==== Bai 49: Liet ke tu khac nhau trong file
// Ham chuyen chuoi ve chu thuong
string chuyenVeThuong49(string s) { // Renamed function
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

// Ham doc file, liet ke tu khac nhau
void lietKeTuKhacNhau49(const string& filename) { // Renamed function
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file " << filename << endl;
        return;
    }

    set<string> tuSet;
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            word = chuyenVeThuong49(word);
            tuSet.insert(word);
        }
    }
    fin.close();

    // In ra cac tu khac nhau theo thu tu tu dien
    for (const string& w : tuSet) {
        cout << w << endl;
    }
}

void XuLyLietKeTuKhacNhauTrongFile() { // Wrapper for main logic
    lietKeTuKhacNhau49("VANBAN.in.txt");
}

// === Bai 50: Hop va giao cua 2 file van ban
// Chuyen chuoi ve chu thuong
string toLowerStr50(const string& s) { // Renamed function
    string res = s;
    for (char& c : res) c = tolower(c);
    return res;
}

// Doc cac tu trong file va tra ve set tu khac nhau
set<string> docTuTuFile50(const string& filename) { // Renamed function
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file " << filename << endl;
        return {};
    }
    set<string> tuSet;
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            word = toLowerStr50(word);
            tuSet.insert(word);
        }
    }
    fin.close();
    return tuSet;
}

// In ra set cac tu cach nhau 1 khoang trang
void inSet50(const set<string>& s) { // Renamed function
    bool first = true;
    for (const string& w : s) {
        if (!first) cout << " ";
        cout << w;
        first = false;
    }
    cout << "\n";
}

void XuLyHopGiaoHaiFileVanBan() { // Wrapper for main logic
    set<string> set1 = docTuTuFile50("DATA1.in.txt");
    set<string> set2 = docTuTuFile50("DATA2.in.txt");

    // Tinh hop
    set<string> hop = set1;
    hop.insert(set2.begin(), set2.end());

    // Tinh giao
    set<string> giao;
    for (const string& w : set1) {
        if (set2.count(w)) {
            giao.insert(w);
        }
    }

    // In ket qua
    inSet50(hop);
    inSet50(giao);
}

int main() {
    // You can call the functions here to test them
    // For example, to run BaiTinhTong:
    // BaiTinhTong();

    // To run all functions (you'll need to provide input for each as prompted):
    // BaiTinhTong();
    // BaiHoaThuong();
    // BaiTinhTongGiaiThua();
    // BaiCanBangChanLe();
    // BaiSoMayMan();
    // BaiSoNguyenToMain();
    // BaiUocSoNguyenTo();
    // BaiSoCoBaUoc();
    // BaiTimSoNhoNhat();
    // SoNhoNhat();
    // QuayVongDaySo();
    // BienDoiNhiPhan();
    // BienCuaMaTran();
    // LietKeSoKhacNhau();
    // DemSoPhanTuLap();
    // TimMinMax();
    // DemXauConDauCuoiGiong();
    // LoaiBoNguyenAm();
    // SapXepChuSo();

    // Example of calling ThiSinh functions (from b_19.cpp):
    // ThiSinh ts;
    // NhapThiSinh(ts);
    // XuatThiSinh(ts);

    // Example of calling NhanVien20 functions (from b_20.cpp):
    // NhanVien20 nv20;
    // nhapNhanVien20(nv20);
    // inNhanVien20(nv20);

    // Example of calling PhanSo21 (for toiGian, from b_21.cpp):
    // PhanSo21 ps21;
    // ps21.nhap();
    // ps21.toiGian();
    // ps21.in();

    // Example of calling PhanSo22 (for cong, from b_22.cpp):
    // PhanSo22 p22, q22;
    // p22.nhap();
    // q22.nhap();
    // PhanSo22 tong22 = p22.cong(q22);
    // tong22.in();
    
    // SaoChepTepTin(); // This function interacts with files, ensure PTIT.in.txt exists
    // QuayMaTran();
    // BienDoiDaySo();
    // CuaSoTruot();
    // DoiSoChuSo();
    // TongSoTrongXau();
    // TachChuSo();
    // HopGiaoCuaHaiDay1();
    // GiaoCuaDaySo2();
    // SapXepXenKe();

    // Example of calling SinhVien33 functions (from b_33.cpp):
    // XuLyDanhSachSinhVien33();

    // Example of calling NhanVien34 functions (from b_34.cpp):
    // XuLyDanhSachNhanVien34();

    // Example of calling SinhVien35 functions (from b_35.cpp):
    // int N35; cin >> N35;
    // vector<SinhVien35> ds35;
    // nhapSinhVien35(ds35, N35);
    // inSinhVien35(ds35);

    // Example of calling SinhVien36 functions (from b_36.cpp):
    // int N36; cin >> N36;
    // vector<SinhVien36> ds36;
    // nhapSinhVien36(ds36, N36);
    // sapXepGPA36(ds36);
    // inSinhVien36(ds36);

    // Example of calling NhanVien37 functions (from b_37.cpp):
    // int N37; cin >> N37;
    // cin.ignore();
    // vector<NhanVien37> ds37;
    // nhapNhanVien37(ds37, N37);
    // sapXepTheoNgaySinh37(ds37);
    // inNhanVien37(ds37);

    // Example of calling SinhVien38 functions (from b_38.cpp):
    // int N38; cin >> N38;
    // cin.ignore();
    // vector<SinhVien38> ds38;
    // nhapSinhVien38(ds38, N38);
    // sapXepTheoMaSV38(ds38);
    // inDanhSach38(ds38);

    // Example of calling SinhVien39 functions (from b_39.cpp):
    // int N39; cin >> N39;
    // cin.ignore();
    // vector<SinhVien39> ds39;
    // nhapSinhVien39(ds39, N39);
    // sapXepTheoHoTen39(ds39);
    // inDanhSach39(ds39);

    // Example of calling Nguoi40 functions (from b_40.cpp):
    // int N40; cin >> N40;
    // vector<Nguoi40> ds40;
    // nhapDanhSach40(ds40, N40);
    // pair<string, string> res40 = timTreVaGia40(ds40);
    // cout << res40.first << "\n" << res40.second << "\n";

    // Example of calling NhanVien41 functions (from b_41.cpp):
    // XuLyNhanVien41();

    // Example of calling SinhVien42 functions (from b_42.cpp):
    // XuLySapXepSinhVien42();

    // Example of calling SinhVien43 functions (from b_43.cpp):
    // XuLySapXepSinhVien43(); // Note: This expects input until EOF or empty line

    // Example of calling SinhVien44 functions (from b_44.cpp):
    // XuLyLietKeSinhVien44();

    // Example of calling GiangVien45 functions (from b_45.cpp):
    // XuLyTimKiemGiangVien45();

    // Example of calling DoanhNghiep46 functions (from b_46.cpp):
    // XuLyDoanhNghiep46();

    // Example of calling LoaiBo100 functions (from b_47.cpp):
    // XuLyLoaiBo100();

    // Example of calling SoKhacNhauTrongFile functions (from b_48.cpp):
    // XuLySoKhacNhauTrongFile(); // Requires DATA.in.txt

    // Example of calling LietKeTuKhacNhauTrongFile functions (from b_49.cpp):
    // XuLyLietKeTuKhacNhauTrongFile(); // Requires VANBAN.in.txt

    // Example of calling HopGiaoHaiFileVanBan functions (from b_50.cpp):
    // XuLyHopGiaoHaiFileVanBan(); // Requires DATA1.in.txt and DATA2.in.txt

    return 0;
}
