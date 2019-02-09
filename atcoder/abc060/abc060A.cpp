#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string a, b, c;

int main(){
    cin >> a >> b >> c;
    if(a[a.size()-1]==b[0] && b[b.size()-1]==c[0]){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
