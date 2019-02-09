#include<iostream>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

double p[300][2];
int n;

double dis(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int circle(double x, double y, int i, int j){
    int count = 2;
    REP(k, n){
        if(k!=i && k!=j){
            if(dis(x, y, p[k][0], p[k][1]) < 1){
                count += 1;
            }
        }
    }
    return count;
}

int main(){
    while(1){
        cin >> n;

        if(n==0) break;

        REP(i, n){
            cin >> p[i][0];
            cin >> p[i][1];
        }

        int output = 1;
        REP(i, n){
            for(int j=i+1; j<n; j++){
                double cx = (p[i][0]+p[j][0]) / 2;
                double cy = (p[i][1]+p[j][1]) / 2;
                double d = dis(p[i][0], p[i][1], p[j][0], p[j][1]);

                if(d>2){
                    continue;
                } else if (d==2){
                    output = max(output, circle(cx, cy , i, j));
                } else {
                    double a1 = acos(d/2);
                    double a2 = atan2((p[j][1]-p[i][1]), p[j][0]-p[i][0]);

                    double x1 = p[i][0] + cos(a2+a1);
                    double y1 = p[i][1] + sin(a2+a1);

                    double x2 = p[i][0] + cos(a2-a1);
                    double y2 = p[i][1] + sin(a2-a1);

                    output = max(output, circle(x1, y1, i, j));
                    output = max(output, circle(x2, y2, i, j));
                }
            }
        }

        cout << output << endl;
    }
}
