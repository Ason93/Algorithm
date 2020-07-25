#include "questions.h"

// 367.Valid Perfect Square
bool isPerfectSquare(int num) {
    if (num == 1 || num == 0) {
        return true;
    }
    int left = 1;
    int right = num;
    int res = 0;
    while (left <= right) {
        // P.S.: if input = 2147483647, left + right might more than max of int
        int mid = left + (right - left) / 2;
        //int mid = (left + right) / 2;
        if (mid == num / mid && 0 == num % mid) {
            return true;
        }
        else if (mid > num / mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return false;
}

// 69. Sqrt(x)
int mySqrt(int x) {
    if (x == 1 || x == 0) {
        return x;
    }
    int left = 1;
    int right = x;
    int res = 0;
    while (left <= right) {
        // P.S.: if input = 2147483647, left + right might more than max of int
        int mid = left + (right - left) / 2;
        //int mid = (left + right) / 2;
        if (mid == x / mid) {
            return mid;
        }
        else if (mid > x / mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            res = mid;
        }
    }
    return res;
}

// 69. Sqrt(x) (Newton iteration method)
double mySqrt(double x) {
    double r = x;
    while (r * r - x > 1e-5) {
        r = (r + x / r) / 2;
    }
    //double r = -x;
    //while (r * r - x > 1e-5) {
    //    r = (r + x / r) / 2;
    //}
    return r;
}

int UseSqrt(){

    const int input = 5;

    cout << "*************** 367.Valid Perfect Square ***************" << endl;
    bool flag = isPerfectSquare(input);
    if (flag)
        cout << "The Input is a Valid Perfect Square" << endl;
    else
        cout << "The Input is not a Valid Perfect Square" << endl;

    cout << "*************** 69. Sqrt(x) ***************" << endl;
    const int result = mySqrt(input);
    cout << "The Sqrt of Input is: " << result << endl;

    double x = 1447;
    const double r = mySqrt(x);
    cout << "The Sqrt of Input is: " << r << endl;

    return 0;
}