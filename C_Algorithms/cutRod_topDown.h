//cutRod_topDown.h
// Created by hehao on 2019/10/7.
//

#ifndef CALGORITHMS_CUTROD_TOPDOWN_H
#define CALGORITHMS_CUTROD_TOPDOWN_H
#define INF 10000000
int cutRod(int* price, int len);
int cutRodAux(int* revenue, int* price, int len);

int cutRod(int* price, int len){
    int revenue[len+1];
    for(int i=0; i<=len; i++)
        revenue[i]=-INF;
    return cutRodAux(revenue, price, len);
}

int cutRodAux(int* revenue, int* price, int len){
    if(revenue[len]>=0)
        return revenue[len];
    int result=-INF;
    if(len==0)
        result=0;
    else if(len>0){
        for(int i=0;i<len;i++){
            int buff=price[len-i-1]+cutRodAux(revenue, price, i);
            result = result<buff ? buff:result;
        }
    }
    revenue[len]=result;
    return result;

}
#endif //CALGORITHMS_CUTROD_TOPDOWN_H
