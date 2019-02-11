#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
const int max_n = 10e5;
int x[max_n+1];
int y[max_n+1];
int w[max_n+1];

int wseg[2*max_n+1];
int hseg[2*max_n+1];

int pow2(int n_){
    int n=1;
    while(n<n_) n*=2;
    return n;
}

void init(int n_, int seg[]){
    int n = pow2(n_);
    REP(i, 2*n-1) seg[i] = 1;
    REP(i, (2*n-1)-(n-n_)) seg[i] = 0;
}

void query(int a, int b, int k, int l, int r, int seg[]){
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){
        seg[k] = 1; return;
    } else {
        query(a, b, k*2+1, l, (l+r)/2, seg);
        query(a, b, k*2+2, (l+r)/2, r, seg);
    }
}

int update(int n_, int seg[]){
    int n=pow2(n_);
    REP(i, n){
        int k = i+n-1;
        while(k>0){
            k = (k-1)/2;
            seg[k] = max(seg[k], min(seg[k*2+1], seg[k*2+2]));
        }
    }
    return seg[0];
}

int main(){
    int n, W, H;
    cin >> n >> W >> H;

    REP(i, n){
        cin >> x[i] >> y[i] >> w[i];
    }

    init(2*W+1, wseg);
    init(2*H+1, hseg);

    REP(i, n){
        query(max(0, 2*(x[i]-w[i])), min(2*W+1, 2*(x[i]+w[i])+1), 0, 0, pow2(2*W+1), wseg);
        query(max(0, 2*(y[i]-w[i])), min(2*W+1, 2*(y[i]+w[i])+1), 0, 0, pow2(2*H+1), hseg);
    }

    /*
    REP(i, 2*pow2(2*W+1)-1) cout << wseg[i];
    cout << endl;
    REP(i, 2*pow2(2*H+1)-1) cout << hseg[i];
    cout << endl;
    */
    if(update(2*W+1, wseg) || update(2*H+1, hseg)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
