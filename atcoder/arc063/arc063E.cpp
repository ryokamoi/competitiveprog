#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

bool written[100000];
vector<int> r[100000];
vector<int> g[100000];

int n, k;

vector<int> fillbrank(int v){
    vector<int> intersection;
    REP(i, g[v].size()){
        vector<int> e;
        if(r[g[v][i]].size()==0){
            e = fillbrank(g[v][i]);
        } else {
            e.push_back(r[g[v][i]][0]-1);
            e.push_back(r[g[v][i]][0]+1);
        }
        if(i==0){
            intersection = e;
        } else {
            vector<int> vec1 = intersection;
            intersection = vector<int>();
            sort(intersection.begin(), intersection.end());
            sort(e.begin(), e.end());
            set_intersection(vec1.begin(), vec1.end(),
                             e.begin(), e.end(),
                             inserter(intersection, intersection.end()));
        }
    }
    return intersection;
}

int main(){
    cin >> n;
    REP(i, n-1){
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    cin >> k;
    REP(i, k){
        int v, p;
        cin >> v >> p;
        written[v-1] = true;
        r[v-1].push_back(p);
    }

    bool flag = true;
    REP(i, n){
        if(written[i]){
            REP(j, g[i].size()){
                if(written[g[i][j]]){
                    if(r[g[i][j]][0]!=r[i][0]+1 && r[g[i][j]][0]!=r[i][0]-1){
                        flag = false; break;
                    }
                } else {
                    if(r[g[i][j]].size()==0){
                        r[g[i][j]].push_back(r[i][0]-1);
                        r[g[i][j]].push_back(r[i][0]+1);
                    } else {
                        vector<int> e;
                        REP(k, r[g[i][j]].size()){
                            if(r[g[i][j]][k]==r[i][0]-1){
                                e.push_back(r[i][0]-1);
                            }
                        }
                        REP(k, r[g[i][j]].size()){
                            if(r[g[i][j]][k]==r[i][0]+1){
                                e.push_back(r[i][0]+1);
                            }
                        }
                        if(e.size()==0){
                            flag = false; break;
                        } else {
                            r[g[i][j]] = e;
                        }
                    }
                }
            }
        }
        if(!flag) break;
    }

    if(flag){
        REP(i, n){
            if(r[i].size()==0){
                vector<int> intersection = fillbrank(i);
                if(intersection.size()==0){
                    flag = false; break;
                } else {
                    r[i] = intersection;
                }
            }
        }
    }

    if(!flag){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        REP(i, n){
            cout << r[i][0] << endl;
        }
    }
}
