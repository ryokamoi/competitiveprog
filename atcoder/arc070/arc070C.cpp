#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll x;

ll sum2n(ll n){
    return n*(n+1)/2;
}

int main(){
    cin >> x;

    ll lb = 0, ub = x;
    while(ub-lb > 1){
        int mid = (lb+ub)/2;

        if(sum2n(mid) >= x){
            ub = mid;
        } else {
            lb = mid;
        }
    }

    cout << ub << endl;
}
