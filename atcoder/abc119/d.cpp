#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

ll a, b;
ll q;
ll s[100010], t[100010];

ll findleft(ll start, bool isshrine) {
    ll idx=0;
    ll left=0;
    ll right;
    ll *array;
    if (isshrine) {
        right = a;
        array = s;
    } else {
        right = b;
        array = t;
    }

    while(right-left>1) {
        ll center = (right+left) / 2;
        if (array[center]>start) {
            right = center;
        } else if (array[center]<start) {
            left = center;
        } else {
            idx = center; break;
        }
        idx = left;
    }

    return idx;
}

ll findright(ll l, ll x, ll *array, ll length) {
    ll r;
    if (array[l]>=x || l==length-1) {
        r = l;
    } else {
        r = l+1;
    }

    return r;
}

int main() {
    cin >> a >> b >> q;

    REP(i, a) {
        cin >> s[i];
    }

    REP(i, b) {
        cin >> t[i];
    }

    REP(i, q) {
        ll x;
        cin >> x;
    
        ll output = 1000000000000;

        ll left, right;
        // first
        ll tl, tr, sl, sr;
        sl = findleft(x, true);
        tl = findleft(x, false);

        sr = findright(sl, x, s, a);
        tr = findright(tl, x, t, b);
        
        left = min(abs(x-s[sl]), abs(x-t[tl]));
        right = min(abs(x-s[sr]), abs(x-t[tr]));

        // left
        ll l2, r2;
        if (abs(x-s[sl]) == left) {
            l2 = findleft(s[sl], false);
            r2 = findright(l2, s[sl], t, b);
            left += min(abs(s[sl]-t[l2]), abs(s[sl]-t[r2]));
        } else {
            l2 = findleft(t[tl], true);
            r2 = findright(l2, t[tl], s, a);
            left += min(abs(t[tl]-s[l2]), abs(t[tl]-s[r2]));
        }

        // left
        if (abs(x-s[sr]) == right) {
            l2 = findleft(s[sr], false);
            r2 = findright(l2, s[sr], t, b);
            right += min(abs(s[sr]-t[l2]), abs(s[sr]-t[r2]));
        } else {
            l2 = findleft(t[tr], true);
            r2 = findright(l2, t[tr], s, a);
            right += min(abs(t[tr]-s[l2]), abs(t[tr]-s[r2]));
        }

        cout << min(left, right) << endl;
    }
}
