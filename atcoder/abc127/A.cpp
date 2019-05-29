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

int a, b;
int main(){
  cin >> a >> b;
  if (a >= 13) {
    cout << b << endl;
  } else if (a >= 6) {
    cout << b/2 << endl;
  } else {
    cout << 0 << endl;
  }
}
