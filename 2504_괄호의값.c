#include <stdio.h>
int main() {
	char str[31];
	int c = 1, lowL = 0, lowR = 0, highL = 0, highR = 0;
	int result = 0;
	int flag = 0;

	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			flag = 1;
			lowL++;
			c *= 2;
		}
		else if (str[i] == '[') {
			flag = 2;
			highL++;
			c *= 3;
		}
		else if (str[i] == ')') {
			lowR++;
			if (lowR > lowL) break;
			if (flag == 1) result += c;
			if (flag == 2) {
				result = 0;
				break;
			}
			c /= 2;
			flag = 0;
		}
		else if (str[i] == ']') {
			highR++;
			if (highR > highL) break;
			if (flag == 2) result += c;
			if (flag == 1) {
				result = 0;
				break;
			}
			c /= 3;
			flag = 0;
		}
		else break;
	}

	if (lowL != lowR || highL != highR) result = 0;
	printf("%d", result);

	return 0;
}