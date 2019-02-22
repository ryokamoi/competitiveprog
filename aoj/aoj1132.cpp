#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main() {
    while(true) {
        int p, q, a, n;
        cin >> p >> q >> a >> n;
        if (p==0) break;

        int mul = (a/q) * q;

        string num = ;
        printf()
        map<ll, int> prev;
        prev[(a/q)*p * 100000*100000 + mul*100000 + 1] = 0;

        int ans = 0;
        REP(i, 7) {
            map<ll, int> nmap;
            for (auto& kv : prev) {
                ll key = kv.first;
                int val = kv.second;

                cout << key << endl;
                ll res = key / (100000*100000);
                ll cul = (key - res*(100000*100000)) / 100000;
                ll prevnum = (key - res*(100000*100000) - cul*100000);
                cout << res << cul << prevnum;
            }
            prev = nmap;
        }
    }
}
