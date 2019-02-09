#include<iostream>
#include<string>

using namespace std;

int main(){
    string a = "671971";
    string output = "361971";
   
    cout << a.size() <<endl;
    cout << output.size() <<endl; 
    cout << (a.size() == output.size()) << endl;
    cout << a.compare(output) << endl;
    
    if(a.size() > output.size() || (a.size() == output.size() && a.compare(output) >= 1)){
        output = a;
    }
    cout << output << endl;
}
