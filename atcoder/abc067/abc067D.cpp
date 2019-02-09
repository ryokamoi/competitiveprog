#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> pii;

const int max_n = 10e5;
int INF = 10e8;

int df[max_n];
int ds[max_n];

int n;
vector<int> g[max_n];
vector<int> spath;

void dfs(int v, int (&d)[max_n]){
    REP(i, g[v].size()){
        if(d[g[v][i]]==INF){
            d[g[v][i]] = d[v] + 1;
            dfs(g[v][i], d);
        }
    }
}

int main(){
    cin >> n;

    REP(i, n) g[i].clear();
    REP(i, n-1){
        int a, b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    REP(i, n){
        df[i] = INF;
        ds[i] = INF;
    }

    df[0] = 0;
    dfs(0, df);
    ds[n-1] = 0;
    dfs(n-1, ds);

    int fe = 0;
    int su = 0;
    REP(i, n){
        if(df[i]<=ds[i]){
            fe += 1;
        } else {
            su += 1;
        }
    }

    if(fe>su){
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}
