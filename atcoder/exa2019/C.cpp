// Ryo Kamoi
//#define DEBUG

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

int n, q;
string s;

char t[200010], d[200010];
int lidx, ridx;
int main(){
    cin >> n >> q;
    cin >> s;

    REP(i, q) {
        cin >> t[i] >> d[i];
    }

    lidx = 0;
    ridx = n-1;
    for(int i=q-1; i>=0; i--) {
        if (d[i]=='R') {
            if (t[i] == s[ridx]) ridx--;
            if (lidx > 0) {
                if (t[i] == s[lidx-1]) lidx--;
            }
        }

        if (d[i]=='L') {
            if (t[i] == s[lidx]) lidx++;
            if (ridx < (n-1)) {
                if (t[i] == s[ridx+1]) ridx++;
            }
        }
#ifdef DEBUG
        cout << i << " " << d[i] << " " << lidx << " " << ridx << endl;
#endif
    }

    cout << max(0, ridx-lidx+1) << endl;
}
