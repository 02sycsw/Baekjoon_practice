#include <stdio.h>
#include <stdlib.h>

typedef struct Save {
	int data;
	int fre;
	int order;
}save;
int main() {
	int N, C;
	scanf("%d %d", &N, &C);

	save* set = (save*)malloc(sizeof(save) * N);

	for (int i = 0; i < N; i++) {
		set[i].data = 0;
		set[i].fre = 0;
		set[i].order = 0;
	}

	int flag = 1;
	for (int i = 0; i < N; i++) {
		int temp, pre = 0;
		scanf("%d", &temp);
		
		for (int j = 0; j < i; j++) {
			if (set[j].data == temp) {
				pre = 1;
				set[j].fre += 1;
				break;
			}
		}

		if (pre == 0) {
			set[i].data = temp;
			set[i].fre += 1;
			set[i].order = flag;
			flag++;
		}
	}

	for (int i = 0; i < N -1 ; i++) {
		for (int j = i; j < N - 1; j++) {
			if (set[i].fre < set[j].fre) {
				save temp = set[j];
				set[j] = set[i];
				set[i] = temp;
			}
			if (set[i].fre == set[j].fre) {
				if (set[i].order > set[j].order) {
					save temp = set[j];
					set[j] = set[i];
					set[i] = temp;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < set[i].fre; j++) {
			printf("%d ", set[i].data);
		}
	}
}