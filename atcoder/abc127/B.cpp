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

int r, d, x;
int main(){
  cin >> r >> d >> x;
  REP(i, 10) {
    x = r*x - d;
    cout << x << endl;
  }
}
