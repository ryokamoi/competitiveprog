#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    
    int max = *max_element(num, num+3);
    int min = *min_element(num, num+3);

    cout << max-min << endl;
}
