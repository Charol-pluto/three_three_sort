

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



void swap_(int * a,int * b);//交换函数
void HeapAdjust(int a[],int s,int m,Info* info);
Info HeapSort(int a[],int n);//堆排序
Info SelectSort(int* arr,int len);//选择排序
Info shellSort(int* arr,int len);//希尔排序
Info insertSort(int* arr,int len);//插入排序
Info BubbleSort(int a[],int lenth);//冒泡排序
int Partition(int a[],int left ,int right ,Info *info);//快排排序规则
void _QuickSort(int a[],int left,int right,Info *info);//快排递归调用函数
Info QuickSort(int a[], int left, int right);//快排初始化壳
void print_ (Info info1,Info info2);//输出函数
void print123(int n);//输出函数

#endif //QUICK_SORT_HEAD_H
