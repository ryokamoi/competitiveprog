#include<iostream>
#include<vector>

using namespace std;

class CalkinWilf {
    public:
int a[2];
int* findRational(vector<char> path) {
    int l=1;
    int r=1;
    for(int i=1; i<path.size()-1; i++) {
        int cl, cr;
        if (path[i] == 'L') {
            cl = l;
            cr = l+r;
        } else {
            cl = l+r;
            cr = r;
        }
        l = cl;
        r = cr;
    }

    a[0] = l;
    a[0] = r;
    return a;
}
};
