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

int n;
int dist[110];
int degree[110];
vector<int> graph[110];
int cur_room;
int max_idx;

int main(){
  cin >> n;
  REP(iter, n) {
    REP(i, 100) {
      dist[i] = INF;
      degree[i] = 0;
      graph[i] = vector<int>();
    }

    cur_room = -1;
    int max_idx = -1;
    while(1) {
      int m;
      cin >> m;
      if (m == 0) break;

      if (m > 0) {
        int prev_room = cur_room;
        max_idx++;
        cur_room = max_idx;
        
        if (prev_room >= 0) {
          degree[prev_room]--;
          degree[cur_room] = m-1;
          dist[cur_room] = dist[prev_room] + 1;
        
          graph[prev_room].push_back(cur_room);
          graph[cur_room].push_back(prev_room);
        } else {
          degree[cur_room] = m;
          dist[cur_room] = 0;
        }
        while(degree[cur_room] == 0) {
          cur_room = graph[cur_room][0];
          if (cur_room == 0) break;
        }
      } else {
        for(int i=cur_room-1; i>=0; i--) {
          if (degree[i] > 0 && dist[i] - dist[cur_room] == m) {
            degree[cur_room]--;
            degree[i]--;

            graph[i].push_back(cur_room);
            graph[cur_room].push_back(i);
            break;
          }
        }

        while(degree[cur_room] == 0) {
          cur_room = graph[cur_room][0];
          if (cur_room == 0) break;
        }
      }
    }

    REP(i, max_idx+1) {
      sort(graph[i].begin(), graph[i].end());
      cout << i+1 << " ";
      REP(j, graph[i].size()) {
        cout << graph[i][j] + 1;
        if (j < graph[i].size()-1) {
          cout << " ";
        } else {
          cout << endl;
        }
      }
    }
  }
}
