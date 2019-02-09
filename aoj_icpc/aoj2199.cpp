#include<iostream>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int sig[20001];
int code[16];
int dp[20001][256];

int cut(int i){
    if(i>=255){
        return 255;
    } else if(i<=0){
        return 0;
    } else {
        return i;
    }
}

int main(){
    while(1){
        int n, m;
        cin >> n >> m;
        if(n==0) break;

        REP(i, m){
            int c;
            cin >> c;
            code[i] = c;
        }

        REP(i, n){
            int s;
            cin >> s;
            sig[i+1] = s;
        }

        REP(i, n+1){
            REP(j, 256){
                dp[i][j] = INF;
            }
        }
        dp[0][128] = 0;

        REP(i, n){
            REP(j, 256){
                if(dp[i][j] != INF){
                    REP(k, m){
                        int tmpsig = cut(j+code[k]);
                        int sd = dp[i][j] + pow(tmpsig - sig[i+1], 2);
                        if(sd < dp[i+1][tmpsig]){
                            dp[i+1][tmpsig] = sd;
                        }
                    }
                }
            }
        }

        /*
        REP(i, 256){
            REP(j, n){
                cout << dp[j][i] << " ";
            }
            cout << endl;
        }
        */

        int output = INF;
        REP(i, 256){
            if(dp[n][i] < output){
                output = dp[n][i];
            }
        }
        cout << output << endl;
    }
}
