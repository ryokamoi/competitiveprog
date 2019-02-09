#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, d, x;
int p[10][10];
int dp[10][100001];

int main(){
    cin >> n >> d >> x;
    REP(i, d){
        REP(j, n){
            cin >> p[i][j];
        }
    }

    int tmp_max = x;

    REP(i, d-1){
        REP(k, tmp_max + 1) dp[i+1][k] = k;
        REP(j, n){
            REP(k, tmp_max + 1){
                if(k-p[i][j]>=0){
                    dp[i+1][k] = max(dp[i+1][k], dp[i+1][k-p[i][j]] + p[i+1][j]);
                }
            }
        }
        int c = tmp_max;
        REP(k, c+1){
            tmp_max = max(tmp_max, dp[i+1][k]);
        }
    }
    cout << tmp_max << endl;
}
