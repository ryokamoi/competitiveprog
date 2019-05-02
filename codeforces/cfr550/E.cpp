// Ryo Kamoi

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

int k;
string ss, ls;
vector<int> svec, lvec;

vector<int> str2vec(string ss) {
    vector<int> output;
    REP(i, k) {
        output.push_back(ss[k-i-1]-'a'+1);
    }
    return output;
}

vector<int> vecdiff(vector<int> lg, vector<int> sm) {
    vector<int> ans = lg;
    REP(i, k) {
        if (sm[i] > ans[i]) {
            ans[i+1]--;
            ans[i] += 26-sm[i];
        } else {
            ans[i] -= sm[i];
        }
    }
    return ans;
}

vector<int> vecadd(vector<int> lg, vector<int> sm) {
    vector<int> ans = lg;
    REP(i, k) {
        ans[i] += sm[i];
        if (ans[i] > 26) {
            ans[i] -= 26;
            ans[i+1]++;
        }
    }
    return ans;
}

vector<int> vecdiv2(vector<int> v) {
    vector<int> ans = v;
    for(int i=k-1; i>=0; i--) {
        if (ans[i]%2 == 1) {
            ans[i-1] += 26;
        }
        ans[i]/=2;
    }
    return ans;
}

void vec2str(vector<int> v) {
    string ans = "";
    REP(i, k) {
        cout << char('a' + v[k-i-1] - 1);
    }
    cout << endl;
}

int main(){
    cin >> k;
    cin >> ss;
    cin >> ls;

    svec = str2vec(ss);
    lvec = str2vec(ls);

    vector<int> diff = vecdiff(lvec, svec);
    vector<int> div2 = vecdiv2(diff);
    vector<int> ans = vecadd(svec, div2);
    vec2str(ans);
}
