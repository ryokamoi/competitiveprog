// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int n;
int p[100010];
int c[100010];
int r[100010];
vector<int> d;

int main(){
    cin >> n;
    REP(i, n) {
        r[i] = 0;
    }

    REP(i, n) {
        cin >> p[i] >> c[i];
        p[i]--;
    }

    REP(i, n) {
        if (c[i] == 0) {
            int par = p[i];
            while(1) {
                if (par == -2) break;
                if (r[par] == 1) {
                    break;
                }
                r[par] = 1;
                if (c[par] == 1) {
                    break;
                }
                par = p[par];
            }
        }
    }

    REP(i, n) {
        if (c[i] == 1 && r[i] == 0) {
            d.push_back(i+1);
        }
    }

    if (d.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    sort(d.begin(), d.end());
    REP(i, d.size()) {
        cout << d[i];
        if (i!=d.size()-1) cout << " ";
    }
    cout << endl;
}
