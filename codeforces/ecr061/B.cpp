// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

ll n;
vector<ll> a;
ll m;
ll q[1000000];
int main(){
    ll sum = 0;

    cin >> n;
    REP(i, n) {
        int ai;
        cin >> ai;
        sum += ai;
        a.push_back(ai);
    }

    sort(a.begin(), a.end(), greater<ll>());

    cin >> m;
    REP(i, m) {
        ll qi;
        cin >> qi;
        cout << sum - a[qi-1] << endl;
    }
}
