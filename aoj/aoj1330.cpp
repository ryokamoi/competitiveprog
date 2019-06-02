// Ryo Kamoi
#define DEBUG

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
int par[100100];
bool used[100100];
set<int> united[100100];
map<pii, int> diff;

ll weight[100100];

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
while(1) {
  cin >> n >> m;
  if (n==0) break;

  REP(i, n) {
    par[i] = i;
    used[i] = false;
    united[i] = set<int>();
  }
  diff = map<pii, int>();

  REP(i, m) {
    char query;
    cin >> query;
    if (query == '!') {
      int a, b, w;
      cin >> a >> b >> w;
      a = a-1; b = b-1;
      
      if (used[a] && used[b]) {
        if (united[par[a]].find(par[b]) == united[par[a]].end()) {
          united[par[a]].insert(par[b]);
          united[par[b]].insert(par[a]);
          int abdiff = (weight[par[b]] - weight[b]) + w
                        - (weight[par[a]] - weight[a]);
          diff[pii(par[a], par[b])] = abdiff;
          diff[pii(par[a], par[b])] = -abdiff;
        }
      } else if (used[b]) {
        unite(a, b);
        weight[a] = weight[b] - w;
      } else {
        unite(b, a);
        weight[b] = weight[a] + w;
      }

      used[a] = true; used[b] = true;
    } else { // ?
      int a, b;
      cin >> a >> b;
      a = a-1; b = b-1;
      if (same(a, b)) {
        cout << weight[b] - weight[a] << endl;
      } else if (united[par[a]].find(par[b]) != united[par[a]].end()) {
        int ans = (weight[b] - weight[par[b]]) + diff[pii(par[a], par[b])]
                    - (weight[a] - weight[par[a]]);
        cout << ans << endl;
#ifdef DEBUG
        cout << par[a] << " " << par[b] << " " << diff[pii(par[a], par[b])] << endl;
#endif
      } else {
        cout << "UNKNOWN" << endl;
      }
    }
  }
}
}
