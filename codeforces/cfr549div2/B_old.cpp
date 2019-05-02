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
vector<ll> v;
int main(){
    cin >> s;
    REP(i, s.size()) {
        if (s[i] == '0') {
            ll idx = i-1;
            while(1) {
                v[idx]--;
                if (v[idx] != 0) break;
                if (idx==0) {
                    v[idx] = 1; break;
                }
                v[idx] = 9;
                idx--;
            }
            REP(j, s.size()-i) {
                v.push_back(9);
            }
            break;
        } else {
            v.push_back(s[i]-'0');
        }
    }

    ll output = 1;
    REP(i, s.size()) {
        output *= v[i];
    }
    cout << output << endl;
}
