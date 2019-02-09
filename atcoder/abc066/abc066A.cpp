#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> s;
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);

    sort(s.begin(), s.end());
    int output = s[0] + s[1];
    cout << output << endl;
}
