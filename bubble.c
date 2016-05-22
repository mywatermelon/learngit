#include <stdio.h>
#include <assert.h>
#include <windows.h>


int* pop(int *dest, int sz)
{
	assert(*dest);
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (*(dest + j)>*(dest + j + 1))
			{
				int temp = *(dest + j + 1);
				*(j + 1 + dest) = *(j + dest);
				*(j + dest) = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	return dest;
}
int main()
{
	int arr[] = { 9, 5, 19, 3, 4, 5, 6, 7, 8, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int m = 0;
	pop(arr, sz);
	for (m = 0; m < sz; m++)
	{
		printf("%d ", arr[m]);
	}
	system("pause");
	return 0;
}