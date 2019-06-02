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

string s;
int main(){
  cin >> s;
  
  int n = 0;
  REP(i, s.size()) {
    if (s[i] == 'o') {
      n++;
    }
  }

  n += 15 - s.size();
  if (n >= 8) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
