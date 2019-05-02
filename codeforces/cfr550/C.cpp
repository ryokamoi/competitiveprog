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

int n;
vector<int> ini;
vector<int> inc;
vector<int> decr;
int main(){
    cin >> n;
    REP(i, n) {
        int ai;
        cin >> ai;
        ini.push_back(ai);
    }

    sort(ini.begin(), ini.end());
    int prev = -10;
    REP(i, ini.size()) {
        if (prev != ini[i]) {
            inc.push_back(ini[i]);
        } else {
            if (decr.size()>0 && decr[decr.size()-1]==ini[i]) {
                cout << "NO" << endl;
                return 0;
            }
            decr.push_back(ini[i]);
        }
        prev = ini[i];
    }

    cout << "YES" << endl;
    cout << inc.size() << endl;
    REP(i, inc.size()) {
        cout << inc[i];
        if (i!=inc.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
    
    cout << decr.size() << endl;
    REP(i, decr.size()) {
        cout << decr[decr.size() - i - 1];
        if (i!=decr.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
}
