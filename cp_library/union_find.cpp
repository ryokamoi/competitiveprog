#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<long long, long long> pii;
typedef pair<long long, pair<int, int> > triple;

#define REP(i, n) for(int i=0; i<n; i++)

int par[max_n];
int r[max_n];

void init(int n){
    REP(i, n){
        par[i] = i;
        r[i] = 0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    if(r[x] < r[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(r[x] == r[y]) r[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
    init(n);
}
