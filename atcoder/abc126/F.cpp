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

int m, k;
int main(){
  cin >> m >> k;
  int max_int = pow(2, m) - 1;
  
  if (k > max_int) {
    cout << -1 << endl;
    return 0;
  }

  if (k==0) {
  REP(i, pow(2, m)) {
    if (i<pow(2, m)-1) {
      cout << i << " " << i << " ";
    } else {
      cout << i << " " << i << endl;
    }
  }
    return 0;
  }

  if (m==1) {
    cout << -1 << endl;
    return 0;
  }

  for(int i=pow(2, m)-1; i>=0; i--) {
    if (i != k) {
      cout << i << " ";
    }
  }
  cout << k << " ";
  REP(i, pow(2, m)) {
    if (i!= k) {
      cout << i << " ";
    }
  }
  cout << k << endl;
}
