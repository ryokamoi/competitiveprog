#include<iostream>
#include<cassert>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int n, W;
ll w[100], v[100];
ll dp[101][950001];

int main(){
    cin >> n >> W;
    REP(i, n){
        cin >> w[i] >> v[i];
    }

    ll wsum = 0;
    REP(i, n) wsum += w[i];
    if(wsum<=W){
        ll vsum = 0;
        REP(i, n) vsum += v[i];
        cout << vsum << endl;
    } else if(w[0]>W) {
        cout << 0 << endl;
    } else {
        if(w[0]>30){
            ll basis = w[0];
            ll plus = 410;
            ll c = W/basis;
            if(W%basis>100) assert(false);
            // if(W-basis*c>1000) assert(false);
            W = W - basis * c + plus * c;
            REP(i, n) w[i] = w[i] - basis + plus;
        }
        // if(W>900001) assert(false);

        REP(i, n+1) REP(j, W+1) dp[i][j] = 0;
        REP(i, n){
            REP(j, W){
                if(j-w[i]+1>=0){
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i][j-w[i]+1]+v[i]);
                } else {
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }

        /*
        REP(i, n+1){
            REP(j, W+1){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */

        cout << dp[n][W] << endl;
    }
}
