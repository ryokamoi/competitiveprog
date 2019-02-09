#include<iostream>
#include<queue>
#include<string>
#include<map>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<pair<int, int>, pair<int, int> > ppp;

int w, h;
bool gone[50][50][50][50];
int rf[50][50];
int lf[50][50];

int dw[4] = {0, 1, 0, -1};
int dh[4] = {-1, 0, 1, 0};

int main(){
    map<char, int> m;
    m.insert(make_pair('.', 0));
    m.insert(make_pair('#', 1));
    m.insert(make_pair('%', 2));
    m.insert(make_pair('R', 0));
    m.insert(make_pair('L', 0));
    
    while(1){
        cin >> w >> h;
        if(w == 0) break;

        queue<ppp> que;
        ppp p;
        REP(i, h){
            string s;
            cin >> s;
            REP(j, w){
                lf[i][j] = m.at(s[j]);
                if(s[j] == 'L'){
                    p.second = make_pair(i, j);
                }
            }
            cin >> s;
            REP(j, w){
                rf[i][j] = m.at(s[j]);
                if(s[j] == 'R'){
                    p.first = make_pair(i, j);
                }
            }
        }

        que.push(p);

        REP(i, h) REP(j, w) REP(k, h) REP(l, w) gone[i][j][k][l] = false;
        gone[p.first.first][p.first.second][p.second.first][p.second.second] = true;

        bool flag = false;
        while(!que.empty()){
            ppp p = que.front();
            que.pop();

            int rh = p.first.first;
            int rw = p.first.second;
            int lh = p.second.first;
            int lw = p.second.second;

            REP(i, 4){
                int nrh = rh + dh[i];
                int nrw = rw + dw[i];
                int nlh = lh + dh[i];
                int nlw = lw - dw[i];
                if(rf[nrh][nrw]==1 || nrh<0 || nrh>=h || nrw<0 || nrw>=w){
                    nrh = rh; nrw = rw;
                }
                if(lf[nlh][nlw]==1 || nlh<0 || nlh>=h || nlw<0 || nlw>=w){
                    nlh = lh; nlw = lw;
                }
                if((rf[nrh][nrw]==2 && lf[nlh][nlw]!=2) || (rf[nrh][nrw]!=2 && lf[nlh][nlw]==2)){
                    continue;
                }
                if(rf[nrh][nrw]==2 && lf[nlh][nlw]==2){
                    flag = true;
                    queue<ppp> empty;
                    swap(que, empty);
                    break;
                }
                if(!gone[nrh][nrw][nlh][nlw]){
                    gone[nrh][nrw][nlh][nlw] = true;
                    que.push(make_pair(make_pair(nrh, nrw), make_pair(nlh, nlw)));
                }
            }
        }

        if(flag){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
