#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef pair<string, bool> psb;

int n;
char al[25];
string s;
vector<psb> can[26];

int main(){
    REP(i, 25){
        al[i] = 'a'+i;
    }

    while(1){
        cin >> s;
        if(s=="#") break;

        REP(i, 26) can[i].clear();
        can[25].push_back(make_pair(s, false));

        for(int i=24; i>=0; i--){
            REP(j, can[i+1].size()){
                psb p = can[i+1][j];

                vector<int> c;
                REP(k, p.first.size()){
                    if(p.first[k] == al[i]){
                        c.push_back(k);
                    }
                }

                if(!p.second){
                    psb np = p;
                    if(c.size()>0) np.second = true;
                    can[i].push_back(np);
                }

                REP(k, c.size()){
                    psb np = p;
                    np.first[c[k]] = al[i]+1;
                    np.second = false;
                    can[i].push_back(np);
                }
            }
        }

        vector<string> output;
        REP(i, can[0].size()){
            string c = can[0][i].first;
            REP(j, 25){
                REP(k, c.size()){
                    if(al[j]+1 == c[k]){
                        c[k] = al[j];
                        break;
                    }
                }
            }
            if(c==s) output.push_back(can[0][i].first);
        }

        sort(output.begin(), output.end());
        cout << output.size() << endl;
        if(output.size()<=10){
            REP(j, output.size()){
                cout << output[j] << endl;
            }
        } else {
            REP(j, 5){
                cout << output[j] << endl;
            }
            REP(j, 5){
                cout << output[output.size()-5+j] << endl;;
            }
        }
    }
}
