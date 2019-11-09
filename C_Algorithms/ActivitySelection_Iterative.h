//
// Created by hehao on 2019/11/2.
//

#ifndef CALGORITHMS_ACTIVITYSELECTION_ITERATIVE_H
#define CALGORITHMS_ACTIVITYSELECTION_ITERATIVE_H
int activitySelection(int* startT, int* endT, int* result, int n);

int activitySelection(int* startT, int* endT, int* result, int n){
    /* assume that the input activities are already
     * sorted in non-decreasing order of finish time */
    if(n<1)
        return 0;
    int k, l;//k is #of the last chosen activity and l is #of the selected activity
    result[0]=0;
    k=0;
    l=1;
    for(int i=1; i<n; i++)
        if(startT[i]>=endT[k]){
            result[l++]=i;
            k=i;
        }
    return 0;
}
#endif //CALGORITHMS_ACTIVITYSELECTION_ITERATIVE_H
