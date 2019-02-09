#include<iostream>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

double k, r, l;
double p, e, t;

double bs(int tk, double r, double l){
    tk += 1;
    double h = (r+l) / 2;

    if(tk<=k){
        if(r>=t-e && l<=t+e){
            return 1;
        } else if (r>t+e || l<t-e){
            return 0;
        } else if (h<t){
            return (1-p)*bs(tk,h,l) + p*bs(tk,r,h);
        } else {
            return p*bs(tk,h,l) + (1-p)*bs(tk,r,h);
        }
    } else {
        if(h<=t+e && h>=t-e){
            return 1;
        } else {
            return 0;
        }
    }
}

int main(){
    cin >> k >> r >> l;
    cin >> p >> e >> t;

    double output = bs(0, r, l);
    cout << fixed << setprecision(6) << output << endl;
}
