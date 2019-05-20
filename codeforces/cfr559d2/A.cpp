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
string s;
int main(){
  cin >> n;
  cin >> s;
  int output = 0;
  REP(i, n) {
    if (s[i] == '+') {
      output++;
    } else {
      if (output > 0) {
        output --;
      }
    }
  }
  cout << output << endl;
}
