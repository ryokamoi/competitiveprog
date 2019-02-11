#include<iostream>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int per[5] = {0, 1, 2, 3, 4};

int main(){
    do{
        REP(i, 4){
            cout << per[i] << " ";
        }
        cout << endl;
    }while(next_permutation(per, per+3));
}
