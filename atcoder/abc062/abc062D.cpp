#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<long long, long long> pll;

long long LL_MAX = 10e17;
long long former[100001];
long long latter[100001];
long long a[300000];

const int MAX_N = 1<<19;

int n;
int m;
pll pdat[2*MAX_N-1];
pll ldat[2*MAX_N-1];

void init(int n_, pll (&dat)[2*MAX_N-1]){
    m = 1;
    while(m<n_) m *= 2;
    REP(i, 2*m-1) dat[i] = pll(LL_MAX, 0);
    REP(i, m){
        dat[i+m-1].second = i;
    }
}

void update(int k, long long a, pll (&dat)[2*MAX_N-1]){
    int km = k+m-1;
    dat[km] = pll(a, k);

    while(km>0){
        km = (km-1) / 2;
        dat[km] = min(dat[km*2+1], dat[km*2+2]);
    }
}

pll query(int a, int b, int k, int l, int r, pll (&dat)[2*MAX_N-1]){
    if(r<=a || b<=l) return pll(LL_MAX, -1);

    if(a<=l && r<= b) return dat[k];
    else{
        pll vl = query(a, b, k*2+1, l, (l+r)/2, dat);
        pll vr = query(a, b, k*2+2, (l+r)/2, r, dat);
        return min(vl, vr);
    }
}

void write(pll (&dat)[2*MAX_N-1]){
    REP(i, 2*m-1) cout << dat[i].first << " ";
    cout << endl;
    REP(i, 2*m-1) cout << dat[i].second << " ";
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    REP(i, 3*n){
        cin >> a[i];
    }

    REP(i, n+1){
        former[i] = 0;
        latter[i] = 0;
    }

    init(n, pdat);
    init(n, ldat);
    REP(i, n){
        former[0] += a[i];
        latter[0] += a[2*n+i];
        update(i, a[i], pdat);
        update(i, -a[2*n+i], ldat);
    }

    REP(i, n){
        if(query(0, n, 0, 0, n, pdat).first<a[n+i]){
            former[i+1] = former[i] - query(0, n, 0, 0, n, pdat).first + a[n+i];
            update(query(0, n, 0, 0, n, pdat).second, a[n+i+1], pdat);
        } else {
            former[i+1] = former[i];
        }

        if(-query(0, n, 0, 0, n, ldat).first>a[2*n-(i+1)]){
            latter[i+1] = latter[i] - (-query(0, n, 0, 0, n, ldat).first) + a[2*n-(i+1)];
            update(query(0, n, 0, 0, n, ldat).second, -a[2*n-(i+1)], ldat);
        } else {
            latter[i+1] = latter[i];
        }
    }

    long long maxdiff = -LL_MAX;
    REP(i, n+1){
        maxdiff = max(maxdiff, former[i]-latter[n-i]);
    }
    cout << maxdiff << endl;
}
