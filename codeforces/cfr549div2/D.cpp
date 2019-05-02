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

ll n, k;
ll a, b;

ll gcd(ll a, ll b) {
    if (a>b) return gcd(b, a);
    if (a==0) return b;
    return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

int main(){
    cin >> n >> k;
    cin >> a >> b;

    ll maxoutput = 0;
    ll minoutput = 1e18;

    ll fs[2];
    REP(i, n) {
        fs[0] = i*k + b;
        fs[1] = i*k - b;
        REP(j, 2) {
            ll f = fs[j];
            if (f==a || f==(-a)) minoutput = 1;
            if (f > a && f-a < n*k) {
                ll l = f-a;
                maxoutput = max(lcm(n*k, l)/l, maxoutput);
                minoutput = min(lcm(n*k, l)/l, minoutput);
            }
            if (f > (-a) && f+a < n*k) {
                ll l = f+a;
                maxoutput = max(lcm(n*k, l)/l, maxoutput);
                minoutput = min(lcm(n*k, l)/l, minoutput);
            }
        }
    }
    cout << minoutput << " " << maxoutput << endl;
}
