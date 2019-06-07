// Ryo Kamoi
// #define DEBUG

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

string s;
int idx = 0;
ll output = 0;
ll anum;

void findabc() {
    if (s[idx] == 'A') {
      if (idx+2 < s.size()) {
        if (s[idx+1]=='B' && s[idx+2]=='C') {
          output += anum+1;
          s[idx+2] = 'A';
          idx++;
        } else {
          anum++;
        }
      }
    } else {
      anum = 0;
    }
}

int main(){
  cin >> s;
  anum = 0;

  while(idx < s.size()) {
    findabc();
    idx++;
  }

  cout << output << endl;
}
