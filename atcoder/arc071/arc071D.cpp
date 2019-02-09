#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll r = 1000000007;
int xn, ym;
ll h, w, s;
ll x[100000], y[100000];
ll as[100000];
ll wminus[100000], hminus[100000];

ll sums;
ll summinus;

int main(){
    cin >> xn >> ym;
    REP(i, xn) cin >> x[i];
    REP(i, ym) cin >> y[i];

    h = y[ym-1] - y[0];
    w = x[xn-1] - x[0];
    s = (h%r * w%r)%r;
    
    REP(i, max(xn, ym)){
        if(i==0){
            as[i] = 0;
        } else {
            as[i] = (as[i-1] + i) % r;
        }
    }

    sums = as[xn-1]*as[ym-1] * s;
    sums = sums % r;

    summinus = 0;
    REP(i, xn-1){
        wminus[i] = ((as[xn-2] + as[i]))%r * as[ym-1];
        wminus[i] = wminus[i]%r;
        summinus = wminus[i] * (x[i+1]-x[i]) * h;
        summinus = summinus % r;
    }
    REP(i, ym-1){
        hminus[i] = ((as[ym-2] + as[i]))%r * as[xn-1];
        hminus[i] = hminus[i]%r;
        summinus = hminus[i] * (y[i+1]-y[i]) * w;
        summinus = summinus % r;
    }

    if(sums<summinus){
        sums += r;
    }
    cout << sums-summinus << endl;
}
