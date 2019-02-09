#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n==0 || n==2){
        cout << 1 << endl;
    } else if (n==1){
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }
}
