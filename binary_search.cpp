/*
    coded by PRATYAKSH GARG
    11-FEB-2024
*/

// Time Complexity:- O(log n)
// Space Complexity:- O(1)

#include <iostream>
using namespace std;
void binarySearch(int arr[], int low, int high, int key){
    int mid = low + (high-low)/2;
    if(arr[mid]==key){
        cout<<"Element found at index: "<<mid<<endl;
        return;
    }
    else if(arr[mid]>key){
        binarySearch(arr,low,mid-1,key);
    }
    else if(arr[mid]<key){
        binarySearch(arr,mid+1,high,key);
    }
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    binarySearch(arr, 0, n-1, key);
    return 0;
}