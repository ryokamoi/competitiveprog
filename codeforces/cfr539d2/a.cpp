#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main() {
    int n, v;
    cin >> n >> v;

    int output;
    
    if (n > v) {
        output = ((1+(n-v))*(n-v)) / 2 + (v-1);
    } else {
        output = n-1;
    }

    cout << output << endl;
}
