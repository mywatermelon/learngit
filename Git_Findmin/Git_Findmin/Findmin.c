#include <stdio.h>
#include <assert.h>
#include <windows.h>

int Findmin(int*dest,int len)
{
	int left = 0;
	int right = len - 1;
	int mid = left + (right - left) / 2;
	assert(dest);
	if (1 == len)
	{
		return *dest;
	}
	while (left != mid&&right != mid&&(*(dest + left) > *(dest + right)))
	{
		if (*(dest + mid) < *(dest + left))
		{
			right = mid;
		}
		if (*(dest + mid) > *(dest + left))
		{
			left = mid;
		}
			mid = left + (right - left) / 2;
	}
	if (*(dest + left) < *(dest + right))
		return *(dest + left);
	else
		return *(dest + right);
}
int main()
{
	int arr[10] = {3,4,5,1,2};
	int min=Findmin(arr, 5);
	printf("%d", min);
	system("pause");
	return 0;
}