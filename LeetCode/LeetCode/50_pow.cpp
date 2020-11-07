/**************************************************
					Pow(x, n)
***************************************************/

#include "questions.h"

//template <typename T>
//T myPow(const T x, const int n){
//	if (n == 0)
//		return 1;
//	if (n < 0)
//		return 1 / myPow(x, -n);
//	if (n % 2 == 1)
//		return x * myPow(x, n - 1);
//	return myPow(x * x, n / 2);
//}

//// for n = -2^31, -n = 2^31 is out of range of int
//template <typename T>
//T myPow(const T x, const int n) {
//	if (n == 0)
//		return 1;
//	if (n > 0 && n % 2 == 1)
//		return  myPow(x * x, n / 2) * x;
//	if (n < 0 && n % 2 == -1)
//		return  myPow(x * x, n / 2) / x;
//	return myPow(x * x, n / 2);
//}

// method 2
template <typename T>
T myPow(const T x, const int n) {

	int count = n;
	T half = x;
	T res = 1;
	while (count) {
		if(count % 2 != 0)
			res *= half;
		half *= half;
		count /= 2;
	}
	return n > 0 ? res : 1 / res;
}


int UseMyPow()
{
	cout << "*************** 50.Pow ***************" << endl;
	const int n = 3;

	const int xi = 3;
	int pxi;
	pxi = myPow<int>(xi, n);
	cout << "result of int myPow is " << pxi << endl;

	const float xf = 4.1;
	float pxf;
	pxf = myPow<float>(xf, n);
	cout << "result of float myPow is " << pxf << endl;

	const double xd = 5.2;
	double pxd;
	pxd = myPow<double>(xd, n);
	cout << "result of double myPow is " << pxd << endl;

	cout << endl;
	return 0;
}
