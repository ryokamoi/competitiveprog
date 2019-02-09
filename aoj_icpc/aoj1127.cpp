#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<double ,pair<int, int> > pdii; // distance, point1, point2

int n;
double dis[100][100];
int unit[100];
vector<pdii> difdis(100);

double x[100], y[100], z[100], r[100];
double cordis;

double dis3d(double x1, double y1, double z1, double x2, double y2, double z2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

bool allunited(){
    int u = unit[0];
    REP(i, n){
        if(unit[i] != u) return false;
    }
    return true;
}

int main(){
    while(1){
        cin >> n;
        if(n==0) break;

        REP(i, n){
            cin >> x[i];
            cin >> y[i];
            cin >> z[i];
            cin >> r[i];
        }

        REP(i, n){
            REP(j, n){
                if(i==j){
                    dis[i][j] = 0;
                } else {
                    dis[i][j] = dis3d(x[i], y[i], z[i], x[j], y[j], z[j]) - (r[i]+r[j]);
                }
            }
        }

        REP(i, n) unit[i] = i;
        REP(i, n){
            int u = unit[i];
            vector<int> update;
            update.push_back(unit[i]);
            REP(j, n){
                if(dis[i][j]<=0){
                    update.push_back(unit[j]);
                    u = min(u, unit[j]);
                    unit[j] = unit[i];
                }
            }
            REP(j, n){
                REP(k, update.size()){
                    if(unit[j] == update[k]){
                        unit[j] = u;
                    }
                }
            }
        }

        cordis = 0;
        while(1){
            if(allunited()) break;

            difdis = vector<pdii>();
            REP(i, n){
                for(int j=i+1; j<n; j++){
                    if(unit[i] != unit[j]){
                        difdis.push_back(pdii(dis[i][j], make_pair(i, j)));
                    }
                }
            }

            sort(difdis.begin(), difdis.end());
            cordis += difdis[0].first;
            int ci = difdis[0].second.first;
            int cj = difdis[0].second.second;

            int ucj = unit[cj];
            REP(i, n){
                if(unit[i] == ucj){
                    unit[i] = unit[ci];
                }
            }
        }

        cout << fixed << setprecision(3) << cordis << endl;
    }
}
