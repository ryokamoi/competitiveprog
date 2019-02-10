#include <iostream>
#include <iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int N;
int count[3];

double dp[310][310][310];

double expec(int c[]) {
    double rsum = 0.0;
    REP(i, 3) {
        if (c[i] > 0) {
            int ic[3] = {c[0], c[1], c[2]};
            ic[i] -= 1;
            if (i>=1) ic[i-1] += 1;

            if (dp[ic[0]][ic[1]][ic[2]] < 0) {
                dp[ic[0]][ic[1]][ic[2]] = expec(ic);
            }
            rsum += dp[ic[0]][ic[1]][ic[2]] * (double) c[i];
        }
    }

    return ((double) N + rsum) / (double) (c[0]+c[1]+c[2]);
}

int main() {
    cin >> N;

    REP(i, 3) {
        count[i] = 0;
    }

    REP(i, N) {
        int a;
        cin >> a;
        count[a-1] += 1;
    }

    REP(i, N+1) {
        REP(j, N+1) {
            REP(k, N+1) {
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = 0;

    cout << fixed << setprecision(10) << expec(count) << endl;
}
