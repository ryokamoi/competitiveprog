#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, m;
int memo[10000000];
int maxnum;

int main() {
    while(1) {
        cin >> n >> m;
        if (n==0) break;

        if (m < 1000) {
            maxnum = 100000;
        } else {
            maxnum = 7368800;
        }

        REP(i, maxnum) {
            memo[i] = 0;
        }

        int output;
        for (int i=n; i<maxnum; i++) {
            if (memo[i]==0) {
                if (m==0) {
                    output = i;
                    break;
                }

                m--;
                REP(j, maxnum/i) {
                    memo[i+i*j] = 1;
                }
            }
        }
        cout << output << endl;
    }
}

