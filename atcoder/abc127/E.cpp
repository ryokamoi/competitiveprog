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

ll R = 1000000009;

vector<ll> a, b;

ll q;
int main(){
  cin >> q;
  REP(i, q) {
    int query;
    cin >> query;
    if (query == 1) {
      ll ai, bi;
      cin >> ai >> bi;
      a.push_back(ai);
      b.push_back(bi);
    } else {
      ll output_x;
      ll output = (ll)INF * (ll)INF;
      REP(i, a.size()) {
        ll x = a[i];
        ll cur = 0;
        REP(j, a.size()) {
          cur += abs(a[j] - x) + b[j];
        }
        if (cur == output) {
          output_x = min(x, a[i]);
        }
        if (cur < output) {
          output_x = a[i];
          output = cur;
        }
      }
      cout << output_x << " " << output << endl;
    }
  }
}
