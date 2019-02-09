#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll n, m;

int main(){
    cin >> n >> m;

    if(n>=m/2){
        cout << m/2 << endl;
    } else {
        cout << n+(m-2*n)/4 << endl;
    }
}
