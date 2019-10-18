// cutRodModified.h
// Created by hehao on 2019/10/12.
//

#ifndef CALGORITHMS_CUTRODMODIFIED_H
#define CALGORITHMS_CUTRODMODIFIED_H

#include <stdio.h>
#include <limits.h>
int cutRod(int* revenue, const int* price, int cost, int len);

int cutRod(int* revenue, const int* price, int cost, int len){
    //assume that revenue and price have already correctly initialized
    revenue[0]=0;
    int q;
    for(int i=1;i<=len;i++){//i is the length of currently processed rod
        q=INT_MIN;
        for(int j=0;j<i;j++){//j is the length of remaining rod after the first cutting
            if(q<price[i-j]+revenue[j]-cost){
                q=price[i-j]+revenue[j]-cost;
            }
        }
        revenue[i]=q;
    }
    return revenue[len];
}

#endif //CALGORITHMS_CUTRODMODIFIED_H
