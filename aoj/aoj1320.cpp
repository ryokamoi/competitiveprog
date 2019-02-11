#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int n;
string s[14];
int w[14][14];
int sum;

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

int pr[1<<15][14];
Weight best[1<<15][14];

void buildPath(int S, int i, vector<int> &path) {
  if (!S) return;
  buildPath(S^(1<<i), pr[S][i], path);
  path.push_back(i);
}

int main(){
    while(1){
        cin >> n;

        int m = n;
        if(n==0) break;

        int sum = 0;
        REP(i, n){
            cin >> s[i];
            sum += s[i].size();
        }

        REP(i, n) REP(j, n) w[i][j] = 20;
        REP(i, n) REP(j, n){
            int u, v;
            if(s[i].size()<s[j].size()){u=i; v=j;}else{u=j; v=i;}
            REP(k, s[v].size() - s[u].size()){
                bool flag = true;
                REP(l, s[u].size()){
                    if(s[u][l]!=s[v][k+l]) flag = false;
                }
                if(flag){
                    REP(k, n){
                        w[u][k] = 0; w[k][u] = 0;
                        m -= 1;
                    }
                    break;
                }
            }

            if(w[i][j]<20) break;
            int c = 20;
            REP(k, min(s[i].size(), s[j].size())) {
                bool flag = true;
                REP(l, k+1){
                    if(s[i][s[i].size()-1-k+l] != s[j][l]){
                        flag = false;
                    }
                }
                if(flag){
                    c = 20 - (k+1);
                }
            }
            w[i][j] = c;
        }

        int output = INF;
        REP(s, n){
          vector<int> path;
          int N = 1 << n;
          REP(S, N) REP(i, n) best[S][i] = INF;
          best[1<<s][s] = 0;
          REP(S,N) REP(i,n) if(S&(1<<i)) REP(j,n){
            if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
              best[S|(1<<j)][j] = best[S][i] + w[i][j],
              pr[S|(1<<j)][j] = i;
          }
          int t = min_element(best[N-1], best[N-1]+n) - best[N-1];
          path.clear(); buildPath(N-1, t, path);
          output = min(output, best[N-1][t]);
        }

        cout << sum - (20*(m-1) - output) << endl;
    }
}

