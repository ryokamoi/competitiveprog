// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

ll R = 1000000007;

ll n, x;
vector<ll> s;
int fact[201];
int dp[201][100010];

ll factfn(ll n) {
    if (n==0) return 1;
    return n*factfn(n-1);
}

ll nextind(int th) {
    REP(i, n) {
        if (s[i] > th) {
            return i;
        }
    }
    return n;
}

ll solve(ll n, ll x) {
    if (dp[n][x] > 0) return dp[n][x];
    if (n==0) return x%R;

    ll output = 0;
    REP(i, n) {
        ll th = x%s[i];
        ll nidx = nextind(th);
        output += solve(nidx, th) * (fact[n-nidx-1]%R);
        output %= R;
    }

    return dp[n][x] = output;
}

int main(){
    cin >> n >> x;
    REP(i, n) {
        ll si;
        cin >> si;
        s.push_back(si);
    }

    REP(i, 201){
        REP(j, 100001) {
            dp[i][j] = -1;
        }
    }
    REP(i, 201) fact[i] = factfn(i);

    sort(s.begin(), s.end());
    cout << solve(n, x) << endl;
}
