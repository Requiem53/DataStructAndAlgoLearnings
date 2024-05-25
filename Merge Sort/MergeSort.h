#ifndef DSA_MERGESORT_H
#define DSA_MERGESORT_H

inline void merge(int arr[], int left, int mid, int right) {

    int lSize = mid - left + 1;
    int rSize = right - mid;

    int leftArr[lSize];
    int rightArr[rSize];

    // copy values from original arr to left and right arrays;
    for (int i = 0; i < lSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rSize; i++)
        rightArr[i] = arr[mid + i + 1];

    // merge stuff
    int l = 0;
    int r = 0;
    int i = left;
    while (l < lSize && r < rSize) {

        if (leftArr[l] < rightArr[r])
            arr[i++] = leftArr[l++];
        else
            arr[i++] = rightArr[r++];
    }

    // copy remaining array values
    while (l < lSize)
        arr[i++] = leftArr[l++];
    while (r < rSize)
        arr[i++] = rightArr[r++];
}

inline void MergeSort(int arr[], int l, int r) {

    // base case
    if (l == r) {
        return;
    }

    int m = (l + r) / 2;

    // divide into left and right
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

#endif // DSA_MERGESORT_H