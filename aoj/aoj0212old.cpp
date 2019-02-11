#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct edge{
    int to, cost;
};

typedef pair<int, pair<int, int> > pii; // distance, edge, ticket

int INF = 10e8;
int c, n, m, s, d;

int dis[101][11];

int main(){
    while(1){
        cin >> c >> n >> m >> s >> d;

        if(n==0) break;

        vector<edge> g[101];
        REP(i, m){
            int a, b, f;
            cin >> a >> b >> f;
            edge ae;
            ae.to = b;
            ae.cost = f;
            g[a].push_back(ae);
            edge be;
            be.to = a;
            be.cost = f;
            g[b].push_back(be);
        }

        priority_queue<pii, vector<pii>, greater<pii> > que;
        REP(i, n+1){
            REP(j, c+1){
                dis[i][j] = INF;
            }
        }
        dis[s][c] = 0;
        pii init = make_pair(0, make_pair(s, c));
        que.push(init);

        while(!que.empty()){
            pii p = que.top();
            que.pop();

            int v = p.second.first;
            int t = p.second.second;
            if(dis[v][t]<p.first) continue;
            REP(i, g[v].size()){
                edge e = g[v][i];
                if(dis[e.to][t] > dis[v][t] + e.cost){
                    dis[e.to][t] = dis[v][t] + e.cost;
                    que.push(pii(make_pair(dis[e.to][t], make_pair(e.to, t))));
                }
                if(t>0 && dis[e.to][t-1] > dis[v][t] + e.cost / 2){
                    dis[e.to][t-1] = dis[v][t] + e.cost / 2;
                    que.push(pii(make_pair(dis[e.to][t-1], make_pair(e.to, t-1))));
                }
            }
        }
        /*
        REP(i, n+1){
            REP(j, c+1){
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }
        */
        int output = INF;
        REP(i, c+1){
            output = min(output, dis[d][i]);
        }
        cout << output << endl;
    }
}
