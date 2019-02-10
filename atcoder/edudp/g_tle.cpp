#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct edge{int from, to; };

int N, M;
edge eg[100010];

int sdist[100010];

int main() {
    cin >> N >> M;

    REP(i, M) {
        int x, y;
        cin >> x >> y;

        edge e;
        e.from = x-1;
        e.to = y-1;
        eg[i] = e;
    }
    
    REP(i, N) {
        sdist[i] = 0;
    }

    REP(i, M) {
        REP(j, M) {
            int x = eg[j].from;
            int y = eg[j].to;

            sdist[x] = max(sdist[x], sdist[y]+1);
        }
    }

    int output = 0;
    REP(i, N) {
        output = max(output, sdist[i]);
    }
    cout << output << endl;
}
