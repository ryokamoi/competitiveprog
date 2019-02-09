#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int c[100000];
int oddc, evenc;

int main(){
    cin >> n;

    REP(i, 100000) c[i] = 0;

    REP(i, n){
        int a;
        cin >> a;
        c[a] += 1;
    }

    oddc = 0; evenc = 0;
    REP(i, 100000){
        if(c[i] !=0 && c[i]%2==0){
            evenc += 1;
        } else if (c[i]%2 == 1){
            oddc += 1;
        }
    }

    evenc = (evenc/2) * 2;
    cout << evenc + oddc << endl;

}
