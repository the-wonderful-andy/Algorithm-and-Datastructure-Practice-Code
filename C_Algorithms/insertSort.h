//insertSort.h
// Created by hehao on 2019/9/15.
//


#ifndef CALGORITHMS_INSERTSORT_H
#define CALGORITHMS_INSERTSORT_H
int insertSort(int* targetArry, int size);

int insertSort(int* targetArry, int size){
    int buffer;
    int j;
    for(int i=1;i<size;i++){
        buffer=targetArry[i];
        for(j=i-1; j>=0&&targetArry[j]<buffer;j--){
            targetArry[j+1]=targetArry[j];
        }
        targetArry[j+1]=buffer;
    }
    return 0;
}

#endif //CALGORITHMS_INSERTSORT_H

