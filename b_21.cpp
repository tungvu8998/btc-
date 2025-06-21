#include <iostream>

using namespace std;

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
//
class PhanSo {
private:
    ll tu;
    ll mau;

public:
    PhanSo(ll t = 0, ll m = 1) {
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
int main() {
	PhanSo ps;
    ps.nhap();
    ps.toiGian();
    ps.in();
	return 0;
}
