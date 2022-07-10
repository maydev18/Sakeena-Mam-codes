#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int elem, int low = 1)
{
    if (low > size)
        return -1;
        
    int mid = (low + size) / 2;
    if (arr[mid - 1] == elem)
    {
        return mid - 1;
    }
    else if (elem > arr[mid - 1])
    {
        return binarySearch(arr, size, elem, mid + 1);
    }
    else
    {
        return binarySearch(arr, mid - 1, elem, low);
    }
}
int main()
{
    int arr[7] = {1, 3, 5, 8, 13, 16, 20};
    cout << binarySearch(arr, 7, 13);
}