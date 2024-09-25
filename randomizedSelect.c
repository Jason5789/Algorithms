#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* arr, int i, int j);
int randomizedPartition(int* arr, int len);
int randomizedSelection(int* arr, int len, int i);

void swap(int* arr, int i, int j){
    if(i != j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
}

int randomizedPartition(int* arr, int len) {
    int pivot = rand() % len;
    swap(arr, pivot, len - 1);
    pivot = len - 1;
    int i = -1;
    for (int j = 0; j < len - 1; j++) {
        if (arr[j] <= arr[pivot]) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, pivot);
    return i + 1;
}

int randomizedSelection(int* arr, int len, int i){
    int p = randomizedPartition(arr, len);
    if(p == i){
        return arr[p];
    } else if(p < i){
        return randomizedSelection(arr + p + 1, len - p - 1, i - p - 1);
    }
    return randomizedSelection(arr, p, i);
}

int main(){
    srand(time(NULL));
    int a[] = {7, 1, 2, 5, 3, 6, 8, 10};
    int len = sizeof(a) / sizeof(a[0]);
    printf("the smallest in a is: %d\n", randomizedSelection(a, len, 0));
    printf("the 1st smallest in a is: %d\n", randomizedSelection(a, len, 1));
    printf("the 2nd smallest in a is: %d\n", randomizedSelection(a, len, 2));
    return 0;
}
