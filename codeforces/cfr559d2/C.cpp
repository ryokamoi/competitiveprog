// Ryo Kamoi
// #define DEBUG

#include<set>
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

ll INF = 1000000000000000000;

ll n, m;
ll b[100010];
vector<int> boy;
ll g[100010];
set<ll> used;

int main(){
  cin >> n >> m;
  
  boy = vector<int>();
  REP(i, n) {
    cin >> b[i];
    boy.push_back(b[i]);
  }
  REP(i, m) {
    cin >> g[i];
  }

  ll bmax = 0;
  ll bsecondmax = 0;
  ll bmaxidx;
  REP(i, n) {
    if (b[i] > bmax) {
      bmax = b[i];
      bmaxidx = i;
    }
  }

  sort(boy.begin(), boy.end(), greater<int>());
  bsecondmax = boy[1];
#ifdef DEBUG
  cout << bsecondmax << endl;
#endif

  int girl_kinds = 0;
  used = set<ll>();

  ll gmin = INF;
  ll gminidx;
  REP(i, m) {
    if (used.find(g[i]) == used.end()) {
      used.insert(g[i]);
      girl_kinds++;
    }
    if (g[i] < gmin) {
      gmin = g[i];
      gminidx = i;
    }
  }
#ifdef DEBUG
  cout << girl_kinds << endl;
#endif
  bool flag = false;
  if (girl_kinds > n) flag = true;
  if (m==1 && bmax != gmin) flag = true;
  if (bmax > gmin) flag = true;

  if (flag) {
    cout << -1 << endl;
    return 0;
  }

  ll output = 0;
  REP(i, n) {
    output += m * b[i];
  }

  REP(i, m) {
    if (i == gminidx && gmin != bmax) {
      output += g[i] - bsecondmax;
    } else {
      output += g[i] - bmax;
    }
  }

  cout << output << endl;
}
