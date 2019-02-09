#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<iomanip>
#include<bitset>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

struct edge{int to; double cost; };
typedef pair<double, pair<int, int> > pii;

ll INF = 10e17;
ll n, m, p, a, b;
vector<edge> g[30];
double d[30][1<<8];
int ticket[8];

void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii> > que;
    REP(i, m) REP(j, 1<<n) d[i][j] = INF;
    d[s][0] = 0;
    que.push(pii(0, make_pair(s, 0)));

    while(!que.empty()){
        pii p = que.top(); que.pop();
        int v = p.second.first;
        int t = p.second.second;
        if(d[v][t]<p.first) continue;
        REP(i, g[v].size()){
            edge e = g[v][i];
            REP(l, n){
                if((t>>l) % 2 == 0){
                    if(d[e.to][t|(1<<l)] > d[v][t] + e.cost / ticket[l]){
                        d[e.to][t|(1<<l)] = d[v][t] + e.cost / ticket[l];
                        que.push(pii(d[e.to][t|(1<<l)], make_pair(e.to, t|(1<<l))));
                    }
                }
            }
        }
    }
}

int main(){
    while(1){
        cin >> n >> m >> p >> a >> b;

        if(n==0) break;

        REP(i, n) cin >> ticket[i];
        REP(i, m) g[i].clear();
        REP(i, p){
            int x, y, z;
            cin >> x >> y >> z;
            edge e;
            e.to = y-1; e.cost = z;
            g[x-1].push_back(e);
            e.to = x-1;
            g[y-1].push_back(e);
        }

        dijkstra(a-1);
        double output = INF;
        REP(i, 1<<n){
            output = min(d[b-1][i], (double)output);
        }
        
        if(output==INF){
            cout << "Impossible" << endl;
        } else {
            cout << fixed << setprecision(4) << output << endl;
        }
    }
}
