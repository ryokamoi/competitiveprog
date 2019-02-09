#include<iostream>
#include<queue>


using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
typedef queue<pair<pair<int, int>, queue<int> > > qii;

int n, m;
bool init[100000][100000];
bool used[100000][100000];

int main(){
    cin >> n >> m;
    REP(i, m){
        int a, b;
        cin >> a >> b;
        init[a-1][b-1] = true;
        init[b-1][a-1] = true;
    }

    queue<int> mini_que;
    mini_que.push(-1);
    mini_que.push(-1);
    mini_que.push(-1);

    qii que;
    que.push(make_pair(make_pair(0, 0), mini_que));

    while(!que.empty()){
        
    }
}
