#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

long long k;
long long a[50];

int main(){
    cin >> k;
    long long n = k/50;
    long long r = k%50;

    REP(i, 50){
        a[i] = i + n;
    }

    REP(i, r){
        a[i] += 51;
        REP(j, 50){
            a[j] -= 1;
        }
    }

    cout << 50 << endl;

    REP(i, 50){
        cout << a[i] << " ";
    }
    cout << endl;
}
