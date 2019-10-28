//MatrixChain_BottomUp.h
// Created by hehao on 2019/10/13.
//

#ifndef CALGORITHMS_MATRIXCHAIN_BOTTOMUP_H
#define CALGORITHMS_MATRIXCHAIN_BOTTOMUP_H
#include<limits.h>
#include <stdio.h>
#include <stdlib.h>
int OptMatrixChain(int* dim, int n, int **solution);
int print_Optimal_Parens(int i, int j, int **solution);

int OptMatrixChain(int* dim, int n, int **solution){
    int m[n][n];
    for(int i=0; i<n; i++)
        m[i][i]=0;

    for(int i=n-2; i>=0; i--){// i+1 is # of the starting element of a sequence of parenthesized matrix
        for(int j=i+1; j<n; j++){// j+1 is # of the last element of a sequence of parenthesized matrix
            int minCost=INT_MAX;
            int solutionBuff;

            for(int k=i; k<j; k++){
                int thiscost=m[i][k]+m[k+1][j]+dim[i]*dim[k+1]*dim[j+1];
                if(minCost>thiscost){
                    minCost=thiscost;
                    solutionBuff=k;
                }

                m[i][j]=minCost;
                solution[i][j]=solutionBuff;
                // printf("%d\n", m[i][j]);
            }

        }
    }
    return m[0][n-1];
}

int print_Optimal_Parens(int i, int j, int  **solution){
    if(i==j){
        printf("A%d", i);
        return 0;
    }

    printf("(");

    print_Optimal_Parens(i, solution[i][j], solution);
    print_Optimal_Parens(solution[i][j]+1, j, solution);

    printf(")");

    return 0;
}


#endif //CALGORITHMS_MATRIXCHAIN_BOTTOMUP_H