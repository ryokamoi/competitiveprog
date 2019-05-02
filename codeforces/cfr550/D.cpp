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

ll n;
vector<ll> a;
ll c[300000];
int main(){
    cin >> n;
    REP(i, 300000) {
        c[i] = 0;
    }

    REP(i, n) {
        int ai;
        cin >> ai;
        a.push_back(ai);
        c[ai]++;
    }

    int maxc = -1;
    int maxn;
    REP(i, 300000) {
        if (maxc < c[i]) {
            maxc = c[i];
            maxn = i;
        }
    }

    cout << n-maxc << endl;
    if (n-maxc == 0) return-0;

    int fstind=0;
    while(true) {
        if (a[fstind]==maxn) break;
        fstind++;
    }

#ifdef  DEBUG
    cout << maxn << " " << fstind << endl;
#endif

    for(int i=fstind-1; i>=0; i--) {
        if (a[i] < maxn) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
        cout << i+1 << " " << i+2 << endl;
    }

    for(int i=fstind+1; i<n; i++) {
        if (a[i]==maxn) continue;
        if (a[i] > maxn) {
            cout << "2 ";
        } else {
            cout << "1 ";
        }
        cout << i+1 << " " << i << endl;
    }
}
