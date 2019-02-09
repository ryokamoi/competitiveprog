#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;

int main(){
    cin >> n;
    int output = 1;

    while(1){
        if(n>=output*2){
            output *= 2;
        } else {
            break;
        }
    }
    cout << output << endl;
}
