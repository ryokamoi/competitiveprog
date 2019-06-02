// Ryo Kamoi
#define DEBUG

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

struct edge {
  int to; int len;
};

int n;
int col[100010];
vector<edge> graph[100010];

int main(){
  cin >> n;

  REP(i, n) {
    col[i] = -1;
  }

  REP(i, n-1) {
    int u, v, w;
    cin >> u >> v >> w;
    edge e1;
    e1.to = v-1; e1.len = w;
    graph[u-1].push_back(e1);
    
    edge e2;
    e2.to = u-1; e2.len = w;
    graph[v-1].push_back(e2);
  }

  queue<int> que;
  que.push(0);
  col[0] = 0;

  while(!que.empty()) {
    int vertex = que.front(); que.pop();
    REP(i, graph[vertex].size()) {
      int next_v = graph[vertex][i].to;
      if (col[next_v] >= 0) continue;

      if (graph[vertex][i].len %2 == 1) {
        col[next_v] = (col[vertex] + 1) % 2;
      } else {
        col[next_v] = col[vertex];
      }

      que.push(next_v);
    }
  }

  REP(i, n) {
    cout << col[i] << endl;
  }
}
