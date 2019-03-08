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

string s, t;
int res[2];
int tcount[2];
int tadd[2];

int main(){
    cin >> s >> t;
    
    REP(i, 2) res[i] = 0;
    REP(i, s.size()) {
        res[s[i]-'0']++;
    }

    REP(i, 2) tcount[i] = 0;
    REP(i, t.size()) {
        tcount[t[i]-'0']++;
    }

    REP(i, 2) tadd[i] = 0;
    string tsubst;
    bool eq = true;
    for(int i=t.size()-1; i>=1; i--) {
        eq = true;
        REP(j, i){
            if(t[j] != t[t.size()-i+j]) {
                eq = false; break;
            }
        }

        if(eq) {
            tsubst = t.substr(i, t.size()-i);
            REP(j, tsubst.size()) {
                tadd[tsubst[j]-'0']++;
            }
#ifdef DEBUG
            cout << i << endl;
            cout << tsubst << endl;
#endif
            break;
        }
    }

    if (!eq) {
        tsubst = t;
        REP(i, 2) tadd[i] = tcount[i];
    }

    bool first = true;
    while(1) {
        if (first && res[0]>=tcount[0] && res[1]>=tcount[1]) {
            cout << t;
            res[0] -= tcount[0];
            res[1] -= tcount[1];
            first = false;
        } else if (!first && res[0]>=tadd[0] && res[1]>=tadd[1]) {
            cout << tsubst;
            res[0] -= tadd[0];
            res[1] -= tadd[1];
        } else {
            REP(i, res[0]) cout << '0';
            REP(i, res[1]) cout << '1';
            break;
        }
    }
    cout << endl;
}
