#include<iostream>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

double k;
double size[200][200][2];

int dir[4][4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int count(int d){
    REP(i, d/k + 1){
        REP(j, d/k + 1){
            size[i][j][0] = i*k;
            size[i][j][1] = j*k;
        }
    }

    int count = 0;
    REP(i, d/k){
        REP(j, d/k){
            bool flag = true;
            REP(k, 4){
                if((dist(d/2, d/2, size[i+dir[k][0]][j+dir[k][1]][0], \
                                    size[i+dir[k][0]][j+dir[k][1]][1])>d/2)){
                    flag = false;
                }
            }
            if(flag) count += 1;
        }
    }
    
    return count;
}

int main(){
    cin >> k;
    
    cout << count(200) << " " << count(300) << endl;
}
