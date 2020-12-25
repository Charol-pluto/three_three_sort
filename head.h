

#ifndef QUICK_SORT_HEAD_H
#define QUICK_SORT_HEAD_H
#define SEED 10000
#define AMOUNT 100
#include <string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct{
    char name[20];
    int time;
    long long step;
    long long cmp;
}Info;

void swap_(int * a,int * b){
    int c;
    c = *a;
    *a  = *b;
    *b = c;
    return;
}


void HeapAdjust(int a[],int s,int m,Info* info);
Info HeapSort(int a[],int n);
Info SelectSort(int* arr,int len);
Info shellSort(int* arr,int len);
Info insertSort(int* arr,int len);
Info BubbleSort(int a[],int lenth);
int Partition(int a[],int left ,int right ,Info *info);
void _QuickSort(int a[],int left,int right,Info *info);
Info QuickSort(int a[], int left, int right);
void print_ (Info info1,Info info2);

#endif //QUICK_SORT_HEAD_H
