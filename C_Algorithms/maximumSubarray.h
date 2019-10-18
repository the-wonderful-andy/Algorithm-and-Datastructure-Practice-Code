//
// Created by hehao on 2019/9/20.
//maximumSubarray.h

#ifndef CALGORITHMS_MAXIMUMSUBARRAY_H
#define CALGORITHMS_MAXIMUMSUBARRAY_H
#define INF 1000000000
#include <string.h>


typedef enum resultField{
    START=0,
    END=1,
    SUM=2
}resultField;

int maxCrossSubarray(const int* targetArry, int* result, int start, int mid, int end);
int maximumSubarray(const int* targetArry, int* result, int start, int end);

int maxCrossSubarray(const int* targetArry, int* result, int start, int mid, int end){
    int leftmax=-INF;
    int rightmax=-INF;
    int sum=0;

    for(int i=mid;i>=start;i--){
        sum+=targetArry[i];
        if(sum>leftmax){
            leftmax=sum;
            result[START]=i;
        }
    }

    sum=0;
    for(int i=mid+1;i<=end;i++){
        sum+=targetArry[i];
        if(sum>rightmax){
            rightmax=sum;
            result[END]=i;
        }
        
    }

    result[SUM]=leftmax+rightmax;
    return 0;
}

int maximumSubarray(const int* targetArry, int* result, int start, int end){
    if(start>=end){
        result[START]=start;
        result[END]=end;
        result[SUM]=targetArry[start];
        return 0;
    }

    int leftmax[3];
    int rightmax[3];
    int crossmax[3];
    int mid = (start+end)/2;

    maximumSubarray(targetArry, leftmax, start, mid);
    maximumSubarray(targetArry, rightmax, mid+1, end);
    maxCrossSubarray(targetArry, crossmax, start, mid, end);

    if(leftmax[SUM]>=rightmax[SUM && leftmax[SUM]>=crossmax[SUM]])
        memcpy(result, leftmax, sizeof(leftmax));
    else if(rightmax[SUM]>=leftmax[SUM]&&rightmax[SUM]>=crossmax[SUM])
        memcpy(result, rightmax, sizeof(leftmax));
    else
        memcpy(result, crossmax, sizeof(leftmax));
    return 0;


}

#endif //CALGORITHMS_MAXIMUMSUBARRY_H


