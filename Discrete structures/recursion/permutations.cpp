#include <iostream>
#include <string>
using namespace std;
void permutations(string source , string curr = ""){
    if(source.size()==0){
        cout<<curr<<endl;
        return;
    }
    for(int i=0 ; i<source.size() ; i++){
        string left = source.substr(0,i);
        string right = source.substr(i+1);
        permutations(left + right , curr + source[i]);
    }
}
int main(){
    cout<<"Enter the number: ";
    int n; cin>>n;
    string nums ="";
    for(int i=1 ; i<=n ; i++){
        nums += to_string(i);
    }
    permutations(nums);
    return 0;
}