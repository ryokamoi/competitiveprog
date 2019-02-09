#include<iostream>
#include<string>
#include<cctype>
#include<math.h>

using namespace std;

bool former_is_bigger(string a, string b){
    if(a.size() > b.size() || (a.size() == b.size() && a.compare(b) >= 1)){
        return true;
    } else {
        return false;
    }
}

int main(){
    while(1){
        int w, h;
        string dp[71][71];
        string map[71][71];
        
        cin >> w >> h;

        if(w==0) break;
        
        for(int i=0; i<h; ++i){
            string line;
            cin >> line;
            for(int j=0; j<w; ++j){
                map[i][j] = line.substr(j, 1);
            }
        }

        for(int i=0; i<71; ++i){
            for(int j=0; j<71; ++j){
                dp[i][j] = "";
            }
        }

        for(int i=h-1; i>=0; --i){
            for(int j=w-1; j>=0; --j){
                int copy_i;
                int copy_j;
                if(isdigit(map[i][j][0])){
                    if(former_is_bigger(dp[i+1][j],  dp[i][j+1])){
                        copy_i = i+1;
                        copy_j = j;
                    } else if(former_is_bigger(dp[i][j+1], dp[i+1][j])){
                        copy_i = i;
                        copy_j = j+1;
                    } else {
                        copy_i = i+1;
                        copy_j = j;
                    }
                    dp[i][j] = map[i][j] + dp[copy_i][copy_j];
                }
            }
        }
        /*
        for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                cout << dp[i][j] << "   ";
            }
            cout << endl;
        }
        */

        string output = "";
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(dp[i][j][0] != '0'){
                    if(former_is_bigger(dp[i][j], output)){
                        output = dp[i][j];
                    }
                }
            }
        }
        cout << output << endl;
    }
}
