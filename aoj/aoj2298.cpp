#include<iostream>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, k, t, u, v, l;
int d[10000];
int c[10000];
int s[10000];

int main(){
    cin >> n >> k >> t >> u >> v >> l;

    REP(i, l){
        c[i] = 0; 
        d[i] = 0;
    }
    REP(i, n){
        int di;
        cin >> di;
        d[di] = 1;
    }

    REP(i, l){
        int g = min(i+v*t, l);
        if(d[i]==1 && s[i]==1){
            if(c[i]+1<=k){
                for(int j=i; j<l; j++){
                    c[j] = c[j] + 1;
                }
            } else {
                for(int j=i; j<g; j++){
                    s[j] = 1;
                }
            }
        } else if(d[i]==1 && s[i]==0){
            for(int j=i; j<g; j++){
                s[j] = 1;
            }
        } else if(d[i]==0 && s[i]==1){
            continue;
        } else {
            if(c[i]>0){
                for(int j=i; j<g; j++){
                    s[j] = 1;
                }
                for(int j=i; j<l; j++){
                    c[j] = c[j] - 1;
                }
            }
        }
    }

    int normal = 0;
    int accel = 0;
    REP(i, l){
        if(s[i] == 0){
            normal += 1;
        } else {
            accel += 1;
        }
    }

    double output = (double)normal/u + (double)accel/v;
    cout << fixed << setprecision(7) << output << endl;
}
