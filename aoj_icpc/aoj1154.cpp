#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    while(1){
        int n, m, K;
        cin >> n >> m >> K;
        if(n==0){
            break;
        }

        ll dp[n+1][m*n+1];
        REP(i, n+1){
            REP(j, m*n+1){
                dp[i][j] = 0;
            }
        }

        dp[0][0] = 1;
        REP(i, n){
            REP(j, m*(i+1)){
                int k;
                if(j>=m){
                    k = m;
                } else {
                    k = j+1;
                }

                ll s = 0;
                REP(l, k){
                    s += dp[i][j-l];
                }
                dp[i+1][j+1] = s;
            }
        }

        ll sum[n*m+1];
        REP(i, n*m){
            sum[i+1] = 0;
        }

        REP(i, n*m){
            if(i+1<=K){
                sum[1] += dp[n][i+1];
            } else {
                sum[i+1-K] += dp[n][i+1];
            }
        }

        /*
        REP(i, n*m){
            cout << sum[i+1] << " ";
        }
        cout << endl;
        */

        ll d = pow(m, n);
        double exp = 0;
        REP(i, n*m){
            exp += double(sum[i+1]) * (i+1) / d;
        }

        cout << fixed << setprecision(8) << exp << endl;
    }
}
