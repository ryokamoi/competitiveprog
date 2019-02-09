#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

struct edge{int to; double cost; };
typedef pair<int, int> pii;

ll INF = 10e17;
ll n;
vector<edge> g[];
double d[1002];

void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii> > que;
    fill(d, d+n+2, INF);
    d[s] = 0;
    que.push(pii(0, 0));

    while(!que.empty()){
        pii p = que.top(); que.pop();
        int v = p.second;
        if(d[v]<p.first) continue;
        REP(i, g[v].size()){
            edge e = g[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(pii(d[e.to], e.to));
            }
        }
    }
}

int main(){
    dijkstra(s);
}
