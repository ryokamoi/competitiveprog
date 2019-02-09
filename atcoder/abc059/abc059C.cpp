#include<iostream>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define ll long long

int n;
ll a[100000];
ll c[2];
ll csum;

int main(){
    cin >> n;
    REP(i, n){
        cin >> a[i];
    }

    c[0] = 0; c[1] = 0;
    REP(l, 2){
        csum = 0;
        ll sign;
        if(l==0){sign = 1;} else {sign = -1;}

        csum += a[0];
        if(csum == 0){
            c[l] += 1;
            csum += sign;
        } else if(csum * sign < 0){
            c[l] = sign * (-csum+sign);
            csum += -csum + sign;
        }

        for(int i=1; i<n; i++){
            ll bsum = csum;
            bsum += a[i];

            if (csum*bsum>=0){
                if(csum>0){
                    c[l] += (bsum+1);
                    bsum -= (bsum+1);
                } else {
                    c[l] += (-bsum+1);
                    bsum += (-bsum+1);
                }
            }
            csum = bsum;
        }
    }
    cout << min(c[0], c[1]) << endl;
}
