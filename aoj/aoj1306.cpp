#include<iostream>
#include<cstdlib>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int n;
int p[40];
int t[40];
int dp[40][3];
bool allinf;

int main(){
    while(1){
        cin >> n;
        if(n==0) break;

        REP(i, n){
            cin >> p[i];
            cin >> t[i];
        }

        REP(i, n){
            REP(j, 3){
                dp[i][j] = INF;
            }
        }

        if(t[0]>=p[0]){
            dp[0][0] = p[0];
        } else {
            cout << "NG 1" << endl;
            continue;
        }

        REP(i, n-1){
            REP(j, 3){
                if(j==0){
                    REP(k, 3){
                        int time = t[i];
                        time += p[i]*(k+2) + p[i+1];
                        if(time<=t[i+1]){
                            dp[i+1][0] = min(dp[i+1][0], dp[i][k]+p[i]+p[i+1]);
                        }
                    }
                } else {
                    int time = t[i];
                    time += abs(p[i]-p[i+1])*(j+1);
                    if(time<=t[i+1]){
                        dp[i+1][j] = min(dp[i+1][j], dp[i][j-1]+abs(p[i]-p[i+1]));
                    }
                }
            }

            allinf = true;
            REP(j, 3){
                if(dp[i+1][j]<INF){
                    allinf = false;
                }
            }
            if(allinf){
                cout << "NG " << i+2 << endl;
                break;
            }
        }

        if(!allinf){
            int output = INF;
            REP(i, 3){
                output = min(dp[n-1][i], output);
            }
            output += p[n-1];
            cout << "OK " << output << endl;
        }
    }
}
