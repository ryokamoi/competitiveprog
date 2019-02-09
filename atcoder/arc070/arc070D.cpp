#include<iostream>
#include<bitset>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, k;
ll a[5000];
bool dp[5001];
bitset<5001> nec[5001];

int main(){
    cin >> n >> k;
    REP(i, n) cin >> a[i];

    bitset<5001> bi;
    bi = ~bi;
    REP(i, k+1) nec[i] = bi;
    nec[0] = bitset<5001>(0);

    REP(i, k+1) dp[i] = false;
    dp[0] = true;
    REP(i, n){
        for(int j=k; j>0; j--){
            if(j-a[i]<0){
                break;
            } else if(dp[j-a[i]]){
                dp[j] = true;
                bitset<5001> cbi(1);
                cbi = cbi << i;
                nec[j] = nec[j] & (nec[j-a[i]] | cbi);
            }
        }
    }

    ll c = 0;
    REP(l, n){
        bool flag = true;
        if(a[l]>=k){
            flag = false;
        } else {
            bitset<5001> one(1);
            for(int i=k-a[l]; i<k; i++){
                if(!(nec[i]>>l)[0]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) c += 1;
    }

    cout << c << endl;
}
