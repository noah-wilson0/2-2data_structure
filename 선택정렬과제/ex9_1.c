#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS



int main(void) {

    int size;
    int list[100]; // �����ϰ� �ִ� 100���� ���Ҹ� ����
     //������ �迭�� �Է�
     InputArray(list, &size);
     /*
     // �������� ��������
    printf("\n<<<<<�������� ��������>>>>>\n");
    AscendingSelectionSort(list, size);

    printf("\n");

    // ���� �迭 ���
    PrintArray(list, size);

    printf("\n");
    // �������� ��������
    printf("\n<<<<<�������� ��������>>>>>\n");
    DescendingSelectionSort(list, size);

    //���� ���� ����
    printf("\n<<<<<��������>>>>>\n");
    bubbleSort(list, size);

    // ���� �迭 ���
    PrintArray(list, size);

    //�� ���� ����
    printf("\n<<<<<<�� ���� >>>>>>\n");
    quickSort(list, 0, size - 1, size);

     printf("\n<<<<<���� ���� >>>>>>\n");
     insertionSort(list, size);
*/
     printf("\n<<<<<�� ���� >>>>>>\n");
     shellSort(list, size);

       /*
    int size;
    int arr[100];
    int* list=arr;
    InputArray(list, &size);

    // ���� �迭 ���
    PrintArray(list, size);
    printf("\n<<<<<�������� ��������>>>>>\n");
    AscendingSelectionSort(list, size);

    printf("\n");

    // ���� �迭 ���
    PrintArray(list, size);

    printf("\n");
    // �������� ��������
    printf("\n<<<<<�������� ��������>>>>>\n");
    DescendingSelectionSort(list, size);

    //���� ���� ����
    printf("\n<<<<<��������>>>>>\n");
    bubbleSort(list, size);
    */
    return 0;
}