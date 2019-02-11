#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<cstdlib>
#include<bitset>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, pair<int, int> > pii;

int INF = 10e8;
int rest[1002][1002];
int d[1002];

int main(){
    int n, m;
    cin >> n >> m;

    REP(i, n+1) REP(j, n+1) rest[i][j] = 0;
    REP(i, m){
        int c, d;
        cin >> c >> d;
        rest[c][d] = 1;
    }

    priority_queue<pii, vector<pii>, greater<pii> > que;
    fill(d, d+n+2, INF);
    d[0] = 0;
    pair<int, int> init;
    init = make_pair(0, 1);
    que.push(pii(0, init));

    while(!que.empty()){
        pii p = que.top();
        que.pop();
        int v = p.second.first;
        if(d[v] < p.first) continue;
        int gone = p.second.second;

        REP(i, n+2){
            if((i==n+1 && gone==(1<<n)-1) || i<=n){
                bool flag = true;
                if(rest[i][v]==1 && !(gone >> i & 1)){
                    flag = false;
                } else if (d[i] <= d[v]+abs(i-v)){
                    flag = false;
                }
                if(flag){
                    d[i] = d[v] + abs(i-v);
                    que.push(make_pair(d[i], make_pair(i, (gone | 1<<i))));
                }
            }
        }
        cout << static_cast<bitset<12> >(gone) << endl;
        REP(i, n+2) cout << d[i] << " ";
        cout << endl;
    }
    cout << d[n+1] << endl;
}
