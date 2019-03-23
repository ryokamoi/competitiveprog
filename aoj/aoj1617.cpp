#include <iostream>
#include <string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s1, s2;
int main() {
    while(1) {
        cin >> s1;
        if (s1 == ".") break;
        cin >> s2;

        int error = 0;
        int ap = 0;
        int i=0, j=0;
        while (1) {
            if (i==s1.size()-1 || j==s2.size()-1) {
                if (s1[i]==s2[j] && i==s1.size()-1 && j==s2.size()-1) break;
                if (error==0 && ap%2==1) {
                    if (s1[s1.size()-1]!=s2[s2.size()-1]) {
                        error=2; break;
                    }
                    int apc = 0;
                    for(int k=i; k<s1.size(); k++) {
                        if (s1[k]=='"') apc++;
                    }
                    for(int k=j; k<s2.size(); k++) {
                        if (s2[k]=='"') apc++;
                    }
                    if (apc>2) {
                        error = 2; break;
                    } else {
                        error = 1; break;
                    }
                }
                error=2; break;
            }

            if (s1[i] == s2[j]) {
                if (s1[i]=='"') ap++;
                i++; j++; continue;
            }

            if (ap%2==0 || error==1) {
                error = 2; break;
            }
            
            error++;
            while(1) {
                if (s1[i]!='"') i++;
                if (s2[j]!='"') j++;
                if (s1[i]=='"' && s2[j]=='"') break;
            }
        }

        if (error==0) {
            cout << "IDENTICAL" << endl;
        } else if (error == 1) {
            cout << "CLOSE" << endl;
        } else {
            cout << "DIFFERENT" << endl;
        }
    }
    
}
