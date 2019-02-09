#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s, output;

int main(){
    cin >> s;
    output = "";
    REP(i, s.size()){
        if((i+1)%2==1){
            output += s[i];
        }
    }
    cout << output << endl;
}
