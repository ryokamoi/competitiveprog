#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int n, m;
vector<ll> d, t;

int main(){
    cin >> n;
    REP(i, n){
        int di;
        cin >> di;
        d.push_back(di);
    }

    cin >> m;
    REP(i, m){
        int ti;
        cin >> ti;
        t.push_back(ti);
    }

    sort(d.begin(), d.end());
    sort(t.begin(), t.end());

    int tmp_d = 0;
    bool flag = true;
    REP(i, m){
        while(1){
            if(t[i]==d[tmp_d]){
                tmp_d += 1;
                break;
            } else if (t[i] < d[tmp_d]){
                flag = false;
                break;
            } else {
                tmp_d += 1;
            }
        }
    }

    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
