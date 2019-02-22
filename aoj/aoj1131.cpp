#include<iostream>
#include<map>
#include<tuple>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<int, int> pii;

int p, q, a, n;
map<tuple<int, int, int, int, int>, int> memo;

int gcd(int a, int b) {
    if (a==0) return b;
    if (a>b) return gcd(b, a);

    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return a*b / gcd(a, b);
}

pii subt(int n1, int d1, int n2, int d2) {
    int l = lcm(d1, d2);
    n1 *= l / d1;
    n2 *= l / d2;
    int s = n1-n2;

    if (s < 0) {
        return pii(s, l);
    } else {
        int g = gcd(s, l);
        return pii(s/g, l/g);
    }
}

int dfs(int nume, int deno, int prev, int mul, int n) {
    if (n<=0) return 0;
    
    auto itr = memo.find(make_tuple(nume, deno, prev, mul, n));
    if (itr != memo.end()) return memo[make_tuple(nume, deno, prev, mul, n)];

    int output = 0;
    for (int i=prev; i<=a/mul; i++) {
        pii ans = subt(nume, deno, 1, i);
        if (ans.first < 0) continue;
        if (ans.first == 0) {
            output += 1;
            continue;
        }

        pii exp = subt(nume, deno, n, i);
        if (exp.first > 0) break;
        if (ans.second / ans.first * i * mul > a) continue;
        
        output += dfs(ans.first, ans.second, i, mul*i, n-1);
    }
    return memo[make_tuple(nume, deno, prev, mul, n)] = output;
}

int main(){
    while(1){
        memo = map<tuple<int, int, int, int, int>, int>();
        
        cin >> p >> q >> a >> n;
        if(p==0) break;

        cout << dfs(p, q, 1, 1, n) << endl;
    }
}
