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
typedef pair<double, double> pdd;

int INF = 1000000000;

int num_blocks[600];
double center[600];
vector<int> above[600];

double leftmost[600];
double rightmost[600];

int largest_idx;
int piece_count;

int w, h;
int blocks[70][20];

int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

void update_most(int idx, int cj) {
  leftmost[idx] = min(leftmost[idx], (double)cj-0.5);
  rightmost[idx] = max(rightmost[idx], (double)cj+0.5);
}

void update_center(int idx, int cj) {
  center[idx] = (center[idx] * (double)num_blocks[idx] + (double)cj) /
    (double)(num_blocks[idx]+1);
}

void build_tree(int idx, pii start){
  int id = blocks[start.first][start.second];
  queue<pii> que;
  que.push(start);
  blocks[start.first][start.second] = -id;

  while(!que.empty()) {
    pii p = que.front(); que.pop();
    int ci = p.first;
    int cj = p.second;
    update_center(idx, cj);
    num_blocks[idx]++;
#ifdef DEBUG
    cout << "ij " << ci << " " << cj << endl;
#endif
    REP(i, 4) {
      int ni = ci + y[i];
      int nj = cj + x[i];

      if (ni >= h) {
        update_most(idx, cj);
        continue;
      }

      if (ni < 0 || nj < 0 || nj >= w) continue;
#ifdef DEBUG
      if (id==1) {
        cout << "id1 " << ni << " " << nj << " " << blocks[ni][nj] << endl;
      }
#endif
      if (i==1 && abs(blocks[ni][nj])!=id && blocks[ni][nj]!=0) {
        update_most(idx, nj);
        continue;
      }

      if (i==0 && blocks[ni][nj]>0 && blocks[ni][nj]!=id) {
        largest_idx++;
        above[idx].push_back(largest_idx);
        build_tree(largest_idx, pii(ni, nj));
        continue;
      }

      if (blocks[ni][nj] == id) {
        que.push(pii(ni, nj));
        blocks[ni][nj] = -id;
      }
    }
  }
}

pdd find_center(int idx) {
  double weight = (double)num_blocks[idx];
  double c = center[idx];
  REP(i, above[idx].size()) {
    pdd cw = find_center(above[idx][i]);
    c = (c * weight + cw.first * cw.second) / (weight + cw.second);
    weight += cw.second;
  }
  return pdd(c, weight);
}

int main(){
  while(1) {
    cin >> w >> h;
    if (w==0) break;

    largest_idx = 0;
    piece_count = 0;
    REP(i, 600) {
      leftmost[i] = (double)INF;
      rightmost[i] = 0.0;
      above[i] = vector<int>();
      num_blocks[i] = 0;
    }

    REP(i, h) {
      string row;
      cin >> row;
      REP(j, w) {
        if (row[j] == '.') {
          blocks[i][j] = 0;
        } else {
          blocks[i][j] = row[j]-'0';
        }
      }
    }

    pii init_p;
    int init_id;
    REP(i, w) {
      if (blocks[h-1][i] != 0) {
        init_p = pii(h-1, i);
        init_id = blocks[h-1][i];
        break;
      }
    }

    build_tree(0, init_p);

    bool stable = true;
    REP(i, largest_idx+1) {
      pdd cw = find_center(i);
#ifdef DEBUG
      cout << leftmost[i] << " " << rightmost[i] << endl;
      cout << center[i] << " " << num_blocks[i] << " " << cw.first << endl;
#endif
      if (cw.first <= leftmost[i] || cw.first >= rightmost[i]) {
        stable = false;
        break;
      }
    }
    if (stable) {
      cout << "STABLE" << endl;
    } else {
      cout << "UNSTABLE" << endl;
    }
  }
}
