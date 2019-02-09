#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int n;
ll a[300][300];
bool need[300][300];

int main(){
    cin >> n;
    REP(i, n){
        REP(j, n){
            cin >> a[i][j];
        }
    }

    REP(i, n) REP(j, n) need[i][j] = true;

    bool flag = true;
    REP(k, n){
        REP(i, n){
            REP(j, n){
                if(i==k || j==k) continue;
                if(a[i][j] > a[i][k] + a[k][j]){
                    flag = false; break;
                }
                if(a[i][j] == a[i][k] + a[k][j]){
                    need[i][j] = false;
                }
            }
            if(!flag) break;
        }
        if(!flag) break;
    }

    if(!flag){
        cout << -1 << endl;
    } else {
        ll output = 0;
        REP(i, n){
            for(int j=0; j<i; j++){
                if(need[i][j]) output += a[i][j];
            }
        }
        cout << output << endl;
    }

}
