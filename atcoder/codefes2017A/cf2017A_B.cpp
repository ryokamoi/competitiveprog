#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

bool able[1000001];
int n, m, k;

int main(){
    cin >> n >> m >> k;
    REP(i, n*m+1) able[i] = false;

    REP(i, n+1){
        REP(j, m+1){
            able[(i)*(j) + (n-i)*(m-j)] = true;
        }
    }

    if(able[k]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
