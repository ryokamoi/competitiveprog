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
typedef long long ll;
typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;
typedef pair<double, pii> pdii;

int INF = 1000000000;

int n;
double pxyz[210][3], vxyz[210][3], r[210], vr[210];
double del_time[210];
vector<pdii> col_time;

vector<double> xyz_coef, r_coef;

void calc_xyz_coef(int idx1, int idx2) {
  xyz_coef = vector<double>();
  REP(i, 3) {
    xyz_coef.push_back(0.0);
  }
  
  REP(i, 3) {
    double a = pow(vxyz[idx1][i], 2) - 2*vxyz[idx1][i]*vxyz[idx2][i]
      + pow(vxyz[idx2][i], 2);
    xyz_coef[0] += a;

    double b = 2 * (pxyz[idx1][i] * vxyz[idx1][i]
        - (pxyz[idx1][i] * vxyz[idx2][i]
          + pxyz[idx2][i] * vxyz[idx1][i])
        + pxyz[idx2][i] * vxyz[idx2][i]);
    xyz_coef[1] += b;

    double c = pow(pxyz[idx1][i], 2) - 2*pxyz[idx1][i]*pxyz[idx2][i]
      + pow(pxyz[idx2][i], 2);
    xyz_coef[2] += c;
  }
}

void calc_r_coef(int idx1, int idx2) {
  r_coef = vector<double>();
  REP(i, 3) {
    r_coef.push_back(0.0);
  }

  double a = pow(vr[idx1], 2) + 2*vr[idx1]*vr[idx2]
    + pow(vr[idx2], 2);
  r_coef[0] += a;

  double b = -2 * (r[idx1] * vr[idx1]
      + r[idx1] * vr[idx2] + r[idx2] * vr[idx1]
      + r[idx2] * vr[idx2]);
  r_coef[1] += b;

  double c = pow(r[idx1], 2) + 2*r[idx1] * r[idx2]
    + pow(r[idx2], 2);
  r_coef[2] += c;
}

pdd quadeq(double a, double b, double c) {
  double D = sqrt(pow(b, 2) - 4*a*c);
  pdd ans;
  ans.first = (-b - D) / (2*a);
  ans.second = (-b + D) / (2*a);
  return ans;
}

double calc_col(int idx1, int idx2) {
  calc_xyz_coef(idx1, idx2);
  calc_r_coef(idx1, idx2);

  vector<double> coef;
  REP(i, 3) {
    coef.push_back(xyz_coef[i] - r_coef[i]);
  }

  double a = coef[0];
  double b = coef[1];
  double c = coef[2];
  if (pow(b, 2) - 4*a*c < 0) return (double)INF;

  pdd ans = quadeq(a, b, c);
#ifdef DEBUG
  cout << ans.first << " " << ans.second << endl;
#endif

  if (ans.first > 0) {
    return ans.first;
  } else if (ans.second > 0) {
    return ans.second;
  }
  return 110.0;
}

int main(){
  while(1) {
    cin >> n;
    if (n==0) break;

    col_time = vector<pdii>();

    REP(i, n) {
      cin >> pxyz[i][0] >> pxyz[i][1] >> pxyz[i][2];
      cin >> vxyz[i][0] >> vxyz[i][1] >> vxyz[i][2];
      cin >> r[i] >> vr[i];
    }

    REP(i, n) {
      del_time[i] = r[i] / vr[i];
    }

    REP(i, n) {
      for(int j=i+1; j<n; j++) {
        double col = calc_col(i, j);
        if (col < (double)INF) {
          col_time.push_back(pdii(col, pii(i, j)));
        }
      }
    }

    sort(col_time.begin(), col_time.end());

    REP(i, col_time.size()) {
      pdii col = col_time[i];
      double colt = col.first;
      int idx1 = col.second.first;
      int idx2 = col.second.second;
      if (colt < del_time[idx1] && colt < del_time[idx2]) {
        del_time[idx1] = colt;
        del_time[idx2] = colt;
      }
    }

    REP(i, n) {
      printf("%.10lf\n", del_time[i]);
    }
  }
}
