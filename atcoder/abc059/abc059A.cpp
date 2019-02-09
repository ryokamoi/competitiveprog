#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    cout << (char)toupper(a[0]) << (char)toupper(b[0]) << (char)toupper(c[0]) << endl;
}
