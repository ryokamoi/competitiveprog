#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int n;
string ans;
char animal[100000];

void init(){
    REP(i, n) animal[i] = '_';
}

void output_ans(){
    REP(i, n) cout << animal[i];
    cout << endl;
}

bool t(int i){
    bool tflag = true;
    for(int i=2; i<=n; i++){
        if((animal[i-1]=='S' && ans[i-1]=='o') || (animal[i-1]=='W' && ans[i-1]=='x')){
            if(animal[i%n]=='_'){
                animal[i%n] = animal[(i-2+n)%n];
            } else {
                if(animal[i%n] != animal[(i-2+n)%n]) tflag = false;;
            }
        }

        if((animal[i-1]=='S' && ans[i-1]=='x') || (animal[i-1]=='W' && ans[i-1]=='o')){
            if(animal[i]=='_'){
                if(animal[(i-2+n)%n]=='S'){
                    animal[i%n] = 'W';
                } else {
                    animal[i%n] = 'S';
                }
            } else {
                if(animal[(i-2+n)%n]=='S'){
                    if(animal[i%n] != 'W') tflag = false;
                } else {
                    if(animal[i%n] != 'S') tflag = false;
                }
            }
        }

        if((animal[(n-i+1)%n]=='S' && ans[(n-i+1)%n]=='o') || (animal[(n-i+1)%n]=='W' && ans[(n-i+1)%n]=='x')){
            if(animal[n-i]=='_'){
                animal[n-i] = animal[(n-i+2)%n];
            } else {
                if(animal[n-i] != animal[(n-i+2)%n]) tflag = false;;
            }
        }

        if((animal[(n-i+1)%n]=='S' && ans[(n-i+1)%n]=='x') || (animal[(n-i+1)%n]=='W' && ans[(n-i+1)%n]=='o')){
            if(animal[n-i]=='_'){
                if(animal[(n-i+2)%n]=='S'){
                    animal[n-i] = 'W';
                } else {
                    animal[n-i] = 'S';
                }
            } else {
                if(animal[(n-i+2)%n]=='S'){
                    if(animal[n-i] != 'W') tflag = false;
                } else {
                    if(animal[n-i] != 'S') tflag = false;
                }
            }
        }
    }

    return tflag;
}

int main(){
    cin >> n >> ans;

    bool flag = false;
    if(ans[0]=='o'){
        init();
        animal[0] = 'S'; animal[1] = 'S'; animal[n-1] = 'S';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }

        init();
        animal[0] = 'S'; animal[1] = 'W'; animal[n-1] = 'W';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }

        init();
        animal[0] = 'W'; animal[1] = 'S'; animal[n-1] = 'W';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }
        
        init();
        animal[0] = 'W'; animal[1] = 'W'; animal[n-1] = 'S';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }
    } else {
        init();
        animal[0] = 'S'; animal[1] = 'S'; animal[n-1] = 'W';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }

        init();
        animal[0] = 'S'; animal[1] = 'W'; animal[n-1] = 'S';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }
        
        init();
        animal[0] = 'W'; animal[1] = 'S'; animal[n-1] = 'S';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }

        init();
        animal[0] = 'W'; animal[1] = 'W'; animal[n-1] = 'W';
        if(t(2) && !flag){
            output_ans(); flag = true;
        }
    }

    if(!flag) cout << -1 << endl;
}
