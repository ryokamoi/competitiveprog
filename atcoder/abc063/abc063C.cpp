#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
vector<int> s;
int c = 0;

int main(){
    cin >> n;
    REP(i, n){
        int si;
        cin >> si;
        s.push_back(si);
        c += si;
    }

    sort(s.begin(), s.end());
    
    int output = 0;
    if(c%10!=0){
        cout << c << endl;
    } else {
        REP(i, n){
            if((c-s[i])%10 != 0){
                output = c - s[i];
                break;
            }
        }
        cout << output << endl;
    }
}
