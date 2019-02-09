#include<iostream>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
vector<int> a;

bool odd(int num){
    if(num%2==0){
        return false;
    } else {
        return true;
    }
}

int main(){
    cin >> n;
    REP(i, n){
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    if(!odd(a[0]) || !odd(a[a.size()-1])){
        cout << "No" << endl;
    } else {
        while(1){
            bool flag = true;
            int f = -1;
            int l = -1;
            REP(i, a.size()){
                if(f == -1 && i == a.size()-1) break;
                if(f == -1 && odd(a[i]) && !odd(a[i+1])){
                    f = i;
                } else if (f != -1 && odd(a[i])){
                    l = i;
                    break;
                }
            }
            if(f==-1 || l==-1) break;
            if(odd(f-l)){
                a.erase(a.begin()+f+1, a.begin()+l);
            } else {
                a.erase(a.begin()+f+1, a.begin()+l+1);
            }
        }
        if(odd(a.size())){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
