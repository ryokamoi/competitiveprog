#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int n;
string s[50];
char alpha[26];
int c[26];

void cnum(string st){
    int tmpc[26];
    REP(i, 26) tmpc[i] = 0;

    REP(i, st.size()){
        REP(j, 26){
            if(st[i] == alpha[j]){
                tmpc[j] += 1;
                break;
            }
        }
    }

    REP(i, 26){
        c[i] = min(c[i], tmpc[i]);
    }
}

int main(){
    REP(i, 26) alpha[i] = char('a'+i);

    cin >> n;
    REP(i, n) cin >> s[i];
    REP(i, 26) c[i] = INF;
    REP(i, n) cnum(s[i]);

    REP(i, 26){
        REP(j, c[i]) cout << alpha[i];
    }
    cout << endl;
}
