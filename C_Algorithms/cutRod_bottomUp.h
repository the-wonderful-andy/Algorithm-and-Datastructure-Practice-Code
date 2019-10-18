//cutRod_bottomUp.h
//This function can return the detailed solution of cut rod problem
// Created by hehao on 2019/10/7.
//

#ifndef CALGORITHMS_CUTROD_BOTTOMUP_H
#define CALGORITHMS_CUTROD_BOTTOMUP_H

#include <stdio.h>
#define INF 100000000
int cutRod(int* solution, int* revenue, const int* price, int len);
int printSolution(int* solution, int len);

int cutRod(int* solution, int* revenue, const int* price, int len){
    //assume that solution, revenue and price have already correctly initialized
    solution[0]=0;
    revenue[0]=0;
    int q;
    for(int i=1;i<=len;i++){
        q=-INF;
        for(int j=0;j<i;j++){
            if(q<price[i-j-1]+revenue[j]){
                q=price[i-j-1]+revenue[j];
                solution[i]=i-j;
            }
        }
        revenue[i]=q;
    }
    return revenue[len];
}

int printSolution(int* solution, int len){
    int n=len;
    while(n>0){
        printf("%d ", solution[n]);
        n-=solution[n];
    }
    printf("\n");
    return 0;
}
#endif //CALGORITHMS_CUTROD_BOTTOMUP_H
