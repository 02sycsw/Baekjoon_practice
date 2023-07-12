#include <stdio.h>
#include <stdlib.h>

int main() {
	int siz1, siz2;
	scanf("%d %d", &siz1, &siz2);

	int* arr1 = (int*)malloc(sizeof(int) * siz1);
	int* arr2 = (int*)malloc(sizeof(int) * siz2);

	for (int i = 0; i < siz1; i++) {
		int temp;
		scanf("%d", &temp);
		arr1[i] = temp;
	}

	for (int i = 0; i < siz2; i++) {
		int temp;
		scanf("%d", &temp);
		arr2[i] = temp;
	}

	int flag1 = 0, flag2 = 0, flag_tot = 0;
	int* arr_tot = malloc(sizeof(int) * (siz1 + siz2));

	while (flag1 < siz1 && flag2 < siz2) {
		if (arr1[flag1] > arr2[flag2]) {
			arr_tot[flag_tot] = arr2[flag2];
			flag_tot++;
			flag2++;
		}
		else if (arr1[flag1] == arr2[flag2]) {
			arr_tot[flag_tot] = arr2[flag2];
			flag_tot++;
			flag2++;
			flag1++;
		}
		else {
			arr_tot[flag_tot] = arr1[flag1];
			flag_tot++;
			flag1++;
		}
	}

	while (flag1 < siz1) {
		arr_tot[flag_tot] = arr1[flag1];
		flag_tot++;
		flag1++;
	}

	while (flag2 < siz2) {
		arr_tot[flag_tot] = arr2[flag2];
		flag_tot++;
		flag2++;
	}

	for (int i = 0; i < flag_tot; i++) {
		printf("%d ", arr_tot[i]);
	}
}