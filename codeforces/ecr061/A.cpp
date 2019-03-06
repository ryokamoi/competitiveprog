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

int t1, t2, t3, t4;
int main(){
    cin >> t1 >> t2 >> t3 >> t4;
    bool flag = true;

    if (t1!=t4) flag = false;
    if (t1==0 && t3>0) flag = false;

    if(flag) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

}
