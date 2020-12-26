

#include "head.h"





int main() {
    int array[AMOUNT];
    srand(SEED);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info shell = shellSort(array,AMOUNT);

    srand(SEED);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info insert = insertSort(array,AMOUNT);

    srand(SEED);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info select = SelectSort(array,AMOUNT);

    srand(SEED);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info  heap= HeapSort(array,AMOUNT);

    srand(SEED);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info BUbble_ = BubbleSort(array,100);


    srand(SEED);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info QuickSort_ = QuickSort(array,0,99);


//    printf("\n插入排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^2),空间复杂度:O(1)");
//    printf("\n希尔排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^1.25),空间复杂度:O(1)");
    print123(1);
    print_(insert,shell);
//    printf("\n选择排序：最好时间复杂度 :O(n^2),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^2),空间复杂度:O(1)");
//    printf("\n堆排序：最好时间复杂度 :O(n*(log(2)n)),最坏时间复杂度:O(n*(log(2)n)),平均时间复杂度:O(n*(log(2)n)),空间复杂度:O(1)");
    print123(2);
    print_(select,heap);
//    printf("\n冒泡排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^2),空间复杂度:O(1)");
//    printf("\n快速排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n*(log(2)n)),空间复杂度:O(n*(log(2)n))");
    print123(3);
    print_(BUbble_,QuickSort_);
    printf("\n\n程序结束！\n\n");
    return 0;
}
