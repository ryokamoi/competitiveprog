#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

const int max_n = 10e5;
int i2rl[max_n+1];
int rc2i[max_n+1];
int lc2i[max_n+1];
int rsum;
int lsum;
int i2c[max_n+1][2];

int n;
int panel[max_n];

int main(){
    cin >> n;

    int rsum = 0;
    int lsum = 0;
    string arrows;
    cin >> arrows;
    REP(i, n){
        char arrow;
        arrow = arrows[i];
        if(arrow == '>'){
            rsum += 1;
            rc2i[rsum] = i; // count -> idx
            i2rl[i] = 0; // idx -> rl;
        } else {
            lsum += 1;
            lc2i[lsum] = i;
            i2rl[i] = 1;
        }
        i2c[i][0] = rsum;
        i2c[i][1] = lsum;
    }

    int rcount = 0;
    int lcount = lsum;
    REP(i, n){
        if(i2rl[i] == 0){
            rcount += 1;
            if(rcount <= lcount){
                panel[i] = lc2i[i2c[i][1]+rcount] + 1;
            } else {
                panel[i] = n - rc2i[rcount-lcount];
            }
        } else {
            if(lcount <= rcount){
                panel[i] = n - rc2i[i2c[i][0] - lcount + 1];
            } else {
                panel[i] = lc2i[i2c[i][1]+rcount] + 1;
            }
            lcount -= 1;
        }
    }

    int output = 0;
    REP(i, n){
        // cout << panel[i] << " "; //
        output = max(output, panel[i]);
    }
    // cout << endl; //
    
    cout << output << endl;
}
