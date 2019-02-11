#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int m, n;
int b[1005];
int r[1005];

vector<int> bd[1005];
vector<int> rd[1005];

struct edge{
    int to, cap, rev;
};
bool used[1005];
vector<edge> g[1005];

int s, t;

void add_edge(int from, int to, int cap){
    g[from].push_back((edge){to, cap, g[to].size()});
    g[to].push_back((edge){from, 0, g[from].size()-1});
}

int dfs(int v, int t, int f){
    if(v==t) return f;
    used[v] = true;
    REP(i, g[v].size()){
        edge &e = g[v][i];
        if(!used[e.to] && e.cap>0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d>0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f==0) return flow;
        flow += f;
    }
}

bool euclid(int x, int y){
    if(x<y){
        int tmp = x;
        x = y;
        y = tmp;
    }

    int r = x % y;
    while(r!=0){
        x = y;
        y = r;
        r = x % y;
    }

    if(y>1){
        return true;
    } else {
        return false;
    }
}

int main(){
    while(1){
        cin >> m >> n;

        if(m==0) break;

        REP(i, m) cin >> b[i];
        REP(i, n) cin >> r[i];

        int s = m+n, t = s+1;

        REP(i, 1005) g[i].clear();

        REP(i, m){
            REP(j, n){
                if(euclid(b[i], r[j])){
                    add_edge(i, m+j, 1);
                }
            }
        }

        REP(i, m) add_edge(s, i, 1);
        REP(i, n) add_edge(m+i, t, 1);

        int output = max_flow(s, t);
        cout << output << endl;
    }
}
