#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

bool used[26];

int main(){
    string s;
    cin >> s;

    REP(i, 26) used[i] = false;

    bool flag = false;
    REP(i, s.size()){
        if(used[s[i]-'a']){
            flag = true;
            break;
        } else {
            used[s[i]-'a'] = true;
        }
    }

    if(flag){
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }
}
