//
// Created by hehao on 2019/10/8.
//

#ifndef CALGORITHMS_MAXIMUMSUBARRAYMODIFIED_H
#define CALGORITHMS_MAXIMUMSUBARRAYMODIFIED_H
#include <limits.h>

int maximumSubarray(int* array, int len, int* start, int* rear);

int maximumSubarray(int* array, int len, int* start, int* rear){
    int maxSum, thisSum;
    int startTemp;
    thisSum=startTemp=*start=*rear=0;
    maxSum=INT_MIN;
    for(int i=0;i<len ;i++){
        thisSum+=array[i];

        if(thisSum>maxSum){
            maxSum=thisSum;
            *start=startTemp;
            *rear=i;
        }

        if(thisSum<0){
            thisSum=0;
            startTemp=i+1;
        }
    }
    return maxSum;
}
#endif //CALGORITHMS_MAXIMUMSUBARRAYMODIFIED_H
