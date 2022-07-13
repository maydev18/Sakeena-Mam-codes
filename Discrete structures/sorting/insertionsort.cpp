#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int insertion_sort(int arr[] , int n){
    int ans = 0;
    for(int i=0 ; i<n-1 ; i++){
        int j = i+1;
        cout<<endl;
        cout<<i+1<<" pass"<<endl;
        while(arr[j] < arr[j-1] && j > 0){
            cout << "swapped " << arr[j] << " and " << arr[j-1]<<endl;
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            ans++;
            j--;
        }
        ans++;
    }
    for(int i=0 ; i<n ; i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    return ans;
}
int main(){
    srand(time(0));
    ofstream out("data.txt");
    // best case complexity all ararys sorted
    for(int i=1 ; i<=100 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = j;
        }
        int ans = insertion_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }
    // worst case complexity all arrays sorted in decreasing order
    for(int i=1 ; i<=20 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = i-j;
        }
        int ans = insertion_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }
    // average case complexity
    for(int i=1 ; i<=50 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = rand();
        }
        int ans = insertion_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }
}