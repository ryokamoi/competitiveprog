#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct status{
    bool o[24];
};

int n;
double x[24], y[24], r[24];
int c[24];
double d[24][24];

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool gone[1<<24];

int o2idx(bool (&o)[24]){
    int output = 0;
    REP(i, n){
        if(o[i]){
            output = output | 1<<i;
        }
    }
    return output;
}

int main(){
    while(1){
        cin >> n;
        if(n==0) break;

        REP(i, n){
            cin >> x[i] >> y[i] >> r[i] >> c[i];
        }

        int colnum = 0;
        REP(i, n){
            colnum = max(colnum, c[i]);
        }

        REP(i, n){
            REP(j, n){
                d[i][j] = dist(x[i], y[i], x[j], y[j])-(r[i]+r[j]);
            }
        }

        REP(i, 1<<n) gone[i]=false;

        int maxnum = 0;
        queue<status> que;
        status s;
        REP(i, n) s.o[i] = true;
        que.push(s);
        gone[o2idx(s.o)] = true;
        while(!que.empty()){
            status s = que.front();
            que.pop();

            int count = 0;
            REP(i, n){
                if(!s.o[i]) count += 1;
                // cout << s.o[i] << " ";
            }
            // cout << endl;
            maxnum = max(maxnum, count);

            vector<int> top[4];
            REP(i, n){
                if(s.o[i]){
                    bool flag = true;
                    REP(j, i){
                        if(s.o[j] && d[i][j]<0) flag = false;
                    }
                    if(flag){
                        top[c[i]-1].push_back(i);
                    }
                }
            }

            REP(i, colnum){
                if(top[i].size()>=2){
                    REP(j, top[i].size()-1){
                        for(int k=j+1; k<top[i].size(); k++){
                            status ns;
                            REP(l, n) ns.o[l] = s.o[l];
                            ns.o[top[i][j]] = false;
                            ns.o[top[i][k]] = false;
                            if(!gone[o2idx(ns.o)]){
                                gone[o2idx(ns.o)] = true;
                                que.push(ns);
                            }
                        }
                    }
                }
            }
        }
        cout << maxnum << endl;
    }
}
