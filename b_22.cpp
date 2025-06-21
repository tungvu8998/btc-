#include <iostream>

using namespace std;

// === Bai 22:  tinh tong tuong doi 2 phan so
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
    PhanSo cong(const PhanSo& other) {
        ll t = tu * other.mau + mau * other.tu;
        ll m = mau * other.mau;
        PhanSo res(t, m);
        res.toiGian();
        return res;
    }

    void in() {
        cout << tu << "/" << mau << "\n";
    }
};

int main() {
	PhanSo p, q;
    p.nhap();
    q.nhap();

    PhanSo tong = p.cong(q);
    tong.in();

	return 0;
}
