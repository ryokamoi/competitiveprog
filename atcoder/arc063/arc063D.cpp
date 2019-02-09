#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll INF = 10e17;
ll n, t;
ll a[100000];

int main(){
    cin >> n >> t;
    REP(i, n) cin >> a[i];

    ll tmin = INF;
    ll p = 0;
    REP(i, n){
        tmin = min(tmin, a[i]);
        p = max(p, a[i] - tmin);
    }

    ll tmin2 = INF;
    ll c = 0;
    REP(i, n){
        tmin2 = min(tmin2, a[i]);
        if(a[i] - tmin2 == p){
            c += 1;
        }
    }
    cout << c << endl;
}
