#include <stdio.h>
#include <windows.h>

void OddEven(int *dest, int len)
{
	int *left = NULL;
	int *right = NULL;
	if (NULL == dest || len < 2)
	{
		return;
	}
	left = dest;
	right = dest + len - 1;

	while (left < right)
	{
		if (0 == ((*left) % 2))
		{
			left = left + 1;
		}
		else if (1 == ((*right) % 2))
		{
			right = right - 1;
		}
		else
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
			left = left + 1;
			right = right - 1;
		}
	}

}

int main()
{
	int dest[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	OddEven(dest, sizeof(dest) / sizeof(dest[0]));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", dest[i]);
	}
	system("pause");
	return 0;
}