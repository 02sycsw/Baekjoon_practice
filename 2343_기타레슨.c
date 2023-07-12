#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int data, int siz, int amount, int* arr) {
	int count = 1;
	int flag = 0;

	for (int i = siz - 1; i >= 0; i--) {
		if (arr[i] > data) return 0;
		flag += arr[i];
		if (flag > data) {
			flag = arr[i];
			count++;
		}
	}

	if (amount >= count) return 1;
	else return 0;
}

int main() {
	int N, M;
	int left = 0, mid, right = 0, res = 0;
	scanf("%d %d", &N, &M);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		right += arr[i];
	}

	while (left <= right) {
		mid = (left + right) / 2;
		int flag = BinarySearch(mid, N, M, arr);

		if (flag) {
			right = mid - 1;
			res = mid;
		}
		else
			left = mid + 1;
	}
	printf("%d", res);

	free(arr);
}