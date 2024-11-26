#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparesearch.h"

// �� Ƚ���� �����ϴ� �۷ι� ����
int compareCount = 0;

// ���� �迭 ���� �Լ�
// �迭�� �� ���ҿ� 0~999 ������ ������ �Ҵ�
void generateRandomArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // ���� ����
    }
}

// �迭 ��� �Լ�
// ���ĵ� �迭�� ó�� 20���� ������ 20�� ���Ҹ� ���
void printArray(int* array) {
    printf("Array Sorting Result:\n");

    // �迭�� ó�� 20�� ���
    for (int i = 0; i < 20; i++)
        printf("%3d ", array[i]);
    printf("\n");

    // �迭�� ������ 20�� ���
    for (int i = SIZE - 20; i < SIZE; i++)
        printf("%3d ", array[i]);
    printf("\n");
}

// ���� Ž�� ��� �� Ƚ�� ��� �Լ�
// �迭���� ���� Ÿ�� ���� 100�� Ž���ϰ� ��� �� Ƚ���� ��ȯ
float getAverageLinearSearchCompareCount(int array[]) {
    int totalCompareCount = 0; // �� �� Ƚ�� ���� ����

    for (int i = 0; i < 100; i++) {
        int target = rand() % 1000; // ���� Ÿ�� �� ����
        int count = 0; // ���� Ž���� �� Ƚ��

        // �迭�� ���������� Ž��
        for (int j = 0; j < SIZE; j++) {
            count++; // �� Ƚ�� ����
            if (array[j] == target) {
                break; // Ÿ�� �� �߰� �� Ž�� ����
            }
        }
        totalCompareCount += count; // ����
    }
    return totalCompareCount / 100.0; // ��� �� Ƚ�� ��ȯ
}

// �� ���� �˰���
// �迭�� �����ϰ� �� Ƚ���� global ���� compareCount�� ���
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = array[high]; // �ǹ� ��
        int i = low - 1;

        // �ǹ� �������� �迭�� ����
        for (int j = low; j < high; j++) {

            compareCount++; // �� Ƚ�� ����
            if (array[j] < pivot) {
                i++;
                // �迭 ��� ����
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // �ǹ� ���� �ùٸ� ��ġ�� �̵�
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1; // �ǹ��� �ε���

        // �ǹ� �������� �� �κ��� ��������� ����
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// �� ���� ���� �� �� Ƚ�� ���
// ���ĵ� ����� �迭�� �ݿ��Ǹ�, �� Ƚ���� compareCount�� ���
void getQuickSortCompareCount(int array[]) {
    compareCount = 0; // �� Ƚ�� �ʱ�ȭ
    quickSort(array, 0, SIZE - 1); // �� ���� ȣ��
}

// ���� Ž�� ��� �� Ƚ�� ��� �Լ�
// ���ĵ� �迭���� ���� Ÿ�� ���� 100�� Ž���ϰ� ��� �� Ƚ���� ��ȯ
float getAverageBinarySearchCompareCount(int array[]) {
    int totalCompareCount = 0; // �� �� Ƚ�� ���� ����

    for (int i = 0; i < 100; i++) {
        int target = rand() % 1000; // ���� Ÿ�� �� ����
        int low = 0, high = SIZE - 1, count = 0;

        // ���� Ž�� ����
        while (low <= high) {
            count++; // �� Ƚ�� ����
            int mid = (low + high) / 2; // �߰� �ε��� ���
            if (array[mid] == target) {
                break; // Ÿ�� �� �߰� �� Ž�� ����
            }
            else if (array[mid] < target) { // Ÿ�� ���� �߰� ������ Ŭ ���
                low = mid + 1;
            }
            else { // Ÿ�� ���� �߰� ������ ���� ���
                high = mid - 1;
            }
        }
        totalCompareCount += count; // ����
    }
    return totalCompareCount / 100.0; // ��� �� Ƚ�� ��ȯ
}