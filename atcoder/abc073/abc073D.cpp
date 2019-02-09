#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int n, m, r;
int rlist[8];
int d[200][200];
int w[8][8];

struct edge{
    int u, v, cost;
};

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
          src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

int pr[1<<9][8];
Weight best[1<<9][8];

void buildPath(int S, int i, vector<int> &path) {
  if (!S) return;
  buildPath(S^(1<<i), pr[S][i], path);
  path.push_back(i);
}



int main(){
    cin >> n >> m >> r;
    
    REP(i, r) cin >> rlist[i];
    REP(i, r) rlist[i] -= 1;
    
    REP(i, n) REP(j, n) d[i][j] = INF;
    REP(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a = a-1; b = b-1;
        d[a][b] = c;
        d[b][a] = c;
    }

    REP(k, n){
        REP(i, n){
            REP(j, n){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    REP(i, r) REP(j, r) w[i][j] = INF;
    REP(i, r) REP(j, r){
        w[i][j] = d[rlist[i]][rlist[j]];
        w[j][i] = w[i][j];
        // cout << w[i][(i+1)%r] << " " << rlist[i] << " " << rlist[(i+1)%r] << endl;
    }
  
  int output = INF;
  REP(s, r){
      vector<int> path;
      int N = 1 << r;
      REP(S,N) REP(i, r) best[S][i] = INF;
      best[1<<s][s] = 0;
      REP(S,N) REP(i,r) if (S&(1<<i)) REP(j,r)
        if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
          best[S|(1<<j)][j] = best[S][i] + w[i][j],
          pr[S|(1<<j)][j] = i;
      int t = min_element(best[N-1], best[N-1]+r) - best[N-1];
      path.clear(); buildPath(N-1, t, path);
      output = min(output, best[N-1][t]);
  }
  cout << output << endl;
}
