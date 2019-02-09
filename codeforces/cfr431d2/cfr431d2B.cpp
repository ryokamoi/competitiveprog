#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int n;
ll y[1000];
bool used[1000];

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> n;
    REP(i, n){
        cin >> y[i];
    }

    bool flag = false;
    REP(i, 2){
        REP(j, n){
            REP(k, n) used[k] = false;
            if(i==j) continue;
            ll c = gcd(y[j]-y[i], j-i);
            ll dx = (j-i)/c;
            ll dy = (y[j]-y[i])/c;

            used[i] = true; used[j] = true;
            REP(k, n){
                if(i+k*dx<n){
                    if(y[i+k*dx] == y[i]+k*dy){
                        used[i+k*dx] = true;
                    }
                }
            }
            REP(k, n){
                if(i-k*dx>=0){
                    if(y[i-k*dx] == y[i]-k*dy){
                        used[i-k*dx] = true;
                    }
                }
            }

            int count = 0;
            int ni;
            REP(k, n){
                if(!used[k]){
                    count += 1;
                    ni = k;
                }
            }
            if(count == 1){
                flag = true;
                break;
            }
            if(count == 0){
                break;
            }

            used[ni] = true;
            REP(k, n){
                if(ni+k*dx<n){
                    if(y[ni+k*dx] == y[ni]+k*dy){
                        used[ni+k*dx] = true;
                    }
                }
            }
            REP(k, n){
                if(ni-k*dx>=0){
                    if(y[ni-k*dx] == y[ni]-k*dy){
                        used[ni-k*dx] = true;
                    }
                }
            }

            flag = true;
            REP(k, n){
                if(!used[k]){
                    flag = false; break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
