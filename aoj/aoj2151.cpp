#include<iostream>
#include<queue>
#include<vector>
 
using namespace std;
 
#define REP(i, n) for(int i=0; i<n; i++)
 
struct edge{
    int to, dist, t;
};
 
typedef pair<int, pair<int, int> > pii; // thief, edge, money
 
int INF = 10e8;
int n, m, l;

int thief[101][101];
 
int main(){
    while(1){
        cin >> n >> m >> l;

        if(n==0) break;
 
        vector<edge> g[101];
        REP(i, m){
            int a, b, d, e;
            cin >> a >> b >> d >> e;
            edge ae;
            ae.to = b;
            ae.dist = d;
            ae.t = e;
            g[a].push_back(ae);
            edge be;
            be.to = a;
            be.dist = d;
            be.t = e;
            g[b].push_back(be);
        }
 
        priority_queue<pii, vector<pii>, greater<pii> > que;
        REP(i, n+1){
            REP(j, l+1){
                thief[i][j] = INF;
            }
        }
        thief[1][l] = 0;
        pii init = make_pair(0, make_pair(1, l));
        que.push(init);
 
        while(!que.empty()){
            pii p = que.top();
            que.pop();
 
            int v = p.second.first;
            int m = p.second.second;
            if(thief[v][m]<p.first) continue;
            REP(i, g[v].size()){
                edge e = g[v][i];
                if(thief[e.to][m] > thief[v][m] + e.t){
                    thief[e.to][m] = thief[v][m] + e.t;
                    que.push(pii(make_pair(thief[e.to][m], make_pair(e.to, m))));
                }
                if(m >= e.dist && thief[e.to][m-e.dist] > thief[v][m]){
                    thief[e.to][m-e.dist] = thief[v][m];
                    que.push(pii(make_pair(thief[e.to][m-e.dist], make_pair(e.to, m-e.dist))));
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
        REP(i, l+1){
            output = min(output, thief[n][i]);
        }
        cout << output << endl;
    }
}
