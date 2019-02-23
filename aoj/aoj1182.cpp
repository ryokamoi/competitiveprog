#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, m, c, s, g;

struct edge {int to, dist, com;};
vector<edge> graph[200];

int comcost[30][200*];

def calccost(int m, int d) {
}

int main() {
    while(true) {
        cin >> n >> m >> c >> s >> g;
        if (n==0) break;

        REP(i, n) {
            int x, y, d, cm;
            cin >> x >> y >> d >> cm;

            edge e;
            e.to = y-1;
            e.dist = d;
            e.com = cm;
            graph[x-1].push_back(e);
            
            e.to = x-1;
            e.dist = d;
            e.com = cm;
            graph[y-1].push_back(e);
        }

        REP(i, c) {
            
        }
    }
}
