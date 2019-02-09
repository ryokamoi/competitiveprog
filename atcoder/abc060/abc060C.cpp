#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll N, T;
ll t[200000];

ll s, e;
ll tsum;

int main(){
    cin >> N >> T;
    REP(i, N){
        cin >> t[i];
    }

    s = t[0];
    e = t[0]+T;
    tsum = 0;
    REP(i, N){
        if(e>=t[i]) {
            e = t[i] + T;
        } else {
            tsum += e-s;
            s = t[i];
            e = t[i] + T;
        }
    }
    tsum += e-s;

    cout << tsum << endl;
}
