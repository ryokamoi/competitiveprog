// Ryo Kamoi
// #define DEBUG

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
vector<int> r, w;
int dp[1010][1010];
int res_sum, full_time;

int solve(int idx, int time) {
  if (dp[idx][time] >=0) return dp[idx][time];

  if (idx == 0) {
    if (time >= w[idx]) {
      return dp[idx][time] = w[idx];
    } else {
      return dp[idx][time] = 0;
    }
  }

  if (time < w[idx]) {
    return solve(idx-1, time);
  }

  return dp[idx][time] = max(
      solve(idx-1, time),
      solve(idx-1, time-w[idx]) + w[idx]
      );
}

int main(){
  while(1) {
    cin >> n;
    if (n==0) break;

    r = vector<int>();
    w = vector<int>();
    REP(i, n) {
      REP(j, 1001) {
        dp[i][j] = -1;
      }
    }


    REP(i, n) {
      int ri, wi;
      cin >> ri >> wi;
      r.push_back(ri);
      w.push_back(wi);
    }

    sort(r.begin(), r.end());
    sort(w.begin(), w.end());

    if (n==1) {
      cout << r[0] * 2 + w[0] << endl;
      continue;
    }
    
    res_sum = 0;
    REP(i, n-1) {
      res_sum += r[i];
    }

    full_time = 0;
    REP(i, n) {
      full_time += r[i] + w[i];
    }

    if (res_sum >= r[n-1]) {
      cout << full_time << endl;
    } else {
      int fill_gap = solve(n-2, r[n-1] - res_sum);
#ifdef DEBUG
      cout << r[n-1]-res_sum << " " << fill_gap << endl;
#endif
      cout << full_time + (r[n-1] - res_sum - fill_gap) << endl;
    }
  }
}
