#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int a[100010];

int gcf(int a, int b){
    if (a>b) return gcf(b, a);

    if (a==0) return b;
    
    return gcf(b%a, a);
}

int main(){
    cin >> n;

    int output;
    cin >> output;
    REP(i, n-1) {
        int a;
        cin >> a;
        output = gcf(output, a);
    }

    cout << output << endl;
}
