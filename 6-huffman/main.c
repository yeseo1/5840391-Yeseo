#include <stdio.h>
#include "6-huffman.h"

int main() {
    char characters[7] = { 'a', 'e', 'i', 'o', 'u', 's', 't' };
    int frequencies[7] = { 10, 15, 11, 3, 4, 12, 18 };

    // ������ �ڵ� ����
    GenerateHuffmanCodes(characters, frequencies, 7);

    // ���� ���
    printf("Press Enter to exit...\n");
    getchar();
    return 0;
}
