#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparesearch.h"

// 비교 횟수를 저장하는 글로벌 변수
int compareCount = 0;

// 랜덤 배열 생성 함수
// 배열의 각 원소에 0~999 사이의 난수를 할당
void generateRandomArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 난수 생성
    }
}

// 배열 출력 함수
// 정렬된 배열의 처음 20개와 마지막 20개 원소를 출력
void printArray(int* array) {
    printf("Array Sorting Result:\n");

    // 배열의 처음 20개 출력
    for (int i = 0; i < 20; i++)
        printf("%3d ", array[i]);
    printf("\n");

    // 배열의 마지막 20개 출력
    for (int i = SIZE - 20; i < SIZE; i++)
        printf("%3d ", array[i]);
    printf("\n");
}

// 선형 탐색 평균 비교 횟수 계산 함수
// 배열에서 랜덤 타겟 값을 100번 탐색하고 평균 비교 횟수를 반환
float getAverageLinearSearchCompareCount(int array[]) {
    int totalCompareCount = 0; // 총 비교 횟수 누적 변수

    for (int i = 0; i < 100; i++) {
        int target = rand() % 1000; // 랜덤 타겟 값 생성
        int count = 0; // 현재 탐색의 비교 횟수

        // 배열을 순차적으로 탐색
        for (int j = 0; j < SIZE; j++) {
            count++; // 비교 횟수 증가
            if (array[j] == target) {
                break; // 타겟 값 발견 시 탐색 종료
            }
        }
        totalCompareCount += count; // 누적
    }
    return totalCompareCount / 100.0; // 평균 비교 횟수 반환
}

// 퀵 정렬 알고리즘
// 배열을 정렬하고 비교 횟수를 global 변수 compareCount에 기록
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = array[high]; // 피벗 값
        int i = low - 1;

        // 피벗 기준으로 배열을 분할
        for (int j = low; j < high; j++) {

            compareCount++; // 비교 횟수 증가
            if (array[j] < pivot) {
                i++;
                // 배열 요소 스왑
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // 피벗 값을 올바른 위치로 이동
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1; // 피벗의 인덱스

        // 피벗 기준으로 두 부분을 재귀적으로 정렬
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// 퀵 정렬 수행 및 비교 횟수 계산
// 정렬된 결과는 배열에 반영되며, 비교 횟수는 compareCount에 기록
void getQuickSortCompareCount(int array[]) {
    compareCount = 0; // 비교 횟수 초기화
    quickSort(array, 0, SIZE - 1); // 퀵 정렬 호출
}

// 이진 탐색 평균 비교 횟수 계산 함수
// 정렬된 배열에서 랜덤 타겟 값을 100번 탐색하고 평균 비교 횟수를 반환
float getAverageBinarySearchCompareCount(int array[]) {
    int totalCompareCount = 0; // 총 비교 횟수 누적 변수

    for (int i = 0; i < 100; i++) {
        int target = rand() % 1000; // 랜덤 타겟 값 생성
        int low = 0, high = SIZE - 1, count = 0;

        // 이진 탐색 수행
        while (low <= high) {
            count++; // 비교 횟수 증가
            int mid = (low + high) / 2; // 중간 인덱스 계산
            if (array[mid] == target) {
                break; // 타겟 값 발견 시 탐색 종료
            }
            else if (array[mid] < target) { // 타겟 값이 중간 값보다 클 경우
                low = mid + 1;
            }
            else { // 타겟 값이 중간 값보다 작을 경우
                high = mid - 1;
            }
        }
        totalCompareCount += count; // 누적
    }
    return totalCompareCount / 100.0; // 평균 비교 횟수 반환
}