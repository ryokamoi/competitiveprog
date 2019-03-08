// Ryo Kamoi
// #define DEBUG

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
int cnt[2][2]; // 00, 01, 10, 11
int res[2][2];

int clown[10000], acro[10000];

int main(){
    cin >> n;

    REP(i, 2) {
        REP(j, 2) {
            cnt[i][j] = 0;
        }
    }

    string cl;
    cin >> cl;
    REP(i, n) {
        clown[i] = cl[i] - '0';
    }

    string ac;
    cin >> ac;
    REP(i, n) {
        acro[i] = ac[i] - '0';

        cnt[clown[i]][acro[i]]++;
    }

#ifdef DEBUG
    REP(i, 2) {
        REP(j, 2) {
            cout << i << j << " " << cnt[i][j] << endl;
        }
    }
#endif

    bool exist = false;
    int a1, b1, c1, d1;
    REP(i, cnt[1][1]+1) {
        d1 = i;
        REP(j, cnt[1][0]+1) {
            c1 = j;

            int d2, b2;
            d2 = cnt[1][1] - d1;
            b2 = c1 + d1 - d2;
            b1 = cnt[0][1] - b2;
            a1 = n/2 - (b1+c1+d1);

            if (d2<0 || b2<0 || b1<0 || a1<0) continue;
            if (a1>cnt[0][0]) continue;
           
#ifdef DEBUG
            cout << a1 << b1 << c1<< d1 << endl;
#endif

            exist = true;
            break;
        }
        if(exist) break;
    }

    if (!exist) {
        cout << -1 << endl;
        return 0;
    }

    res[0][0] = a1;
    res[0][1] = b1;
    res[1][0] = c1;
    res[1][1] = d1;

    REP(i, n) {
        if (res[clown[i]][acro[i]] > 0) {
            cout << i+1;
            res[clown[i]][acro[i]] --;
            if (i != n-1) cout << " ";
        }
    }
    cout << endl;
}
