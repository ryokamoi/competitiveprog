#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int lplus = 0;
    int lcount = 0;
    REP(i, n){
        if(s[i]=='('){
            lcount += 1;
        } else {
            if(lcount == 0){
                lplus += 1;
            } else {
                lcount -= 1;
            }
        }
    }

    s = string(lplus, '(') + s + string(lcount, ')');
    cout << s << endl;
}
