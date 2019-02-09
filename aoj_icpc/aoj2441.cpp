#include<iostream>
#include<string>
#include<math.h>
#include <sstream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

long long c3;
long long c5;
long long c15;

long long s;

long long lpow(int n){
    long long output = 1;
    REP(i, n){
        output *= 10;
    }
    return output;
}

long long lfb(long long t, int i, long long len){
    long long t15 = t / 15 - c15;
    long long t3 = t / 3 - t15 - c15 - c3;
    long long t5 = t / 5 - t15 - c15 - c5;

    c15 += t15;
    c3 += t3;
    c5 += t5;

    long long l15 = t15*(8-i);
    long long l3 = t3*(4-i);
    long long l5 = t5*(4-i);
    len += i*(t - (lpow(i-1)-1)) + l15 + l3 + l5;

    return len;
}

long long fb(long long n){
    int i = 1;

    c3 = 0;
    c5 = 0;
    c15 = 0;

    long long len = 0;
    long long t1 = 1;
    while(1){
        long long t = lpow(i) - 1;
        if(t>n) break;

        len = lfb(t, i, len);
        i += 1;
    }

    len = lfb(n, i, len);
    return len;
}

long long bs(){
    long long n = 10e16;
    long long ub = n;
    long long lb = 0;
    while(ub-lb > 1){
        long long mid = (ub - lb) / 2 + lb;
        long long fbhn = fb(mid);
        if(fbhn >= s){
            ub = mid;
        } else {
            lb = mid;
        }
    }
    
    return lb += 1;
}

int main(){
    cin >> s;

    long long num = bs();
    long long crfb = fb(num-1);

    string str;
    REP(i, 500){
        if(num % 15 == 0){
            str += "FizzBuzz";
        } else if (num % 3 == 0){
            str += "Fizz";
        } else if (num % 5 == 0){
            str += "Buzz";
        } else {
            stringstream ss;
            ss << num;
            str += ss.str();
        }
        num += 1;
    }

    cout << str.substr(s-crfb-1, 20) << endl;
}
