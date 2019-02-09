#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> pii;

const int max_n = 10e5;
int INF = 10e8;

struct edge{
    int to, cost;
};

int d[max_n];
int n;
vector<edge> g[max_n];
vector<int> spath;

int pre[max_n];

void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii> > que;
    fill(d, d+n, INF);
    fill(pre, pre+n, -1);
    d[s] = 0;
    que.push(pii(0, s));

    while(!que.empty()){
        pii p = que.top();
        que.pop();
        int v = p.second;

        if(d[v]<p.first) continue;
        REP(i, g[v].size()){
            edge e = g[v][i];
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(pii(d[e.to], e.to));
                pre[e.to] = v;
            }
        }
    }
}

vector<int> get_path(int t){
    vector<int> path;
    while(t!=-1){
        path.push_back(t);
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    return path;
}

int node_size(int v){
    int sum = 0;
    bool used[max_n];
    REP(i, n) used[i] = false;
    REP(i, spath.size()){
        used[spath[i]] = true;
    }

    queue<int> que;
    que.push(v);
    while(!que.empty()){
        int p = que.front();
        que.pop();
        REP(i, g[p].size()){
            edge e = g[p][i];
            if(!used[e.to]){
                sum += 1;
                que.push(e.to);
                used[e.to] = true;
            }
        }
    }
    return sum;
}

int main(){
    cin >> n;

    REP(i, n) g[i].clear();
    REP(i, n-1){
        int a, b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        edge e;
        e.to = b;
        e.cost = 1;
        g[a].push_back(e);
        e.to = a;
        g[b].push_back(e);
    }
    
    dijkstra(0);
    spath = get_path(n-1);

    int fe = 0;
    int su = 0;
    int meet;
    vector<int> medge;
    if(spath.size()%2==0){
        meet = spath.size()/2;
    } else {
        meet = spath.size()/2 + 1;
    }

    fe += meet;
    su = spath.size() - meet;
    REP(i, spath.size()){
        if(i<meet){
            fe += node_size(spath[i]);
        } else {
            su += node_size(spath[i]);
        }
    }

    if(fe>su){
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}
