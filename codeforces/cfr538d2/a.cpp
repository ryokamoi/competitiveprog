#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int a, b, c;
    cin >> a >> b >> c;

    bool flag = true;
    
    if (a >= x) {
        a -= x;
    } else {
        flag = false;
    }

    if (a + b >= y) {
        if (a >= y) {
            a -= y;
        } else {
            b -= (y-a);
            a = 0;
        }
    } else {
        flag = false;
    }

    if (a + b + c < z) {
        flag = false;
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
