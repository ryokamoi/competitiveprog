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

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int n, m;
int par[100010];

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
}

bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
}


int main(){
  cin >> n >> m;
  REP(i, n) {
    par[i] = i;
  }

  REP(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    unite(x-1, y-1);
  }

  set<int> count_type;
  REP(i, n) {
#ifdef DEBUG
    cout << root(i) << endl;
#endif
    count_type.insert(root(i));
  }
  cout << count_type.size() << endl;
}
