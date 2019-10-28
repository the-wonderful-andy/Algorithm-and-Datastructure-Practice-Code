#include <stdio.h>
#include <stdlib.h>
#include "Optimal_BST.h"
#include <limits.h>


int main() {
    double p[]={INT_MAX, 0.15, 0.10, 0.05, 0.10, 0.20};
    double q[]={0.05, 0.10, 0.05, 0.05 ,0.05, 0.10};
    double ans;

    ans=optimalBst(p, q, 5);
    printf("cost: %f\n", ans);
    return 0;
}
