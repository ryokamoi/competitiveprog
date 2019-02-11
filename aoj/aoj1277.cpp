#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

int next_idx(int max_n, int cor, int dice){
    int output;
    if(cor+dice <= max_n){
         output = cor+dice;
     } else {
         output = max_n - (cor+dice-max_n);
     }
     return output;
}

int main(){
    while(1){
        int N, T, L, B;
        int MAX_N = 100, MAX_T = 100;

        int l[MAX_N];
        int b[MAX_N];

        double dp[MAX_T+1][MAX_N+1];
        int map[MAX_N+1];

        cin >> N >> T >> L >> B;

        if (N==0) break;

        for(int i=0; i<L; ++i){
            cin >> l[i];
        }
        for(int i=0; i<B; ++i){
            cin >> b[i];
        }

        for(int i=0; i<=MAX_N; ++i){
            map[i] = 0;
        }
        for(int i=0; i<L; ++i){
            map[l[i]] = 1;
        }
        for(int i=0; i<B; ++i){
            map[b[i]] = 2;
        }

        for(int i=0; i<=MAX_T; ++i){
            for(int j=0; j<=MAX_N; ++j){
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        for(int i=0; i<T; ++i){
            dp[i+1][N] += dp[i][N];
            for(int j=0; j<N; ++j){
                for(int k=1; k<=6; ++k){
                    int next = next_idx(N, j, k);
                    if(map[next] == 1 && i+2<=T){
                        dp[i+2][next] += dp[i][j]/6;
                    } else if(map[next] == 1 && i+1==T) {
                        dp[i+1][next] += dp[i][j]/6;
                    } else if(map[next]==2) {
                        dp[i+1][0] += dp[i][j]/6;
                    } else {
                        dp[i+1][next] += dp[i][j]/6;
                    }
                }
            }
        }

        cout << fixed << setprecision(6) << dp[T][N] << endl;
    }
}
