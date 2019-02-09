#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct edge{
    int to, cost;
};

typedef pair<int, int> pii;

const int max_v = 100;
const int max_n = 10;
const int INF = 10e8;
int dp[max_n + 1][max_v + 1];

int main(){
    while(1){
        int c, n, m, s, d;
        cin >> c >> n >> m >> s >> d;
        s = s-1;
        d = d-1;

        if(c==0) break;

        vector<edge> g[max_v];
        REP(i, m){
            int a, b, f;
            cin >> a >> b >> f;
            a = a-1;
            b = b-1;
            edge ea = {b, f};
            edge eb = {a, f};
            g[a].push_back(ea);
            g[b].push_back(eb);
        }

        priority_queue<pii, vector<pii>, greater<pii> > que;
        
        fill(dis, dis+m, INF);
        dis[s] = 0;
        que.push(pii(0, s));

        while(!que.empty()){
            pii p = que.top();
            que.pop();
            int v = p.second;
            if(dis[v] < p.first){
                continue;
            }
            REP(i, g[v].size()){
                edge e = g[v][i];
                if(dis[e.to] > dis[v] + e.cost){
                    dis[e.to] = dis[v] + e.cost;
                    que.push(pii(dis[e.to], e.to));
                }
            }
        }

        REP(i, m){
            cout << dis[i] << endl;
        }
        cout << dis[d] << endl;
    }
}
