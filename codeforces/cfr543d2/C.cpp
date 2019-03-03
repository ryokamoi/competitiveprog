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

int n, k;
int status[110][150100];
int sol[110][150100];
bool used[1010];
int d[150100];

int main(){
    cin >> n >> k;

    REP(i, k) {
        REP(j, 150100) {
            status[i][j] = -1;
        }
    }

    queue<int> que;
    REP(i, n) {
        int ai;
        cin >> ai;
        que.push(ai);
    }

    REP(i, n) {
        used[i] = false;
    }

    REP(i, 150100) d[i] = -1;

    int idx[110];
    REP(i, k) idx[i] = 0;

    int solidx = 0;
    while(!que.empty()) {
        int ai = que.front(); que.pop();
        int mink;
        int minidx = 150100;
        REP(i, k) {
            if (idx[i] < minidx) {
                minidx = idx[i];
                mink = i;
            }
        }

        for (int i=1; i<=ai; i++) {
            status[mink][minidx+i-1] = i;
            sol[mink][minidx+i-1] = solidx;
        }
        status[mink][minidx+ai] = -10;
        idx[mink] += ai;
    
        solidx++;
    }

    int done = 0;
    d[0] = 0;
    REP(i, 150100) {
        if (i==0) continue;
        REP(j, k) {
            if (status[j][i] == 1 || status[j][i] == -10) done++;
        }
        d[i] = floor(100.0 * (double)done/(double)n + 0.5);
    }

    int output = 0;
    REP(i, 150100) {
        REP(j, k) {
            if (used[sol[j][i]]) continue;
            if (status[j][i] == d[i]) {
                output ++;
                used[sol[j][i]] = true;
            }
        }
    }

    cout << output << endl;
}
