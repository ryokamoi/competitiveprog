#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;
string t = "YAKI";

int main(){
    cin >> s;
    bool flag = true;

    if(s.size()>=4){
        REP(i, 4){
            if(s[i] != t[i]){
                flag = false;
            }
        }
    } else {
        flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
