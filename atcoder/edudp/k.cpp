#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int dp[100010];
int a[110];

int main() {
    int n, k;
    cin >> n >> k;

    REP(i, n) {
        cin >> a[i];
    }

    REP(i, k+1) {
        dp[i] = 0;
    }

    REP(i, k) {
        if (i < a[0]) {
            dp[i] = -1;
        }

        REP(j, n) {
            if (i+a[j] > k) continue;
            if (dp[i+a[j]] != 1) {
                dp[i+a[j]] = -dp[i];
            }
        }
    }

    if(dp[k] == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
