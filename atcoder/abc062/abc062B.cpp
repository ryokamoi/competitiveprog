#include<iostream>
#include<string>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int h, w;
    cin >> h >> w;
    cout << string(w+2, '#') << endl;

    REP(i, h){
        string s;
        cin >> s;
        s = "#" + s + "#";
        cout << s << endl;
    }

    cout << string(w+2, '#') << endl;
}
