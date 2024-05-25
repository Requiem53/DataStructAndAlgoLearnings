#include <iostream>
using namespace std;

inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline int partitioner(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&(arr[i]), &(arr[j]));
        }
    }
    swap(&(arr[++i]), &(arr[high])); 
    return i;
}

inline void quickSort(int arr[], int low, int high){
    if(low >= high) return;

    int pi = partitioner(arr, low, high);

    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
}