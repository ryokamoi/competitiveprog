#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll r = 1000000007;
ll n;
ll a[100000];
ll c[100001];

ll pow2(ll x, ll num){
    if(num==0) return 1;

    ll res = pow2(x*x%r, num/2);
    if(num%2==1) res = res*x%r;

    return res;
}

int main(){
    cin >> n;

    REP(i, n+1) c[i] = 0;
    REP(i, n){
        ll a;
        cin >> a;
        c[a] += 1;
    }

    bool flag = true;
    if(n % 2 == 1){
        if(c[0] != 1) flag = false;
        for(int i=2; i<=n; i++){
            if(i%2==0 && c[i]!=2){
                flag = false;
                break;
            }
        }
    } else {
        REP(i, n+1){
            if(i%2==1 && c[i]!=2){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout << pow2(2, n/2) << endl;
    } else {
        cout << 0 << endl;
    }
}
