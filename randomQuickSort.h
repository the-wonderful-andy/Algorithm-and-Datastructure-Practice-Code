//
// Created by hehao on 2019/9/21.
//

#ifndef CALGORITHMS_RANDOMQUICKSORT_H
#define CALGORITHMS_RANDOMQUICKSORT_H
#include "quickSort.h"
#include <stdlib.h>
#include <time.h>
int randomQuickSort(int* targetArry, int start, int end);

int randomQuickSort(int* targetArry, int start, int end){
    if(start>=end)
        return 0;
    int n_comparison=0;
    srand(time(NULL));
    int rand_n = start+rand()%(end-start+1);
    swap(&targetArry[rand_n], &targetArry[end]);

    int mid=partition(targetArry, start, end, &n_comparison);
    n_comparison += randomQuickSort(targetArry, start, mid-1);
    n_comparison += randomQuickSort(targetArry, mid+1, end);
    return n_comparison;

}
#endif //CALGORITHMS_RANDOMQUICKSORT_H



