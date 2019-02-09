#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int a, b, c, d;
int main(){
    cin >> a >> b >> c >> d;

    int sum = 1728*a+144*b+12*c+d;
    cout << sum << endl;
}
