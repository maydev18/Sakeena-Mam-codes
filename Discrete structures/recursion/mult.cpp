#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int multiply(int a , int b){
    if(b == 1) return a;
    return a + multiply(a,--b);
}
int division(int a , int b){
    if(a-b <= 0) return b;
    return division(a-b , b);
}
int maximum(int arr[], int n){
    if(n==1) return arr[0];
    else return max(arr[n-1],maximum(arr,n-2));
}
int main(){
    // cout<<division(38,6);
    int arr[5] = {1,3,2,6,8};
    cout<<maximum(arr,5);
}