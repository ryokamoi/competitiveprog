// Ryo Kamoi
#define DEBUG

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int INF = 1000000000;

ll n, x;
vector<pll> li, ui;
vector<ll> bi, taka;
ll output;

ll gcd(ll a, ll b) {
  if (a>b) return gcd(b, a);

  if (a==0) return b;
  return gcd(b%a, a);
}

int main(){
  cin >> n >> x;

  output = 0;
  REP(i, n) {
    ll b, l, u;
    cin >> b >> l >> u;
    output += b;

    bi.push_back(b);
    taka.push_back(b);
    li.push_back(pll(l, i));
    ui.push_back(pll(u, i));
  }

  sort(li.begin(), li.end());
  sort(ui.begin(), ui.end(), greater<pll>());

  int lidx=0;
  while(1) {

  }

  cout << output << endl;
}

