#include<iostream>
#include<math.h>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef unsigned long long ll;

ll n, k;
ll a[100010];

ll llpow2(ll a) {
    if (a==0) return 1;
    ll half = llpow2(a/2);
    if (a%2 == 0) {
        return half * half;
    } else {
        return half * half * 2;
    }
}

bool bestisone(ll idx, ll *a) {
    int output = 0;
    REP(i, n) {
        if(a[i] & (1ll<<idx)) output ++;
    }

    return !(n-output < output);
}

int bitsum(ll idx, ll *a, bool kbit) {
    int output = 0;
    REP(i, n) {
        if(bool(a[i] & (1ll<<idx)) != kbit) output ++;
    }

    return output;
}

int main(){
    cin >> n >> k;
    REP(i, n) {
        cin >> a[i];
    }

    int maxidx=0;
    REP(i, 50) {
        bool flag = true;
        if (k >= llpow2(i)) flag=false;
        REP(j, n) {
            if(a[j] >= llpow2(i)) flag = false;
        }

        if (flag) {
            maxidx = i-1;
            break;
        }
    }

    string output = "";
    bool small = false;
    for (int i=maxidx; i>=0; i--) {
        bool abit = bestisone(i, a);
        if ((bool)(k & (1ll<<i))==abit || small) {
            output += to_string(bitsum(i, a, abit));
        } else {
            if (!abit) small = true;
            output += to_string(bitsum(i, a, 0));
        }
    }

    ll numoutput = 0;
    for (int i=output.size()-1; i>=0; i--) {
        numoutput += (output[output.size()-i-1]-'0') * llpow2(i);
    }
    cout << numoutput << endl;
}
