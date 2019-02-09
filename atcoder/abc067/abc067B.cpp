#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> l;
    REP(i, n){
        int li;
        cin >> li;
        l.push_back(li);
    }

    sort(l.begin(), l.end(), greater<int>());
    int sum = 0;
    REP(i, k){
        sum += l[i];
    }
    cout << sum << endl;
}
