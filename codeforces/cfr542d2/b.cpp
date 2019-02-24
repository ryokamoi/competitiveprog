#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> pii;
typedef long long ll;

map<pii, ll> mp;
ll n;
vector<ll> idx[1000010];

ll dist(int sas, int dim, int cake) {
    if (mp.count(pii(sas, dim)) > 0) {
        return mp[pii(sas, dim)];
    }

    vector<ll> ids = idx[cake];
    int a1 = ids[0];
    int a2 = ids[1];

    if (cake==n) {
        return mp[pii(sas, dim)]=
            min(abs(sas-a1)+abs(dim-a2), abs(sas-a2)+abs(dim-a1));
    }

    ll ans1 = dist(a1, a2, cake+1) + abs(sas-a1) + abs(dim-a2);
    ll ans2 = dist(a2, a1, cake+1) + abs(sas-a2) + abs(dim-a1);
    return mp[pii(sas, dim)] = min(ans1, ans2);
}

int main() {
    cin >> n;
    REP(i, 2*n) {
        ll a;
        cin >> a;
        idx[a].push_back(i);
    }

    cout << dist(0, 0, 1) << endl;
}
