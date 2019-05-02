// Ryo Kamoi
//#define DEBUG

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

int w, h;
int cliff[70][40];
int dist[70][40][2];
pii start[2800];
pii goal[2800];

int steplx[9] = {3, 2, 2, 2, 1, 1, 1, 1, 1};
int steply[9] = {0, -1, 0, 1, -2, -1, 0, 1, 2};

int main(){
    while(1){
        cin >> w >> h;
        if (w==0 && h==0) break;

        REP(i, 70) {
            REP(j, 40) {
                cliff[i][j] = 0;
                REP(k, 2) {
                    dist[i][j][k] = INF;
                }
            }
        }

        REP(i, 2){
            start[i] = pii(-1, -1);
        }
        
        int start_num = 0;
        int goal_num = 0;
        REP(i, h) {
            REP(j, w) {
                char num;
                cin >> num;
                if (num == 'X') {
                    cliff[i][j] = -1;
                } else if (num == 'S') {
                    cliff[i][j] = 0;
                    REP(k, 2) dist[i][j][k] = 0;
                    start[start_num] = pii(i, j);
                    start_num++;
                } else if (num == 'T') {
                    cliff[i][j] = -2;
                    goal[goal_num] = pii(i, j);
                    goal_num++;
                } else {
                    cliff[i][j] = num - '0';
                }
            }
        }

        queue<pair<pii, pii>> que;
        int sign[2] = {-1, 1};
        REP(i, start_num) {
            REP(j, 2) {
                que.push(pair<pii, pii>(pii(0, sign[j]), start[i]));
            }
        }

        while(!que.empty()) {
            pair<pii, pii> p = que.front(); que.pop();
            int d = p.first.first;
            int x = p.second.second;
            int y = p.second.first;
            int lr = p.first.second;
            if (d > dist[y][x][(1+lr)/2]) continue;

#ifdef DEBUG
            cout << y << " " << x << " " << d << " " << lr << endl;
#endif

            REP(i, 9) {
                int nx = x + lr * steplx[i];
                int ny = y + steply[i];
                if (nx>=0 && ny>=0 && nx<w && ny<h) {
                    if (cliff[ny][nx] == -1) continue;
                    int next_dist = dist[y][x][(1+lr)/2] + max(0, cliff[ny][nx]);
                    if (dist[ny][nx][(1-lr)/2] > next_dist) {
                        dist[ny][nx][(1-lr)/2] = next_dist;
                        if (cliff[ny][nx] == -2) continue;
                        que.push(pair<pii, pii>(pii(next_dist, -lr), pii(ny, nx)));
                    }
                }
            }
        }

        int output = INF;
        REP(i, goal_num) {
            REP(k, 2) {
                output = min(dist[goal[i].first][goal[i].second][k], output);
            }
        }

        if (output == INF) {
            cout << -1 << endl;
        } else {
            cout << output << endl;
        }
    }
}
