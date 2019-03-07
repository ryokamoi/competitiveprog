#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int h[1000];

int main(){
    cin >> n;
    REP(i, n) {
        cin >> h[i];
    }
    
    int output = 0;
    bool finish = false;
    while(!finish) {
        finish = true;
        bool watering = false;
        REP(i, n) {
            if (!watering && h[i]>0) {
                output ++;
                watering = true;
                finish = false;
            }

            if(h[i]>0) {
                h[i]--;
                continue;
            }

            if (watering && h[i] == 0) {
                watering = false;
            }
        }
    }
    cout << output << endl;
}
