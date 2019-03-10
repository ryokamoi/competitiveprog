#define DEBUG

#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

ll length, n;
ll x[200010];
ll dp[3000][3000][2];

ll dist(int r, int l) {
    if (l > r){
        return length - x[l] + x[r];
    } else {
        return x[r] - x[l];
    }
}

ll solve(int r, int l, int c) {
    int bc;
    if (r-c == 1) {
        bc = 0;
    } else {
        bc = 1;
    }

    if (dp[l][r][bc] >= 0) return dp[l][r][bc];

    if (l-r == 1) {
        ll output = 0;
        output = max(output,
                dist(c, l) + dist(r, l));
        output = max(output,
                dist(r, c) + dist(r, l));
        output = max(output,
                length - dist(c, l));
        output = max(output,
                length - dist(l, c));
        return output;
    }

    return dp[l][r][bc] = max(solve(r, l-1, l) + dist(c, l),
                solve(r+1, l, r) + dist(r, c));
}

int main(){
    cin >> length >> n;

    x[0] = 0;
    REP(i, n) {
        cin >> x[i+1];
    }

    REP(i, n+1) {
        REP(j, n+1) {
            REP(k, 2) {
                dp[i][j][k] = -1;
            }
        }
    }

    cout << solve(1, n, 0) << endl;
}
