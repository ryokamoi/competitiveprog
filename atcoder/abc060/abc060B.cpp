#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int a, b, c;

int main(){
    cin >> a >> b >> c;

    bool flag = false;
    REP(i, 1000){
        if((a*(i+1))%b == c){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
