//
// Created by hehao on 2019/11/11.
//

#ifndef CALGORITHMS_KNAPSACK_H
#define CALGORITHMS_KNAPSACK_H

#include <stdlib.h>
int knapsack(int const * weights, int const * values, int n, int W);

int knapsack(int const * weights, int const * values, int n, int W){
    int** c = (int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<=n; i++){
        c[i]=(int*)malloc((W+1)*sizeof(int));
        c[i][0]=0;
    }
    for(int j=0; j<=W; j++)
        c[0][j]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(weights[i-1]>j)
                c[i][j]=c[i-1][j];
            else{
                int a, b;
                a=c[i-1][j];
                b=c[i-1][j-weights[i-1]]+values[i-1];
//                printf("%d %d\n", a, b);
                c[i][j]=a>b?a:b;
            }
//            printf("%d\n", c[i][j]);

        }
    }
    return c[n][W];

}
#endif //CALGORITHMS_KNAPSACK_H
