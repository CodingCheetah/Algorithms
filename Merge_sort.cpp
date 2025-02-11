/*
    coded by PRATYAKSH GARG
    11-FEB-2024
*/

// Time Complexity:- O(nLogn)
// Space Complexity:- O(n)

#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int a[n1]; //temp arr1;
    int b[n2]; //temp arr2;

    //loop to fill values inside a and b array;
    for(int i = 0;i<n1 || i<n2; i++){
        if(i<n1){
            a[i] = arr[l+i];
        }
        if(i<n2){
            b[i] = arr[mid+1+i];
        }
    }

    int i = 0, j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k++] = a[i++];
        }
        else {
            arr[k++] = b[j++];
        }
    }
    while(i<n1){
        arr[k++] = a[i++]; //if some part of a array still left from merging;
    }
    while(j<n2){
        arr[k++] = b[j++]; //if some part of b array still left from merging;
    }

}
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr, l, mid); // to sort left part of array;
        mergeSort(arr, mid+1, r); // to sort right part of array;
        merge(arr,l,mid,r); // to merge sorted parts of array;
    }
}
int main(){
    int arr[] = {6,3,9,5,2,8,7,1};
    mergeSort(arr,0,7);
    for(int x: arr){
        cout<<x<<" ";
    }
}