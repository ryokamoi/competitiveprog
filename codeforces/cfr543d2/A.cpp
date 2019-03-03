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

int n, m, k;

int strongest[110];
int id[110];

int p[110];
int school[110];

int main(){
    cin >> n >> m >> k;

    REP(i, n) {
        strongest[i] = -100;
    }

    REP(i, n) {
        cin >> p[i];
    }

    REP(i, n) {
        int s;
        cin >> s;
        school[i] = s-1;

        if (p[i] > strongest[s-1]) {
            strongest[s-1] = p[i];
            id[s-1] = i;
        }
    }

    int output = 0;
    REP(i, k) {
        int co;
        cin >> co;
        if (id[school[co-1]] != co-1) output++;
    }
    cout << output << endl;
}
