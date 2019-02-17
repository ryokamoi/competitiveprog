#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct edge {int to, dist, c;} ;

typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef pair<double, pi3> P; // time, vertex, from, velocity

int main() {
    while(true) {
        int n, m;
        cin >> n >> m;
        if (n==0) break;

        int s, g;
        cin >> s >> g;

        double time[40][40][40]; // vertex, velocity, from
        REP(i, n) {
            REP(j, 31) {
                REP(k, n) {
                    time[i][j][k] = 1000000000;
                }
            }
        }
        time[s-1][0][s-1] = 0;

        vector<edge> gr[40];
        REP(i, m) {
            int x, y, d, c;
            cin >> x >> y >> d >> c;
            
            edge e1;
            e1.to = y-1;
            e1.dist = d;
            e1.c = c;
            gr[x-1].push_back(e1);

            edge e2;
            e2.to = x-1;
            e2.dist = d;
            e2.c = c;
            gr[y-1].push_back(e2);
        }

        priority_queue<P, vector<P>, greater<P>> que;
        P q = P(0.0, pi3(s-1, pii(s-1, 0)));
        que.push(q);

        while(!que.empty()) {
            P q = que.top(); que.pop();
            double t = q.first;
            int v = q.second.first;
            int from = q.second.second.first;
            int velo = q.second.second.second;
            if (time[v][velo][from] < t) continue;

            REP(i, gr[v].size()) {
                if (gr[v][i].to == from) continue; // u-turn
                REP(a, 3) {
                    int accel = a-1;
                    if(velo+accel <= 0 || velo+accel > gr[v][i].c) continue;

                    if (time[gr[v][i].to][velo+accel][v] >
                            time[v][velo][from] + (double)gr[v][i].dist / (double)(velo+accel)){
                        time[gr[v][i].to][velo+accel][v]= 
                            time[v][velo][from] + (double)gr[v][i].dist / (double)(velo+accel);
                        
                        P q = P(time[gr[v][i].to][velo+accel][v],
                                pi3(gr[v][i].to, pii(v, velo+accel)));
                        que.push(q);
                    }
                }
            }
        }
        
        double output = 1000000000;
        REP(i, n) {
            output = min(time[g-1][1][i], output);
        }

        if (output == 1000000000) {
            cout << "unreachable" << endl;
        } else {
            printf("%.10lf\n", output);
        }
    }
}
