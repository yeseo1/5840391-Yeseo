#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "5-maxheaptree.h"
int main() {
    int inputData[] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 }; // Ʈ�� ������
    int size = sizeof(inputData) / sizeof(inputData[0]);

    TreeNode* root = generateMaxHeapTree(inputData, size); // �ִ� ���� Ʈ�� ����
    runUserInterface(root); // ����� �������̽� ����
    freeTree(root); // �޸� ����

    return 0;
}