#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

string L[100];
double P[100];
int A[100];
int B[100];
int C[100];
int D[100];
int E[100];
int F[100];
double S[100];
int M[100];

int t[100];
double profit[100];
double eff[100];

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        REP(i, n){
            cin >> L[i] >> P[i] >> A[i];
            cin >> B[i] >> C[i] >> D[i];
            cin >> E[i] >> F[i] >> S[i] >> M[i];
            t[i] = A[i]+B[i]+C[i]+D[i]+E[i];
            profit[i] = F[i]*S[i]*M[i]-P[i];
            if(M[i]>=2){
                t[i] += (D[i]+E[i])*(M[i]-1);
            }
            eff[i] = profit[i] / t[i];
        }
        
        vector<pair<double, string> > output(n);
        REP(i, n){
            output[i] = make_pair(-eff[i], L[i]);
        }
        sort(output.begin(), output.end());

        REP(i, n){
            cout << output[i].second << endl;
        }
        cout << "#" << endl;
    }
}
