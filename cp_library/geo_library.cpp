#include<iostream>
#include<math.h>
#include<complex>

using namespace std;

#define REpoint(i, n) for(int i=0; i<n; i++)

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
    if(dot(b-a, c-a)<EPS) return abs(c-a);
    if(dot(a-b, c-b)<EPS) return abs(c-b);
    return dis_lp(a, b, c);
}

int is_intersected(point a1, point a2, point b1, point b2){
    return (cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1)<EPS) &&
           (cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1)<EPS);
}

// rotation
point rotate(point a, double d){
    point r = polar(1.0, d*2*pi/360);
    return a*r;
}

int main(){
    point a1(0, 0), a2(1, 1), b1(0, 1), b2(1, 0);
    cout << is_intersected(a1, a2, b1, b2) << endl;

    cout << rotate(b2, 90) << endl;
}

