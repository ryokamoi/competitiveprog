#include<iostream>
#include<string>
#include<queue>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define rREP(i, s, n) for(int i=s; i<n; i++)
typedef pair<int, int> pii;

int k;
string a, b;
int s[10], g[10];
int c;
bool locked[10];
queue<pii> que;

void divide(int first, int second){
    bool cor = false;
    int f;
    rREP(i, first, second){
        if(!cor && locked[i]){
            f = i; cor=true;
        }
        if(cor && !locked[i]){
            que.push(pii(f, i));
            cor = false;
        }
        if(cor && i==second-1){
            que.push(pii(f, second));
        }
    }

}

int main(){
    while(1){
        cin >> k;
        if(k==0) break;

        cin >> a >> b;
        REP(i, k){
            s[i] = a[i] - '0';
            g[i] = b[i] - '0';
        }

        c = 0;
        REP(i, k){
            locked[i] = s[i]!=g[i];
        }
        que = queue<pii>();
        divide(0, k);
        while(!que.empty()){
            pii p = que.front(); que.pop();
            c += 1;
            
            int ss[10];
            REP(i, k) ss[i] = s[i];
            int maxn, maxind; maxn = 0;
            REP(i, 10){
                int corn = 0;
                rREP(j, p.first, p.second){
                    if((ss[j]+i)%10 ==g[j]) corn += 1;
                }
                if(corn > maxn){
                    maxn = corn; maxind = i;
                }
            }

            rREP(i, p.first, p.second) s[i] = (s[i]+maxind)%10;
            rREP(i, p.first, p.second) locked[i] = s[i]!=g[i];
            divide(p.first, p.second);
        }
        cout << c << endl;
    }
}
