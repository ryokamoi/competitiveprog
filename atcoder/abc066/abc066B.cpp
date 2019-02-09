#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    string s;
    cin >> s;
    
    int count = 0;
    for(int i=1; i<=(s.size()-1)/2; i++){
        bool flag = true;
        REP(j, i){
            if(s[j+i] != s[j]){
                flag = false;
            }
        }
        if(flag) count = i;
    }
    cout << count*2 << endl;
}
