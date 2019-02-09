#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> P;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int main(){
    int r, c;
    int sy, sx;
    int gy, gx;
    char maze[100][100];
    int dist[100][100];

    scanf("%d %d", &r, &c);
    scanf("%d %d", &sy, &sx);
    scanf("%d %d", &gy, &gx);

    REP(i, r) {
        string row;
        cin >> row;
        REP(j, c) {
            maze[i][j] = row[j];
            dist[i][j] = -1;
        }
    }

    queue<P> que;
    que.push(P(sx-1, sy-1));
    dist[sy-1][sx-1] = 0;
    while (que.size()) {
        int x, y;
        P p = que.front();
        x = p.first;
        y = p.second;
        que.pop();

        REP(i, 4) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (maze[ny][nx] == '.' && 
                    dist[ny][nx] == -1){
                dist[ny][nx] = dist[y][x] + 1;
                que.push(P(nx, ny));
            }
        }
    }

    printf("%d\n", dist[gy-1][gx-1]);
}
