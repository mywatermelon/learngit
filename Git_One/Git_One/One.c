#include<stdio.h>
#include <windows.h>

int One(int num)
{
	int i = 0;
	int count = 0;
	if (!num)
	{
		return 0;
	}
	for (i = 0; i < 32; i++)
	{
		if (1 == (num >> i & 1))     //如果num是负数，如果是符号移位，会陷入死循环
		{
			count++;
		}
	}
	return count;
}

int Onebetter(int num)                //每次将num与num-1进行按位与，每次会与之后二进制中1的个数回减一
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	return count;
}

int main()
{
	int num = 15;
	int ret = Onebetter(num);
	printf("%d", ret);
	system("pause");
	return 0;
}