#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int main() {
    int n;
    cin >> n;

    ll sum = 0;
    REP(i, n) {
        ll a;
        cin >> a;
        sum += (a-1);
    }

    cout << sum << endl;
}
