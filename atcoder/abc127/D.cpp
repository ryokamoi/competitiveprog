// Ryo Kamoi
// #define DEBUG

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int INF = 1000000000;

ll n, m;
vector<ll> a;
vector<pll> bc;

int main(){
  cin >> n >> m;
  REP(i, n) {
    ll ai;
    cin >> ai;
    a.push_back(ai);
  }
  sort(a.begin(), a.end());

  REP(i, m) {
    ll b, c;
    cin >> b >> c;
    bc.push_back(pii(c, b));
  }

  sort(bc.begin(), bc.end(), greater<pll>());

  ll bc_idx = 0;
  REP(i, n) {
    if (bc_idx >= bc.size()) break;

    a[i] = max(a[i], bc[bc_idx].first);
    bc[bc_idx].second--;
    if (bc[bc_idx].second == 0) {
      bc_idx++;
    }

#ifdef DEBUG
    cout << a[i] << " ";
#endif
  }

  ll output = 0;
  REP(i, n) {
    output += a[i];
  }
  cout << output << endl;
}
