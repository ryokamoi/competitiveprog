#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

long long p = 1000000007;

long long res(long long l){
    long long d = l/p;
    return l - d*p;
}

long long fact(long long l){
    if(l == 0) return 1;
    if(l == 1) return 1;

    return res(l%p * fact(l-1));
}

int main(){
    long long n, m;
    cin >> n >> m;

    long long output;
    if(n-m == -1 || n-m == 1){
        output = res(fact(n)*fact(m));
    } else if (n==m){
        output = res(2*(fact(n)*fact(m)));
    } else {
        output = 0;
    }

    cout << output << endl;
}
