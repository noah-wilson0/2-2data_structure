#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS



int main(void) {

    int size;
    int list[100]; // 간단하게 최대 100개의 원소를 가정
     //정수를 배열에 입력
     InputArray(list, &size);
     /*
     // 오름차순 선택정렬
    printf("\n<<<<<오름차순 선택정렬>>>>>\n");
    AscendingSelectionSort(list, size);

    printf("\n");

    // 원래 배열 출력
    PrintArray(list, size);

    printf("\n");
    // 내림차순 선택정렬
    printf("\n<<<<<내림차순 선택정렬>>>>>\n");
    DescendingSelectionSort(list, size);

    //버블 정렬 수행
    printf("\n<<<<<버블정렬>>>>>\n");
    bubbleSort(list, size);

    // 원래 배열 출력
    PrintArray(list, size);

    //퀵 정렬 수행
    printf("\n<<<<<<퀵 정렬 >>>>>>\n");
    quickSort(list, 0, size - 1, size);

     printf("\n<<<<<삽입 정렬 >>>>>>\n");
     insertionSort(list, size);
*/
     printf("\n<<<<<셸 정렬 >>>>>>\n");
     shellSort(list, size);

       /*
    int size;
    int arr[100];
    int* list=arr;
    InputArray(list, &size);

    // 원래 배열 출력
    PrintArray(list, size);
    printf("\n<<<<<오름차순 선택정렬>>>>>\n");
    AscendingSelectionSort(list, size);

    printf("\n");

    // 원래 배열 출력
    PrintArray(list, size);

    printf("\n");
    // 내림차순 선택정렬
    printf("\n<<<<<내림차순 선택정렬>>>>>\n");
    DescendingSelectionSort(list, size);

    //버블 정렬 수행
    printf("\n<<<<<버블정렬>>>>>\n");
    bubbleSort(list, size);
    */
    return 0;
}