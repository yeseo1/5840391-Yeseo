#include "5-maxheaptree.h"

int main() {
    int inputData[] = { 90, 89, 70, 36, 75, 13, 21, 18, 5, 63 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    // Ʈ�� ����
    TreeNode* root = generateMaxHeapTree(inputData, size);

    // ����� �������̽� ����
    runUserInterface(root);

    // Ʈ�� �޸� ����
    freeTree(root);

    return 0;
}
