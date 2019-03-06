#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define mci map<char, int>

mci m;
int n;
string s[8];
vector<char> candi;
bool used[10][10][10][10][10][10][10][10];

int np[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // next permutation
int pow10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main(){
    while(1){
        cin >> n;
        if(n==0) break;

        REP(i, n){
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
        }

        candi = vector<char>();
        REP(i, n){
            REP(j, s[i].size()){
                bool add = true;
                REP(k, candi.size()){
                    if(s[i][j] == candi[k]){
                        add = false;
                        break;
                    }
                }
                if(add){
                    candi.push_back(s[i][j]);
                }
            }
        }

        REP(q, 10) REP(w, 10) REP(e, 10) REP(r, 10) REP(t, 10) REP(y, 10) REP(u, 10) REP(i, 10){
            used[q][w][e][r][t][y][u][i] = false;
        }

        int output = 0;
        REP(i, candi.size()) np[i] = i;
        do{
            bool consistent = true;
            m = mci();
            REP(i, candi.size()){
                m.insert(make_pair(candi[i], np[i]));
            }

            bool valid = true;
            int idx[8];

            REP(i, 8) idx[i] = 0;
            REP(i, candi.size()){
                idx[i] = np[i];
            }
            if(used[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]][idx[5]][idx[6]][idx[7]]){
                valid = false;
            } else {
                used[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]][idx[5]][idx[6]][idx[7]] = true;
            }

            REP(i, n){
                if(m.at(s[i][s[i].size()-1]) == 0){
                    valid = false;
                    break;
                }
            }

            if(valid){
                int ans = 0;
                REP(j, s[n-1].size()){
                    ans += pow10[j] * m.at(s[n-1][j]);
                }

                int sum = 0;
                REP(i, 8){
                    REP(j, n){
                        if(s[j].size() > i){
                            sum += m.at(s[j][i]) * pow10[i];
                        }
                    }
                    if(ans%pow10[i+1] != sum%pow10[i+1]){
                        consistent = false;
                        break;
                    }
                }

                if(consistent) output += 1;
                if(consistent){
                    cout << ans << endl;
                }
            }
        } while(next_permutation(np, np+10));

        cout << output << endl;
    }
}
