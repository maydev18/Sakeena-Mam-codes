#include <iostream>
using namespace std;
long long fact(int n){
    if(n == 1 || n == 0) return 1;
    else return n * fact(n-1);
}
int main(){
    int n , r;
    cout << "enter the number of x: "; cin>>n;
    cout << "enter the sum of all x: "; cin>>r;
    long long fact1 = fact(n+r-1);
    long long fact2 = fact(r-1);
    long long fact3 = fact(n);
    cout << fact1/(fact2 * fact3)<<endl;
    return 0;
}