#include<iostream>

using namespace std;

int a, b;

int main(){
  cin >> a >> b;

  int p = a*b;
  if (p%2 == 0){
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
}
