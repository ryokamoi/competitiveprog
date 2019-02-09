#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int n;
    cin >> n;

    vector<int> a;
    REP(i, n){
        int ai;
        cin >> ai;
        a.push_back(ai);
    }
    sort(a.begin(), a.end());
    cout << a[n-1]-a[0] << endl;
}
