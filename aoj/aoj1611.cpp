#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int w[400];
int dp[400][400];

// the maximum number of block can be removed
int cnt(int b, int t) {
    if (dp[b][t] >= 0) return dp[b][t];

    if (abs(w[t]-w[b])<=1 && cnt(b+1, t-1) == t-(b-1)-2) {
        return dp[b][t] = t-(b-1);
    }

    int output = 0;
    for(int i=b; i<=t-1; i++) {
        output = max(output, cnt(b, i)+cnt(i+1, t));
    }
    return dp[b][t] = output;
}

int main() {
    while(true) {
        cin >> n;
        if (n==0) break;

        REP(i, n) {
            cin >> w[i];
        }

        REP(i, n) {
            REP(j, n) {
                if (i==j) {
                    dp[i][j] = 0;
                } else if (j-i == 1){
                    if (abs(w[i] - w[j]) <= 1) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    dp[i][j] = -1;
                }
            }
        }

        cout << cnt(0, n-1) << endl;
    }
}
