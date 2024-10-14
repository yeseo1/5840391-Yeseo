#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "5-maxheaptree.h"
int main() {
    int inputData[] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 }; // 트리 데이터
    int size = sizeof(inputData) / sizeof(inputData[0]);

    TreeNode* root = generateMaxHeapTree(inputData, size); // 최대 히프 트리 생성
    runUserInterface(root); // 사용자 인터페이스 실행
    freeTree(root); // 메모리 해제

    return 0;
}