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

int n;
vector<int> graph[10010];
bool done[10010];
int deg[10010];
vector<int> labels;

int output[10010];
int score;
int main(){
  cin >> n;
  REP(i, n-1) {
    int a, b;
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }

  REP(i, n) {
    int c;
    cin >> c;
    labels.push_back(c);
  }

  sort(labels.begin(), labels.end(), greater<int>());
  score = 0;
  REP(i, n) {
    if (i==0) continue;
    score += labels[i];
  }

  int max_deg = 0;
  REP(i, n) {
    if (graph[i].size() > graph[max_deg].size()) {
      max_deg = i;
    }
  }

  REP(i, n) {
    done[i] = false;
  }
  done[max_deg] = true;
  output[max_deg] = labels[0];

#ifdef DEBUG
  cout << score << endl;
#endif

  int label_idx = 1;
  queue<int> que;
  que.push(max_deg);
  while(!que.empty()) {
    int q = que.front(); que.pop();
    REP(i, graph[q].size()) {
      int next = graph[q][i];
      if (!done[next]) {
        done[next] = true;
        output[next] = labels[label_idx];
        que.push(next);
        label_idx++;
      }
    }
  }

  cout << score << endl;
  REP(i, n) {
    cout << output[i];
    if (i != n-1) {
      cout << " ";
    }
  }
  cout << endl;
}
