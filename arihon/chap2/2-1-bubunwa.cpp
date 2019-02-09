#include <iostream>

using namespace std;

#define EPS (1e-9)

#define REP(i, n) for(int i=0; i<n; i++)

int k;
int a[100];
int n;

bool bubunwa(int i, int sum){
    if (sum == k) return true;
    
    if (i == n) return false;

    if (bubunwa(i+1, sum+a[i])) return true;
    if (bubunwa(i+1, sum)) return true;

    return false;
}

int main(){
    scanf("%d", &n);

    REP(i, n) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    if (bubunwa(0, 0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
