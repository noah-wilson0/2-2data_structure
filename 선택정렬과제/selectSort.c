#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


// 배열에 정수를 입력받는 함수
void InputArray(int a[], int* size) {
    int i;
    printf("원소의 개수를 입력하세요: ");
    scanf_s("%d", size);

    printf("%d개의 정수를 입력하세요:\n", *size);
    for (i = 0; i < *size; i++) {
        printf("원소 %d: ", i + 1);
        scanf_s("%d", &a[i]);
    }

}
// 배열의 원소를 출력하는 함수
void PrintArray(int a[], int size) {
    printf("\n정렬한 원소: ");
    for (int i = 0; i < size; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

// 오름차순 선택정렬 함수
void AscendingSelectionSort(int a[], int size) {
    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (a[j] < a[min]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("\n%d단계 : ", i + 1);
        for (int t = 0; t < size; t++) printf("%3d", a[t]);
    }
}

// 내림차순 선택정렬 함수
void DescendingSelectionSort(int a[], int size) {
    int i, j, max, temp;

    for (i = 0; i < size - 1; i++) {
        max = i;
        for (j = i + 1; j < size; j++) {
            if (a[j] > a[max]) max = j;
        }
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;

        printf("\n%d단계 : ", i + 1);
        for (int t = 0; t < size; t++) printf("%3d", a[t]);
    }
}
//버블 정렬
void bubbleSort(int a[], int size) {
    int i, j, t, temp;

    for (i = size - 1; i > 0; i--) {
        printf("\n%d 단계>>", size - i);
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            printf("\n\t");
            for (t = 0; t < size; t++) printf("%3d", a[t]);
        }
    }
}
//퀵 정렬
int i = 0;
int partition(int a[], int begin, int end, int size){
    int pivot, L, R, t, temp;
    L = begin;
    R = end;
    //pivot=begin; //피봇이 처음에 위치한 원소일때
    //pivot = (begin + end) / 2;//피봇이 중간에 위치한 원소일때
    pivot = end; //피봇이 마지막 원소일때   //SELF TEST
    printf("\n[%d단계:pivot=%d] \n", i++, a[pivot]);
    while (L < R) {
        while (a[L] < a[pivot] && (L < R)) L++;
        while (a[R] >= a[pivot] && (L < R)) R--;
        if (L < R) {
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;
            if (L == pivot) pivot = R;
        }
    }

    temp = a[pivot];
    a[pivot]= a[R];
    a[R] = temp;
    for (t = 0; t < size; t++) printf("%4d", a[t]);
    printf("\n");
    return R;
        
}
void quickSort(int a[], int begin, int end, int size) {
    int p;
    if (begin < end) {
        p = partition(a, begin, end, size);
        quickSort(a, begin, p-1, size);
        quickSort(a, p+1, end, size);
    }
}

//삽입 정렬
void insertionSort(int a[], int size) {
    int i, j, t, temp;
    for (i = 1; i < size; i++) {
        temp = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > temp)) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = temp;
        printf("\n %d단계 : ", i);
        for (t = 0; t < size; t++)printf("%3d", a[t]);
    }
}
//셸 정렬
void intervalSort(int a[], int begin, int end, int interval) {
    int i, j, item;
    for (i = begin + interval; i <= end; i = i + interval) {
        item = a[i];
        for (j = i - interval; j >= begin && item < a[j]; j = j - interval)
            a[j + interval] = a[j];
        a[j + interval] = item;
    }
}

shellSort(int a[], int size) {
    int i, interval;
    interval = size / 2;
    while (interval >= 1) {
        for (i = 0; i < interval; i++) intervalSort(a, i, size - 1, interval);
        printf("\n interval=%d >>", interval);
        for (i = 0; i < size; i++)printf("%3d", a[i]);
        printf("\n");
        interval = interval / 2;
    }
}



/*

// 배열에 정수를 입력받는 함수
void InputArray(int* a, int *size) {
    int i;
    printf("원소의 개수를 입력하세요: ");
    scanf_s("%d", size);

    printf("%d개의 정수를 입력하세요:\n", *size);
    for (i = 0; i < *size; i++) {
        printf("원소 %d: ", i + 1);
        scanf_s("%d", (a+i));
    }
}

   void PrintArray(int *a, int size) {
        printf("\n정렬한 원소: ");
        for (int i = 0; i < size; i++) {
            printf("%3d", *(a+i));
        }
        printf("\n");
   }

   // 오름차순 선택정렬 함수
   void AscendingSelectionSort(int *a, int size) {
       int i, j, min, temp;

       for (i = 0; i < size - 1; i++) {
           min = i;
           for (j = i + 1; j < size; j++) {
               if (*(a+j) < *(a+min)) min = j;
           }
           temp = *(a+i);
           *(a+i) = *(a+min);
           *(a+min) = temp;

           printf("\n%d단계 : ", i + 1);
           for (int t = 0; t < size; t++) printf("%3d", *(a+t));
       }
   }

   // 내림차순 선택정렬 함수
   void DescendingSelectionSort(int *a, int size) {
       int i, j, max, temp;

       for (i = 0; i < size - 1; i++) {
           max = i;
           for (j = i + 1; j < size; j++) {
               if (a[j] > a[max]) max = j;
           }
           temp = *(a+i);
           *(a+i) = *(a+max);
           *(a+max) = temp;

           printf("\n%d단계 : ", i + 1);
           for (int t = 0; t < size; t++) printf("%3d", *(a+t));
       }
   }

   void bubbleSort(int *a, int size) {
       int i, j, t, temp;

       for (i = size - 1; i > 0; i--) {
           printf("\n%d 단계>>", size - i);
           for (j = 0; j < i; j++) {
               if (*(a+j) > a[j + 1]) {
                   temp = *(a+j);
                   *(a+j) = *(a+j + 1);
                   *(a+j + 1) = temp;
               }
               printf("\n\t");
               for (t = 0; t < size; t++) printf("%3d", *(a+t));
           }
       }


   }
   */