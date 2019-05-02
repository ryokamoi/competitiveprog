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
int l, r;
int main(){
    cin >> n;
    REP(i, n) {
        int num;
        cin >> num;
        if (num == 0) {
            l = i+1;
        } else {
            r = i+1;
        }
    }
    cout << min(l, r) << endl;
}
