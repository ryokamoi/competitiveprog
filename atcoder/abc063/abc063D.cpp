#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<long long, int> pli;

int n;
long long a, b;
vector<pli> h;
long long c[100000];
long long bcount;
long long output;

int main(){
    cin >> n >> a >> b;
    REP(i, n){
        long long hi;
        cin >> hi;
        h.push_back(pli(hi, i));
    }

    sort(h.begin(), h.end(), greater<pli>());
    REP(i, n){
        h[i].first = max(0LL, h[i].first - b*bcount);
        long long m = h[i].first/a;
        bcount += m;
        c[h[i].second] = bcount;
        h[i].first -= a*m;

        output += m;
    }

    REP(i, n){
        h[i].first = max(0LL, h[i].first - b*(bcount-c[h[i].second]));
        c[h[i].second] = bcount;
    }

    sort(h.begin(), h.end(), greater<pli>());
    
    REP(i, n){
        h[i].first = max(0LL, h[i].first - b*(bcount-c[h[i].second]));
        if(h[i].first>0){
            bcount += 1;
            output += 1;
        }
    }

    cout << output << endl;
}
