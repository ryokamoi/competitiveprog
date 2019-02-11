#include <iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int inout[10010][1300];
int use[10010][1300];

int main(){
    while(true){
        int N, M, r;
        cin >> N >> M;
        if (N==0) break;

        cin >> r;

        REP(i, M){
            REP(j, 1261){
                inout[i][j] = 0;
                use[i][j] = 0;
            }
        }

        REP(i, r){
            int t, n, m, s;
            cin >> t >> n >> m >> s;
            if (s==1) {
                inout[m-1][t] += 1;
            } else {
                inout[m-1][t] += -1;
            }
        }

        // syakutori method
        REP(i, M) {
            int status = 0;
            for (int t=540; t<=1260; t++) {
                status += inout[i][t];
                use[i][t] = status;
            }
        }

        int q;
        cin >> q;
        REP(i, q) {
            int ts, te, m;
            cin >> ts >> te >> m;
            int output = 0;
            for (int t=ts; t<te; t++) {
                if (use[m-1][t] > 0) {
                    output += 1;
                }
            }
            printf("%d\n", output);
        }
    }
}
