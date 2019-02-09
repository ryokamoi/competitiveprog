#include<iostream>
#include<vector>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int h, w;
int alpha[26];
int red, blue, green;

vector<int> odd, even, four;

int main(){
    cin >> h >> w;
    red = (h/2) * (w/2);
    
    blue = 0;
    if(h%2 == 1){
        blue += w/2;
    }
    if(w%2 == 1){
        blue += h/2;
    }

    if(h%2==1 && w%2==1){
        green = 1;
    } else {
        green = 0;
    }

    REP(i, 26) alpha[i] = 0;
    REP(i, h){
        REP(j, w){
            char a;
            cin >> a;
            alpha[a - 'a'] += 1;
        }
    }

    REP(i, 26){
        if(alpha[i]>0){
            if(alpha[i]%4==0){
                four.push_back(i);
            } else if (alpha[i]%2==0){
                even.push_back(i);
            } else {
                odd.push_back(i);
            }
        }
    }

    bool flag = true;
    if(odd.size()==1 && green==1){
        if((alpha[odd[0]]-1) == 0){
            green = 1;
        } else if((alpha[odd[0]]-1)%4 == 0){
            four.push_back(odd[0]);
        } else {
            even.push_back(odd[0]);
        }
    } else if(odd.size()==0 && green==0){
        green = 0;
    } else {
        flag = false;
    }

    if(even.size()>blue){
        flag = false;
    } else {
        blue -= even.size();
    }

    if(blue%2 == 1) flag = false;

    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
