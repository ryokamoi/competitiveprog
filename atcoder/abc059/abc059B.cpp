#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    string a, b;
    cin >> a >> b;

    bool flag = false;
    if(a.size()>b.size()){
        cout << "GREATER" << endl;
        flag = true;
    } else if(a.size()<b.size()){
        cout << "LESS" << endl;
        flag = true;
    } else {
        REP(i, a.size()){
            if(a[i]>b[i]){
                cout << "GREATER" << endl;
                flag = true;
                break;
            } else if (a[i]<b[i]){
                cout << "LESS" << endl;
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        cout << "EQUAL" << endl;
    }
}
