#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll r = 1000000007;
int n;
bool is_prime[1001];
int c[1001];

int main(){
    cin >> n;

    REP(i, 1001) is_prime[i] = true;
    is_prime[0] = false; is_prime[1] = false;

    REP(i, 1001){
        if(is_prime[i]){
            for(int j=2*i; j<=1001; j+=i) is_prime[j] = false;
        }
    }

    REP(i, 1001) c[i] = 0;
    for(int i=1; i<=n; i++){
        int num = i;
        REP(j, 1001){
            while(1){
                if(is_prime[j] && num%j==0){
                    c[j] += 1;
                    num /= j;
                } else {
                    break;
                }
            }
        }
    }

    ll output = 1;
    REP(i, 1001){
        if(c[i]>0){
            output *= (c[i]+1);
            output = output%r;
        }
    }
    cout << output << endl;
}
