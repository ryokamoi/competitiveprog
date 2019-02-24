#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;

int n;
int r1, c1, r2, c2;

int map[100][100];
int gone[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<pii> bfs(pii start) {
    vector<pii> reachable;
    queue<pii> que;
    que.push(start);
    gone[start.first][start.second] = true;
    while(!que.empty()) {
        pii idx = que.front();
        que.pop();
        int r = idx.first;
        int c = idx.second;
        if (map[r][c] == -1) continue;
        reachable.push_back(idx);

        REP(i, 4) {
            if (r+dr[i]>=0 && r+dr[i]<n && c+dc[i]>=0 && c+dc[i]<n) {
                if (gone[r+dr[i]][c+dc[i]]) continue;
                if (map[r+dr[i]][c+dc[i]]==0) {
                    que.push(pii(r+dr[i], c+dc[i]));
                    gone[r+dr[i]][c+dc[i]] = true;
                }
            }
        }
    }

    return reachable;
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    REP(i, n) {
        string s;
        cin >> s;
        REP(j, n) {
            map[i][j] = s[j]-'0';
        }
    }

    REP(i, n) {
        REP(j, n) {
            gone[i][j] = false;
        }
    }
    vector<pii> start = bfs(pii(r1-1, c1-1));
    REP(i, n) {
        REP(j, n) {
            gone[i][j] = false;
        }
    }
    vector<pii> goal = bfs(pii(r2-1, c2-1));

    int output = 1000000000;
    REP(i, start.size()) {
        REP(j, goal.size()) {
            pii s = start[i];
            pii g = goal[j];
            int fst = s.first-g.first;
            int snd = s.second-g.second;
            int dist = fst*fst + snd*snd;
            output = min(output, dist);
        }
    }

    cout << output << endl;
}
