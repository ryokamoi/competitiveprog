#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, m;
vector<pair<int, ll>> g[300];

bool eq(int i, int j){
    queue<pair<pair<int, int>, ll> > que;
    bool used[300][300];

    used[i][j] = true;
    que.push(make_pair(make_pair(i, j), 0));

    while(!que.empty()){
        pair<pair<int, int>, ll> q = que.front();
        int to = q.first.second;
        ll cost = q.second;
        REP(k, g[to].size()){
            if(!used[to][g[to][k]]){
            }
        }
    }
}

int main(){
    cin >> n >> m;
    
    REP(i, n){
        ll a, b, c;
        cin >> a >> b >> c;
        pair<int, ll> init;
        init = make_pair(b, c);
        g[a-1].push_back(init);
    }

    bool flag = true;
    REP(i, n){
        REP(j, g[i].size()){
            if(!eq(i, g[i][j].first)) flag = false;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
