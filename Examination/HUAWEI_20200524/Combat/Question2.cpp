/******************************************************************************
2.中国有句俗语叫“三天打鱼两天晒网”。某人从1990年1月1日起开始“三天打鱼两天晒网”，
  问这个人在以后的某一天中是“打鱼”还是“晒网”。 
  问题分析与算法设计：根据题意可以将解题过程分为三步： 
  1)计算从1990年1月1日开始 到2917年1月1日至指定日期共有多少天； 
  2)由于“打鱼”和“晒网”的周期为5天，所以将计算出的天数用5去除； 
  3)根据余数判断他是在“打鱼”还是在“晒网”； 若 余数为1，2，3，则他是在“打鱼”否则是在“晒网”
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int Day(int y, int m, int d);

int main()
{
    int y, m, d;
    int days;
    int flag;

    scanf("%4d-%2d-%2d", &y, &m, &d);

    days = Day(y, m, d);
    flag = days % 5;

    if (days == -1)
        printf("Invalid input");
    else if (flag == 1 || flag == 2 || flag == 3)
        printf("He is working");
    else if (flag == 4 || flag == 0)
        printf("He is having a rest");

    return 0;
}

int Day(int y, int m, int d)
{
    int i;
    int r = 0;
    int a[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    if (y >= 1990 && m > 0 && m < 13 && d>0 && d < 32)
    {
        for (i = 1990; i <= y; i++)
        {
            if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
                r++;
        }
        for (i = 0; i < m - 1; i++)
        {
            d += a[i];
        }
        if ((y % 400 == 0 || y % 100 != 0 && y % 4 == 0) && m < 3)
        {
            r--;
        }
        return 365 * (y - 1990) + r + d;
    }
    else
    {
        return -1;
    }
}