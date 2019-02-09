#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

struct nijd{
    int n, i, j, k;
};

int INF = 10e8;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool gone[50][50][4];
int f[50][50];
int n, m;
map<char, int> c2i;

bool out(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return true;
    } else {
        return false;
    }
}

int main(){
    c2i.insert(make_pair('^', 0));
    c2i.insert(make_pair('>', 1));
    c2i.insert(make_pair('v', 2));
    c2i.insert(make_pair('<', 3));
    c2i.insert(make_pair('.', 4));
    c2i.insert(make_pair('#', 5));
    c2i.insert(make_pair('G', 6));

    cin >> n >> m;
    
    queue<nijd> que;
    nijd init;
    init.n = 0;

    REP(i, n){
        string s;
        cin >> s;
        REP(j, m){
            if(s[j]>=0 && s[j]<=3){
                f[i][j] = c2i.at('#');
                init.i = i;
                init.j = j;
                init.k = c2i.at(s[j]);
                que.push(init);
            } else {
                f[i][j] = c2i.at(s[j]);
            }
        }
    }

    REP(i, n){
        REP(j, m){
            REP(k, 4){
                gone[i][j][k] = false;
            }
        }
    }

    int count = INF;
    while(!que.empty()){
        nijd p = que.front();
        que.pop();

        int ni = p.i+dx[p.k];
        int nj = p.j+dy[p.k];
        int ri = p.i+dx[p.k];
        int rj = p.j+dy[p.k];
        int li = p.i+dx[(p.k+2)%4];
        int lj = p.j+dx[(p.k+2)%4];
        if(f[p.i][p.j] == c2i.at('G')){
            count = min(count, p.n);
        } else if (!out(ni, nj) && f[ni][nj]==c2i.at('.') && !gone[ni][nj][p.k]){
            nijd np;
            np.n = p.n+1;
            np.i = ni; np.j = nj; np.k = p.k;
            que.push(np);
            gone[np.i][np.j][np.k] = true;
        } else if ((out(ri, rj) || f[ri][rj]==c2i.at('#')) && !gone[p.i][p.j][(p.k+1)%4]){
            nijd np;
            np.n = p.n; np.i = p.i; np.j = p.j;
            np.k = (p.k+1)%4;
            que.push(np);
            gone[np.i][np.j][np.k] = true;
        } else if ((out(li, lj) || f[li][lj]==c2i.at('#')) && !gone[p.i][p.j][(p.k+3)%4]){
            nijd np;
            np.n = p.n; np.i = p.i; np.j = p.j;
            np.k = (p.k+3)%4;
            que.push(np);
            gone[np.i][np.j][np.k] = true;
        }
    }

    if(count == INF){
        cout << -1 << endl;
    } else {
        cout << count << endl;
    }

}
