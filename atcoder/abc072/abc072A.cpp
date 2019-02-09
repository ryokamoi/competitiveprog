#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int main(){
    ll x, t;
    cin >> x >> t;
    x = max(0LL, x-t);
    cout <<x << endl;
}
