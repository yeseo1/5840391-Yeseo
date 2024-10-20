#include <stdio.h>
#include "6-huffman.h"

int main() {
    char characters[7] = { 'a', 'e', 'i', 'o', 'u', 's', 't' };
    int frequencies[7] = { 10, 15, 11, 3, 4, 12, 18 };

    // 허프만 코드 생성
    GenerateHuffmanCodes(characters, frequencies, 7);

    // 종료 대기
    printf("Press Enter to exit...\n");
    getchar();
    return 0;
}
