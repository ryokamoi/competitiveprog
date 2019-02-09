#include<iostream>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

typedef pair<ll, ll> pll; // removed index, gcd;

ll n, a[200000];
vector<ll> g[200000];
vector<ll> route[200000];
bool used[200000];
ll beauty[200000];
pll log[200000];

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

vector<ll> bigcd(vector<ll> g1, vector<ll> g2){
    if(g1.size() == 1 && g2.size()==1){
        return vector<ll>(gcd(g1[0], g2[0]));
    } else {
        if(g1.size()>1){
            vector<ll> g11(g1.begin(), g1.begin()+g1.size()/2);
            vector<ll> g12(g1.begin()+g1.size()/2, g1.end());
            g1 = bigcd(g11, g12);
        }
        if(g2.size()>1){
            vector<ll> g21(g2.begin(), g2.begin()+g2.size()/2);
            vector<ll> g22(g2.begin()+g2.size()/2, g2.end());
            g2 = bigcd(g21, g22);
        }
        return bigcd(g1, g2);
    }
}

void find_route(int v){
    if(v==0){
        beauty[v] = a[v];
        log[v] = pll(v, a[v]);
    } else {
        pll l = log[route[v][-2]];

        vector<ll> ra;
        REP(i, route[v].size()){
            ra.push_back(a[route[v][i]]);
        }

        vector<ll> r = ra;
        r.erase(r.begin()+l.first);
        ll c1;
        if(r.size()>1){
            vector<ll> g1(r.begin(), r.begin()+r.size()/2);
            vector<ll> g2(r.begin()+r.size()/2, r.end());
            c1 = bigcd(g1, g2)[0];
        } else {
            c1 = r[0];
        }
        ll nx_erase;

        if(c1>=l.second){
            nx_erase = l.first;
            beauty[v] = c1;
        } else {
            nx_erase = v;
            beauty[v] = l.second;
        }

        ll nx_gcd;
        if(route[v].size()>1){
            vector<ll> r1(ra.begin(), ra.begin()+ra.size()/2);
            vector<ll> r2(ra.begin()+ra.size()/2, ra.end());
            nx_gcd = bigcd(r1, r2)[0];
        } else {
            nx_gcd = a[route[v][0]];
        }
        log[v] = pll(nx_erase, nx_gcd);
    }

    REP(i, g[v].size()){
        if(!used[g[v][i]]){
            vector<ll> r = route[v];
            r.push_back(g[v][i]);
            route[g[v][i]] = r;
            used[g[v][i]] = true;
            find_route(g[v][i]);
        }
    }
    return;
}

int main(){
    cin >> n;
    REP(i, n) cin >> a[i];

    REP(i, n-1){
        ll x, y;
        cin >> x >> y;
        x -= 1; y -= 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    REP(i, n) used[i] = false;
    used[0] = true;
    vector<ll> init;
    init.push_back(0);
    route[0] = init;
    find_route(0);

    REP(i, n-1){
        cout << beauty[i] << " ";
    }
    cout << beauty[n-1] << endl;
}
