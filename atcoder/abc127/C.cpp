// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int INF = 1000000000;

int n, m;
int low, up;
int main(){
  cin >> n >> m;
  low = -1; up = INF;

  REP(i, m) {
    int l, r;
    cin >> l >> r;
    low = max(low, l);
    up = min(up, r);
  }

  cout << max(0, up-low+1) << endl;
}
