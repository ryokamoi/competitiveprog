#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int s[100001];
int c[100000];
int n;

int main(){
    cin >> n;
    REP(i, 100001) s[i] = 0;
    REP(i, n){
        int l, r;
        cin >> l >> r;
        s[l-1] += 1;
        s[r] += -1;
    }

    int t = 0;
    REP(i, 100000){
        t += s[i];
        c[i] = t;
    }

    int output = 0;
    REP(i, 100000) output += c[i];
    cout << output << endl;
}
