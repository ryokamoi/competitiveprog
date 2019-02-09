#include<iostream>

#define REP(i, n) for(int i; i<n; i++)

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sec;
    if(b<=c || d<=a){
        sec = 0;
    } else {
        sec = min(b, d)- max(a, c);
    }

    cout << sec << endl;
}
