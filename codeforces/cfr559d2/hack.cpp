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

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> b(n), g(m);
  REP(i, n) {
    cin >> b[i];
  }
  REP(i, m) {
    cin >> g[i];
  }
  sort(b.begin(), b.end());
  sort(g.begin(), g.end());
  if (g[0] == b[n-1]) {
    ll ss=0;
    REP(i, n-1) {
      ss = (ss+m*b[i]);
    }
    REP(i, n) {
      ss = ss+g[i];
    }
    cout << ss << endl;
  }
}
