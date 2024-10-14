#include "5-maxheaptree.h"

int main() {
    int inputData[] = { 90, 89, 70, 36, 75, 13, 21, 18, 5, 63 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    // 트리 생성
    TreeNode* root = generateMaxHeapTree(inputData, size);

    // 사용자 인터페이스 실행
    runUserInterface(root);

    // 트리 메모리 해제
    freeTree(root);

    return 0;
}
