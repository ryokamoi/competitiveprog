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

int alp[30];
int n;
int main(){
    cin >> n;
    REP(i, n) {
        REP(j, 30) {
            alp[j] = 0;
        }
        string s;
        cin >> s;
        
        vector<int> seq;
        REP(j, s.size()) {
            int cor = s[j]-'0';
            seq.push_back(cor);
        }
        sort(seq.begin(), seq.end());
        
        bool flag = true;
        for(int j=1; j<seq.size(); j++) {
            if (seq[j] - seq[j-1] != 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
