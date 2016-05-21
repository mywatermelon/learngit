#include "SList.h"

void InitSList(PNode *PHead)    //初始化链表
{
	*PHead = NULL;
}


PNode NewNode(int data)      //建立新结点
{
	PNode NewNode = (PNode)malloc(sizeof(Node));
	if (NULL == NewNode)
	{
		return NULL;
	}
	NewNode->data = data;
	NewNode->PNext = NULL;
	return NewNode;
}

void PrintfFtoH(PNode PHead)     //从尾到头打印整个链表
{
	if (NULL != PHead)
	{
		PrintfFtoH(PHead->PNext);
		printf("%d ", PHead->data);
	}
}

void EraseNotEndNode(PNode pos)   //删除标记位置（非尾节点）的元素
{
	PNode flag = NULL;
	if ((NULL == pos)||(NULL==pos->PNext))
	{
		return;
	}
	else
	{
		flag = pos->PNext;
		pos->data = flag->data;
		pos->PNext = pos->PNext->PNext;
		free(flag);
	}
}

void InsertNotHead(PNode pos, int data)    //在标记位置（非头结点）插入新元素
{
	PNode pNewNode = NULL;
	if (NULL == pos)
	{
		return;
	}
	pNewNode = NewNode(pos->data);
	//判断是否开辟新节点成功
	if (NULL == pNewNode)
	{
		return;
	}
	pNewNode->PNext = pos->PNext;
	pos->PNext = pNewNode;
	pos->data = data;
}

PNode Findmid(PNode PHead)        //查找链表中点元素的地址
{
	assert(PHead);
	PNode first = PHead;
	PNode later = PHead;
	while (NULL != first&&NULL != first->PNext)
	{
		first = first->PNext->PNext;
		later = later->PNext;
	}
	return later;
}

void PushBack(PNode *PHead, int data)    //尾插
{
	PNode flag = *PHead;
	PNode newnode = NewNode(data);
	if (NULL == NewNode)
	{
		return;
	}
	if (NULL == *PHead)
	{
		*PHead = newnode;
		return;
	}
	while (NULL != flag->PNext)
	{
		flag = flag->PNext;
	}
	flag->PNext = newnode;
}


void PopBack(PNode *PHead)       //尾删
{
	PNode flag = *PHead;
	if (NULL == *PHead)
	{
		return;
	}
	if (NULL == (*PHead)->PNext)
	{
		*PHead = NULL;
		free(flag);
		return;
	}
	while (flag->PNext->PNext)
	{
		flag = flag->PNext;
	}
	free(flag->PNext);
	flag->PNext = NULL;
}

void PrintfSList(PNode PHead)      //打印整个链表
{
	if (NULL == PHead)
	{
		printf("NULL\n");
		return;
	}
	PNode flag = PHead;
	while (NULL != flag)
	{
		printf("%d->", flag->data);
		flag = flag->PNext;
	}
	printf("NULL\n");
}

PNode find(PNode PHead,int data)       //查找特定元素
{
	PNode flag = PHead;
	if (NULL == PHead)
	{
		return NULL;
	}
	while ((data != flag->data) && (NULL != flag))
	{
		flag = flag->PNext;
	}
	if (NULL == flag)
	{
		return NULL;
	}
	return flag;

}


void PushFront(PNode* PHead, int data)      //头插
{
	PNode new = NewNode(data);
	if (NULL == *PHead)
	{
		*PHead = new;
	}
	else
	{
		new->PNext = *PHead;
		*PHead = new;
	}
}

void PopFront(PNode* PHead)                //头删
{
	if (NULL == *PHead)
	{
		return;
	}
	else
	{
		PNode flag = *PHead;
		*PHead = (*PHead)->PNext;
		free(flag);
	}
}

void Insert(PNode* PHead, PNode pos, int data)       //在标记位置插入新元素
{
	PNode new = NewNode(data);
	PNode flag = *PHead;
	if (NULL == pos)
	{
		return;
	}
	while ((NULL != flag) && (pos != flag))
	{
		flag = flag->PNext;
	}
	if (NULL == flag)           
	{
		return;
	}
	else
	{
		new->PNext = flag->PNext;
		flag->PNext = new;
	}
}

void Erase(PNode* PHead, PNode pos)   //删除标记位置的元素
{
	PNode flag = *PHead;
	if (NULL == pos)
	{
		return;
	}
	if (NULL == *PHead)
	{
		return;
	}
	if (pos == *PHead)
	{
		*PHead = (*PHead)->PNext;
		free(flag);
		return;
	}
	while ((NULL != flag->PNext) && (pos != flag->PNext))
	{
		flag = flag->PNext;
	}
	if (NULL == flag->PNext)
	{
		return;
	}
	else
	{
		PNode _flag = flag->PNext;
		flag->PNext = flag->PNext->PNext;
		free(_flag);
	} 
}


