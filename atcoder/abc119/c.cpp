#include <iostream>
#include <math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int a, b, c;
int l[10];

int calccost(int bits, int goal) {
    int num = 0;
    int sum = 0;
    int one = 1;
    REP(i, n) {
        int check = bits&one;
        if (check != 0) {
            num ++;
            sum += l[i];
        }
        one = one<<1;
    }

    return 10*(num-1) + abs(sum-goal);
}

int main() {
    cin >> n >> a >> b >> c;

    REP(i, n) {
        cin >> l[i];
    }

    int output = 1000000000;
    int mx = pow(2, n);
    int check;
    for(int i=1; i<mx; i++) {
        for(int j=1; j<mx; j++) {
            check = i&j;
            if (check != 0) continue;
            for(int k=1; k<mx; k++) {
                check = j&k;
                if (check != 0) continue;
                check = k&i;
                if (check != 0) continue;
                
                int cost = 0;
                cost += calccost(i, a);
                cost += calccost(j, b);
                cost += calccost(k, c);
                output = min(cost, output);
            }
        }
    }
    cout << output << endl;
}
