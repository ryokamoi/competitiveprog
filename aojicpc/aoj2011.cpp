#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int par[100];

int root(int x){
    if(par[x] == x){
        return x;
    } else {
        return par[x] = root(par[x]);
    }
}

bool same(int x, int y){
    return root(x) == root(y);
}

bool all_united(int num){
    REP(i, num-1){
        if(!same(i, i+1)){
            return false;
        }
    }
    return true;
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y){
        return;
    } else {
        par[x] = y;
    }
}

int letter[50][50];

bool completed(int num){
    REP(i, num){
        REP(j, num){
            if(letter[i][j] == 0){
                break;
            } else if(j==num-1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    while(1){
        int num;
        cin >> num;

        if(num==0) break;

        int cal[num][31];
        REP(i, num){
            REP(j, 31){
                cal[i][j] = 0;
            }
        }

        REP(i, num){
            int dnum;
            cin >> dnum;
            REP(j, dnum){
                int date;
                cin >> date;
                cal[i][date] = 1;
            }
        }

        /*
        REP(i, num){
            REP(j, 10){
                cout << cal[i][j];
            }
            cout << endl;
        }
        */

        REP(i, num){
            REP(j, num){
                letter[i][j] = 0;
            }
        }

        int today[num];
        int output = -1;
        REP(j, 31){
            REP(i, num){
                today[i] = 0;
            }
            REP(i, num){
                if(cal[i][j] == 1){
                    today[i] = 1;
                    REP(k, num){
                        if(letter[i][k]==1){
                            today[k] = 1;
                        }
                    }
                }
            }
            REP(i, num){
                if(cal[i][j] ==1){
                    REP(k, num){
                        if(today[k]==1){
                            letter[i][k] = 1;
                        }
                    }
                }
            }

            /*
            cout << j << endl;
            REP(l, num){
                REP(m, num){
                    cout << letter[l][m] << " ";
                }
                cout << endl;
            }
            */

            if(completed(num)){
                output = j;
                break;
            }
        }
        cout << output << endl;
    }
}
