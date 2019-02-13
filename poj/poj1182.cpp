#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int par[3 * 50050];
int rk[3 * 50050];

void init (int n) {
    REP(i, n) {
        par[i] = i;
        rk[i] = 0;
    }
}

int find (int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return ;
    } else {
        if (rk[x] < rk[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rk[x] == rk[y]) {
                rk[x] += 1;
            }
        }
        return ;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, k;
    cin >> n >> k;

    init(3*n);

    int miss = 0;
    REP(i, k) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        
        if (x<=0 || x>n || y<=0 || y>n) {
            miss ++; continue;
        }
        
        x --; y--;
        
        if (t == 1) {
            if (same(x, n+y) || same(x, 2*n+y)) {
                miss++;
            } else {
                unite(x, y); unite(x+n, y+n); unite(x+2*n, y+2*n);
            }
        }

        if (t == 2) {
            if (same(x, y) || same(x, 2*n+y)) {
                miss++;
            } else {
                unite(x, y+n); unite(x+n, y+2*n); unite(x+2*n, y);
            }
        }
    }

    printf("%d\n", miss);
}
