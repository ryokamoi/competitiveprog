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
vector<int> v;
int idx;
int main(){
    cin >> s;
    ll output = 1;
    REP(i, s.size()) {
        output *= s[i]-'0';
    }

    REP(i, s.size()-1) {
        v = vector<int>();
        REP(j, i+1) {
            v.push_back(s[j]-'0');
        }
        idx = i;
        while(1) {
            v[idx]--;
            if (v[idx] != 0) break;
            if (idx==0) {
                v[idx] = 1; break;
            }
            v[idx] = 9;
            idx--;
        }
        ll ans = 1;
        REP(j, v.size()) {
            ans *= v[j];
        }
        REP(j, s.size()-v.size()) {
            ans *= 9;
        }
        output = max(output, ans);
    }
    cout << output << endl;
}
