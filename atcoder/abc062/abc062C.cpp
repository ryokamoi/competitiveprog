#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

long long h, w;
long long mindiff;
long long INF = 10e17;

int main(){
    cin >> h >> w;

    mindiff = INF;

    if(h==2 && w==2) mindiff = 1;

    long long hmi, hma;
    if(h>=3){
        hmi = floor((long double)h/3);
        hma = ceil((long double)h/3);
        mindiff = min(mindiff, hma*w - hmi*w);
    }

    long long wmi, wma;
    if(w>=3){
        wmi = floor((long double)w/3);
        wma = ceil((long double)w/3);
        mindiff = min(mindiff, wma*h - wmi*h);
    }

    long long s1, s2, s3;
    if(h>=3){
        s1 = hmi*w;
        s2 = floor((long double)w/2)*(h-hmi);
        s3 = ceil((long double)w/2)*(h-hmi);
        mindiff = min(mindiff, max({s1, s2, s3})-min({s1, s2, s3}));

        s1 = hma*w;
        s2 = floor((long double)w/2)*(h-hma);
        s3 = ceil((long double)w/2)*(h-hma);
        mindiff = min(mindiff, max({s1, s2, s3})-min({s1, s2, s3}));
    }

    if(w>=3){
        s1 = wmi*h;
        s2 = floor((long double)h/2)*(w-wmi);
        s3 = ceil((long double)h/2)*(w-wmi);
        mindiff = min(mindiff, max({s1, s2, s3})-min({s1, s2, s3}));

        s1 = wma*h;
        s2 = floor((long double)h/2)*(w-wma);
        s3 = ceil((long double)h/2)*(w-wma);
        mindiff = min(mindiff, max({s1, s2, s3})-min({s1, s2, s3}));
    }

    cout << mindiff << endl;
}
