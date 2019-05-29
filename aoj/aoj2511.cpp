// Ryo Kamoi
// #define DEBUG

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

int n, m;
bool exist[210], used[210];
bool cur_used[210];
vector<pii> disap;
int cost[210][210];
int prim_cost[210];

int main(){
  while(1) {
    cin >> n >> m;
    if (n==0) break;

    disap = vector<pii>();
    REP(i, n) {
      exist[i] = false;
      used[i] = false;
    }

    REP(i, n) {
      REP(j, n) {
        cost[i][j] = INF;
      }
    }

    REP(i, n) {
      int h;
      cin >> h;
      disap.push_back(pii(h, i));
    }

    REP(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      cost[a-1][b-1] = c;
      cost[b-1][a-1] = c;
    }

    sort(disap.begin(), disap.end(), greater<pii>());

    int output = 0;
    REP(i, n) {
      exist[disap[i].second] = true;

      if (i==0) {
        used[disap[0].second] = true;
        continue;
      }

      if (i<n-1 && disap[i].first == disap[i+1].first) {
        continue;
      }

      REP(j, n) {
        cur_used[j] = used[j];
        prim_cost[j] = INF;
      }

      REP(j, n) {
        if (!exist[j]) continue;
        REP(k, n) {
          if (!cur_used[k]) continue;
          prim_cost[j] = min(prim_cost[j], cost[j][k]);
        }
      }

      int cur_cost = 0;
      while(true) {
        int v = -1;
        REP(j, n) {
          if(!cur_used[j] && prim_cost[j] < INF
             && (v==-1 || prim_cost[j] < prim_cost[v])) v = j;
        }
#ifdef DEBUG
        cout << v << " " << prim_cost[v] << " " << disap[i].second << endl;
#endif

        if (v==-1) break;
        cur_used[v] = true;
        cur_cost += prim_cost[v];

        REP(j, n) {
          if (exist[j]) {
            prim_cost[j] = min(prim_cost[j], cost[v][j]);
          }
        }
      }

      bool update = true;
      REP(j, n) {
        if (cur_used[j] != exist[j]) {
          update = false; break;
        }
      }
      
      if (!update) {
        REP(j, n) {
          used[j] = false;
        }
        used[disap[0].second] = true;
        output = 0;
        continue;
      }

      REP(j, n) {
        used[j] = cur_used[j];
      }
      output += cur_cost;
#ifdef DEBUG
      cout << output << " cost" << endl;
#endif
    }

    cout << output << endl;
  }
}
