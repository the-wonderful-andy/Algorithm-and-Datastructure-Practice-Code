//mergeSort.h
// Created by hehao on 2019/9/16.
//

#ifndef CALGORITHMS_MERGESORT_H
#define CALGORITHMS_MERGESORT_H
int const inf=100000000;
int merge(int* targetArry, int start, int mid, int end);
int mergeSort(int* targetArry, int start, int end);

int merge(int* targetArry, int start, int mid, int end){
    int buffa[mid-start+1+1];
    int buffb[end-mid+1];
    int a=0;
    int b=0;
    for(int i=0; i<mid-start+1; i++)
        buffa[i]=targetArry[start+i];
    buffa[mid-start+1]=inf;
    for(int i=0; i<end-mid; i++)
        buffb[i]=targetArry[mid+1+i];
    buffb[end-mid]=inf;
    for(int i=0;i<end-start+1;i++){
        if(buffa[a]<buffb[b])
            targetArry[start+i]=buffa[a++];
        else
            targetArry[start+i]=buffb[b++];
    }
    return 0;
}

int mergeSort(int* targetArry, int start, int end){
    if(start>=end)
        return 0;
    int mid=(start+end)/2;
    mergeSort(targetArry, start, mid);
    mergeSort(targetArry, mid+1, end);
    merge(targetArry, start, mid, end);
    return 0;


}
#endif //CALGORITHMS_MERGESORT_H

