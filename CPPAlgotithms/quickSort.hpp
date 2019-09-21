//
// Created by hehao on 2019/9/19.
//

#ifndef CPP_ALGORITHMS_QUICKSORT_HPP
#define CPP_ALGORITHMS_QUICKSORT_HPP
template <typename T>
int swap(T* a, T* b);

template <typename T>
int partition(T* targetArry, int start, int end);

template <typename T>
int quickSort(T* targetArry, int start, int end);

template <typename T>
int swap(T* a, T* b){
    T buffer;
    buffer=*a;
    *a=*b;
    *b=buffer;
    return 0;

}

template <typename T>
int partition(T* targetArry, int start, int end){
    T pivot =targetArry[end];
    int smallEnd = start-1;
    int unsortedStart = start;
    while(unsortedStart<end){
        if(targetArry[unsortedStart]<pivot)
            swap(&targetArry[unsortedStart++], &targetArry[++smallEnd]);
        else
            unsortedStart++;
    }
    swap(&targetArry[smallEnd+1], &targetArry[end]);
    return smallEnd+1;
}

template <typename T>
int quickSort(T* targetArry, int start, int end){
    if(start >= end)
        return 0;
    int mid=partition(targetArry, start, end);
    quickSort(targetArry, start, mid-1);
    quickSort(targetArry, mid+1, end);
    return 0;
}
#endif //CPP_ALGORITHMS_QUICKSORT_HPP

