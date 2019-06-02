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

int n, k;
string s;
int main(){
  cin >> n >> k;
  cin >> s;

  if (s[k-1] == 'A') {
    s[k-1] = 'a';
  }
  if (s[k-1] == 'B') {
    s[k-1] = 'b';
  }
  if (s[k-1] == 'C') {
    s[k-1] = 'c';
  }

  cout << s << endl;
}
