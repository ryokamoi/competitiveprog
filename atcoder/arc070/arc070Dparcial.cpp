#include<iostream>
#include<bitset>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, k;
ll a[5000];
bool dp[5001];

int main(){
    bitset<5000> bi(1);
    bi = bi << 4999;
    cout << bi << endl;
    cin >> n >> k;
    REP(i, n) cin >> a[i];

    ll c = 0;
    REP(l, n){
        REP(i, k+1) dp[i] = false;
        dp[0] = true;
        REP(i, n){
            if(i!=l){
                for(int j=k; j>0; j--){
                    if(j-a[i]>=0){
                        if(dp[j-a[i]]) dp[j] = true;
                    }
                }
            }
        }
        bool flag = true;
        if(a[l]>=k){
            flag = false;
        } else {
            for(int i=k-a[l]; i<k; i++){
                if(dp[i]) flag = false;
            }
        }
        if(flag) c += 1;
    }

    cout << c << endl;
}
