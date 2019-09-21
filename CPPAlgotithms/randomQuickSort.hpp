//
// Created by hehao on 2019/9/21.
//

#ifndef CPP_ALGORITHMS_RANDOMQUICKSORT_HPP
#define CPP_ALGORITHMS_RANDOMQUICKSORT_HPP
#include "quickSort.hpp"
#include <ctime>
#include <cstdlib>
template <typename T>
int randQuickSort(T* targetArry, int start, int end);

template <typename T>
int randQuickSort(T* targetArry, int start, int end){
    if(start>=end)
        return 0;

    srand(time(nullptr));
    int rand_n = start+rand()%(end-start+1);
    swap(&targetArry[rand_n], &targetArry[end]);

    int mid=partition(targetArry, start, end);
    randQuickSort(targetArry, start, mid-1);
    randQuickSort(targetArry, mid+1, end);
    return 0;

}

#endif //CPP_ALGORITHMS_RANDOMQUICKSORT_HPP

