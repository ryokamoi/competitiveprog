#include<iostream>
#include<utility>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct dice{
    int top, bottom;
    int brfl[4];
};

int n;
int f;
int t;
int top[200][200];
int c[200][200];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

dice d;

void roll(int i){
    swap(d.brfl[i], d.top);
    swap(d.top, d.brfl[(i+2)%4]);
    swap(d.brfl[(i+2)%4], d.bottom);
}

int tf[7][7];
int output[6];

int main(){
    tf[1][2] = 3; tf[1][3] = 5; tf[1][4] = 2; tf[1][5] = 4;
    tf[2][3] = 1; tf[2][4] = 6; tf[2][6] = 3; tf[2][1] = 4;
    tf[3][5] = 1; tf[3][6] = 5; tf[3][1] = 2; tf[3][2] = 6;
    tf[4][5] = 6; tf[4][6] = 2; tf[4][1] = 5; tf[4][2] = 1;
    tf[5][6] = 4; tf[5][1] = 3; tf[5][3] = 6; tf[5][4] = 1;
    tf[6][2] = 4; tf[6][3] = 2; tf[6][4] = 5; tf[6][5] = 3;

    while(1){
        cin >> n;
        if(n==0) break;

        REP(i, 200){
            REP(j, 200){
                top[i][j] = 0;
                c[i][j] = 0;
            }
        }
        REP(i, 6) output[i] = 0;

        REP(i, n){
            cin >> t >> f;
            d.top = t; d.bottom = 7-t, d.brfl[2] = f; d.brfl[0] = 7-f;
            d.brfl[1] = tf[t][f]; d.brfl[3] = 7-tf[t][f];

            int x = 100, y = 100;
            while(1){
                bool flag = false;
                int nx, ny, nj;
                int max_num = 0;
                REP(j, 4){
                    if(d.brfl[j]>=4 && c[x][y]>c[x+dx[j]][y+dy[j]]){
                        if(d.brfl[j]>max_num){
                            max_num = d.brfl[j];
                            nx = x+dx[j]; ny = y+dy[j]; nj = j;
                            flag = true;
                        }
                    }
                }
                if(!flag) break;
                roll(nj);
                x = nx; y = ny;
            }
            top[x][y] = d.top;
            c[x][y] += 1;
        }

        REP(i, 200){
            REP(j, 200){
                if(top[i][j]>0){
                    output[top[i][j]-1]+=1;
                }
            }
        }

        REP(i, 6){
            cout << output[i];
            if(i!=5){
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}
