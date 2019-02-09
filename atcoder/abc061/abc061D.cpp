#include<iostream>
#include<cstring>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

struct edge{
    int from, to;
    ll cost;
};

ll INF = 10e17;
edge es[2000];
ll d[1000];
int n, m; // vertex, edge

bool shortest_path(int s){
    REP(i, n) d[i] = INF;
    d[s] = 0;
    REP(i, 2*n){
        REP(j, m){
            edge e = es[j];
            if(d[e.from]!=INF && d[e.to]>d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;

                if(i>=n-1 && e.to==n-1) return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    REP(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a -= 1;
        b -= 1;
        edge e;
        e.from = a; e.to = b; e.cost = -c;
        es[i] = e;
    }

    bool flag = shortest_path(0);
    if(flag){
        cout << "inf" << endl;
    } else {
        cout << -d[n-1] << endl;
    }
}
