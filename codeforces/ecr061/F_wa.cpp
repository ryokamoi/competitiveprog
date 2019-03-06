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
string s;
int dp[1000][1000];

int search(int left, int right) {
    if (dp[left][right] >= 0) return dp[left][right];

    int minnum = 1000000000;
    
    bool flag = true;
    for(int i=left; i<right-1; i++) {
        if(s[i] != s[i+1]) {
            flag = false;
            minnum = min(minnum,
                        search(left, i+1) + search(i+1, right));
        }
    }

    if (flag) {
        return dp[left][right] = 1;
    }

    if(s[left] == s[right-1]) {
        int corsum = 1;
        int l, r;
        for(int i=left; i<right-1; i++) {
            if (s[i]==s[left] && s[i+1]!=s[left]) {
                l = i+1;
            }
            if (s[i]!=s[left] && s[i+1]==s[left]) {
                r = i+1;
                corsum += search(l, r);
            }
        }
        minnum = min(minnum, corsum);

        //
        for(int i=left; i<right; i++) {
            if (s[i] != s[left]) {
                l = i;
                break;
            }
        }
        for(int i=right-1; i>=left; i--) {
            if (s[i] != s[left]) {
                r = i+1;
                break;
            }
        }
        minnum = min(minnum, 1+search(l, r));
    }

    return dp[left][right] = minnum;
}

int main(){
    cin >> n;
    cin >> s;

    REP(i, n) {
        for(int j=i+1; j<=n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << search(0, n) << endl;
}
