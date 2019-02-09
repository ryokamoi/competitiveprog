#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;

int main(){
    cin >> s;
    int c = 0;
    REP(i, s.size()-1){
        if(s[i] != s[i+1]) c += 1;
    }
    cout << c << endl;
}
