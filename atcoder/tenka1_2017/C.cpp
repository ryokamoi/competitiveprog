#include<iostream>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int N;
int M, E;
int h, n, w;

vector<int> divisor;
vector<int> dp[4][14001];

int main(){
    cin >> N;

    for(int i=3500; i>=0; i--){
        if(i%N == 0){
            M = i; break;
        }
    }
    
    E = 4 * M/N;

    divisor = vector<int>();
    for(int i=1; i<=M; i++){
        if(M%i == 0){
            divisor.push_back(i);
        }
    }

    REP(i, 4){
        for(int j=E; j>=1; j--){
            dp[i][j] = vector<int>();
        }
    }

    vector<int> init;
    init.push_back(0);
    dp[0][0] = init;
    REP(i, 3){
        for(int j=E; j>=1; j--){
            REP(k, divisor.size()){
                if(j-divisor[k]>=0 && dp[i][j-divisor[k]].size()>0){
                    vector<int> e = dp[i][j-divisor[k]];
                    e.push_back(divisor[k]);
                    dp[i+1][j] = e;
                    break;
                }
            }
        }
    }

    cout << E << endl;
    cout << N << endl;
    h = M/dp[3][E][1];
    n = M/dp[3][E][2];
    w = M/dp[3][E][3];

    cout << h << " " << n << " " << w << endl;

}
