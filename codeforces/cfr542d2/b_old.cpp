#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef long long ll;

ll n;
vector<ll> idx[1000010];

int main() {
    cin >> n;
    REP(i, 2*n) {
        ll a;
        cin >> a;
        idx[a].push_back(i);
    }

    ll output = 0;
    
    // first
    ll cor = 0;
    for(int i=1; i<=n; i++) {
        int si;
        ll dist = 1000000000;
        REP(j, 2) {
            if (dist > abs(cor - idx[i][j])) {
                dist = abs(cor - idx[i][j]);
                si = j;
            }
        }
        cor = idx[i][si];
        output += dist;
        idx[i].erase(idx[i].begin() + si);
    }

    //second
    cor = 0;
    for(int i=1; i<=n; i++) {
        output += abs(cor - idx[i][0]);
        cor = idx[i][0];
    }

    cout << output << endl;
}
