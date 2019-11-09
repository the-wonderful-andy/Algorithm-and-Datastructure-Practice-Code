#include <stdio.h>
#include <stdlib.h>
//#include "ActivitySelection_Iterative.h"
#include "AcitvitySelection_Recursive.h"
#include <limits.h>


int main() {
    int startTime[]={1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finishTime[]={4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int result[11];
    for(int i=0; i<10; i++)
        result[i]=-1;
    activitySelection(startTime, finishTime, result, 11, -1, 0);
    for(int i=0; result[i]>=0; i++){
        printf("%d ", result[i]+1);
    }
    return 0;
}
