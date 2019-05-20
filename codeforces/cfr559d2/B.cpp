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
int a[300010];
int main(){
  cin >> n;
  REP(i, n) {
    cin >> a[i];
  }

  int output = INF;
  REP(i, n) {
    int diff = max(i, (n-1)-i);
    output = min(output, a[i] / diff);
  }

  cout << output << endl;
}
