// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int n, m;
vector<int> ans;
vector<pair<int, int>> edges;

vector<int> graph[300000];
int state[300000];
bool done[300000];

bool solve(int v) {
    if (done[v]) return true;
    done[v] = true;

    if (state[v] == -1) {
        REP(i, graph[v].size()) {
            int to = graph[v][i];
            if (state[to] != -1) {
                state[v] = 1-state[to];
                break;
            }
        }
    }

    if (state[v] == -1) state[v] = 0;

    REP(i, graph[v].size()) {
        int to = graph[v][i];
        if (state[to] == -1) {
            state[to] = 1-state[v];
            if (solve(to)) {
                continue;
            } else {
                return false;
            }
        }
        if (state[to] == state[v]) {
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    REP(i, n) {
        state[i] = -1;
        done[i] = false;
    }

    REP(i, m) {
        int ui, vi;
        cin >> ui >> vi;
        graph[ui-1].push_back(vi-1);
        graph[vi-1].push_back(ui-1);
        edges.push_back(pii(ui-1, vi-1));
    }

    bool flag = solve(0);
    if (!flag) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    REP(i, m) {
        cout << state[edges[i].first];
    }
    cout << endl;
}
