//
// Created by hehao on 2019/9/21.
//bubbleSort.h

#ifndef CALGORITHMS_BUBBLESORT_H
#define CALGORITHMS_BUBBLESORT_H
int bubbleSort(int* targetArry, int size);
int swap(int* a, int*b);

int bubbleSort(int* targetArry, int size){
    int unsortedEnd=size-1;
    while(unsortedEnd>0){
        for(int i=0; i<unsortedEnd; i++)
            if(targetArry[i]>targetArry[i+1])
                swap(&targetArry[i], &targetArry[i+1]);
        unsortedEnd--;
    }
    return 0;
}

int swap(int* a, int* b){
    int buffer;
    buffer=*a;
    *a=*b;
    *b=buffer;
    return 0;
}
#endif //CALGORITHMS_BUBBLESORT_H
