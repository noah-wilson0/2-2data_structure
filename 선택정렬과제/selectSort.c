#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


// �迭�� ������ �Է¹޴� �Լ�
void InputArray(int a[], int* size) {
    int i;
    printf("������ ������ �Է��ϼ���: ");
    scanf_s("%d", size);

    printf("%d���� ������ �Է��ϼ���:\n", *size);
    for (i = 0; i < *size; i++) {
        printf("���� %d: ", i + 1);
        scanf_s("%d", &a[i]);
    }

}
// �迭�� ���Ҹ� ����ϴ� �Լ�
void PrintArray(int a[], int size) {
    printf("\n������ ����: ");
    for (int i = 0; i < size; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

// �������� �������� �Լ�
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

        printf("\n%d�ܰ� : ", i + 1);
        for (int t = 0; t < size; t++) printf("%3d", a[t]);
    }
}

// �������� �������� �Լ�
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

        printf("\n%d�ܰ� : ", i + 1);
        for (int t = 0; t < size; t++) printf("%3d", a[t]);
    }
}
//���� ����
void bubbleSort(int a[], int size) {
    int i, j, t, temp;

    for (i = size - 1; i > 0; i--) {
        printf("\n%d �ܰ�>>", size - i);
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
//�� ����
int i = 0;
int partition(int a[], int begin, int end, int size){
    int pivot, L, R, t, temp;
    L = begin;
    R = end;
    //pivot=begin; //�Ǻ��� ó���� ��ġ�� �����϶�
    //pivot = (begin + end) / 2;//�Ǻ��� �߰��� ��ġ�� �����϶�
    pivot = end; //�Ǻ��� ������ �����϶�   //SELF TEST
    printf("\n[%d�ܰ�:pivot=%d] \n", i++, a[pivot]);
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

//���� ����
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
        printf("\n %d�ܰ� : ", i);
        for (t = 0; t < size; t++)printf("%3d", a[t]);
    }
}
//�� ����
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

// �迭�� ������ �Է¹޴� �Լ�
void InputArray(int* a, int *size) {
    int i;
    printf("������ ������ �Է��ϼ���: ");
    scanf_s("%d", size);

    printf("%d���� ������ �Է��ϼ���:\n", *size);
    for (i = 0; i < *size; i++) {
        printf("���� %d: ", i + 1);
        scanf_s("%d", (a+i));
    }
}

   void PrintArray(int *a, int size) {
        printf("\n������ ����: ");
        for (int i = 0; i < size; i++) {
            printf("%3d", *(a+i));
        }
        printf("\n");
   }

   // �������� �������� �Լ�
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

           printf("\n%d�ܰ� : ", i + 1);
           for (int t = 0; t < size; t++) printf("%3d", *(a+t));
       }
   }

   // �������� �������� �Լ�
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

           printf("\n%d�ܰ� : ", i + 1);
           for (int t = 0; t < size; t++) printf("%3d", *(a+t));
       }
   }

   void bubbleSort(int *a, int size) {
       int i, j, t, temp;

       for (i = size - 1; i > 0; i--) {
           printf("\n%d �ܰ�>>", size - i);
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