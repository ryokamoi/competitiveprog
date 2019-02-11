#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

string s;
ll dp[80000][11];

int main(){
    while(1){
        cin >> s;
        if(s=="0") break;

        REP(i, s.size()) REP(j, 11) dp[i][j] = 0;
        REP(i, s.size()){
            if(i%2==0){
                if(s[i]!='0') dp[i][(s[i]-'0')%11] = 1;
                if(i>0) REP(j, 11) dp[i][(j+(s[i]-'0'))%11] += dp[i-1][j];
            } else {
                if(s[i]!='0') dp[i][(11-(s[i]-'0'))%11] = 1;
                if(i>0) REP(j, 11) dp[i][(11+j-(s[i]-'0'))%11] += dp[i-1][j];
            }
        }
        
        ll output = 0;
        REP(i, s.size()) output += dp[i][0];
        cout << output << endl;
    }
}
