#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(int argc, char* argv[]) {
	Node* root = NULL;
	srand(time(NULL));
	float allCount = 0.0;

	// �������� ���õ� AVL�� ���� 2000ȸ Batch �۾��� �����Ѵ�.
	doAVLBatch(root);
	allCount = (float)compareCount / searchCount;
		printf("average AVL compare count: %.2f\n", allCount);

	// ������ȸ�ϸ� AVLƮ���� ��������� ��� �����͸� free
	freeTree(root);
	root = NULL;
	compareCount = allCount = 0;

	// �������� ���õ� Binary Search Tree Batch�� �����Ѵ�.
	doBinaryBatch(root);
	allCount = (float)compareCount / searchCount;
	printf("average Bin compare count: %.2f\n", allCount);

	freeTree(root);
	return 0;
}