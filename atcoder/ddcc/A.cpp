#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;
int main(){
    cin >> s;

    bool flag = true;
    if(s[0]!=s[1] || s[1]==s[2] || s[2]!=s[3]){
        flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
