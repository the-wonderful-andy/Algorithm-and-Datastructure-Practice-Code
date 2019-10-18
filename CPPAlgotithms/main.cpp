#include <iostream>
#include "quickSort.hpp"
#include "randomQuickSort.hpp"
using std::cout;
using std::endl;
int main() {
    double a[]{0, 1, -10, 10, 0, 1000, 23, 52, 51.51, 54, 54.00010101};
    for(int i=0; i<11; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    randQuickSort(a, 0, 10);
    for(int i=0; i<11; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}

