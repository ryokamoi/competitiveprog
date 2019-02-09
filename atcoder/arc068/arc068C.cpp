#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

ll x;
ll inte;
ll res;

int main(){
    cin >> x;

    inte = x/11;
    res = x%11;
    if(res==0){
        cout << inte*2 << endl;
    } else if (res <= 6){
        cout << inte*2 + 1 << endl;
    } else {
        cout << inte*2 + 2 << endl;
    }
}
