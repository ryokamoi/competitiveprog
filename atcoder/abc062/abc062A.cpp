#include<iostream>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0}};

int main(){
    int x, y;
    cin >> x >> y;
    bool flag = false;
    REP(i, 3){
        if(find(a[i], a[i]+7, x)!=end(a[i]) && find(a[i], a[i]+7, y)!=end(a[i])){
            flag = true;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
