
#include <string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define AMOUNT 100
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

void HeapAdjust(int a[],int s,int m,Info* info){
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)//通过循环沿较大的孩子结点向下筛选
    {
        info->cmp++;
        if(j<m&&a[j]<a[j+1]) j++;//j为较大的记录的下标
        if(rc>a[j]) break;
        a[s]=a[j];s=j;
        info->step++;
    }
    a[s]=rc;//插入
}
Info HeapSort(int a[],int n){
    Info info;
    strcpy(info.name,"HeapSort");
    if(n<2){
        info.time = 0;
        info.step = 0;
        return info;
    }
    info.time = clock();
    info.step = 0;
    info.cmp = 0;
    int temp,i,j;
    for(i=n/2;i>0;i--){
        HeapAdjust(a,i,n,&info);//通过循环初始化顶堆
    }
    for(i=n;i>0;i--){
        info.step++;
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;//将堆顶记录与未排序的最后一个记录交换
        HeapAdjust(a,1,i-1,&info);//重新调整为顶堆
    }
    info.time = clock() - info.time;
    return info;
}
Info SelectSort(int* arr,int len){
    Info info;
    strcpy(info.name,"SelectSort");
    int j;
    if(len<2){
        info.time = 0;
        info.step = 0;
        return info;
    }
    info.time = clock();
    info.step = 0;
    info.cmp = 0;
    for(int i=0;i<len;i++){
        int min=arr[i],mini=i;
        for(j=i+1;j<len;j++){
            info.cmp++;
            if(min>arr[j]){
                mini=j;
                min=arr[j];
            }
        }
        if(mini!=i){
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
            info.step++;
        }
    }
    info.time = clock() - info.time;
    return info;
}
Info shellSort(int* arr,int len){
    Info info;
    strcpy(info.name,"shellSort");
    if(len<2){
        info.time = 0;
        info.step = 0;
        info.cmp = 0;
        return info;
    }
    info.time = clock();
    info.step = 0;
    for(int h = len>>1 ;h>=1; h>>=1){
        for(int i = h;i<len;i++){
            int t = arr[i];
            int j = i;
            while(j-h>=0&&arr[j-h]>t){
                info.step++;
                info.cmp++;
                arr[j] = arr[j-h];
                j -= h;
            }
            if(j-h>=0)
                info.cmp++;
            arr[j] = t;
        }
    }
    info.time = clock()-info.time;
    return info;
}
Info insertSort(int* arr,int len){
    Info info;
    strcpy(info.name,"insertSort");
    if(len<2){
        info.time = 0;
        info.step = 0;
        return info;
    }
    info.time = clock();
    info.step = 0;
    info.cmp = 0;
    for(int i=1;i<len;i++){
        int j = i;
        int t = arr[j];
        while(j-1>=0&arr[j-1]>t){
            info.step++;
            info.cmp++;
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=t;
    }
    info.time = clock() - info.time;
    return info;
}



Info BubbleSort(int a[],int lenth){
    Info info;
    strcpy(info.name,"BubbleSort");
    info.cmp=0;
    info.step=0;
    info.time=0;
//    printf("\n冒泡：\n原数组为： \n");
//    for (int i = 0; i <lenth ; ++i) {
//        printf("%d ",a[i]);
//    }
    for (int i = 0; i <lenth ; ++i) {
        for (int j = 0; j < lenth-1-i; ++j) {
            if (a[j]>a[j+1]){
                swap_(&a[j],&a[j+1]);
                info.step++;
                info.cmp++;
            }else{
                info.cmp++;
            }
        }
    }
//    printf("\n排列好顺序如下：\n");
//    for (int i = 0; i <lenth ; ++i) {
//        printf("%d ",a[i]);
//    }
    return info;
}

int Partition(int a[],int left ,int right ,Info *info){
    int pivot=a[left];
    while(left<right){
        while(left<right&&a[right]>=pivot) {
            info->cmp++;
            right--;
        }
        a[left]=a[right];
        info->step++;
        while(left<right&&a[left]<=pivot) {
            info->cmp++;
            left++;
        }
        a[right]=a[left];
        info->step++;
    }
    a[left]=pivot;
    return left;
}
void _QuickSort(int a[],int left,int right,Info *info){
    if(left<right){

        int pivotpos=Partition(a,left,right,info);
        _QuickSort(a,left,pivotpos-1,info);
        _QuickSort(a,pivotpos+1,right,info);
    }
}


Info QuickSort(int a[], int left, int right){
    Info info;
    strcpy(info.name,"QuickSort");
    info.cmp=0;
    info.step=0;
    info.time=0;
//    printf("\n快排：\n原数组为： \n");
//    for (int i = 0; i <right-left+1 ; ++i) {
//        printf("%d ",a[i]);
//    }
    _QuickSort(a,left,right,&info);

//    printf("\n排列好顺序如下：\n");
//    for (int i = 0; i <right-left+1 ; ++i) {
//        printf("%d ",a[i]);
//    }
    return info;
}

void print_ (Info info1,Info info2){
//    double cmp_percent=0;
//    double step_percent=0;
//    cmp_percent = info2.cmp/info1.cmp;
//    step_percent = info2.step/info1.step;
    printf("\n%s V.S %s\n",info1.name,info2.name);
    printf("%s step:%lld cmp:%lld\n",info1.name,info1.step,info1.cmp);
    printf("%s step:%lld cmp:%lld\n",info2.name,info2.step,info2.cmp);
//    printf("cmp percent:%.1f%,step percent:%.1f%\n\n",cmp_percent,step_percent);

}


int main() {
    int array[AMOUNT];
    srand(10000);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info shell = shellSort(array,AMOUNT);

    srand(10000);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info insert = insertSort(array,AMOUNT);

    srand(10000);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info select = SelectSort(array,AMOUNT);

    srand(10000);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info  heap= HeapSort(array,AMOUNT);

    srand(10000);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info BUbble_ = BubbleSort(array,100);


    srand(10000);
    for(int i=0;i<AMOUNT;i++){
        array[i] = rand()*rand();
    }
    Info QuickSort_ = QuickSort(array,0,99);



    /*for(int i = 0;i<10;i++)
        printf("%d ",array[i]);*/

    printf("\n插入排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^2),空间复杂度:O(1)");
    printf("\n希尔排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^1.25),空间复杂度:O(1)");
    print_(insert,shell);
    printf("\n选择排序：最好时间复杂度 :O(n^2),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^2),空间复杂度:O(1)");
    printf("\n堆排序：最好时间复杂度 :O(n*(log(2)n)),最坏时间复杂度:O(n*(log(2)n)),平均时间复杂度:O(n*(log(2)n)),空间复杂度:O(1)");
    print_(select,heap);
    printf("\n冒泡排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n^2),空间复杂度:O(1)");
    printf("\n快速排序：最好时间复杂度 :O(n),最坏时间复杂度:O(n^2),平均时间复杂度:O(n*(log(2)n)),空间复杂度:O(n*(log(2)n))");
    print_(BUbble_,QuickSort_);


//    printf("\nshellSort step:%lld cmp:%lld\n",shell.step,shell.cmp);
//    printf("HeapSort step:%lld cmp:%lld\n",heap.step,heap.cmp);
//    printf("insertSort step:%lld cmp:%lld\n",insert.step,insert.cmp);
//    printf("selectSort step:%lld cmp:%lld\n",select.step,select.cmp);
//    printf("BubbleSort step:%lld cmp:%lld\n",BUbble_.step,BUbble_.cmp);
//    printf("QuickSort step:%lld cmp:%lld\n",QuickSort_.step,QuickSort_.cmp);

    return 0;
}







//int main() {
//    int a[10]={3,4,2,1,7,6,8,10,5,23};
//    Info info;
////    info  = QuickSort(a,0,9);
//
//    info  = BubbleSort(a,10);
//    return 0;
//}
