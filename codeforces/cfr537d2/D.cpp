#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<map>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

int INF = 1000000000;

map<char, ll> mp;
string inits;
int q;

ll r = 1000000007;

ll lfact(ll n) {
    return 1;
}

ll choose(ll n, ll m) {
    nfac = lfact(n);
    mfac = lfact(m);

}

ll countnum(ll x, ll y) {
    ll initsum = mp[x];
    if (x != y) initsum += mp[y];
    if (initsum > inits.size()/2) return 0;

    ll output = 0;
    output += choose(inits.size()/2, mp[x]);
    output %= r;
    if (x!=y) {
        output += choose(inits.size()/2-mp[x], mp[y]);
        output %= r;
    }

    ll res = inits.size() - initsum;
    for(auto kv=mp.begin(); kv!=mp.end(); ++kv) {
        char vil = kv->first;
        if (vil==x || vil==y) continue;

        output += choose(res, mp[vil]);
        res -= mp[vil];
    }

    return output;
}

int main(){
    cin >> inits;

    REP(i, inits.size()) {
        if (mp.find(inits[i]) != mp.end()) {
            mp[inits[i]] ++;
        } else {
            mp[inits[i]] = 1;
        }
    }

    cin >> q;
    REP(i, q) {
        ll x, y;
        cin >> x >> y;
        cout << countnum(inits[x-1], inits[y-1]) << endl;
    }
}
