#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<long long, long long> pii;
typedef pair<long long, pair<int, int> > triple;

#define REP(i, n) for(int i=0; i<n; i++)

const int max_n = 10e5;
vector<pii> xind;
vector<pii> yind;
vector<triple> dist;

int n;

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
    xind.clear();
    yind.clear();
    dist.clear();

    cin >> n;
    REP(i, n){
        long long x, y;
        cin >> x >> y;
        xind.push_back(pii(x, i));
        yind.push_back(pii(y, i));
    }
    sort(xind.begin(), xind.end());
    sort(yind.begin(), yind.end());

    REP(i, n-1){
        dist.push_back(triple(xind[i+1].first - xind[i].first, pii(xind[i].second, xind[i+1].second)));
        dist.push_back(triple(yind[i+1].first - yind[i].first, pii(yind[i].second, yind[i+1].second)));
    }
    sort(dist.begin(), dist.end());

    init(n);
    long long money = 0;
    int count = 0;
    REP(i, dist.size()){
        if(count == n-1) break;
        
        long long d = dist[i].first;
        long long x = dist[i].second.first;
        long long y = dist[i].second.second;

        if(same(x, y)){
            continue;
        } else {
            unite(x, y);
            money += d;
            count += 1;
        }
    }

    cout << money << endl;
}
