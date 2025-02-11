/*
    coded by PRATYAKSH GARG
    11-FEB-2024
*/

#include <iostream>
using namespace std;

//partition function
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low ; j< high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    quickSort(arr,0,5);
    for(int x: arr){
        cout<<x<<" ";
    }
}