#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, m;
bool to1[200001];
bool ton[200001];

int main(){
    cin >> n >> m;
    REP(i, n+1){
        to1[i] = false;
        ton[i] = false;
    }

    REP(i, m){
        int a, b;
        cin >> a >> b;

        if(a==1){
            to1[b] = true;
        } else if(b==n){
            ton[a] = true;
        }
    }

    bool flag = false;
    REP(i, n+1){
        if(to1[i] && ton[i]){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
