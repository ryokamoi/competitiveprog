#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

bool prime[1100000];
int mazen[1100][1100];
int dp[1100][1100];
int n, m;
int num;
int hen;
bool flag;
int jx, iy;
int si, sj;

void makemaze(int x, int y){
    REP(i, hen) {
        num++;
        if (num > n) {
            flag = false; break;
        }

        iy += y;
        jx += x;
        mazen[iy][jx] = num;
        if (num == m) {si = iy; sj = jx;}
    }
}

int main() {
    REP(i, 1100000) prime[i] = true;
    prime[0] = false; prime[1] = false;
    for(int i=2; i<1100000; i++) {
        if (prime[i]) {
            for(int j=2; j<1100000/i; j++) {
                prime[i*j] = false;
            }
        }
    }

    while(true) {
        cin >> n >> m;
        if (n==0) break;

        int sq;
        REP(i, 1100) {
            if ((2*i+1)*(2*i+1) >= n) {
                sq = 2*i+1; break;
            }
        }

        // initial index
        jx = (sq+1)/2 - 1;
        iy = jx;

        REP(i, sq+3) {
            REP(j, sq+3) {
                dp[i][j] = -1;
                mazen[i][j] = -1;
            }
        }

        mazen[iy][jx] = 1;
        if (m==1) {
            si = iy; sj = jx;
        }

        hen = 1;
        num = 1;
        flag = true;
        int x1, y1, x2, y2;
        while(flag) {
            if (hen % 2 == 1) {
                x1=1; y1=0;
                x2=0; y2=-1;
            } else {
                x1=-1; y1=0;
                x2=0; y2=1;
            }
            
            makemaze(x1, y1);
            makemaze(x2, y2);
            hen++;
        }

        dp[si][sj] = 0;
        int output = 0;
        int last;
        if (prime[mazen[si][sj]]) {
            dp[si][sj]++;
            output = 1;
            last = mazen[si][sj];
        }
        
        for(int i=si; i<sq; i++) {
            REP(j, sq) {
                if (dp[i][j]<0 || mazen[i][j]<0) continue;
                REP(k, 3) {
                    int mv = k-1;
                    if (j+mv < 0 || mazen[i+1][j+mv]<0) continue;

                    dp[i+1][j+mv] = max(dp[i+1][j+mv], dp[i][j]);
                }
            }

            REP(j, sq) {
                if (dp[i+1][j] >= 0 && prime[mazen[i+1][j]]) {
                    dp[i+1][j]++;

                    // output
                    if (dp[i+1][j] > output) {
                        last = mazen[i+1][j];
                        output = dp[i+1][j];
                    }
                    if (dp[i+1][j] == output) {
                        last = max(last, mazen[i+1][j]);
                    }
                }
            }
        }

        if (output == 0) {
             cout << "0 0" << endl;
        } else {
             cout << output << " " << last << endl;
        }
    }
}

