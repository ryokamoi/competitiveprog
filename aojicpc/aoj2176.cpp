#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int n, d;
stack<int> st[1000];
int csum[1000];
int csort[1000];

void init(){
    REP(i, n){
        csort[i] = csum[i];
    }
}

void sortcsort(){
    sort(csort, csort+n, greater<int>());
}

int main(){
    while(1){
        cin >> n >> d;

        if(n==0) break;

        REP(i, 1000) csum[i] = 0;
        REP(i, 1000) csort[i] = 0;
        REP(i, 1000) st[i] = stack<int>();

        REP(i, n){
            int m;
            cin >> m;
            REP(j, m){
                int c;
                cin >> c;
                csum[i] += c;
                st[i].push(c);
            }
        }

        init();
        sortcsort();

        while(1){
            int end = true;
            REP(i, n){
                while(!st[i].empty()){
                    int c = st[i].top();
                    int max_c = csort[0];
                    if(max_c == csum[i]){
                        max_c = max(csum[i]-c, csort[1]);
                    }
                    if(max_c - (csum[i]-c) <= d){
                        st[i].pop();
                        csum[i] -= c;
                        init();
                        sortcsort();
                        end = false;
                    } else {
                        break;
                    }
                }
            }

            int flag = true;
            REP(i, n){
                if(!st[i].empty()) flag = false;
            }
            if(flag){
                cout << "Yes" << endl;
                break;
            }
            if(end){
                cout << "No" << endl;
                break;
            }
        }
    }
}
