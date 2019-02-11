#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P; // idx, vertex

vector<int> g[200010];
int d[200010];
bool done[200010];

#define REP(i, n) for(int i=0; i<n; i++)

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    REP(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // initialization
    REP(i, n+1) {
        d[i] = 0;
        done[i] = false;
    }
    d[s] = s;

    // dijkstra
    priority_queue<P> que;
    que.push(P(s, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();

        int v = p.second;
        if (done[v]) continue;
        done[v] = true;

        REP(i, g[v].size()) {
            int to = g[v][i];
            if (d[to] < d[v]) {
                d[to] = min(to, d[v]);
                que.push(P(d[to], to));
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if (d[i] >= i) {
            printf("%d\n", i);
        }
    }
}
