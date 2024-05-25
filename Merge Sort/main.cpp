#include <iostream>

#include "MergeSort.h"

using namespace std;

// void MergeSort(int arr[], int left, int right);
// void merge(int arr[], int left, int mid, int right);
// void swap(int *a, int *b);
void printArr(int arr[], int len);

int main() {
    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "MERGE SORT" << std::endl;

    MergeSort(arr, 0, len - 1);

    printArr(arr, len);
}

void printArr(int arr[], int len) {

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}