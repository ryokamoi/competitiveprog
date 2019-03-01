#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, m;
vector<int> x;
vector<int> gap;

int main(){
    cin >> n >> m;

    REP(i, m) {
        int xi;
        cin >> xi;
        x.push_back(xi);
    }
    
    if (n>=m) {
        cout << "0" << endl;
        return 0;
    }

    sort(x.begin(), x.end());

    REP(i, m-1) {
        gap.push_back(x[i+1] - x[i]);
    }

    sort(gap.begin(), gap.end(), greater<int>());

    int output = x[x.size()-1] - x[0];
    REP(i, n-1) {
        output -= gap[i];
    }
    cout << output << endl;
}
