#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll gcd(ll a, ll b){
    if (a>b){
        return gcd(b, a);
    }

    ll r = b%a;
    if (r==0){
        return a;
    } else {
        return gcd(r, a);
    }
}

int main(){
    int n;
    cin >> n;

    ll num[3500];
    ll l = 1;
    REP(i, n){
        cin >> num[i];
        ll g = gcd(l, num[i]);

        l = l*num[i]/g;
    }

    ll ans = 0;
    REP(j, n){
        ans += (l-1) % num[j];
    }

    cout << ans << endl;
}
