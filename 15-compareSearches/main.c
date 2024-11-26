#include <stdio.h>
#include <stdlib.h>
#include "comparesearch.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int array[SIZE];

	generateRandomArray(array);
	//��հ��� ��ȯ�ޱ� ���� ��ġ
	printf("Average Linear Search Compare Count: %.2f\n",
		getAverageLinearSearchCompareCount(array));

	//compareCount�� global variable�̹Ƿ�, ������ ���� ����
   //array�� ���ؼ� ���� �����ϸ� �ȴ�.
	getQuickSortCompareCount(array);
	printf("Quick Sort Compare Count: %d\n", compareCount);

	//���ĵ� Array�� ���ؼ� Binary Search 100ȸ ���� �� ��� ��Ƚ�� ���
	printf("Average Binary Search Compare Count: %.2f\n\n",
		getAverageBinarySearchCompareCount(array));
	printArray(array);
	return 0;
}
