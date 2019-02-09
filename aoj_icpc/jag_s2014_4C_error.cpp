#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main(){
    double d;
    cin >> d;
    
    double output;
    if(pow(d, 2) - pow(floor(d), 2) <= 2){
        output = max(sqrt(2) * d, floor(d)+1);
    } else {
        output = sqrt(2) * d;
    }

    cout << fixed << setprecision(10) << output << endl;
}
