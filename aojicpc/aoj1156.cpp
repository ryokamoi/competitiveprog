#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<pair<int, int>, pair<int, int> > pii; // cost, from, x, y

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int INF = 10e8;
int w, h;
int map[30][30][4];
int cmap[30][30][4];
int c[4];

int main(){
    while(1){
        cin >> w >> h;
        if(w==0) break;

        REP(i, h) REP(j, w) REP(k, 4) map[i][j][k] = INF;
        REP(i, h){
            REP(j, w){
                int s;
                cin >> s;
                if(s<=3){
                    map[i][j][s] = 0;
                }
            }
        }

        REP(i, 4) cin >> c[i];
        REP(i, h) REP(j, w) REP(k, 4) map[i][j][k] = min(map[i][j][k], c[k]);

        REP(i, h) REP(j, w) REP(k, 4) cmap[i][j][k] = INF;
        cmap[0][0][1] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > que;
        que.push(pii(make_pair(0, 1), make_pair(0, 0)));
        while(!que.empty()){
            pii p = que.top();
            que.pop();
            int cost = p.first.first;
            int from = p.first.second;
            int x = p.second.first;
            int y = p.second.second;
            REP(i, 4){
                int nx = x+dx[(i+from)%4];
                int ny = y+dy[(i+from)%4];
                if(nx>=0 && ny>=0 && nx<w && ny<h){
                    if(cmap[ny][nx][(i+from)%4] > map[y][x][i] + cost){
                        cmap[ny][nx][(i+from)%4] = map[y][x][i] + cost;
                        que.push(pii(make_pair(cmap[ny][nx][(i+from)%4], (i+from)%4), make_pair(nx, ny)));
                    }
                }
            }
        }

        /*
        REP(i, h){
            REP(j, w){
                int out = INF;
                REP(k, 4) out = min(cmap[i][j][k], out);
                cout << out;
            }
            cout << endl;
        }
        */

        int output = INF;
        REP(i, 4) output  = min(output, cmap[h-1][w-1][i]);
        cout << output << endl;
    }
}
