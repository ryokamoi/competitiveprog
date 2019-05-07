// Ryo Kamoi
// #define DEBUG

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef pair<ll, ll> pll;

int INF = 1000000000;

struct rect {
  pdd points[4]; double h;
};

struct linear {
  double a, b, c;
};

int n;
double sx, sy, ex, ey;
pdd normal;
linear course;

vector<rect> rects;

double eps = 0.0000000001;

linear points2line(pdd p1, pdd p2) {
  linear line;
  if (abs(p1.first - p2.first) < eps) {
    line.a = 1.0;
    line.b = 0.0;
    line.c = -p1.first;
    return line;
  }

  line.a = -(p1.second - p2.second) / (p1.first - p2.first);
  line.b = 1.0;
  line.c = - (line.a * p1.first + line.b * p1.second);
  return line;
}

pdd intersect(linear l1, linear l2) {
  if (abs(l1.a) < eps && abs(l2.a) < eps) {
    return pdd((double)INF, (double)INF);
  }
  if (abs(l1.b) < eps && abs(l2.b) < eps) {
    return pdd((double)INF, (double)INF);
  }
  if (abs(l1.a) < eps && abs(l2.b) < eps) {
    return pdd(-l2.c/l2.a, -l1.c/l1.b);
  }
  if (abs(l2.a) < eps && abs(l1.b) < eps) {
    return pdd(-l1.c/l1.a, -l2.c/l2.b);
  }

  double x=0, y=0;
  if (abs(l2.a) < eps) {
    y = -(l2.c / l2.b);
    x = -(l1.b * y + l1.c) / l1.a;
  } else {
    x = -(l2.c / l2.a);
    y = -(l1.a * x + l1.c) / l1.b;
  }

  return pdd(x, y);
}

double l2norm(pdd p) {
  return sqrt(p.first*p.first + p.second*p.second);
}

bool on_the_line(rect r) {
  double seg_maxx = max(sx, ex);
  double seg_maxy = max(sy, ey);
  double seg_minx = min(sx, ex);
  double seg_miny = min(sy, ey);
  if (seg_maxx<r.points[0].first && seg_maxy<r.points[0].second &&
      seg_minx>r.points[2].first && seg_miny>r.points[2].second) {
    return true;
  }

  REP(i, 4){
    linear l = points2line(r.points[i], r.points[(i+1)%4]);
    pdd ip = intersect(course, l);

    if (abs(l.a) < eps) {
      double ux = max(r.points[i].first, r.points[(i+1)%4].first);
      double lx = min(r.points[i].first, r.points[(i+1)%4].first);
      if (ip.first <= ux && ip.first >= lx) {
        if (ip.second <= max(sy, ey)+eps
            && ip.second >= min(sy, ey)-eps) {
          return true;
        }
      }
    } else {
      double uy = max(r.points[i].second, r.points[(i+1)%4].second);
      double ly = min(r.points[i].second, r.points[(i+1)%4].second);
      if (ip.second <= uy && ip.second >= ly) {
        if (ip.first <= max(sx, ex)+eps
           && ip.first >= min(sx, ex)-eps) {
          return true;
        }
      }
    }
  }
  return false;
}

double euclid_dist(pdd p1, pdd p2) {
  pdd p = pdd(p1.first - p2.first, p1.second - p2.second);
  return l2norm(p);
}

double dist2rad(double dist, double height) {
  if (dist < height) {
    return dist;
  }
  return (pow(dist, 2) + pow(height, 2)) / (2*height);
}

double inner(pdd p1, pdd p2) {
  return p1.first * p2.first + p1.second * p2.second;
}

bool on_lineseg(pdd p, pdd start, pdd end) {
  pdd linseg = pdd(end.first-start.first, end.second-start.second);
  pdd pvec = pdd(p.first-start.first, p.second-start.second);
  double projection = inner(linseg, pvec) / pow(l2norm(linseg), 2);
  return (projection < 1.0 && projection > 0.0);
}

double linedist(pdd p) {
  return abs(course.a * p.first + course.b * p.second + course.c) /
    sqrt(course.a*course.a + course.b*course.b);
}

double recrad(rect r) {
  double dist = (double)INF;

  REP(i, 4) {
    pdd p = r.points[i];
    if (!on_lineseg(p, pdd(sx, sy), pdd(ex, ey))) {
#ifdef DEBUG
      cout << "not on line seg" << p.first << " " << p.second << endl;
#endif
      dist = min(dist, euclid_dist(p, pdd(sx, sy)));
      dist = min(dist, euclid_dist(p, pdd(ex, ey)));
#ifdef DEBUG
      cout << dist << endl;
#endif
      if (on_lineseg(pdd(sx, sy), p, r.points[(i+1)%4])) { 
        if (i%2==0) {
          dist = min(dist, abs(p.first - sx));
        } else {
          dist = min(dist, abs(p.second - sy));
        }
      }
      if (on_lineseg(pdd(ex, ey), p, r.points[(i+1)%4])) { 
        if (i%2==0) {
          dist = min(dist, abs(p.first - ex));
        } else {
          dist = min(dist, abs(p.second - ey));
        }
      }
    } else {
      dist = min(dist, linedist(p));
    }
  }
#ifdef DEBUG
  cout << dist << " " << dist2rad(dist, r.h) << endl;
#endif
  return dist2rad(dist, r.h);
}

int main(){
  while(1) {
    cin >> n;
    if (n==0) break;

    cin >> sx >> sy >> ex >> ey;
    double nx = ey-sy;
    double ny = -(ex-sx);
    double norm = l2norm(pdd(nx, ny));
    nx = nx / norm;
    ny = ny / norm;
    normal = pdd(nx, ny);
    course = points2line(pdd(sx, sy), pdd(ex, ey));

#ifdef DEBUG
    cout << nx << " " << ny << endl;
    cout << course.a << " " << course.b << " " << course.c << endl;
#endif

    rects = vector<rect>();
    REP(i, n) {
      double minx, miny, maxx, maxy, h;
      cin >> minx >> miny >> maxx >> maxy >> h;
      rect r;
      r.points[0] = pdd(maxx, maxy);
      r.points[1] = pdd(maxx, miny);
      r.points[2] = pdd(minx, miny);
      r.points[3] = pdd(minx, maxy);
      r.h = h;
      rects.push_back(r);
    }
    
    double rad = (double)INF;
    REP(i, rects.size()) {
      if (on_the_line(rects[i])) {
        rad = 0.0;
#ifdef DEBUG
        cout << i << " on line" << endl;
#endif
        break;
      }

      rad = min(rad, recrad(rects[i]));
    }

    printf("%.10lf\n", rad);
  }
}
