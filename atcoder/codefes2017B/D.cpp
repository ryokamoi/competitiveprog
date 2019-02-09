#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string s;
int c;
int n;
int main(){
    cin >> n;
    cin >> s;

    c = 0;

    string erased = "";

    int i=0;
    while(1){
        if(i>=s.size()){
            break;
        }

        if(i+2<s.size() && s[i]=='1' && s[i+1]=='0' && s[i+2]=='1'){
            erased += "101";
            i += 3;
            while(1){
                if(i>=s.size()) break;
                if(s[i]=='0' && s[i+1]=='1'){
                    erased += "01";
                    i += 2;
                } else {
                    break;
                }
            }
            while(1){
                if(i>=s.size()) break;
                if(s[i]=='1'){
                    c+=1;
                    i+=1;
                } else {
                    break;
                }
            }
        } else {
            erased += s[i];
            i += 1;
        }
    }

    cout << erased << endl;

    reverse(erased.begin(), erased.end());

    string erased2 = "";
    i=0;
    while(1){
        if(i>=erased.size()){
            break;
        }

        if(i+2<erased.size() && erased[i]=='1' && erased[i+1]=='0' && erased[i+2]=='1'){
            erased2 += "101";
            i += 3;
            while(1){
                if(i>=erased.size()) break;
                if(erased[i]=='0' && erased[i+1]=='1'){
                    erased2 += "01";
                    i += 2;
                } else {
                    break;
                }
            }
            while(1){
                if(i>=erased.size()) break;
                if(erased[i]=='1'){
                    c+=1;
                    i+=1;
                } else {
                    break;
                }
            }
        } else {
            erased2 += s[i];
            i += 1;
        }
    }

    cout << erased2 << endl;

    i=0;
    while(1){
        if(i>=erased2.size()){
            break;
        }

        if(i+2<erased2.size() && erased2[i]=='1' && erased2[i+1]=='0' && erased2[i+2]=='1'){
            c += 1;
            i += 3;
        } else {
            i += 1;
        }
    }
    cout << c << endl;
}
