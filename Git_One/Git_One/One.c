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
		if (1 == (num >> i & 1))     //���num�Ǹ���������Ƿ�����λ����������ѭ��
		{
			count++;
		}
	}
	return count;
}

int Onebetter(int num)                //ÿ�ν�num��num-1���а�λ�룬ÿ�λ���֮���������1�ĸ����ؼ�һ
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