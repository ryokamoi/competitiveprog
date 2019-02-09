#include<iostream>
#include<string.h>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    char str1[10000] = "";
    cin >> str1;
    string str2 = str1;
    cout << str2 << endl;

    bool flag = true;
    REP(i, 26){
        char c[1] = {'a'+i};
        string str2 = str1;
        string s = c;
        cout << s << endl;
        cout << (int)str2.find(s) << endl;
        if((int)str2.find(s) < 0){
            cout << c << endl;
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "None" << endl;
    }
}
