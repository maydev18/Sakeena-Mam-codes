#include <iostream>
#include <fstream>
using namespace std;
int bubble_sort(int arr[] , int size){
    int ans = 0;
    for(int i=0 ; i<size-1 ; i++){
        ans++;
        cout<<endl;
        cout<<i+1<<" pass"<<endl;
        for(int j = 0 ; j<size-1-i ; j++){
            ans++;
            if(arr[j+1] < arr[j]){
                cout << "swapped " << arr[j] << " and " << arr[j+1]<<endl;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                ans++;
            }
        }
    }
    for(int i=0 ; i<size ; i++) cout << arr[i]<<" ";
    return ans;
}
int main(){
    ofstream out("data.txt");
    // best case complexity all ararys sorted
    for(int i=1 ; i<=100 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = j;
        }
        int ans = bubble_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }
    // // worst case complexity all arrays sorted in decreasing order
    for(int i=1 ; i<=40 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = i-j;
        }
        int ans = bubble_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }
    //average case complexity
    for(int i=1 ; i<=50 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = rand();
        }
        int ans = bubble_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }
}