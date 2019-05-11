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

struct edge {
  int to; int overlap;
};

int n, k, s;
int xyz[2010][3];
vector<edge> g[2010];

vector<vector<int>> cube[2];

void generate_cube(int idx1, int idx2) {
  int addv[8][3] = {{0, 0, 0}, {s, 0, 0}, {0, s, 0}, {0, 0, s},
    {s, s, 0}, {s, 0, s}, {0, s, s}, {s, s, s}};
  int idx[2] = {idx1, idx2};

  REP(i, 2) {
    cube[i] = vector<vector<int>>();
    REP(j, 8) {
      vector<int> cur_cube = vector<int>();
      REP(k, 3) {
        cur_cube.push_back(xyz[idx[i]][k] + addv[j][k]);
      }
      cube[i].push_back(cur_cube);
    }
  }
}

bool is_inside_cube(int cube_idx, int point_idx) {
  int point_cube_idx = (cube_idx+1) % 2;
  REP(i, 3) {
    if (cube[cube_idx][0][i] > cube[point_cube_idx][point_idx][i]) {
      return false;
    }
    if (cube[cube_idx][7][i] < cube[point_cube_idx][point_idx][i]) {
      return false;
    }
  }
  return true;
}

int calc_overlap(int idx1, int idx2) {
  generate_cube(idx1, idx2);
  vector<int> overlap_idx[2];
  REP(i, 2) {
    REP(j, 8) {
      if (is_inside_cube((i+1)%2, j)) {
        overlap_idx[i].push_back(j);
      }
    }
  }

  int max_surface = 0;
  REP(p, overlap_idx[0].size()) {
    REP(q, overlap_idx[1].size()) {
      int overlap_xyz[3];
      REP(i, 3) {
        overlap_xyz[i] = abs(cube[0][overlap_idx[0][p]][i]
                          - cube[1][overlap_idx[1][q]][i]);
      }

      int surface = 0;
      REP(i, 3) {
        surface += 2 * overlap_xyz[i] * overlap_xyz[(i+1)%3];
      }
      max_surface = max(max_surface, surface);
    }
  }
  return max_surface;
}

int graph_overlap(int idx, int e_idx) {
  if (k==1) return 0;

  int overlap = g[idx][e_idx].overlap;
  int n_idx = g[idx][e_idx].to;
  int from = idx;
  REP(i, k-2) {
    int to = -1;
    REP(j, g[n_idx].size()) {
      if (g[n_idx][j].to == from) continue;
      to = g[n_idx][j].to;
      overlap += g[n_idx][j].overlap;
    }
    if (to == -1) {
      return 0;
    }

    from = n_idx;
    n_idx = to;
  }

  // circuit
  if (k>=3) {
    int to = -1;
    REP(j, g[n_idx].size()) {
      if (g[n_idx][j].to == idx) {
        overlap += g[n_idx][j].overlap;
      }
    }
  }
  return overlap;
}

int main(){
  while(1) {
    cin >> n >> k >> s;
    if (n==0) break;

    REP(i, n) {
      cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
      g[i] = vector<edge>();
    }

    REP(i, n) {
      for(int j=i+1; j<n; j++) {
        int overlap = calc_overlap(i, j);
        if (overlap == 0) continue;

        edge e1;
        e1.to = j; e1.overlap = overlap;
        g[i].push_back(e1);
        
        edge e2;
        e2.to = i; e2.overlap = overlap;
        g[j].push_back(e2);

#ifdef DEBUG
        cout << i << " " << j << " " << overlap << endl;
#endif
      }
    }

#ifdef DEBUG
    cout << "calc overlap" << endl;
#endif

    int max_overlap = 0;
    REP(i, n) {
#ifdef DEBUG
      cout << i << " " << g[i].size() << endl;
#endif
      REP(j, g[i].size()) {
        int g_overlap = graph_overlap(i, j);
        max_overlap = max(max_overlap, g_overlap);
      }
#ifdef DEBUG
      cout << max_overlap << endl;
#endif
    }

    int sum_surf = 6*s*s*k;
    if (k>1 && max_overlap == 0) {
      cout << -1 << endl;
    } else {
      cout << sum_surf - max_overlap << endl;
    }
  }
}
