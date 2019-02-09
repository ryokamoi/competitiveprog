#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll l, r, x, y, k;

int main(){
    cin >> l >> r >> x >> y >> k;

    bool flag = false;
    for(int i=x; i<=y; i++){
        if(i*k>=l && i*k<=r){
            flag = true; break;
        }
        if(i*k>r) break;
    }
    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

// why?
