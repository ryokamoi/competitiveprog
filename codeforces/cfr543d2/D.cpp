// Ryo Kamoi
#define DEBUG

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

map<int, int> b;
map<int, int> req;

int n, k, m, s;

int a[500010];

int main(){
    cin >> n >> k >> m >> s;
    REP(i, m) {
        cin >> a[i];
    }

    REP(i, s) {
        int bi;
        cin >> bi;
        if (b.find(bi) != b.end()) {
            b[bi]++;
        } else {
            b[bi] = 1;
        }
    }

}
