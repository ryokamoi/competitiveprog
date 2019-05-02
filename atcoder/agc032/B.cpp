// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int vnum_odd(int n) {
    return (n*(n-1)) / 2 - n/2;
}

int n;
int m;
int main(){
    cin >> n;

    if (n%2==1) {
        m = vnum_odd(n);
    } else {
        m = vnum_odd(n-1) + n-2;
    }
    cout << m << endl;

    int add = 0;
    if (n%2==0) {
        add = 1;
        REP(i, n-2) {
            cout << "1 " << (i+2) << endl;
        }
    }

    // for odd
    REP(i, n-add) {
        for(int j=i+2; j<=(n-add); j++) {
            if (j == (n-add)-(i+1)) continue;
            cout << (i+1+add) << " " << (j+add) << endl;
        }
    }
}
