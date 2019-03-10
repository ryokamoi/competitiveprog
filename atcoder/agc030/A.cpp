#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int a, b, c;

int main(){
    cin >> a >> b >> c;

    int output = 0;
    output += min(a+b+1, c);
    output += b;
    cout << output << endl;
}
