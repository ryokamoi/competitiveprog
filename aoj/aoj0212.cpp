#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define INF 1000000000

struct edge {int cost, to; };

typedef pair<int, pair<int, int> > P; // cost, vertex, chicket
typedef pair<int, int> Pint; //

int c, n, m, s, d;
int dist[110][15];

int main() {
    while(true) {
        cin >> c >> n >> m >> s >> d;
        if (n==0) break;

        vector<edge> g[110];
        REP(i, m) {
            int a, b, f;
            cin >> a >> b >> f;
            
            edge e;
            e.to = b-1;
            e.cost = f;
            g[a-1].push_back(e);
            
            edge e2;
            e2.to = a-1;
            e2.cost = f;
            g[b-1].push_back(e2);
        }

        REP(i, n) {
            REP(j, c+1) {
                dist[i][j] = INF;
            }
        }
        dist[s-1][c] = 0;

        P p=pair<int, Pint>(0, Pint(s-1, c));
        priority_queue<P, vector<P>, greater<P> > que;
        que.push(p);

        while(!que.empty()) {
            P p = que.top();
            que.pop();

            int v = p.second.first;
            int ckt = p.second.second;
            if(dist[v][ckt] < p.first) continue;

            REP(i, g[v].size()) {
                int to = g[v][i].to;
                int cost = g[v][i].cost;
                // don't use chicket
                if (dist[to][ckt] > dist[v][ckt] + cost){
                    dist[to][ckt] = dist[v][ckt] + cost;
                    P p = pair<int, Pint>(dist[v][ckt] + cost, Pint(to, ckt));
                    que.push(p);
                }

                // use chicket
                if (ckt >= 1) {
                    if (dist[to][ckt-1] > dist[v][ckt] + cost/2){
                        dist[to][ckt-1] = dist[v][ckt] + cost/2;
                        P p = pair<int, Pint>(dist[v][ckt] + cost/2, Pint(to, ckt-1));
                        que.push(p);
                    }
                }
            }
        }
        
        int output = INF;
        REP(i, c+1) {
            output = min(output, dist[d-1][i]);
        }

        cout << output << endl;
    }
}
