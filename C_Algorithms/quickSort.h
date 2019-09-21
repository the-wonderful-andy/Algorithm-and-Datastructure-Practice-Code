//quickSort.h
// Created by hehao on 2019/9/16.
//

#ifndef CALGORITHMS_QUICKSORT_H
#define CALGORITHMS_QUICKSORT_H
int partition(int* targetArry, int start, int end, int* n_comparison);
int quickSort(int* targetArry, int start, int end);
int swap(int *a, int *b);


int partition(int* targetArry, int start, int end, int* n_comparison){
    int smallEnd=start-1;
    int unsortedStart=start;
    int pivot=targetArry[end];
    while(unsortedStart<end){
        if(targetArry[unsortedStart]<pivot)
            swap(&targetArry[++smallEnd], &targetArry[unsortedStart++]);
        else
            unsortedStart++;
        (*n_comparison)++;
    }
    swap(&targetArry[smallEnd+1], &targetArry[end]);
    return smallEnd+1;

}

int quickSort(int* targetArry, int start, int end){
    if(start>=end)
        return 0;
    int mid;
    int n_comparison=0;
    mid=partition(targetArry, start, end, &n_comparison);
    n_comparison += quickSort(targetArry, start, mid-1);
    n_comparison += quickSort(targetArry, mid+1, end);
    return n_comparison;
}

int swap(int* a, int* b){
    int buffer;
    buffer=*a;
    *a=*b;
    *b=buffer;
    return 0;
}
#endif //CALGORITHMS_QUICKSORT_H
