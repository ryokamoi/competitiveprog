#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, x;
ll a[100000];

int main(){
    cin >> n >> x;
    REP(i, n) cin >> a[i];

    ll c = 0;
    REP(i, n-1){
        ll tmp = a[i] + a[i+1];
        if(tmp >= x){
            if(a[i+1] >= tmp-x){
                a[i+1] -= (tmp-x);
            } else {
                a[i] -= (tmp-x-a[i+1]);
                a[i+1] = 0;
            }
            c += tmp-x;
        }
    }
    cout << c << endl;
}
