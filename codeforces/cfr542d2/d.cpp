#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, m;
int cnum[10000];
int mindist[10000];

int dist(int from, int to) {
    if (to >= from) {
        return to - from;
    } else {
        return to+n - from;
    }
}

int main() {
    cin >> n >> m;

    REP(i, n) {
        cnum[i] = 0;
        mindist[i] = 1000000000;
    }

    REP(i, m) {
        int a, b;
        cin >> a >> b;
        cnum[a-1]++;
        mindist[a-1] = min(mindist[a-1], dist(a-1, b-1));
    }

    REP(i, n) {
        int output = 0;
        REP(j, n) {
            if (cnum[j] == 0) continue;
            output = max((cnum[j]-1)*n + dist(i, j) + mindist[j], output);
        }
        cout << output;
        if (i<n-1) cout << " ";
    }
    cout << endl;
}
