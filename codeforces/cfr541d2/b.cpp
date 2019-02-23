#include <iostream>

using namespace std;

#define REP(i, n) for(int i; i<n; i++)

int a[10010], b[10010];
int n;

int main() {
    cin >> n;
    a[0] = 0;
    b[0] = 0;

    REP(i, n){
        cin >> a[i+1];
        cin >> b[i+1];
    }

    int idx = 0;
    int output = 1;
    while(idx < n) {
        int d = 1;
        while(idx+d<=n && a[idx]==a[idx+d] && b[idx]==b[idx+d]) {
            d++;
        }

        if (a[idx]==a[idx+d] && b[idx]==b[idx+d]) break;

        int add = min(a[idx+d], b[idx+d]) - max(a[idx], b[idx]);
        if (add >= 0) {
            output += add;
            if (a[idx] != b[idx]) output ++;
        }

        idx+=d;
    }
    cout << output << endl;
}
