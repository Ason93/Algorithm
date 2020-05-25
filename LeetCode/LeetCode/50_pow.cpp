/**************************************************
					Pow(x, n)
***************************************************/

#include "questions.h"

template <typename T>
T MyPow(const T x, const int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 1 / MyPow(x, -n);
	if (n % 2 == 1)
		return x * MyPow(x, n - 1);
	return MyPow(x * x, n / 2);
}

int UseMyPow()
{
	cout << "*************** 50.Pow ***************" << endl;
	const int n = 3;

	const int xi = 3;
	int pxi;
	pxi = MyPow<int>(xi, n);
	cout << "result of int MyPow is " << pxi << endl;

	const float xf = 4.1;
	float pxf;
	pxf = MyPow<float>(xf, n);
	cout << "result of float MyPow is " << pxf << endl;

	const double xd = 5.2;
	double pxd;
	pxd = MyPow<double>(xd, n);
	cout << "result of double MyPow is " << pxd << endl;

	cout << endl;
	return 0;
}
