for(int i=1 ; i<=20 ; i++){
        int arr[i];
        for(int j=0 ; j<i ; j++){
            arr[j] = i-j;
        }
        int ans = insertion_sort(arr,i);
        out << i <<","<<ans<<'\n';
    }