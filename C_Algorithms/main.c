#include <stdio.h>
#include <stdlib.h>
#include "MatrixChain_BottomUp.h"


int main() {
    int dim[]={1, 3, 1, 3, 6, 13, 2, 2};
    int** solution=(int**)malloc(7*sizeof(int*));
    for(int i=0; i<7; i++){
        solution[i]=(int*)malloc(7*sizeof(int));
    }

    int c=OptMatrixChain(dim, 7, solution);
    printf("the minimum of scalar multiplications: %d\n", c);
    printf("Optimal parenthesizing: ");
    print_Optimal_Parens(0, 6, solution);
    return 0;
}
