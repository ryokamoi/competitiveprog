#include<iostream>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

double R, d;
ll n;
double x[100000], y[100000], r[100000];
double dis[100000];

double distance(double x, double y){
    return sqrt(x*x+y*y);
}

int main(){
    cin >> R >> d;
    cin >> n;

    REP(i, n){
        cin >> x[i] >> y[i] >> r[i];
        dis[i] = distance(x[i], y[i]);
    }

    ll count = 0;
    REP(i, n){
        if(dis[i]>=r[i]+R-d && dis[i]<=R-r[i]) count += 1;
    }

    cout << count << endl;
}
