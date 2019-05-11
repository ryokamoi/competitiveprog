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
int p[101];
int res_[101];
int rt_[101];
pii dp[500*100+1];
pii prevdp[500*100+1];
int main(){
  while(1) {
    cin >> n;
    if (n==0) break;

    p[0] = INF; // not used
    REP(i, n) {
      cin >> p[i+1];
    }

    REP(k, 500*n+1) {
      prevdp[k] = pii(0, INF);
      dp[k] = pii(0, INF);
    }
    prevdp[0] = pii(0, 0);

    for(int i=1; i<=n; i++) { 
      REP(k, 500*n+1) {
        int res = p[i] % 1000;
        int rt = 1000 - res;

        if (rt == 1000) {
          res = 1000;
          rt = 0;
        }

        dp[k] = prevdp[k];
        if (rt >= 500) {
          if (k>=(rt-500)) {
            pii prev = prevdp[k-(rt-500)];
            if (prev.second >= INF) continue;
            if (dp[k].first == prev.first+1) {
              dp[k] = pii(prev.first+1, min(dp[k].second, prev.second+p[i]));
            } else if (dp[k].first < prev.first+1) {
              dp[k] = pii(prev.first+1, prev.second+p[i]);
            }
          }
        } else {
          if (k<=500*n-(res-500)) {
            pii prev = prevdp[k+(res-500)];
            if (prev.second < INF) {
              if (dp[k].first < prev.first + 1) {
                dp[k].first = prev.first+1;
                dp[k].second = prev.second + p[i];
              } else if (dp[k].first == prev.first + 1) {
                dp[k].second = min(dp[k].second, prev.second+p[i]);
              }
            }
          }
          if (k>=rt) {
            pii prev = prevdp[k-rt];
            if (prev.second < INF) {
              if (dp[k].first == prev.first) {
                dp[k].second = min(dp[k].second, prev.second + p[i]);
              } else if (dp[k].first < prev.first) {
                dp[k].first = prev.first;
                dp[k].second = prev.second + p[i];
              }
            }
          }
        }
      }

      REP(k, 500*n+1) {
        prevdp[k] = dp[k];
      }
    }

    int maxnum = 0;
    int price;
    REP(k, 500*n+1) {
      if (dp[k].second >= INF) {
        continue;
      }

      if (dp[k].first > maxnum) {
        maxnum = dp[k].first;
        price = dp[k].second;
      } else if (dp[k].first == maxnum) {
        price = min(price, dp[k].second);
      }
    }

    cout << maxnum << " " << price << endl;
  }
}
