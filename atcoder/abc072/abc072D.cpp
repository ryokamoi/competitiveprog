#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int p[100000];
vector<int> conti;

int main(){
    cin >> n;
    REP(i, n) cin >> p[i];

    REP(i, n){
        if(p[i] == i+1){
            if(i!=0 && p[i-1]==i){
                conti[conti.size()-1] += 1;
            } else {
                conti.push_back(1);
            }
        }
    }

    int output = 0;
    REP(i, conti.size()){
        output += ceil(double(conti[i])/2);
    }
    cout << output << endl;
}
