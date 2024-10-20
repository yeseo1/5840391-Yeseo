#include <stdio.h>
#include "6-sortbyheap.h"

int main() {
    int inputData[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 35, 85, 29, 78, 41, 56, 86 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    printf("<Sort>\n");
    BuildMaxHeapAndSort(inputData, size);

    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", inputData[i]);
    }
    printf("\n");

    // 프로그램이 종료되지 않도록 사용자 입력 대기
    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}
