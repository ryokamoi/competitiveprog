// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int n;
vector<int> sizes;
set<int> cands;

int main(){
    cin >> n;
    REP(i, n) {
        int ai;
        cin >> ai;
        sizes.push_back(ai);
    }

    sort(sizes.begin(), sizes.end());

    REP(i, n-1) {
        for(int j=i+1; j<n; j++) {
            cands.insert(sizes[i] + sizes[j]);
        }
    }

    int output = -1;
    set<int>::iterator it;
    for(it = cands.begin(); it!=cands.end(); ++it) {
        int s = *it;
        int l=0, r=n-1;
        int c = 0;
        while(r>l) {
            int cor = sizes[l] + sizes[r];
            if (cor == s) {
                c++;
                l++; r--;
            }
            if (cor < s) {
                l++;
            }
            if (cor > s) {
                r--;
            }
        }
        output = max(c, output);
    }
    cout << output << endl;
}
