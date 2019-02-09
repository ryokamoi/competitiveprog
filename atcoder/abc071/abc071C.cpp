#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int n;
    cin >> n;

    vector<long long> a(n);
    REP(i, n){
        long long ai;
        cin >> ai;
        a.push_back(ai);
    }

    sort(a.begin(), a.end(), greater<long long>());
    vector<long long> candidate(n);
    vector<long long> rect(n);
    while(!a.empty()){
        long long ai = a[a.size()-1];
        a.pop_back();
        if(ai == a[a.size()-1]){
            candidate.push_back(ai);
            a.pop_back();
            long long count = 2;
            while(ai ==a[a.size()-1]){
                a.pop_back();
                count += 1;
                if(count == 4){
                    rect.push_back(ai);
                }
            }
        }
    }

    if(candidate.size()>=2){
        sort(candidate.begin(), candidate.end(), greater< long long >());
        long long output = candidate[0] * candidate[1];
        if(rect.size()>=1){
            sort(rect.begin(), rect.end(), greater<long long>());
            output = max(output, rect[0]*rect[0]);
        }
        cout << output << endl;
    } else {
        cout << 0 << endl;
    }
}
