#include<iostream>
#include<vector>
#include<queue>

#define REP(i, n) for(int i; i<n; i++)
typedef unsigned long long ull;
using namespace std;
typedef vector<pair<int, ull> > vpu;

int p[100001];

int main(){
    ull n;
    cin >> n;
    vpu tree[100001];

    REP(i, n-1){
        int a, b;
        ull c;
        cin >> a >> b >> c;
        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }

    int q, k;
    cin >> q >> k;

    REP(i, q){
        int x, y;
        cin >> x >> y;
        ull dx[n];
        REP(i, n){
            dx[i] = 0;
        }

        queue<ull> qx;
        qx.push(x);
        while(!qx.empty()){
            ull a;
            a = qx.front();
            qx.pop();
            REP(j, tree[a].size()){
                ull next = tree[a][j].first;
                if(next!=x || dx[next]==0){
                    dx[next] = dx[a]+tree[a][j].second;
                    qx.push(next);
                }
            }
        }

        ull xk = dx[k];
        
        ull dk[n];
        REP(i, n){
            dk[i] = 0;
        }

        queue<ull> qk;
        qk.push(k);
        while(!qk.empty()){
            ull a;
            a = qk.front();
            qk.pop();
            REP(j, tree[a].size()){
                ull next = tree[a][j].first;
                if(next!=k || dk[next]==0){
                    dk[next] = dk[a]+tree[a][j].second;
                    qk.push(next);
                }
            }
        }

        ull ky = dk[y];
        cout << (xk + ky) << endl;
    }
}
