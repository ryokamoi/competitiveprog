#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

int n, m;
vector<int> vec;
ll ithsum[300000];

int main() {
    cin >> n >> m;

    REP(i, n) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.rbegin(), vec.rend());
    ll culsum = 0;
    REP(i, n) {
        culsum += vec[i];
        ithsum[i] = culsum;
    }

    ll output = -1;
    for(ll i=1; i<=n; i++) {
        ll sum = 0;
        ll idx = 0;
        bool flag = true;
        while(flag) {
            if((idx+1)*i-1 < n-1 && vec[(idx+1)*i-1] > idx) {
                idx++;
                continue;
            }

            for(ll j=idx*i; j<(idx+1)*i; j++) {
                if (vec[j] <= idx) {
                    sum = ithsum[j-1];
                    sum -= i*(idx+1)*idx/2 - ((idx+1)*i-j)*idx;
                    flag = false;
                    break;
                }
                if (j==n-1) {
                    sum = ithsum[j];
                    sum -= i*(idx+1)*idx/2 - ((idx+1)*i-(j+1))*idx;
                    flag = false;
                    break;
                }
            }
        }

        if (sum >= m) {
            output = i;
            break;
        }
    }

    cout << output << endl;
}
