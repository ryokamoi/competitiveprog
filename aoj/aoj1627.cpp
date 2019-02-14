#include <iostream>
#include <map>
#include <string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int wl[10][10];
int n, m;

map<string, int> update(int i, int j, string state,
        map<string, int> nmap, int num) {
    if (state[i]-'0'>=1 && state[n+j]-'0'>=1) {
        string nstate = state;
        nstate[i] = to_string(state[i]-'0'-1)[0];
        nstate[n+j] = to_string(state[n+j]-'0'-1)[0];

        auto iter = nmap.find(nstate);
        if (iter != nmap.end()) {
            nmap[nstate] += num;
        } else {
            nmap[nstate] = num;
        }
    }
    return nmap;
}

int main() {
    while (true) {
        cin >> n >> m;

        if (n==0) break;

        REP(i, n) {
            REP(j, n) {
                wl[i][j] = 0;
            }
        }

        string initn = to_string((n-1)/2);
        string inits = string(n * 2, initn[0]);
        // 1 - (n-1)/2 : win
        // n - (n-1) : lose

        REP(i, m) {
            int x, y;
            cin >> x >> y;
            wl[x-1][y-1] = 1;
            wl[y-1][x-1] = -1;

            int xwin = inits[x-1] - '0';
            inits[x-1] = to_string(xwin - 1)[0];

            int ylose = inits[n + (y-1)] - '0';
            inits[n + (y-1)] = to_string(ylose - 1)[0];
        }

        map<string, int> prevm;
        prevm[inits] = 1;
        REP(i, n-1) {
            for (int j=i+1; j<n; j++) {
                if (wl[i][j] == 0) {
                    map<string, int> nextm;
                    for(auto& kv: prevm) {
                        string state = kv.first;
                        int num = kv.second;

                        nextm = update(i, j, state, nextm, num);
                        nextm = update(j, i, state, nextm, num);
                    }
                    prevm = nextm;
                }
            }
        }

        string ends = string(n*2, '0');
        cout << prevm[ends] << endl;
    }
}
