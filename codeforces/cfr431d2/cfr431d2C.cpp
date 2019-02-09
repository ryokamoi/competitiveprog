#include<iostream>
#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;

int main(){
    cin >> n;

    string output = "";
    bool flag = false;
    for(int i=1; i<=26; i++){
        for(int j=1; j<=100000/(2*i); j++){
            if(i*j*j + i*j*(j-1) == n){
                string s = "";
                REP(k, i){
                    char c = 'a'+k;
                    s += {c};
                }
                REP(k, j){
                    output += s;
                }
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout << output << endl;
}
