#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int a[100000];
int c[100001];

int main(){
    cin >> n;
    REP(i, n){
        cin >> a[i];
    }
    REP(i, 100001) c[i] = 0;

    REP(i, n){
        for(int j=max(0, a[i]-1); j<=min(100000, a[i]+1); j++){
            c[j] += 1;
        }
    }

    int output = 0;
    REP(i, 100001){
        output = max(output, c[i]);
    }
    cout << output << endl;
}
