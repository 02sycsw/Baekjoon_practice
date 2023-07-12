#include <stdio.h>
#include <stdlib.h>

void Push(int arr[], int* top, int data, int siz) {
	if ((*top) == siz - 1) return;
	arr[++(*top)] = data;
}

int Pop(int arr[], int* top) {
	if (top == -1) return 0;
	else return arr[(*top)--];
}

int main(void) {
	int n, top = -1, sum = 0;
	scanf("%d", &n);

	int* stack = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		int num, temp;
		scanf("%d", &num);

		if (num == 0)
			temp = Pop(stack, &top);
		else
			Push(stack, &top, num, n);
	}

	while (1) {
		int temp;
		temp = Pop(stack, &top);
		if (temp <= 0) break;
		sum += temp;
	}

	printf("%d", sum);
}