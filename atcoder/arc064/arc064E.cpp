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
vector<edge> g[1002];
double d[1002];
double x[1002], y[1002], r[1002];

double dis(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

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
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    r[0] = 0; r[1] = 0;

    cin >> n;
    REP(i, n){
        cin >> x[i+2] >> y[i+2] >> r[i+2];
    }

    REP(i, n+2){
        REP(j, n+2){
            edge e;
            e.to = j;
            e.cost = max((double)0, dis(x[i], y[i], x[j], y[j]) - r[i] - r[j]);
            g[i].push_back(e);
        }
    }

    dijkstra(0);
    cout << fixed << setprecision(10) << d[1] << endl;
}
