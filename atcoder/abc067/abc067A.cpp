#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int a, b;
    cin >> a >> b;
    if(a%3==0 || b%3==0 || (a+b)%3==0){
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
