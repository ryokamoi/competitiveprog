#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n, m;
vector<int> a;

string memo[10010];

string larger(string a, string b) {
    if (a[0] == '-') return b;
    if (b[0] == '-') return a;
    
    if (a.size() > b.size()) {
        return a;
    } else if (a.size() < b.size()) {
        return b;
    } else {
        REP(i, a.size()) {
            if (a[i] == b[i]) continue;
            if (a[i] > b[i]) {
                return a;
            } else {
                return b;
            }
        }
    }

    return a;
}

int mnum[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string maxnum(int res) {
    if (res==0) return "";
    if (memo[res] != "null") return memo[res];
        
    string output = "-";
    
    REP(i, a.size()) {
        if (res < mnum[a[i]]) continue;
        string ith = maxnum(res - mnum[a[i]]) + to_string(a[i]);
        output = larger(output, ith);
    }

    return memo[res] = output;
}

int main(){
    a = vector<int>();
    cin >> n >> m;

    REP(i, 10010) memo[i] = "null";

    REP(i, m) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    cout << maxnum(n) << endl;
}
