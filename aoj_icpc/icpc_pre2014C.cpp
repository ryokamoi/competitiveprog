#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

double INF = 10e8;
int plus20[40];
int maxh[21];

int main(){
    while(1){
        double r;
        int n;
        cin >> r >> n;

        if(r==0) break;

        REP(i, 40) plus20[i] = 0;
        REP(i, n){
            int xr, xl;
            double h;
            cin >> xr >> xl >> h;
            for(int j = xr+20; j < xl+20; j++){
                plus20[j] = max((double)plus20[j], h);
            }
        }

        REP(i, 21) maxh[i] = 0;
        REP(i, r+1){
            if(i==r){
                maxh[i] = 0;
            } else {
                double ph = min(plus20[20+i], plus20[20+i-1]);
                double nh = min(plus20[20-i], plus20[20-i-1]);
                maxh[i] = min(ph, nh);
            }
        }

        double output = INF;
        REP(i, r){
            output = min(output, r - sqrt(pow(r, 2)-pow(i, 2)) + maxh[i]);
        }

        cout << fixed << setprecision(4) << output << endl;
    }
}
