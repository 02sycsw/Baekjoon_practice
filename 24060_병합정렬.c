#include <stdio.h>
#include <stdlib.h>

int N, K, cnt, key = -1;
int arr[500001], temp[500001];

void merge(int p, int q, int r) {
	int i = p, j = q + 1, t = 1;

	while (i <= q && j <= r) {
		if (arr[i] <= arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}

	while (i <= q)
		temp[t++] = arr[i++];
	while (j <= r)
		temp[t++] = arr[j++];

	i = p, t = 1;

	while (i <= r) {
		arr[i++] = temp[t++];
		cnt++;
		if (cnt == K) key = arr[i - 1];
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(0, N - 1);

	printf("%d", key);

	return 0;
}