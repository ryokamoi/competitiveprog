#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define pii pair<pair<int, int>, pair<int, int> >

int h, w, d;
int masu[500][500];
bool can_use[5];
bool in_line[1000][4];
bool in_line2[1000][4];
char color[4] = {'R', 'Y', 'G', 'B'};

vector<pii> idx;

int main(){
    cin >> h >> w >> d;

    REP(i, h) REP(j, w) masu[i][j] = 4;

    REP(i, h) REP(j, w) idx.push_back(pii(make_pair(i+j, abs(i-j)), make_pair(i, j)));
    sort(idx.begin(), idx.end());
    REP(i, h+w) REP(j, 4) in_line[i][j] = false;
    REP(i, h+w) REP(j, 4) in_line2[i][j] = false;

    REP(l, h*w){
        pii ij = idx[l];
        int line = ij.first.first;
        int line2 = ij.first.second;
        int i = ij.second.first;
        int j = ij.second.second;

        REP(k, 4) can_use[k] = true;
        int ue = max(0, i-d);
        int sita = min(h, i+d+1);
        for(int k=ue; k<sita; k++){
            int left = j - (d - abs(i-k));
            int right = j + (d - abs(i-k));
            if(left>=0 && left<w){
                can_use[masu[k][left]] = false;
            }
            if(right>=0 && right<w){
                can_use[masu[k][right]] = false;
            }
        }
        bool flag = false;
        REP(k, 4){
            if(can_use[k] && in_line[line][k]){
                masu[i][j] = k;
                flag = true;
                break;
            }
        }
        if(!flag){
            REP(k, 4){
                if(can_use[k] && in_line2[line2][k]){
                    masu[i][j] = k;
                    in_line[line][k] = true;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            REP(k, 4){
                if(can_use[k]){
                    masu[i][j] = k;
                    in_line[line][k] = true;
                    in_line2[line2][k] = true;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) assert(false);
    }

    REP(i, h){
        REP(j, w){
            cout << color[masu[i][j]];
        }
        cout << endl;
    }
}
