#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
long long c[100][100];

int main(){
    cin >> n;

    REP(i, n){
        REP(j, n){
            cin >> c[i][j];
        }
    }

    long long cost = 0;
    REP(i, n){
        for(int j=i+1; j<n; j++){
            cost += min(c[i][j], c[j][i]);
        }
    }

    cout << cost << endl;
}
