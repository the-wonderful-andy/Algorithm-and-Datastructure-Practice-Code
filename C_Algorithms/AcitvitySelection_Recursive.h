//
// Created by hehao on 2019/11/2.
//

#ifndef CALGORITHMS_ACITVITYSELECTION_RECURSIVE_H
#define CALGORITHMS_ACITVITYSELECTION_RECURSIVE_H
int activitySelection(int* startT, int* endT, int* result, int n, int k, int l);

int activitySelection(int* startT, int* endT, int* result, int n, int k, int l){
    /* assume that the input activities are already
     * sorted in non-decreasing order of finish time */
    // k is the last chosen activity
    // l is #of the chosen activity
    if(l==0){
        result[l++]=0;
        activitySelection(startT, endT, result, n, 0, l);
    }
    else
    {
        int m=k+1;
        while(startT[m]<endT[k] && m<=n)
            m++;
        if(m>=n)
            return 0;
        else{
            result[l++]=m;
            activitySelection(startT, endT, result, n, m, l);
            return 0;
        }
    }

}
#endif //CALGORITHMS_ACITVITYSELECTION_RECURSIVE_H
