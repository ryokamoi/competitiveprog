#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<double, pair<int, int> > pii;

int a, b, c, d, e, f;
bool ab[3001], cd[3001];
vector<pii> dens;

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    a = 100*a; b = 100*b;
    
    REP(i, f+1){
        ab[i] = false; cd[i] = false;
    }
    ab[0] = true; cd[0] = true;

    REP(i, f+1){
        if(i-a >= 0 && ab[i-a]) ab[i] = true;
        if(i-c >= 0 && cd[i-c]) cd[i] = true;
    }
    REP(i, f+1){
        if(i-b >= 0 && ab[i-b]) ab[i] = true;
        if(i-d >= 0 && cd[i-d]) cd[i] = true;
    }

    dens = vector<pii>();
    REP(i, f+1){
        if(ab[i]){
            int max_s = min(i*e/100, f-i);
            int sugar;
            for(int j=max_s; j>=0; j--){
                if(cd[j]){
                    sugar = j; break;
                }
            }
            pii d;
            d.first = (double)sugar * 100 / (sugar + i);
            d.second.first = i + sugar;
            d.second.second = sugar;
            dens.push_back(d);
        }
    }

    sort(dens.begin(), dens.end(), greater<pii>());
    cout << dens[0].second.first << " " << dens[0].second.second << endl;
}
