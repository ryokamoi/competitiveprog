#include<iostream>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int d[100][100];
int n, m, l, k, a, h;
bool cold[100];

int main(){
    while(1){
        cin >> n >> m >> l >> k >> a >> h;
        
        if(n==0) break;

        REP(i, n){
            REP(j, n){
                if(i==j){
                    d[i][j] = 0;
                } else {
                    d[i][j] = INF;
                }
            }
        }

        REP(i, n) cold[i] = false;
        REP(i, l){
            int cold_ind;
            cin >> cold_ind;
            cold[cold_ind] = true;
        }
        cold[a] = true;
        cold[h] = true;

        REP(i, k){
            int x, y, t;
            cin >> x >> y >> t;
            d[x][y] = t;
            d[y][x] = t;
        }

        REP(i, n){
            if(!cold[i]){
               REP(j, n){
                   REP(k, n){
                       d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                       d[k][j] = d[j][k];
                   }
               }
            }
        }
        REP(i, n){
            if(!cold[i]){
                REP(j, n){
                    d[i][j] = INF;
                    d[j][i] = INF;
                }
            }
        }

        /*
        REP(i, n){
            REP(j, n){
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        */

        REP(i, n){
            REP(j, n){
                if(d[i][j] > m){
                    d[i][j] = INF;
                }
            }
        }

        REP(k, n){
            REP(i, n){
                REP(j, n){
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }

        if(d[a][h] == INF){
            cout << "Help!" << endl;
        } else {
            int output = d[a][h] + max(0, d[a][h] - m);
            cout << output << endl;
        }
    }
}
