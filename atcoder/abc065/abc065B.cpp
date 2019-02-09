#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int n;
    cin >> n;
    int a[100000];
    bool gone[100000];
    REP(i, n){
        cin >> a[i];
        a[i] -= 1;
        gone[i] = false;
    }

    int l = 0;
    int output = -1;
    int i = 1;
    while(1){
        gone[l] = true;
        if(a[l] == 1){
            output = i;
            break;
        }

        l = a[l];
        if(gone[l]){
            break;
        }
        i += 1;
    }

    cout << output << endl;
}
