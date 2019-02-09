#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long
typedef pair<ll, ll> pll;

ll n;
priority_queue<pll> que;
ll c[10000];

int main(){
    cin >> n;
    REP(i, n){
        ll a;
        cin >> a;
        que.push(pll(-a, i+1));
    }

    REP(i, n) c[i] = 0;
    while(!que.empty()){
        pll p = que.top(); que.pop();
        c[p.second-1] += 1;

        if(p.first+1<0) que.push(pll(p.first+1, p.second));
    }

    REP(i, n) cout << c[i] << endl;
}
