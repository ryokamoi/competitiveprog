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
vector<int> b;
vector<int> ans;

int main(){
    cin >> n;
    REP(i, n) {
        int bi;
        cin >> bi;
        b.push_back(bi);
    }

    REP(i, n) {
        bool flag = false;
        REP(j, b.size()) {
            int idx= b.size()-j-1;
            if (b[idx] == idx+1) {
                ans.push_back(b[idx]);
                b.erase(b.begin()+idx);
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << -1 << endl;
            return 0;
        }
    }

    REP(i, n) {
        cout << ans[n-i-1] << endl;
    }
}
