#include <iostream>
using namespace std;

int main(void) {
	int getIn, getOut;
	int sum = 0;
	int max = 0;

	for (int i = 0; i < 10; i++) {
		cin >> getOut >> getIn;
		sum -= getOut;
		sum += getIn;

		if (sum > max) max = sum;
	}

	cout << max << endl;
}