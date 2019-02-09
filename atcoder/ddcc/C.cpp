#include<iostream>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, c;
ll l[100010];

int main(){
    cin >> n >> c;
    REP(i, n){
        cin >> l[i];
    }

    sort(l, l+n);
    ll count = 0;
    ll left = 0;

    for(int i=n-1; i>=0; i--){
        if(left<i && l[left] + l[i] + 1 <= c){
            count += 1;
            left += 1;
        } else if (left<=i){
            count += 1;
        }
    }

    cout << count << endl;
}
