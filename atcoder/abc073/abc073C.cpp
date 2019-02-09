#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int n;
vector<ll> a;

int main(){
    cin >> n;
    REP(i, n){
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }
    sort(a.begin(), a.end());

    ll tmp = -1;
    ll c;
    ll output = 0;
    REP(i, a.size()){
        if(a[i] == tmp){
            c += 1;
        } else {
            if(c%2==1) output += 1;
            tmp = a[i];
            c = 1;
        }
    }
    if(c%2==1) output += 1;
    cout << output << endl;
}
