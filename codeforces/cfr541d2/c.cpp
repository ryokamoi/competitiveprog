#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

vector<int> a;

int main() {
    int n;
    cin >> n;

    REP(i, n) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    sort(a.begin(), a.end());
    int idx = 0;
    while(idx < n) {
        cout << a[idx] << " ";
        idx += 2;
    }

    if (n % 2 == 1) {
        idx = n-2;
    } else {
        idx = n-1;
    }

    while(idx >= 0) {
        cout << a[idx];
        if (idx-2 >= 0) {
            cout << " ";
        }

        idx -= 2;
    }

    cout << endl;
}
