#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<map>

using namespace std;

#define REP(i, n) for(long i=0; i<n; i++)

typedef pair<long, long> pii;

const long max_n = 10e5;
const long max_i = 10e9;
long n;
char com;
map<long, long> f2i;
map<long, long> i2f;

deque<pii> empty;
vector<pii> used[max_n];

void writef(long f, long c, long idx){
    f2i[f] = idx;
    i2f[idx] = f;

    while(1){
        if(c==0) break;

        pii e = empty.front();
        empty.pop_front();
        if(e.second-e.first>c){
            used[f2i[f]].push_back(make_pair(e.first, e.first+c));
            empty.push_front(make_pair(e.first+c, e.second));
            c = 0;
        } else {
            c -= (e.second - e.first);
            used[f2i[f]].push_back(e);
        }
    }
}

void delf(long f){
    deque<pii> tmp;
    REP(i, used[f2i[f]].size()){
        pii u = used[f2i[f]][i];
        while(!empty.empty()){
            pii e = empty.front();
            empty.pop_front();
            if(u.second<=e.first){
                tmp.push_back(u);
                empty.push_front(e);
                break;
            } else {
                tmp.push_back(e);
            }
        }
    }

    while(!tmp.empty()){
        pii t = tmp.back();
        tmp.pop_back();
        empty.push_front(t);
    }
    used[f2i[f]].clear();
}

void readf(long s){
    REP(i, n){
        REP(j, used[i].size()){
            pii u = used[i][j];
            if(u.first<=s && s<u.second){
                cout << i2f[i] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main(){
    while(1){
        cin >> n;
        if(n==0) break;

        empty.clear();
        REP(i, max_n) used[i].clear();

        empty.push_back(make_pair(0, max_i));
        REP(i, n){
            cin >> com;

            if(com=='W'){
                long f, c; // file, count
                cin >> f >> c;
                writef(f, c, i);
            } else if(com=='D'){
                long f;
                cin >> f;
                delf(f);
            } else if(com=='R'){
                long s;
                cin >> s;
                readf(s);
            }
        }
        cout << endl;
    }
}
