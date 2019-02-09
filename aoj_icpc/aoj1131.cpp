#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int p, q, a, n;
vector<vector<int> > dp[8][12001];
int s;
vector<int> d;

int main(){
    while(1){
        cin >> p >> q >> a >> n;
        if(p==0) break;

        int s = p * ceil((double)a / q);
        int c = s * q / p;

        cout << s << endl;

        d.clear();
        REP(i, c/2+1){
            if(i>=1 && c%i==0) d.push_back(i);
        }
        d.push_back(c);

        /*
        REP(i, d.size()){
            cout << d[i] << " ";
        }
        cout << endl;
        */

        REP(i, n) REP(j, s+1) dp[i][j].clear();
        REP(i, d.size()){
            vector<int> init;
            init.push_back(d[i]);
            dp[1][d[i]].push_back(init);
        }

        for(int i=2; i<=n; i++){
            REP(j, s+1){
                REP(k, d.size()){
                    if(j-d[k]>0){
                        REP(l, dp[i-1][j-d[k]].size()){
                            if(dp[i-1][j-d[k]][l].back()<=d[k]){
                                vector<int> nd = dp[i-1][j-d[k]][l];
                                nd.push_back(d[k]);
                                dp[i][j].push_back(nd);
                            }
                        }
                    }
                }
            }
        }

        /*
        REP(i, dp[n][s].size()){
            REP(j, dp[n][s][i].size()){
                cout << dp[n][s][i][j] << " ";
            }
            cout << endl;
        }
        */

        int count = 0;
        REP(i, n+1){
            REP(j, dp[i][s].size()){
                int pro = 1;
                REP(k, dp[i][s][j].size()){
                    pro *= c/dp[i][s][j][k];
                }
                if(pro<=a) count += 1;
            }
        }

        cout << count << endl;
    }
}
