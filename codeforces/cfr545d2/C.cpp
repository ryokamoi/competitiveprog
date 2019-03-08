// Ryo Kamoi
// #define DEBUG

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<numeric>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int n, m;
int heights[1010][1010];
int colsl[1010][1010][2];
int rowsl[1010][1010][2];

int sl[1010][2];

void calcsl(int* rc, int size) {
    vector<int> indices(size);
    iota(indices.begin(), indices.end(), 0);

    // sort
    sort(indices.begin(), indices.end(),
            [&rc](int i1, int i2){return rc[i1]<rc[i2];});

    int rk[1010];
    int cornum=-1, cork=-1;
    REP(i, size) {
        if (cornum != rc[indices[i]]) {
            cork++;
            cornum = rc[indices[i]];
        }
        rk[indices[i]] = cork;
    }

    REP(i, size) {
        sl[i][0] = rk[i];
        sl[i][1] = cork - rk[i];
    }
}

int main(){
    cin >> n >> m;
    REP(i, n) {
        REP(j, m) {
            cin >> heights[i][j];
        }
    }

    // row
    int cor[1010];
    REP(i, n) {
        REP(j, m) {
            cor[j] = heights[i][j];
        }
        calcsl(cor, m);

        REP(j, m) {
            colsl[i][j][0] = sl[j][0];
            colsl[i][j][1] = sl[j][1];
        }
    }
    
    // col
    REP(j, m) {
        REP(i, n) {
            cor[i] = heights[i][j];
        }
        calcsl(cor, n);

        REP(i, n) {
            rowsl[i][j][0] = sl[i][0];
            rowsl[i][j][1] = sl[i][1];
        }
    }

    REP(i, n) {
        REP(j, m) {
            int output;
            output = max(colsl[i][j][0], rowsl[i][j][0]);
#ifdef DEBUG
            cout << colsl[i][j][0] << " " << rowsl[i][j][0] << endl;
            cout << colsl[i][j][1] << " " << rowsl[i][j][1] << endl;
#endif
            output += max(colsl[i][j][1], rowsl[i][j][1]);
            output ++;
            cout << output;

            if (j != m-1) cout << " ";
        }
        cout << endl;
    }
}
