#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i++; i<n)

typedef pair<int, int> pii;

int w, h;
int dnum;
char tiles[30][30];
int tiledist[30][30];
int dist[20][20];

int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

vector<pii> dtiles;
map<pii, int> dtiles_idx;

void cleandist() {
    REP(i, h) {
        REP(j, w) {
            tiledist[i][j] = 0;
        }
    }
}

void calcdist(int idx) {
    
}

int main() {
    while(1) {
        cin >> w >> h;

        if (w==0) break;

        dtiles = vector<pii>();
        dtiles_idx = map<pii, int>();

        dnum = 0;
        REP(i, h) {
            string s;
            cin >> s;
            REP(j, w) {
                tiles[i][j] = s[j];
                if (tiles[i][j] == 'o') {
                    dtiles.insert(dtiles.begin(), pii(i, j));
                }
                if (tiles[i][j] == '*') {
                    dtiles.push_back(pii(i, j));
                    dnum++;
                }
            }
        }

        REP(i, dtiles.size()) {
            cleandist();
            calcdist(i);
        }
    }
}
