// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main() {
    srand(time(NULL));  // 랜덤 시드 초기화

    // 동일한 배열을 여러 정렬 함수에서 사용하기 위해 미리 생성
    int arr[SIZE];
    generateRandomData(arr);

    // 선택 정렬
    int arrForSelection[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrForSelection[i] = arr[i];
    }
    selectionSort(arrForSelection);

    // 삽입 정렬
    int arrForInsertion[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrForInsertion[i] = arr[i];
    }
    insertionSort(arrForInsertion);

    // 버블 정렬
    int arrForBubble[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrForBubble[i] = arr[i];
    }
    bubbleSort(arrForBubble);

    return 0;
}
