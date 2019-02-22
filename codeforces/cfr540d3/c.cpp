#include <iostream>
#include <queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int c[1100]; // count

queue<int> que[5];
int req[5];
int matrix[30][30];

bool countnum(int num) {
    REP(i, 1100) {
        while(c[i]>=num && req[num]>0) {
            que[num].push(i);
            c[i] -= num;
            req[num]--;
        }
        if (req[num]<=0) break;
    }
    return (req[num] == 0);
}

int main() {
    cin >> n;

    REP(i, 1100) c[i] = 0;
    REP(i, n*n) {
        int a;
        cin >> a;
        c[a]++;
    }

    req[4] = (n/2) * (n/2);
    req[2] = 0;
    req[1] = 0;
    if (n%2 == 1) {
        req[2] = 2 * (n/2);
        req[1] = 1;
    }

    bool flag = true;
    flag = countnum(4);

    if (flag && n%2 == 1) {
        flag = countnum(2);
        if (flag) flag = countnum(1);
    }

    if (!flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        REP(i, n/2) {
            REP(j, n/2) {
                int e = que[4].front();
                que[4].pop();
                
                matrix[i][j] = e;
                matrix[i][n-1-j] = e;
                matrix[n-1-i][j] = e;
                matrix[n-1-i][n-1-j] = e;
            }
        }

        if (n%2 == 1) {
            int e = que[1].front();
            matrix[n/2][n/2] = e;

            REP(i, n/2) {
                int e = que[2].front();
                que[2].pop();
                matrix[i][n/2] = e;
                matrix[n-1-i][n/2] = e;
                
                e = que[2].front();
                que[2].pop();
                matrix[n/2][i] = e;
                matrix[n/2][n-1-i] = e;
            }
        }

        REP(i, n) {
            REP(j, n) {
                cout << matrix[i][j];
                if (j!=(n-1)) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
