// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main() {
    srand(time(NULL));  // ���� �õ� �ʱ�ȭ

    // ������ �迭�� ���� ���� �Լ����� ����ϱ� ���� �̸� ����
    int arr[SIZE];
    generateRandomData(arr);

    // ���� ����
    int arrForSelection[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrForSelection[i] = arr[i];
    }
    selectionSort(arrForSelection);

    // ���� ����
    int arrForInsertion[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrForInsertion[i] = arr[i];
    }
    insertionSort(arrForInsertion);

    // ���� ����
    int arrForBubble[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrForBubble[i] = arr[i];
    }
    bubbleSort(arrForBubble);

    return 0;
}
