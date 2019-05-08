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

struct edge{
  int to; int d;
};

int n;
vector<edge> g[1000];
int p[1000];
int dist[1000];
bool done[1000];
int t;
int maxdist;

void solve(int idx) {
  done[idx] = true;
#ifdef DEBUG
  cout << idx << " " << t << endl;
#endif
  REP(i, g[idx].size()) {
    if (done[g[idx][i].to]) continue;

    if (g[g[idx][i].to].size() == 1) {
      t += g[idx][i].d;
      done[g[idx][i].to] = true;
      continue;
    }

    t += g[idx][i].d * 3;
    solve(g[idx][i].to);
  }
}

int calcdist(int idx) {
  int innerdist[1000];
  bool innerdone[1000];
  REP(i, n) {
    innerdist[i] = 0;
    innerdone[i] = false;
  }
  innerdone[idx] = true;

  queue<int> que;
  que.push(idx);
  while(!que.empty()) {
    int cur = que.front(); que.pop();
    REP(i, g[cur].size()) {
      if (innerdone[g[cur][i].to]) continue;
      if (g[g[cur][i].to].size() == 1) continue;
      
      innerdist[g[cur][i].to] = innerdist[cur] + g[cur][i].d;
      que.push(g[cur][i].to);
      innerdone[g[cur][i].to] = true;
    }
  }

  int maxdist = 0;
  REP(i, n) {
    maxdist = max(maxdist, innerdist[i]);
  }
  return maxdist;
}

int main(){
  while(1) {
    cin >> n;
    if (n==0) break;

    t = 0;
    REP(i, n) {
      g[i] = vector<edge>();
      done[i] = false;
    }

    REP(i, n-1) {
      int to;
      cin >> to;
      p[i] = to-1;
    }
    REP(i, n-1) {
      cin >> dist[i];
    }
    REP(i, n-1) {
      edge e1;
      e1.to = p[i];
      e1.d = dist[i];
      g[i+1].push_back(e1);

      edge e2;
      e2.to = i+1;
      e2.d = dist[i];
      g[p[i]].push_back(e2);
    }

    int start;
    REP(i, n) {
      if (g[i].size() == 1) {
        start = i; break;
      }
    }
    solve(g[start][0].to);

    maxdist = 0;
    REP(i, n) {
      if (g[i].size() > 1) {
        maxdist = max(maxdist, calcdist(i));
#ifdef DEBUG
        cout << i << " " << g[i].size() << " " << calcdist(i) << endl;
#endif
      }
    }

#ifdef DEBUG
    cout << t << " " << maxdist << endl;
#endif
    cout << t - maxdist << endl;
  }
}
