// Ryo Kamoi
//#define DEBUG

#include<iostream>
#include<string>
#include<set>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

set<char> alpset;
map<char, int> alp;

int n;
string eq[15];

int perm[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int pow10lst[9] = {1, 10, 100, 1000, 10000,
            100000, 1000000, 10000000, 100000000};
int coeff[10];
vector<int> firstalp;
vector<int> goaleq;

int str2int(string s) {
    int output = 0;
    REP(i, s.size()) {
        output += perm[goaleq[i]] * pow10lst[s.size()-1-i];
    }
    return output;
}

int factorial(int n) {
    if (n==0) return 1;
    return n*factorial(n-1);
}

int main() {
    while(1) {
        cin >> n;
        if (n==0) break;

        alpset = set<char>();

        REP(i, n) {
            string s;
            cin >> s;
            eq[i] = s;
            REP(j, s.size()) {
                alpset.insert(s[j]);
            }
        }

        set<char>::iterator it;
        int idx = 0;
        for(it=alpset.begin(); it!=alpset.end(); ++it) {
            alp[*it] = idx;
            idx ++;
        }

        REP(i, 10) coeff[i] = 0;
        firstalp = vector<int>();
        REP(i, n-1) {
            REP(j, eq[i].size()) {
                coeff[alp[eq[i][j]]] += pow10lst[eq[i].size()-1-j];
            }
            if (eq[i].size() > 1) {
                firstalp.push_back(alp[eq[i][0]]);
            }
        }
        firstalp.push_back(perm[alp[eq[n-1][0]]]);

        goaleq = vector<int>();
        REP(i, eq[n-1].size()) {
            goaleq.push_back(alp[eq[n-1][i]]);
        }
        int output = 0;
        do {
            bool flag = true;
            // detect zero
            REP(i, firstalp.size()) {
                if (perm[firstalp[i]]==0) {
                    flag = false; break;
                }
            }
            if (!flag) continue;

            int upbound = (perm[alp[eq[n-1][0]]]+1) * pow10lst[eq[n-1].size()-1];
            int sum = 0;
            REP(i, alpset.size()) {
                sum += perm[i] * coeff[i];
                if (sum > upbound) break;
            }
            int goal = str2int(eq[n-1]);
            if (sum == goal) {
                output++;
            }
        } while (next_permutation(perm, perm+10));

        output /= factorial(10-alpset.size());
        cout << output << endl;
    }
}

