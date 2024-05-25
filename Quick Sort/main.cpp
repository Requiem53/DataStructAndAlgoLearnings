#include <iostream>

#include "QuickSort.h"

using namespace std;

void printArr(int arr[], int len);

int main() {
    //    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    //    int len = sizeof(arr) / sizeof(arr[0]);

    int arr[] = { 25, 32, 26, 22, 7, 46, 31, 22, 42 };
    int len = 9;

    std::cout << "QUICK SORT" << std::endl;

    quickSort(arr, 0, len - 1);

    printArr(arr, len);
}

void printArr(int arr[], int len) {

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}