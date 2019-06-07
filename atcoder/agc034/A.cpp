// Ryo Kamoi
#define DEBUG

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

int n;
int a, b, c, d;
string s;

bool conseq_stones(int st, int gl) {
  bool prev = false;
  for (int i=st; i<=gl; i++) {
    if (s[i] == '#') {
      if (prev) {
        return true;
      }
      prev = true;
    } else {
      prev = false;
    }
  }
  return false;
}

bool three(int st, int gl) {
  int num = 0;
  for (int i=st; i<=gl; i++) {
    if (s[i] == '#') {
      num = 0;
    } else {
      num++;
      if (num == 3) return true;
    }
  }
  return false;
}

int main(){
  cin >> n >> a >> b >> c >> d;
  cin >> s;

  if (c<a || d<b) {
    cout << "No" << endl;
    return 0;
  }

  if (s[a-1]=='#' || s[b-1]=='#' || s[c-1]=='#' || s[d-1]=='#') {
    cout << "No" << endl;
    return 0;
  }


  if (conseq_stones(a-1, c-1) || conseq_stones(b-1, d-1)) {
    cout << "No" << endl;
    return 0;
  }
  
  if ((b>a && c>d || a>b && d>c)) {
    if (!three(max(a, b)-2, min(c, d))) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
