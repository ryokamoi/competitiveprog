#include<iostream>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
vector<int> a[9];
int main(){
    cin >> n;

    REP(i, n){
        int ai;
        cin >> ai;

        REP(j, 8){
            if(400*j<=ai && ai<400*(j+1)){
                a[j].push_back(ai);
            }
        }
        if(ai>=3200){
            a[8].push_back(ai);
        }
    }

    int count = 0;
    REP(i, 8){
        if(a[i].size()>=1){
            count += 1;
        }
    }

    if(count==0){
        if(a[8].size()==0){
            cout << "0 0" << endl;
        } else {
            cout << "1 " << a[8].size() << endl;
        }
    } else {
        int l = count;
        count += a[8].size();
        cout << l << " " << count << endl;
    }
}
