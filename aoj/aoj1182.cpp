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
    int cost; int to;
};

int n, m, c, start, goal;
int dist[30][100][100];
int cost[100][100];
int p[30];
int q[30][60], r[30][60];
int dist_cost[30][10010];

int calc_cost(int com, int dist) {
    int output = 0;
    REP(i, p[com]-1) {
        if (dist > q[com][i+1]) {
            output += r[com][i] * (q[com][i+1]-q[com][i]);
        } else {
            output += r[com][i] * (dist-q[com][i]);
            return output;
        }
    }
    output += r[com][p[com]-1] * (dist-q[com][p[com]-1]);
    return output;
}

int main(){
    while(1) {
        cin >> n >> m >> c >> start >> goal;
        if (n==0) break;

        REP(i, c) {
            REP(j, n) {
                REP(k, n) {
                    dist[i][j][k] = INF;
                    if (j==k) {
                        dist[i][j][k] = 0;
                    }
                }
            }
        }

        // distance
        REP(i, m) {
            int x, y, di, ci;
            cin >> x >> y >> di >> ci;
            dist[ci-1][x-1][y-1] = min(dist[ci-1][x-1][y-1], di);
            dist[ci-1][y-1][x-1] = min(dist[ci-1][y-1][x-1], di);
        }

        // cost
        REP(i, c) {
            cin >> p[i];
        }

        REP(com, c) {
            q[com][0] = 0;
            REP(i, p[com]-1) {
                cin >> q[com][i+1];
            }
            REP(i, p[com]) {
                cin >> r[com][i];
            }
        }

        // min dist for each company
        REP(com, c) {
            REP(k, n) {
                REP(i, n) {
                    REP(j, n) {
                        dist[com][i][j] = min(dist[com][i][j],
                                dist[com][i][k] + dist[com][k][j]);
                    }
                }
            }
        }

        // calculate cost
        REP(i, n) {
            REP(j, n) {
                cost[i][j] = INF;
                if (i==j) {
                    cost[i][j] = 0;
                }
            }
        }

        REP(com, c) {
            REP(i, n) {
                REP(j, n) {
                    if (dist[com][i][j] < INF) {
                        cost[i][j] = min(cost[i][j],
                                calc_cost(com, dist[com][i][j]));
                    }
                }
            }
        }

#ifdef DEBUG
        REP(i, 15) {
            cout << calc_cost(0, i) << " ";
        }
        cout << endl;
        cout << calc_cost(0, 100000) << endl;
#endif

        REP(k, n) {
            REP(i, n) {
                REP(j, n) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        if (cost[start-1][goal-1] < INF) {
            cout << cost[start-1][goal-1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
