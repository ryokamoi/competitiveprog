#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

ll n, m;
vector<int> vec;

bool cando(int day){
    ll sum = 0;
    REP(i, n) {
        sum += max(0, vec[i] - i/day);
    }

    return (sum >= m);
}

int main() {
    cin >> n >> m;

    REP(i, n) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.rbegin(), vec.rend());

    if (!cando(n)) {
        cout << "-1" << endl;
        return 0;
    }

    int l=0;
    int r=n;
    while(r-l > 1) {
        int s = (l+r)/2;
        if (cando(s)) {
            r = s;
        } else {
            l = s;
        }
    }

    cout << r << endl;
}
