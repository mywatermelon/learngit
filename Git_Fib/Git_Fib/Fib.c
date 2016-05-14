#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int Fib(int n)
{
	int first = 0;
	int later = 1;
	int FibN = 0;
	if (0 == n)
		return 0;
	if (1 == n)
		return 1;
	while (--n)
	{
		FibN = first + later;
		first = later;
		later = FibN;
	}
	return FibN;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d", ret);
	system("pause");
	return 0;
}