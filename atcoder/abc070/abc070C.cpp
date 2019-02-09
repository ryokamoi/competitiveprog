#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i, n) for(int i; i<n; i++)

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(a<b){
        unsigned long long tmp = a;
        a = b;
        b = tmp;
    }
    unsigned long long r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    int n;
    cin >> n;
    vector<unsigned long long> t;
    
    REP(i, n){
        unsigned long long ct;
        cin >> ct;
        t.push_back(ct);
    }

    unsigned long long a;
    unsigned long long r = t[0];
    for(int i=1; i<t.size(); i++){
        a = t[i];
        unsigned long long b = gcd(a, r);
        r = a*(r/b);
    }
    cout << r << endl;
}
