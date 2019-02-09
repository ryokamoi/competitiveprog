#include<iostream>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int d;
    cin >> d;
    REP(i, d){
        int m, n;
        cin >> m >> n;

        int count = 0;
        for(int j = -sqrt(m*m+n*n); j<=sqrt(m*m+n*n); j++){
            for(int k = -sqrt(m*m+n*n); k<=sqrt(m*m+n*n); k++){
                if(j*j+k*k>0){
                    if((j*m+k*n)%(j*j+k*k)==0 && (j*n-k*m)%(j*j+k*k)==0){
                        count += 1;
                    }
                }
            }
        }

        if(count == 8){
            cout << 'P' << endl;
        } else {
            cout << 'C' << endl;
        }
    }
}
