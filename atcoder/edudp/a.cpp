#include <iostream>
#include <cstdlib>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int cost[100010];
int h[100010];

int main() {
    int N;
    cin >> N;

    cost[0] = 0;
    REP(i, N) {
        cin >> h[i+1];
        cost[i+1] = 0;
    }

    for(int i=1; i<N; i++) {
        if (i+1 >= 3) {
            cost[i+1] = min(cost[i]+abs(h[i]-h[i+1]),
                        cost[i-1]+abs(h[i-1]-h[i+1]));
        } else {
            cost[i+1] = cost[i] + abs(h[i]-h[i+1]);
        }
    }

    cout << cost[N] << endl;
}
