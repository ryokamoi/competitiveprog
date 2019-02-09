#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int h, w;
int a, b;
string field[220];

ll ns, ew, four;
bool used[220][220];

int main(){
    cin >> h >> w;
    cin >> a >> b;

    REP(i, h){
        cin >> field[i];
    }

    ll sum = 0;
    REP(i, h){
        REP(j, w){
            if(field[i][j]=='S'){
                sum += 1;
            }
        }
    }

    ns = 0;
    ew = 0;
    four = 0;

    REP(i, h){
        REP(j, w){
            used[i][j] = false;
        }
    }

    REP(i, h/2){
        REP(j, w/2){
            if(field[i][j] == 'S' && field[h-1-i][j]=='S' && field[i][w-1-j]=='S' && field[h-1-i][w-1-j]=='S'){
                four += 1;
                used[i][j] = true;
                used[h-1-i][j] = true;
                used[i][w-1-j] = true;
                used[h-1-i][w-1-j] = true;
            }
        }
    }

    REP(i, h/2){
        REP(j, w){
            if(field[i][j] == 'S' && field[h-1-i][j] == 'S' && !used[i][j]){
                ns += 1;
            }
        }
    }

    REP(i, h){
        REP(j, w/2){
            if(field[i][j] == 'S' && field[i][w-1-j]=='S' && !used[i][j]){
                ew += 1;
            }
        }
    }

    ll output=0;
    int add = 0;
    if(sum == four * 4){
        four -= 1;
        add = 1;
    } else if(sum == four*4 + ns*2){
        ns -= 1;
    } else if(sum == four*4 + ew*2){
        ew -= 1;
    }
    output = max(output, ns*a + four * (a+b) + (four+add) * a);
    output = max(output, ns*a + four * (a+b) + (four+add) * b);
    output = max(output, ew*b + four * (a+b) + (four+add) * a);
    output = max(output, ew*b + four * (a+b) + (four+add) * b);

    output += (a+b);
    cout << output << endl;
}
