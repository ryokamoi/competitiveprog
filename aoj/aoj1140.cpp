// Ryo Kamoi
// #define DEBUG

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

typedef pair<int, pii> piii;

int INF = 1000000000;

int w, h;
int dist[20][20];
int tile[30][30];
int tile_dist[30][30];
vector<pii> points;
int dirty_num;

int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

int dp[1 << 12][12];

void init_dist() {
    REP(i, h) {
        REP(j, w) {
            tile_dist[i][j] = INF;
        }
    }
}

void calc_dist(int idx) {
    init_dist();
    queue<piii> que;
    que.push(piii(0, points[idx]));
    tile_dist[points[idx].first][points[idx].second] = 0;

    while (!que.empty()) {
        piii p = que.front(); que.pop();
        int d = p.first;
        int ih = p.second.first;
        int jw = p.second.second;
        if (tile_dist[ih][jw] != d) continue;
        
        REP(i, 4) {
            int ni = ih + y[i];
            int nj = jw + x[i];

            if (ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if (tile[ni][nj] == -1) continue;
            if (tile_dist[ni][nj] <= d + 1) continue;
            tile_dist[ni][nj] = d+1;
            que.push(piii(d + 1, pii(ni, nj)));
        }
    }

    REP(i, dirty_num+1) {
        dist[idx][i] = tile_dist[points[i].first][points[i].second];
    }
}

// S: history, v: current state
int tsp(int S, int v) {
    if (dp[S][v] >= 0) {
        return dp[S][v];
    }

    if (S==(1<<(dirty_num+1))-1) {
        return dp[S][v] = 0;
    }

    int res = INF;
    REP(u, dirty_num+1) {
        if (!(S>>u & 1)) {
            res = min(res, tsp(S|1<<u, u) + dist[v][u]);
        }
    }
    return dp[S][v] = res;
}

int main(){
    while(1) {
        cin >> w >> h;
        if (w==0) break;

        REP(i, h) {
            REP(j, w) {
                tile[i][j] = 0;
            }
        }

        points = vector<pii>();
        dirty_num = 0;
        REP(i, h) {
            string row;
            cin >> row;
            REP(j, w) {
                if (row[j] == 'o') {
                    points.insert(points.begin(), pii(i, j));
                }
                if (row[j] == '*') {
                    dirty_num ++;
                    points.push_back(pii(i, j));
                }
                if (row[j] == 'x') {
                    tile[i][j] = -1;
                }
            }
        }

        REP(i, dirty_num+1) {
            REP(j, dirty_num+1) {
                dist[i][j] = INF;
            }
        }

        REP(i, dirty_num+1) {
            calc_dist(i);
        }

#ifdef DEBUG
        REP(i, dirty_num+1) {
            REP(j, dirty_num+1) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
#endif

        bool end = false;
        REP(i, dirty_num+1) {
            if (dist[0][i] == INF) {
                cout << -1 << endl;
                end = true;
                break;
            }
        }
        if (end) continue;

        // TSP
        memset(dp, -1, sizeof(dp));
        cout << tsp(1, 0) << endl;
    }
}
