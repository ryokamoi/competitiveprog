#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef pair<long long, double> pii;

long long q, h, s, d;
long long p[4];
vector<pii> price;
long long n;

int main(){
    cin >> q >> h >> s >> d;
    cin >> n;

    price.push_back(make_pair(q*8, 0.25));
    price.push_back(make_pair(h*4, 0.5));
    price.push_back(make_pair(s*2, 1.0));
    price.push_back(make_pair(d, 2.0));
    sort(price.begin(), price.end());

    long long sum = 0;
    if(price[0].second == 2.0){
        if((long long)n % 2==0){
            sum = n/2 * price[0].first;
        } else {
            sum = n/2 * price[0].first + price[1].first / 2;
        }
    } else {
        sum = n * price[0].first / 2;
    }

    cout << sum << endl;

    /*
    long long sum = 0;
    REP(i, 4){
        long long c = floor(n / price[i].second);
        sum += c * price[i].first * price[i].second / 2.0;
        n -= c * price[i].second;
    }
    cout << sum << endl;
    */
}
