#include<iostream>
#include<vector>
#include<numeric>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

long long INF = 10e17;

long long labs(long long a, long long b){
    if(a-b>=0){
        return a-b;
    } else {
        return b-a;
    }
}

int main(){
    long long n;
    cin >> n;

    vector<long long> l;
    REP(i, n){
        long long li;
        cin >> li;
        l.push_back(li);
    }

    long long sum = 0;
    REP(i, n){
        sum += l[i];
    }

    long long output = INF;
    long long a = 0;
    long long b = sum;
    for(long long i=0; i<n-1; i++){
        a += l[i];
        b -= l[i];
        output = min(output, labs(a, b));
    }
    cout << output << endl;
}
