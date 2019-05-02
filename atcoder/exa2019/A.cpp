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

int a, b, c;
int main(){
    cin >> a >> b >> c;
    bool flag = true;
    if (a!=b) flag = false;
    if (b!=c) flag = false;

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
