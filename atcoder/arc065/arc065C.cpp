#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;

int main(){
    cin >> s;
    string tmps = "";

    bool flag = true;
    REP(i, s.size()){
        tmps = s[s.size()-i-1] + tmps;
        if(tmps == "dream"|| tmps == "dreamer" || tmps == "erase" || tmps == "eraser"){
            tmps = "";
        }
        if(tmps.size()>7){
            flag = false;
            break;
        }
    }

    if(tmps.size()>0) flag = false;

    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
