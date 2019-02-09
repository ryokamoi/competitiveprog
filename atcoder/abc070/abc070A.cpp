#include<iostream>
#include<string>
#define REP(i, n) for(int i; i<n; i++)

using namespace std;

int main(){
    string s;
    cin >> s;
    
    bool flag = true;
    REP(i, s.size()){
        if(s[i] != s[s.size()-i-1]){
            flag = false;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
