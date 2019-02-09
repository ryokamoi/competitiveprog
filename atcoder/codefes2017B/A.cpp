#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;

int main(){
    cin >> s;
    REP(i, s.size()-8){
        cout << s[i];
    }
    cout << endl;
}
