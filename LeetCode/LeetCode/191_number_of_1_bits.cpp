#include "questions.h"

int hammingWeight(uint32_t n) {
	int count = 0;
	while (n != 0) {
		count++;
		n = n & (n - 1);
		}
	return count;
}

int UseHammingWeight() {
	cout << "*************** 191. Number of 1 Bits ***************" << endl;
	uint32_t n = 6;
	const int count = hammingWeight(n);
	cout << "The number of 1 bits is: " << count << endl;
	return 0;
}