#include <stdio.h>
#include <string.h>
#include <windows.h>


void Replace(char* dest)
{
	int len = strlen(dest);          //�ַ�������
	int j = 0;
	int ilen = 0;
	char *idest = dest;
	char *right = NULL;
	if (!dest)                //�в���Ч���жϣ��紫����ַ��� ��ֱ�ӷ���
	{
		return;
	}
	while (*idest)                 //����ո����
	{
		if (' ' == *idest)
		{
			j++;
		}
		idest++;
	}
	idest = dest+len-1;
	ilen = len + 2 * j;              //�������ַ����ĳ���
	right = dest + ilen-1;             
	while (idest != right)           //�Ӻ���ǰ���������ַ���
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