#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<map>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

int INF = 1000000000;

int n, k, a, b;
vector<int> ave;

typedef pair<ll, ll> pll;
map<pll, ll> mp;

ll countave(int be, int en) {
    vector<int>::iterator it1 = lower_bound(ave.begin(), ave.end(), be);
    vector<int>::iterator it2 = lower_bound(ave.begin(), ave.end(), en);

    return it2-it1;
}

ll dfs(int be, int en) {
    auto itr = mp.find(pll(be, en));
    if (itr != mp.end()) return mp[pll(be, en)];

    ll avenum = countave(be, en);
    
    ll cor;
    if (avenum==0) {
        return a;
    } else {
        cor = b * avenum * (en-be);
    }
    
    if (en-be == 1) return cor;
    return mp[pll(be, en)] = min(cor, dfs(be, (be+en)/2) + dfs((be+en)/2, en));
}

ll pow2ll(int n) {
    if (n==0) return 1;
    ll half = pow2ll(n/2);
    if (n%2 == 0) {
        return half*half;
    } else {
        return half*half*2;
    }
}

int main(){
    cin >> n >> k >> a >> b;
    REP(i, k) {
        int posi;
        cin >> posi;
        ave.push_back(posi-1);
    }
    
    sort(ave.begin(), ave.end());
    cout << dfs(0, pow2ll(n)) << endl;
}
