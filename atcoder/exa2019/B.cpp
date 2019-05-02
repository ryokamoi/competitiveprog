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
int main(){
    int r = 0;
    cin >> n;
    cin >> s;
    REP(i, n) {
        if (s[i] == 'R') r++;
    }

    if (n-r < r) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
