#include<iostream>
#include<cstdlib>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int x, a, b;

    cin >> x >> a >> b;

    int da = abs(x-a);
    int db = abs(x-b);

    if(da<db){
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
}
