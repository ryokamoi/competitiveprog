#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct status {
    int k;
    vector<int> log;
    int map[8][8];
};

int h, w, c;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool gone[8][8];

void change_color(int ac, int (&map)[8][8]){
    int cc = map[0][0];
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    REP(i, h) REP(j, w) gone[i][j] = false;
    gone[0][0] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        map[x][y] = ac;
        REP(i, 4){
            int nx = x+d[i][0];
            int ny = y+d[i][1];
            if(!gone[nx][ny] && nx>=0 && nx<h && ny>=0 && ny<w){
                gone[nx][ny] = true;
                if(map[nx][ny]==cc){
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int count_color(int (&map)[8][8]){
    int cc = map[0][0];
    int count = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    REP(i, h) REP(j, w) gone[i][j] = false;
    gone[0][0] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        count += 1;
        REP(i, 4){
            int nx = x+d[i][0];
            int ny = y+d[i][1];
            if(!gone[nx][ny] && nx>=0 && nx<h && ny>=0 && ny<w){
                gone[nx][ny] = true;
                if(map[nx][ny]==cc){
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return count;
}

vector<int> find_color(int (&map)[8][8]){
    int cc = map[0][0];
    vector<int> candidates;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    REP(i, h) REP(j, w) gone[i][j] = false;
    gone[0][0] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        REP(i, 4){
            int nx = x+d[i][0];
            int ny = y+d[i][1];
            if(!gone[nx][ny] && nx>=0 && nx<h && ny>=0 && ny<w){
                gone[nx][ny] = true;
                if(map[nx][ny]==cc){
                    q.push(make_pair(nx, ny));
                } else {
                    candidates.push_back(map[nx][ny]);
                }
            }
        }
    }
    return candidates;
}

int main(){
    while(1){
        cin >> h >> w >> c;

        if(h==0) break;

        queue<status> que;
        status init;
        init.k = 0;
        init.log = vector<int>();
        REP(i, h){
            REP(j, w){
                cin >> init.map[i][j];
            }
        }

        que.push(init);
        int output = 0;
        while(!que.empty()){
            status s = que.front();
            que.pop();
            if(s.k == 4){
                change_color(c, s.map);
                int count = count_color(s.map);
                output = max(output, count);
            } else {
                status next;
                next.k = s.k+1;
                REP(i, h) REP(j, w) next.map[i][j] = s.map[i][j];
                que.push(next);

                vector<int> candidates = find_color(s.map);
                REP(i, candidates.size()){
                    status next;
                    next.k = s.k+1;
                    next.log = s.log;
                    next.log.push_back(candidates[i]);
                    REP(i, h) REP(j, w) next.map[i][j] = s.map[i][j];
                    change_color(candidates[i], next.map);
                    que.push(next);
                }
            }
        }

        cout << output << endl;
    }
}
