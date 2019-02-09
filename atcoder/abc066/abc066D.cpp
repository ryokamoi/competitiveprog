#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define rangeREP(i, j, n) for(int i=j; i<n; i++)

unsigned long long a[100000];
unsigned long long n;
unsigned long long lm = 10e9 + 7;
unsigned long long m = 7;
unsigned long long f[100001];
unsigned long long rf[100001];

unsigned long long mpow(unsigned long long t, unsigned long long u){
    if(u==0){
        return 1;
    } else if (u==1){
        return t;
    }

    unsigned long long s = mpow(t, u/2)%m;
    if (u%2==0){
        return (s * s)%m;
    } else {
        return (t * s * s)%m;
    }
}

unsigned long long fact(unsigned long long t){
    if(t == 0) return 1;
    return (f[t-1] * t) % m;
}

unsigned long long rfact(unsigned long long t){
    return mpow(f[t], m-2);
}

unsigned long long bi(unsigned long long l, unsigned long long k){
    if(l<k){
        return 0;
    } else {
        unsigned long long r = f[l];
        unsigned long long b = (rf[l-k] * rf[k])%m;
        cout << r << " " << b << endl;
        return (r*b)%m;
    }
}

bool used[100000];

int main(){
    cin >> n;
    REP(i, n+1){
        cin >> a[i];
    }

    REP(i, 100001) f[i] = fact(i);
    REP(i, 100001) rf[i] = rfact(i);
    
    REP(i, n) used[i] = false;
    bool cont = false;
    int idx;
    if(n>=2){
        REP(i, n){
            if(a[i] == a[i+1]) cont = true;
            if(used[a[i]]) idx = i;
            used[a[i]] = true;
        }
    }

    REP(i, 100) cout << rf[i] << endl;
    
    cout << "a" << endl;
    cout << bi(20, 10) << endl;
    cout << endl;

    if(!cont){
        cout << n << endl;
        for(int i=1; i<n+1; i++){
            cout << bi(n+1, i+1) - bi(n-idx, i) << endl;
        }
    } else {
        REP(i, n+1){
            cout << bi(n, i+1) + bi(n-1, i-1) << endl;
        }
    }
}
