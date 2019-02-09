#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
double r[500];
double dp[500];

double dis(double r1, double r2){
    return sqrt(pow(r1+r2, 2)-pow(r1-r2, 2));
}

int main(){
    cin >> n;

    REP(i, n){
        cin >> r[i];
    }

    int s = 0;
    double sd = 0;
    double tsd = 0;
    REP(i, n){
        if(i==0){
            sd = r[0];
            tsd = r[0];
        } else {
            if(dis(r[i-1], r[i])+tsd < r[i]){
                s = i;
                tsd = r[i];
                sd = r[i];
            } else {
                tsd = dis(r[i-1], r[i]) + tsd;
            }
        }
    }

    int g = n-1;
    double gd = 0;
    double tgd = 0;
    for(int i=n-1; i>=0; i--){
        if(i == n-1){
            gd = r[n-1];
            tgd = r[n-1];
        } else {
            if(dis(r[i+1], r[i])+tgd < r[i]){
                g = i;
                tgd = r[i];
                gd = r[i];
            } else {
                tgd = dis(r[i+1], r[i]) + tgd;
            }
        }
    }

    REP(i, g+1) dp[i] = 0;
    for(int i = s; i < g; i++){
        for(int j = s; j<=i; j++){
            if(dp[i+1] < dp[j] + dis(r[j], r[i+1])){
                dp[i+1] = dp[j] + dis(r[j], r[i+1]);
            }
        }
    }
    
    double output = sd + gd + dp[g];
    cout << fixed << setprecision(5) << output << endl;
}
