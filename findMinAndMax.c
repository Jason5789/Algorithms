#include <stdio.h>

int findMinAndMax(const int* arr, int k, int* max, int* min) {
    int i;
    int count=0;
    
    if(k%2==0){                                        count++;
        if(arr[0]>arr[1]){*max=arr[0]; *min=arr[1];}
        else{*max=arr[1]; *min=arr[0];}
        i=2;
    }
    else{*min=arr[0]; *max=arr[0]; i=1;                count++;}
    for( ;i<k;i+=2){
        if(arr[i]<arr[i+1]){                           count++;
            if(arr[i]<*min) *min=arr[i];
            if(arr[i+1]>*max) *max=arr[i+1];
        }
        else{                                          count++;
            if(arr[i+1]<*min) *min=arr[i+1];
            if(arr[i]>*max) *max=arr[i];
        }
    }
    return count;
}

int main() {
    int a[] = {4,1,2,3};
    int max, min;
    
    int count=findMinAndMax(a, sizeof(a) / sizeof(a[0]), &max, &min);
    
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Count: %d\n",count);
    return 0;
}
