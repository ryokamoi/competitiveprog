#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int c = 0;

    while(1){
        if(n==1) break;
        n = ceil((double)n/3);
        c += 1;
    }

    cout << c << endl;
}
