// Ryo Kamoi
// #define DEBUG

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

pii dp[33][33][33][33]; // num of groups, yobi

int h, w, s;
int min_pow;
int field[33][33];

pii pii_sum(pii a, pii b) {
    if (a.second >= 0 && b.second >= 0) {
        return pii(a.first+b.first, min(a.second, b.second));
    }
    if (a.first == 1 && b.first == 1) {
        return pii(1, min_pow + a.second + b.second);
    }
    return pii(-INF, -INF);
}

pii solve(int u, int d, int l, int r) {
    if (dp[u][d][l][r].first > 0) {
        return dp[u][d][l][r];
    }

    if (u==d && l==r) {
        return dp[u][d][l][r] = pii(1, field[u][l]-min_pow);
    }
    
    pii output = pii(-INF, -INF);
    for (int i=u; i<d; i++) {
        output = max(output, pii_sum(solve(u, i, l, r),
                    solve(i+1, d, l, r)));
    }
    for (int i=l; i<r; i++) {
        output = max(output, pii_sum(solve(u, d, l, i),
                    solve(u, d, i+1, r)));
    }
#ifdef DEBUG
    cout << u << " " << d << " " << l << " " << r << endl;
    cout << output.first << " " << output.second << endl;
#endif
    return dp[u][d][l][r] = output;
}

int main(){
    while(1) {
        cin >> h >> w >> s;
        if (h==0) break;

        // initialize dp
        REP(i, h) {
            for (int j=i; j<h; j++) {
                REP(k, w) {
                    for (int l=k; l<w; l++) {
                        dp[i][j][k][l] = pii(0, 0);
                    }
                }
            }
        }

        int sum_supply = 0;
        REP(i, h) {
            REP(j, w) {
                cin >> field[i][j];
                sum_supply += field[i][j];
            }
        }
        min_pow = sum_supply - s;
#ifdef DEBUG
        cout << min_pow << endl;
#endif

        pii p = solve(0, h-1, 0, w-1);
        cout << p.first << ' ' << p.second << endl;
    }
}
