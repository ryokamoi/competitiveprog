#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;

int main(){
    cin >> s;
    bool flag = false;
    REP(i, s.size()){
        if(s[i]=='9') flag = true;
    }
    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
