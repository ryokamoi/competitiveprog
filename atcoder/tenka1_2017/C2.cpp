#include<iostream>

using namespace std;

#define REP(i, nn) for(int i=0; i<nn; i++)
#define ll long long

ll N;
ll h, n, w;
int main(){
    cin >> N;

    bool flag = false;
    REP(i, 3501){
        REP(j, 3501){
            if(i==0 || j==0) continue;

            h = i;
            n = j;
            ll e = N*h*n;
            ll f = 4*h*n;
            ll wu = f - (N*n) - (N*h);
            if(wu>0 && e % wu == 0){
                w = e / wu;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    cout << h << " " << n << " " << w << endl;
}
