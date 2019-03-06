// Ryo Kamoi
//#define DEBUG

#include<iostream>
#include<string>
#include<set>
#include<math.h>
#include<algorithm>
#include<map>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

set<char> alpset;
map<char, int> alp;

int n;
string eq[15];

int perm[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int str2int(string s) {
    int output = 0;
    REP(i, s.size()) {
        output += perm[alp[s[i]]] * pow(10, s.size()-1-i);
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

        int output = 0;
        do {
            // detect zero
            bool flag = true;
            int upbound=0, lowbound=0;
            REP(i, n) {
                int fst = perm[alp[eq[i][0]]];
                if (eq[i].size()!=1 && fst==0) {
                    flag = false;
                    break;
                }
                int zeronum = pow(10, eq[i].size()-1);
                lowbound += fst * zeronum;
                upbound += (fst+1) * zeronum;
            }
            if(!flag) continue;
            
            int goal = str2int(eq[n-1]);
            if (goal < lowbound || goal > upbound) {
                continue;
            }
            
            int sum = 0;
            REP(i, n-1) {
                sum += str2int(eq[i]);
                if (sum > goal) break;
            }
            if (sum == goal) output++;
        } while (next_permutation(perm, perm+10));

        output /= factorial(10-alpset.size());
        cout << output << endl;
    }
}


