// Ryo Kamoi
//#define DEBUG

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
double prob;

int coin_count(int deme) {
  int output = 0;
  int point = deme;
  while (k > point) {
    point *= 2;
    output ++;
  }
  return output;
}

int main(){
  cin >> n >> k;
  prob = 0.0;

  for(int i=1; i<=n; i++) {
    int num = coin_count(i);
#ifdef DEBUG
    cout << num << endl;
#endif
    prob += pow(0.5, num) / (double)n;
  }

  printf("%.12lf\n", prob);
}
