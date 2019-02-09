#include<iostream>
 
using namespace std;
 
#define REP(i, n) for(int i=0; i<n; i++)
 
int n;
int p[100];
bool dp[10001];
 
int main(){
    cin >> n;
    REP(i, n) cin >> p[i];
 
    REP(i, 10001) dp[i] = false;
    dp[0] = true;
    REP(j, n){
        for(int i=10000; i>0; i--){
            if(i-p[j]>=0 && dp[i-p[j]]){
                dp[i] = true;
            }
        }
    }
 
    int output = 0;
    REP(i, 10001){
        if(dp[i]) output += 1;
    }
    cout << output << endl;
}