void Remove(PNode* PHead, int data)      //删除第一个符合条件的元素
{
	PNode flag = *PHead;
	if (NULL == *PHead)
	{
		return;
	}
	if (data == (*PHead)->data)
	{
		*PHead = (*PHead)->PNext;
		free(flag);
		return;
	}
	while ((NULL != flag->PNext) && (data != flag->PNext->data))
	{
		flag = flag->PNext;
	}
	if (NULL == flag->PNext)
	{
		return;
	}
	else
	{
		PNode _flag = flag->PNext;
		flag->PNext = flag->PNext->PNext;
		free(_flag);
	}
}

void RemoveAll(PNode* PHead, int data)   //删除所有符合条件的元素
{
	PNode flag = NULL;
	PNode _flag = NULL;
	if (NULL == *PHead)
	{
		return;
	}
	flag = *PHead;
	while (NULL != flag&&data == flag->data)
	{
		*PHead = (*PHead)->PNext;
		free(flag);
		flag = *PHead;
	}
	if (NULL == flag)
	{
		return;
	}
	while (NULL != flag->PNext)
	{
		if (data == flag->PNext->data)
		{
			_flag = flag->PNext;
			flag->PNext = flag->PNext->PNext;
			free(_flag);
		}
	}

}

void UnionNode(PNode PHead1, PNode PHead2)    //输出两个已排序单链表中相同的数据
{
	PNode flag1 = NULL;
	PNode flag2 = NULL;
	if (NULL == PHead1 || NULL == PHead2)
	{
		return;
	}
	flag1 = PHead1;
	flag2 = PHead2;
	while(NULL != flag1 && NULL != flag2)
	{
		if (flag1->data == flag2->data)
		{
			printf("%d", flag1->data);
			while (NULL != flag1->PNext&&flag1->data == flag1->PNext->data)
			{
				flag1 = flag1->PNext;
			}
			while (NULL != flag2->PNext&&flag2->data == flag2->PNext->data)
			{
				flag2 = flag2->PNext;
			}
			flag1 = flag1->PNext;
			flag2 = flag2->PNext;
		}
		else if (flag1->data > flag2->data)
		{
			flag2 = flag2->PNext;
		}
		else
		{
			flag1 = flag1->PNext;
		}

	}

}

void ReverseEndToHead(PNode* PHead)//翻转链表
{
	PNode newHead = NULL;
	PNode flag1 = NULL;
	PNode flag2 = NULL;
	if (NULL == *PHead)
	{
		return;
	}
	flag1 = *PHead;
	while (NULL != flag1)
	{
		flag2 = flag1->PNext;
		flag1->PNext = newHead;
		newHead= flag1;
		flag1 = flag2;
	}
	*PHead = newHead;
}

PNode HasCircle(PNode PHead)//判断链表是否含环 如果含环返回快慢指针在环内的交点
{
	PNode fast = NULL;
	PNode slow = NULL;
	if(NULL == PHead||NULL==PHead->PNext )
	{
		return NULL;
	}
	fast = PHead->PNext->PNext;
	slow = PHead->PNext;
	while (fast != NULL && fast->PNext != NULL && fast != slow)
	{
		fast = fast->PNext->PNext;
		slow = slow->PNext;
	}
	if (fast == NULL||NULL==fast->PNext)
	{
		return NULL;
	}
	else
	{
		return fast;
	}
}

int SlistLen(PNode PHead)//求链表的长度
{
	PNode flag = NULL;
	int len = 0;
	if (NULL == PHead)
	{
		return len;
	}
	flag = PHead;
	while (NULL != flag)
	{
		flag = flag->PNext;
		len++;
	}
	return len;
}

int IsCros(PNode PHead1, PNode PHead2) //判断两个单链表是否相交 若相交返回1

{
	PNode flag1 = NULL;
	PNode flag2 = NULL;
	if (NULL == PHead1 || NULL == PHead2)
	{
		return 0;
	}
	flag1 = PHead1;
	flag2 = PHead2;
	while (NULL != flag1->PNext)
	{
		flag1 = flag1->PNext;
	}
	while (NULL != flag2->PNext)
	{
		flag2 = flag2->PNext;
	}
	if (flag1 == flag2)
	{
		return 1;
	}
	return 0;
}

