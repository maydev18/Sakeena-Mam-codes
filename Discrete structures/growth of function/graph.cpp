#include <iostream>
#include <fstream>
using namespace std;
int fun(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n + fun(n-1);
    }
}
int main(){
    ofstream out;
    out.open("data.txt");
    int n; 
    cout << "enter the value of n: "; cin>>n;
    for(int i=0 ; i <= n ; i++){
        out << i <<"," << fun(i) <<'\n';
    }
    return 0;
}