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
vector<int> odd;
vector<int> even;
int main(){
    cin >> n;
    REP(i, n) {
        int a;
        cin >> a;
        if (a%2 == 0) {
            even.push_back(a);
        } else {
            odd.push_back(a);
        }
    }

    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());
    
    int output = 0;
    if (even.size() == odd.size()) {
            cout << 0 << endl;
            return 0;
    }
    if (even.size() > odd.size()) {
        for(int i=odd.size()+1; i<even.size(); i++) {
            output += even[i];
        }
    } else {
        for(int i=even.size()+1; i<odd.size(); i++) {
            output += odd[i];
        }
    }
    cout << output << endl;
}
