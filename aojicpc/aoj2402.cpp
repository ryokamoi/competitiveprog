#include<iostream>
#include<math.h>
#include<complex>
#include<iomanip>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)
#define EQV(a, b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

typedef complex<double> point;

static const double pi = acos(-1.0);

double dot(point a, point b){
    return (a.real()*b.real() + a.imag()*b.imag());
}

double cross(point a, point b){
    return (a.real()*b.imag() - a.imag()*b.real());
}

int is_orthogonal(point a1, point a2, point b1, point b2) {
    return EQ( dot(a1-a2, b1-b2), 0.0 );
}

int is_parallel(point a1, point a2, point b1, point b2) {
    return EQ( cross(a1-a2, b1-b2), 0.0 );
}

// distance between the line ab and the point c
double dis_lp(point a, point b, point c){
    return abs(cross(b-a, c-a)) / abs(b-a);
}

// distance between the line segment ab and the point c
double dis_lsp(point a, point b, point c){
    if(dot(b-a, c-a)<0) return abs(c-a);
    if(dot(a-b, c-b)<0) return abs(c-b);
    return dis_lp(a, b, c);
}

int is_intersected(point a1, point a2, point b1, point b2){
    return (cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1)<0) && 
           (cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1)<0);
}

// rotation
point rotate(point a, double d){
    point r = polar(1.0, d*2*pi/360);
    return a*r;
}

int INF = 10e8;
int n, m, l;
double dis[100][100];
double x[100];
double y[100];
double a[100];
double r[100];

complex<double> star[100][5];

int main(){
    while(1){
        cin >> n >> m >> l;
        if(n==0) break;

        REP(i, n){
            REP(j, n){
                dis[i][j] = INF;
            }
        }

        REP(i, n){
            cin >> x[i] >> y[i] >> a[i] >> r[i];
            point p = point(x[i], y[i]);
            point t = point(0, r[i]);
            REP(j, 5){
                star[i][j] = p + rotate(t, (double)144*j+a[i]);
            }
        }

        /*
        REP(i, n){
            REP(j, 5){
                cout << star[i][j] << " ";
            }
            cout << endl;
        }
        */

        REP(i, n){
            REP(j, n){
                REP(k, 5){
                    REP(l, 5){
                        if(is_intersected(star[i][k], star[i][(k+1)%5], star[j][l], star[j][(l+1)%5])){
                            dis[i][j] = 0;
                        }
                    }
                }
            }
        }

        REP(i, n){
            REP(j, n){
                REP(k, 5){
                    REP(l, 5){
                        dis[i][j] = min(dis[i][j], dis_lsp(star[i][k], star[i][(k+1)%5], star[j][l]));
                        dis[j][i] = min(dis[i][j], dis[j][i]);
                    }
                }
            }
        }

        /*
        REP(i, n){
            REP(j, n){
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }
        */

        REP(k, n){
            REP(i, n){
                REP(j, n){
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }

        cout << fixed << setprecision(7) << dis[m-1][l-1] << endl;
    }
}
