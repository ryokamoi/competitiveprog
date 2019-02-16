#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int c[110];

int main() {
    int n;
    cin >> n;

    REP(i, 110) {
        c[i] = 0;
    }

    set<int> st;
    REP(i, n) {
        int a;
        cin >> a;
        c[a] += 1;
        st.insert(a);
    }

    while(st.size() >= 2) {
        int b = *st.begin();
        int e = *(--st.end());
        bool flag = false;
        int mini;
        int minsum = 1000;
        for(int i=(e/b); i>=2; i--) {
            if (e%i == 0 and b*i < e) {
                flag = true;
                if (e/i + b*i < minsum) {
                    minsum = e/i + b*i;
                    mini = i;
                }
            }
        }

        if(flag){
            int d = min(c[b], c[e]);
            c[e] -= d;
            c[b] -= d;
            if(c[e] == 0) st.erase(e);
            if(c[b] == 0) st.erase(b);

            st.insert(e/mini);
            st.insert(b*mini);
            c[e/mini] += d;
            c[b*mini] += d;
        } else {
            st.erase(e);
        }
    }

    int output = 0;
    REP(i, 101) {
        output += i*c[i];
    }
    cout << output << endl;
}
