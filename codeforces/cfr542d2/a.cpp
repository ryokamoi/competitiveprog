#include <iostream>
#include <cmath>
using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int zero, posi, neg;

int main() {
    cin >> n;
    zero = 0;
    posi = 0;
    neg = 0;
    REP(i, n) {
        int a;
        cin >> a;
        if (a==0) {
            zero ++;
        }
        if (a>0) {
            posi ++;
        }
        if (a<0) {
            neg ++;
        }
    }

    int size = ceil(double(n)/2);
    if (posi >= size) {
        cout << 1 << endl;
    } else if (neg >= size) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }
}
