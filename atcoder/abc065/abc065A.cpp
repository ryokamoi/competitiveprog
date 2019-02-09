#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int x, a, b;
    cin >> x >> a >> b;

    if(b<=a){
        cout << "delicious" << endl;
    } else if (b<=a+x){
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
}
