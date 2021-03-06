/******************************************************************************
1.已知：50个人围成圈报数，从1开始，依次累加，报到7的倍数或者数字中带有7的出局。
	求：最后留下来的时第几个人。
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i, k, m, n, num[50], * p;
	n = 50; // 总人数
	p = num;
	for (i = 0; i < n; i++)
		*(p + i) = i + 1;
	i = 0; // i 循环计数变量
	k = 0; // k 报数时的计数变量
	m = 0; // m 退出人数
	while (m < n - 1) // 当未退出人数大于1时
	{
		if (*(p + i) != 0)
			k++;
		if (k % 7 == 0)
		{
			*(p + i) = 0;
			m++;
		}
		else
		{
			while (k % 10 != 7 && k / 10 != 0)
			{
				if (k % 10 == 7)
				{
					*(p + i) = 0;
					m++;
					break;
				}
				k = k / 10;
			}
		}
		i++;
		if (i == n)
			i = 0;
	}
	while (*p == 0)
		p++;
	cout << "The last one is No." << *p << endl;
	return 0;

}