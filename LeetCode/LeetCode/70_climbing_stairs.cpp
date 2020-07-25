#include "questions.h"

int climbStairs(int n) {
	int x = 1;
	int y = 2;

	// 1.Ò×¶®´úÂë£º
	//if (n == 1) {
	//	return x;
	//}
	//else if (n == 2) {
	//	return y;
	//}
	//else {
	//	int temp;
	//	for (int i = 2; i < n; i++) {
	//		temp = y;
	//		y = x + y;
	//		x = temp;
	//	}
	//	return y;
	//}

	// 2.¼ò½à´úÂë
	int temp;
	for (int i = 2; i < n; i++) {
		temp = y;
		y = x + y;
		x = temp;
	}
	return n == 1 ? x: y;

}

int UseClimbStairs() {
	cout << "*************** 70. Climbing Stairs ***************" << endl;
	const int n = 4;
	const int result = climbStairs(n);
	cout << "The Number of Solution of Climb Stairs is: " << result << endl;
	return 0;
}