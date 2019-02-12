#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define INF 1000000000

typedef pair<int, int> Pii;
typedef pair<int, Pii> P; // time, town, coldtime

struct edge {int to, cost; };

int coldtown[110];
int d[110][110];

int main() {
    while(true) {
        int n, m, l, k, a, h;
        cin >> n >> m >> l >> k >> a >> h;
        if (n == 0) break;

        vector<edge> g[110];
        // initialization
        REP(i, n) {
            REP(j, m+1) {
                d[i][j] = INF;
            }
        }
        d[h][0] = 0;

        // cold town
        REP(i, n) coldtown[i] = 0;
        REP(i, l) {
            int idx;
            cin >> idx;
            coldtown[idx] = 1;
        }

        REP(i, k) {
            int x, y, t;
            cin >> x >> y >> t;

            edge e1;
            e1.to = y;
            e1.cost = t;
            g[x].push_back(e1);

            edge e2;
            e2.to = x;
            e2.cost = t;
            g[y].push_back(e2);
        }

        // dijkstra
        priority_queue<P> que;
        P p = P(0, Pii(h, 0));
        que.push(p);

        while(!que.empty()) {
            P p = que.top(); que.pop();
            int time = p.first;
            int town = p.second.first;
            int ctime = p.second.second;
            if (d[town][ctime] < time) continue;

            REP(i, g[town].size()) {
                int to = g[town][i].to;
                int cost = g[town][i].cost;

                if (m < ctime + cost) continue; // cannot achieve
                
                int ntime, nctime;
                if (coldtown[to]) {
                    ntime = time + cost + (cost + ctime);
                    nctime = 0;
                } else {
                    ntime = time + cost;
                    nctime = ctime + cost;
                }
                if (d[to][nctime] > ntime) {
                    d[to][nctime] = ntime;
                    que.push(P(ntime, Pii(to, nctime)));
                }
            }
        }

        int output = INF;
        REP(i, m+1) {
            if (d[a][i] != INF) {
                int ctime = (d[a][i] - i) / 2;
                output = min(d[a][i] - min(ctime, m-i), output);
            }
        }

        if (output == INF) {
            cout << "Help!" << endl;
        } else {
            cout << output << endl;
        }
    }
}

