#include <stdio.h>
#include <string.h>
#include <windows.h>


void Replace(char* dest)
{
	int len = strlen(dest);          //字符串长度
	int j = 0;
	int ilen = 0;
	char *idest = dest;
	char *right = NULL;
	if (!dest)                //行参有效性判断，如传入空字符串 则直接返回
	{
		return;
	}
	while (*idest)                 //计算空格个数
	{
		if (' ' == *idest)
		{
			j++;
		}
		idest++;
	}
	idest = dest+len-1;
	ilen = len + 2 * j;              //计算新字符串的长度
	right = dest + ilen-1;             
	while (idest != right)           //从后向前遍历整个字符串
	{
		if (*idest == ' ')
		{
			*right-- = '0';
			*right-- = '2';
			*right-- = '%';
			idest--;
		}
		if (*idest!=' ')
		{
			*right-- = *idest--;
		}
	}
}

int main()
{
	char arr[100] = "i can be the best one!";
	Replace(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}