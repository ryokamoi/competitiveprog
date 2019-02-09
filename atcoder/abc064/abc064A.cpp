#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    int num = 100*r + 10*g + b;
    if(num%4==0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
