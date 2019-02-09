#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
int s[200000];
vector<int> o1;
vector<int> o2;

int main(){
    cin >> n;
    REP(i, n){
        cin >> s[i];
    }

    for(int i=0; i<n; i++){
        if(i%2==0){
            o1.push_back(s[i]);
        } else {
            o2.push_back(s[i]);
        }
    }
    if(n==1){
        printf("%d\n", o1[0]);
    } else if((n-1)%2==0){
        for(int i=o1.size()-1; i>=0; i--){
            printf("%d ", o1[i]);
        }
        REP(i, o2.size()-1){
            printf("%d ", o2[i]);
        }
        printf("%d\n", o2[o2.size()-1]);
    } else {
        for(int i=o2.size()-1; i>=0; i--){
            printf("%d ", o2[i]);
        }
        REP(i, o1.size()-1){
            printf("%d ", o1[i]);
        }
        printf("%d\n", o1[o1.size()-1]);
    }
}
