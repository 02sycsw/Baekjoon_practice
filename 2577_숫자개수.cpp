#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	int result = a * b * c;
	int cnt[10] = { 0 };

	while (result > 0) {
		int temp = result % 10;
		cnt[temp]++;
		result /= 10;
	}

	for (int i = 0; i <= 9; i++) {
		cout << cnt[i] << endl;
	}
}