PNode CrosNode(PNode PHead1, PNode PHead2)//求取两个相交链表的交点 如不想交返回NULL
{
	int Len1 = 0;
	int Len2 = 0;
	int step = 0;
	PNode flag1 = NULL;
	PNode flag2 = NULL;
	if (0 == IsCros(PHead1, PHead2))
	{
		return NULL;
	}
	Len1 = SlistLen(PHead1);
	Len2 = SlistLen(PHead2);
	step = Len1 - Len2;
	flag1 = PHead1;
	flag2 = PHead2;
	if (step > 0)
	{
		while (step--)
		{
			flag1 = flag1->PNext;
		}
	}
	else
	{
		step = 0 - step;
		while (step--)
		{
			flag2 = flag2->PNext;
		}
	}
	while (flag1 != flag2)
	{
		flag1 = flag1->PNext;
		flag2 = flag2->PNext;
	}
	return flag1;
}


PNode Together(PNode *PHead1, PNode *PHead2) //合并两个有序链表, 合并后依然有序
{
	PNode flag1 = NULL;
	PNode flag2 = NULL;
	PNode NewHead = NULL;
	PNode Nflag = NULL;
	if (NULL == (*PHead1))
	{
		return *PHead2;
	}
	if (NULL == (*PHead2))
	{
		return *PHead1;
	}
	flag1 = *PHead1;
	flag2 = *PHead2;
	if (flag1->data > flag2->data)
	{
		NewHead = flag2;
		Nflag = NewHead;
		flag2 = flag2->PNext;
	}
	else
	{
		NewHead = flag1;
		Nflag = NewHead;
		flag1 = flag1->PNext;
	}
	while (NULL != flag1&&NULL != flag2)
	{
		if (flag1->data > flag2->data)
		{
			Nflag->PNext = flag2;
			Nflag = Nflag->PNext;
			flag2 = flag2->PNext;
		}
		else
		{
			Nflag->PNext = flag1;
			Nflag = Nflag->PNext;
			flag1 = flag1->PNext;
		}
	}
	if (NULL == flag1)
	{
		Nflag->PNext = flag2;
	}
	else
	{
		Nflag->PNext = flag1;
	}
	return NewHead;
}

void Bubble(PNode *PHead)//冒泡排序
{
	PNode pos = NULL;
	PNode tail = NULL;
	int flag = 0;
	assert(PHead);
	if (NULL == (*PHead) || NULL == (*PHead)->PNext)
	{
		return;
	}
	while (tail != (*PHead)->PNext)
	{
		pos = *PHead;
		flag = 0;
		while (pos->PNext != tail)
		{
			if (pos->data > pos->PNext->data)
			{
				int tmp = pos->data;
				pos->data = pos->PNext->data;
				pos->PNext->data = tmp;
				flag = 1;
			}
			pos = pos->PNext;
		}
		if (0 == flag)
		{
			return;
		}
		tail = pos;
	}
}

void QuickSoft(PNode *PHead)//快排
{
	PNode flag = NULL;
	PNode tail = NULL;
	PNode pos = NULL;
	PNode Prepos = NULL;
	if (NULL == (*PHead) || NULL == (*PHead)->PNext)
	{
		return;
	}
	while (tail != (*PHead)->PNext)
	{
		pos = *PHead;
		flag = (*PHead)->PNext;
		while (flag!= tail)
		{
			if (pos->data < flag->data)
			{
				pos = flag;
			}
			if (tail == flag->PNext)
			{
				Prepos = flag;
				break;
			}
			flag = flag->PNext;

		}
		if (pos != Prepos)
		{
			int tmp = pos->data;
			pos->data = Prepos->data;
			Prepos->data = tmp;
		}
		tail = Prepos;
	}
}

PNode Find_k(PNode PHead,int k) //查找倒数第k个元素
{
	PNode fast = NULL;
	PNode slow = NULL;
	if (NULL == PHead || k <= 0)
	{
		return NULL;
	}
	fast = PHead;
	slow = PHead;
	while (--k)
	{
		if (NULL == fast->PNext)
		{
			return NULL;
		}
		fast = fast->PNext;
	}
	while (fast->PNext != NULL)
	{
		fast = fast->PNext;
		slow = slow->PNext;
	}
	return slow;
}

PNode JosephCircle(PNode *PHead, int step)
{
	PNode pos = NULL;
	PNode flag = NULL;
	if (NULL == (*PHead) || step<=1)
	{
		return NULL;
	}

}


PNode CircleNode(PHead)//返回含环链表的环的入口点
{
	PNode MeetNode = NULL;
	PNode flag = NULL;
	if (NULL == PHead)
	{
		return NULL;
	}
	flag = PHead;
	MeetNode = HasCircle(PHead);
	if (!MeetNode)
	{
		return NULL;
	}
	while (flag != MeetNode)
	{
		flag = flag->PNext;
		MeetNode = MeetNode->PNext;
	}
	return flag;
}
int HasCrosWithCircle(PNode PHead1, PNode PHead2)
{
	return 0;
}