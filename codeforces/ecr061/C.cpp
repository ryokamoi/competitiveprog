// Ryo Kamoi
//#define DEBUG

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

int n, q;
int l[10000], r[10000];
int num[10000];
int ruiseki[10000];
bool ign[10000];

int main(){
    cin >> n >> q;
    REP(i, n+1) {
        num[i] = 0;
        ruiseki[i] = 0;
    }

    REP(i, q) {
        cin >> l[i] >> r[i];
        num[l[i]-1]++;
        num[r[i]]--;
    }

    int cor = 0;
    int sum = 0;
    REP(i, n) {
        cor += num[i];
        ruiseki[i] = cor;
        if (cor>0) sum++;
    }

    REP(i, q) {
        ign[i] = false;
    }

    REP(i, q) {
        bool flag = true;
        for(int j=l[i]-1; j<r[i]; j++){
            if (ruiseki[j]<3) {
                flag = false;
                break;
            }
        }
        ign[i] = flag;
    }

    int maxnum = 0;
    bool end = false;
    REP(i,  q) {
        int thisi = sum;
        if (!ign[i]) {
            for(int j=l[i]-1; j<r[i]; j++) {
                if (ruiseki[j] == 1) thisi--;
            }
        }
        if (maxnum > thisi) continue;
#ifdef DEBUG
        cout << i << " " << thisi << endl;
#endif
        
        for(int j=i+1; j<q; j++) {
            if (ign[i] && ign[j]){
                maxnum = sum;
                end = true;
                break;
            }

            if (ign[j]) {
                maxnum = thisi;
                break;
            }

            int cor = thisi;
            int dl, dr;
            dl = max(l[i], l[j]);
            dr = min(r[i], r[j]);
            if (dl<=dr) {
                for(int k=dl-1; k<dr; k++) {
                    if(ruiseki[k]==2) cor--;
                }

                for(int k=l[j]-1; k<dl-1; k++) {
                    if(ruiseki[k]==1) cor--;
                }
                for(int k=dr; k<r[j]; k++) {
                    if(ruiseki[k]==1) cor--;
                }
            
            } else {
                for(int k=l[j]-1; k<r[j]; k++) {
                    if (ruiseki[k]==1) cor--;
                }
            }
            maxnum = max(maxnum, cor);
        }
        if(end) break;
    }

    cout << maxnum << endl;
}
