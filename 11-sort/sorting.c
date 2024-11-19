// sorting.c
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 랜덤 데이터 생성 함수
void generateRandomData(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  // 0부터 999 사이의 숫자 생성
    }
}

// 선택 정렬 함수 (10~20 단위로 출력)
void selectionSort(int arr[]) {
    int i, j, minIdx, temp;
    printf("Selection Sort:\n");
    for (i = 0; i < SIZE - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // 요소 교환
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        // 10부터 홀수 번대만
        if (i % 10 == 0 && i % 20 == 10) {
            printf("Step %d: ", i);
            for (int k = 0; k < SIZE; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n\n");
        }

        // 마지막 단계 (99번째 단계)도 출력
        if (i == SIZE - 2) {
            printf("Step %d: ", i + 1); // 99번째는 i + 1
            for (int k = 0; k < SIZE; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n\n\n");
        }
    }
}

// 삽입 정렬 함수 (20회 실행, 평균 비교 횟수 출력)
void insertionSort(int arr[]) {
    int totalComparisons = 0;
    int comparisons;

    for (int run = 0; run < 20; run++) {
        comparisons = 0;
        for (int i = 1; i < SIZE; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                comparisons++;
            }
            arr[j + 1] = key;
        }
        totalComparisons += comparisons;
    }

    printf("Insertion Sort Compare Average: %d\n", totalComparisons / 20);

    printf("Insertion Sort Result: \n");
    int j = 0;
    for (j = 0; j < SIZE; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n\n");
}

// 버블 정렬 함수 (20회 실행, 평균 이동 횟수 출력)
void bubbleSort(int arr[]) {
    int totalMoves = 0;
    int moves;

    for (int run = 0; run < 20; run++) {
        moves = 0;
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // 요소 교환
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    moves += 3;  // 각 교환이 3회 이동으로 계산
                }
            }
        }
        totalMoves += moves;
    }

    printf("Bubble Sort Move Average: %d\n", totalMoves / 20);

    printf("Bubble Sort Result: \n");
    int j = 0;
    for (j = 0; j < SIZE; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
