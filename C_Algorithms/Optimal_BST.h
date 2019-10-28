//Optimal_BST.h
// Created by hehao on 2019/10/28.
//

#ifndef CALGORITHMS_OPTIMAL_BST_H
#define CALGORITHMS_OPTIMAL_BST_H

#include <stdlib.h>
#include <limits.h>
double optimalBst(double* leavesWeight, double* dummyWeight, int nElement);

double optimalBst(double* leavesWeight, double* dummyWeight, int nElement){
    double** w;
    double** cost;
    double ans;
    double minCost;
    double thisCost;

    w = (double**)malloc((nElement+2)*sizeof(double*));
    cost = (double**)malloc((nElement+2)*sizeof(double*));
    for(int i=1; i<=nElement+1; i++){
        w[i]=(double*)malloc((nElement+1)*sizeof(double));
        cost[i]=(double*)malloc((nElement+1)*sizeof(double));
    }

    for(int i=1; i<=nElement+1; i++){
        cost[i][i-1]=dummyWeight[i-1];
        w[i][i-1]=dummyWeight[i-1];
    }

    for(int i=nElement; i>=1; i--){
        for(int j=i; j<=nElement; j++){
            w[i][j]=w[i][j-1]+leavesWeight[j]+dummyWeight[j];
            minCost=INT_MAX;
            for(int k=i; k<=j; k++){
                thisCost=cost[i][k-1]+cost[k+1][j]+w[i][j];
                minCost=minCost>thisCost?thisCost:minCost;
            }
            cost[i][j]=minCost;
        }
    }

    ans=cost[1][nElement];
    for(int i=1; i<=nElement+1;i++){
        free(w[i]);
        free(cost[i]);
    }
    free(w);
    free(cost);

    return ans;
}
#endif //CALGORITHMS_OPTIMAL_BST_H
