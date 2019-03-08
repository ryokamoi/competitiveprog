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
vector<int> cont;

int main(){
    cin >> n;
    
    int cor = 1;
    int prev;
    cin >> prev;
    REP(i, n-1) {
        int ti;
        cin >> ti;
        
        if (prev == ti) {
            cor ++;
        } else {
            cont.push_back(cor);
            cor = 1;
        }
        prev = ti;
    }
    cont.push_back(cor);

    int output = 0;
    REP(i, cont.size()-1) {
        output = max(output, min(cont[i], cont[i+1]));
    }
    cout << output*2 << endl;
}
