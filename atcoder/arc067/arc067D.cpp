#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, a, b;
ll x[100000];
ll f;

int main(){
    cin >> n >> a >> b;
    REP(i, n){
        cin >> x[i];
    }

    REP(i, n-1){
        f += min(a*(x[i+1]-x[i]), b);
    }
    cout << f << endl;
}
