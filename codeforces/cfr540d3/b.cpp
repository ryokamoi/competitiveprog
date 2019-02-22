#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int a[300010];
int odd1, odd2, even1, even2;

int main() {
    cin >> n;
    
    odd1 = 0; odd2 = 0; even1 = 0; even2 = 0;
    REP(i, n) {
        cin >> a[i];

        if ((i+1)%2 == 0) { // even
            even2 += a[i];
        } else { // odd
            odd2 += a[i];
        }
    }

    int ans = 0;
    REP(i, n) {
        int even;
        int odd;
        if ((i+1)%2 == 0) { // give even
            even2 -= a[i];
        } else { // give odd
            odd2 -= a[i];
        }

        even = even1 + odd2;
        odd = odd1 + even2;
        
        if (even == odd) {
            ans++;
        }

        if ((i+1)%2 == 0) {
            even1 += a[i];
        } else {
            odd1 += a[i];
        }
    }

    cout << ans << endl;
}
