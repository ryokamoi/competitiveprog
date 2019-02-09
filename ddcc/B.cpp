#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll unsigned long long

ll n, z;
ll a[200002];
ll d[200002];
ll ans;

ll gcd(ll a, ll b){
    ll c;

    if (a < b) {
            a+=b; b=a-b; a-=b;
        }

    while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }

    return a;
}

ll lcm(ll m, ll n){
    return ((m / gcd(m, n)) * n);
}

int main(){
    cin >> n >> z;
    REP(i, n){
        cin >> a[i];
        d[i] = gcd(a[i], z);
    }

    ans = 1;
    REP(i, n){
        ans = lcm(ans, d[i]);
    }
    cout << ans << endl;
}
