#include <iostream>
#include <map>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

char sign[1010][1010];
int fst[1010];
int snd[1010];

map<char, int> mp;

int main() {
    int n, m;
    cin >> n >> m;

    mp['>'] = 1;
    mp['='] = 2;
    mp['<'] = 3;

    REP(i, n) {
        bool unif = true;
        
        int eq;
        bool eqflag = false;
        
        int lmax = -1000000000;
        int rmin = 1000000000;
        REP(j, m) {
            cin >> sign[i][j];
            
            if (i==0) {
                snd[j] = mp[sign[i][j]];
                continue;
            }

            if (j!=0) {
                if (sign[i][j] != sign[i][j-1]) unif = false;
            }

            if (sign[i][j] == '=') {
                if (!eqflag) {
                    eq = snd[j];
                    eqflag = true;
                } else {
                    if (snd[j] != eq) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }

            if (sign[i][j] == '>') {
                lmax = max(lmax, snd[j]);
            }

            if (sign[i][j] == '<') {
                rmin = min(rmin, snd[j]);
            }
        }
        
        if (i==0) continue;
        if (unif) continue;

        if (lmax > rmin) {
            cout << "No" << endl;
            return 0;
        } else if (rmin - lmax < 2) {
            REP(j, m) {
                if (sign[i][j] == '<') {
                    snd[j] += (2 - (rmin-lmax));
                }
            }
        }
    }

    REP(i, n) {
        int lmax = -1000000000;
        int rmin = 1000000000;
        
        int eq;
        bool eqflag = false;
        REP(j, m) {
            if (sign[i][j] == '=') {
                if (!eqflag) {
                    eqflag = true;
                    eq = snd[j];
                } else {
                    if (eq != snd[j]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }

            if (sign[i][j] == '>') {
                lmax = max(lmax, snd[j]);
            }

            if (sign[i][j] == '<') {
                rmin = min(rmin, snd[j]);
            }
        }

        if (eqflag) {
            if (lmax >= eq || rmin <= eq) {
                cout << "No" << endl;
                return 0;
            }
            fst[i] = eq;
            continue;
        }

        if (rmin <= lmax) {
            cout << "No" << endl;
            return 0;
        } else {
            if (lmax == -1000000000) {
                fst[i] = rmin-1;
            } else {
                fst[i] = lmax+1;
            }
        }
    }

    cout << "Yes" << endl;

    int minnum = 1000000000;
    REP(i, n) {
        minnum = min(minnum, fst[i]);
    }

    REP(i, m) {
        minnum = min(minnum, snd[i]);
    }
    
    REP(i, n) {
        cout << fst[i] + (1-minnum);
        if (i<n-1) {
            cout << " ";
        }
    }
    cout << endl;

    REP(i, m) {
        cout << snd[i] + (1-minnum);
        if (i<m-1) {
            cout << " ";
        }
    }
    cout << endl;
}
