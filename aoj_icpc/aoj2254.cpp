#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int t[16][17];
int dp[1 << 16];
int INF = 10e8;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        REP(i, n){
            REP(j, n+1){
                int ct;
                cin >> ct;
                t[i][j] = ct;
            }
        }

        REP(i, 1 << n){
            dp[i] = INF;
        }
        dp[0] = 0;

        REP(i, 1 << n){
            REP(j, n){
                if((i>>j) & 1) continue;
                int tmpmin = t[j][0];
                REP(k, n){
                    if((i>>k) & 1){
                        tmpmin = min(tmpmin, t[j][k+1]);
                    }
                }
                dp[i|1<<j] = min(dp[i|1<<j], dp[i] + tmpmin);
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
}
