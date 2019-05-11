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

int n, m;
string recipe[1000];
map<string, int> dp;
vector<string> keys;

int intrecipe[1000];
int intdp[5000000];

string nand(string s1, string s2) {
  string output = s1;
  REP(i, m) {
    output[i] = '0' + (s1[i]-'0' + s2[i]-'0') % 2;
  }
  return output;
}

int str2int(string s) {
  int output = 0;
  REP(i, m) {
    if (s[i] == '1') {
      int shift = m-1-i;
      output += 1<<shift;
    }
  }
  return output;
}

int main(){
  while(1) {
    cin >> n >> m;
    if (n==0) break;

    REP(i, n) {
      cin >> recipe[i];
      intrecipe[i] = str2int(recipe[i]);
    }

    if (m <= 22) {
      int maxnum = pow(2, m);
      REP(i, maxnum) {
        intdp[i] = -1;
      }
      intdp[0] = 0;
      
      REP(i, n) {
        int cur_dp[5000000];
        REP(i, maxnum) {
          cur_dp[i] = -1;
        }

        REP(key, maxnum) {
          cur_dp[key] = max(cur_dp[key], intdp[key]);
          if (intdp[key] < 0) continue;

          int new_key = key^intrecipe[i];
          cur_dp[new_key] = max(intdp[new_key], intdp[key]+1);
        }

        REP(i, maxnum) {
          intdp[i] = cur_dp[i];
        }
      }
      cout << intdp[0] << endl;
    
    } else {
      dp = map<string, int>();
      keys = vector<string>();

      string init = string(m, '0');
      dp[init] = 0;
      keys.push_back(init);

      REP(i, n) {
        int keysize = keys.size();
        map<string, int> cur_dp;
        REP(j, keysize) {
          string key = keys[j];
          cur_dp[key] = max(cur_dp[key], dp[key]);
          string new_key = nand(key, recipe[i]);
          
          if (dp.find(new_key) != dp.end()) {
            cur_dp[new_key] = max(dp[new_key], dp[key] + 1);
          } else {
            cur_dp[new_key] = dp[key] + 1;
            keys.push_back(new_key);
          }
        }
        dp = cur_dp;
      }

      cout << dp[init] << endl;
    }
  }
}
