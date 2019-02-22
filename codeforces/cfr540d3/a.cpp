#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

int main() {
    int q;
    cin >> q;

    REP(i, q) {
        ll n, a, b;
        cin >> n >> a >> b;
        if (2*a <= b) {
            cout << a*n << endl;
        } else {
            cout << b*(n/2) + (n%2)*a << endl;
        }
    }
}
