#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int a, b;
    cin >> a >> b;
    if(a+b<10){
        cout << a+b << endl;
    } else {
        cout << "error" << endl;
    }
}
