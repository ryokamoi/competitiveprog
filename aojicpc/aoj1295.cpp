#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int wh[21];
int dh[21];

int main(){
    while(1){
        int w, d;
        cin >> w >> d;

        if(w==0) break;

        REP(i, 21){
            wh[i] = 0;
            dh[i] = 0;
        }

        REP(i, w){
            int wi;
            cin >> wi;
            wh[wi] += 1;
        }
        REP(i, d){
            int di;
            cin >> di;
            dh[di] += 1;
        }

        REP(i, 21){
            dh[i] = max(0, dh[i]-wh[i]);
        }

        int output = 0;
        REP(i, 21){
            output += i*(dh[i] + wh[i]);
        }

        cout << output << endl;
    }
}
