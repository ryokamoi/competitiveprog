#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    string s, t;
    cin >> s >> t;

    bool flag = false;
    REP(i, s.length()){
        if (s.compare(t) == 0){
            flag = true;
        }
        char fw = s[s.size()-1];
        s = s.substr(0, s.size()-1);
        s = fw + s;
    }
    
    if (flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
