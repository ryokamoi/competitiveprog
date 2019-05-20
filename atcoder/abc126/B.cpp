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

int s;

bool yymm(int fst, int snd) {
  if (snd <= 0 || snd > 12) {
    return false;
  }
  return true;
}

bool mmyy(int fst, int snd) {
  if (fst == 0 || fst > 12) {
    return false;
  }
  return true;
}

int main(){
  cin >> s;
  int fst = s / 100;
  int snd = s % 100;

  bool ym = yymm(fst, snd);
  bool my = mmyy(fst, snd);

  if (ym && my) {
    cout << "AMBIGUOUS" << endl;
  } else if (ym) {
    cout << "YYMM" << endl;
  } else if (my) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }
}
