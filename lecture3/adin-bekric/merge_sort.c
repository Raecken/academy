#include <stdio.h>
#include "paroot.h"

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100];
    int R[100];

    for(i=0;i<n1;i++)
        L[i] = arr[left+i];

    for(j=0;j<n2;j++){
        R[j] = arr[mid+1+j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        { arr[k] = L[i]; i++; }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    { arr[k] = L[i]; i++; k++; }

    while(j<n2){
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    int mid;
    if(left < right)
{
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
}
}

int main() {
    int arr[100];
    int n;
    n = get_int("How many numbers? ");

    for(int i=0;i<n;i++){
        printf("Num %d: ", i+1);
        arr[i] = get_int("");
    }

    mergeSort(arr, 0, n-1);

    print_array_int(arr, n);
}
