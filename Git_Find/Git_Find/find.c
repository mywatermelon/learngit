#include <stdio.h>
#include <windows.h>
#include <assert.h>
#define LINE 4
#define ROW 4

int find(int *dest,int row,int line, int num)     
{
	int i = 0;
	int j = LINE-1;
	assert(dest);
	while ((i<row)&&(j>=0))        //Ϊ��ֹ����Խ�磬���к��н����޶�
	{
		if (num > dest[i*line+j])
		{
			i += 1;
		}
		if (num < dest[i*line + j])
		{
			j -= 1;
		}
		if (num == dest[i*line + j])
		{
			return 1;    //���ҳɹ�����1
		}
	}
	return -1;      //����ʧ�ܷ���-1
}

int main()
{
	int arr[ROW][LINE] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int ret = find((int *)arr,ROW,LINE, 8);
	printf("%d", ret);
	system("pause");
	return 0;
}			