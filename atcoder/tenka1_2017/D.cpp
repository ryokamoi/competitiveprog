#include<iostream>
#include<bitset>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, k;
ll a[100000], b[100000];

int main(){
    cin >> n >> k;
    REP(i, n){
        cin >> a[i] >> b[i];
    }

    ll max_v = 0;
    ll num = 0;
    ll max_d = 1;

    ll next_d = 0;
    ll plus = 1;
    while(1){
        plus = 1;
        while(1){
            if((next_d|plus) <= k){
                next_d = (next_d | plus);
                plus *= 2;
            } else {
                break;
            }
        }

        ll tmp_v = 0;
        REP(i, n){
            if(a[i] <= next_d && (a[i]|next_d) == next_d){
                tmp_v += b[i];
            }
        }
        
        cout << static_cast<std::bitset<8> >(next_d) << std::endl;
        max_v = max(tmp_v, max_v);
        if(next_d == k) break;

        next_d += 1;
    }

    cout << max_v << endl;
}
