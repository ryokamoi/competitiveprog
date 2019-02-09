#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, pair<int, int> > triple;

#define REP(i, n) for(int i=0; i<n; i++)

int const max_n = 200000;
int n, k, l;
map<pii, int> c;
int par1[max_n], par2[max_n];
int r1[max_n], r2[max_n];

void init(int n, int (&par)[max_n], int (&r)[max_n]){
    REP(i, n){
        par[i] = i;
        r[i] = 0;
    }
}

int find(int x, int (&par)[max_n]){
    if(par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x], par);
    }
}

void unite(int x, int y, int (&par)[max_n], int (&r)[max_n]){
    x = find(x, par);
    y = find(y, par);

    if(x == y) return;
    if(r[x] < r[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(r[x] == r[y]) r[x]++;
    }
}

bool same(int x, int y, int (&par)[max_n]){
    return find(x, par) == find(y, par);
}

int main(){
    cin >> n >> k >> l;
    init(n, par1, r1);
    REP(i, k){
        int p, q;
        cin >> p >> q;
        unite(p-1, q-1, par1, r1);
    }
    init(n, par2, r2);
    REP(i, l){
        int r, s;
        cin >> r >> s;
        unite(r-1, s-1, par2, r2);
    }

    REP(i, n){
        if(c.find(make_pair(find(i, par1), find(i, par2))) != c.end()){
            c[make_pair(find(i, par1), find(i, par2))] += 1;
        } else {
            c[make_pair(find(i, par1), find(i, par2))] = 1;
        }
    }
    REP(i, n){
        cout << c[make_pair(find(i, par1), find(i, par2))];
        if(i<n-1){
            cout << " ";
        } else {
            cout << endl;
        }
    }
}
