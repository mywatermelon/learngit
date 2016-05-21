#include <windows.h>
#include "SList.h"

void test()
{
	PNode PHead;
	InitSList(&PHead);
	PushBack(&PHead, 1);
	PushBack(&PHead, 2);
	PushBack(&PHead, 3);
	PushBack(&PHead, 4);
	PrintfSList(PHead);
	PrintfFtoH(PHead);
	PopBack(&PHead);
	PopBack(&PHead);
	PopBack(&PHead);
	PopBack(&PHead);
	PrintfSList(PHead);

}

void test1()
{
	PNode PHead;
	InitSList(&PHead);
	PushFront(&PHead, 1);
	PushFront(&PHead, 2);
	PushFront(&PHead, 3);
	PrintfFtoH(PHead);

}

void test2()
{
	PNode PHead;
	InitSList(&PHead);
	PushFront(&PHead, 1);
	PushFront(&PHead, 2);
	PushFront(&PHead, 3);
	Insert(&PHead, find(PHead,2), 5);
	Erase(&PHead, find(PHead,1));
	Remove(&PHead, 3);
	PrintfSList(PHead);
}

void test3()
{
	PNode PHead;
	InitSList(&PHead);
	PushFront(&PHead, 1);
	PushFront(&PHead, 2);
	PushFront(&PHead, 3);
	PushFront(&PHead, 3);
	PushFront(&PHead, 3);
	Insert(&PHead, find(PHead, 2), 5);
	PrintfSList(PHead);
	Erase(&PHead, find(PHead, 1));
	PrintfSList(PHead);
	Remove(&PHead, 5);
	Remove(&PHead, 2);
	PrintfSList(PHead);
	RemoveAll(&PHead, 3);
	PrintfSList(PHead);
}

void test4()
{

	PNode PHead1,PHead2;
	InitSList(&PHead1);
	PushBack(&PHead1, 2);
	PushBack(&PHead1, 2);
	PushBack(&PHead1, 3);
	PushBack(&PHead1, 4);
	PrintfSList(PHead1);
	ReverseEndToHead(&PHead1);
	PrintfSList(PHead1);


}

void test5()
{
	int i = 0;
	PNode PHead1, PHead2;
	InitSList(&PHead1);
	PushBack(&PHead1, 2);

	PrintfSList(PHead1);
	i = SlistLen(PHead1);
	printf("%d", i);
}

void test6()
{

	PNode PHead1, PHead2,flag1,flag2;
	InitSList(&PHead1);
	PushBack(&PHead1, 1);
	PushBack(&PHead1, 3);
	PushBack(&PHead1, 5);
	PushBack(&PHead1, 7);
	PrintfSList(PHead1);

	InitSList(&PHead2);
	PushBack(&PHead2, 2);
	PushBack(&PHead2, 4);
	PushBack(&PHead2, 6);
	PushBack(&PHead2, 8);
	PrintfSList(PHead2);

	flag1 = Together(&PHead1, &PHead2);
	PrintfSList(flag1);
}

void test7()
{

	PNode PHead1;
	InitSList(&PHead1);
	//PushBack(&PHead1, 1);
	PushBack(&PHead1, 2);
	PushBack(&PHead1, 1);
	//PushBack(&PHead1, 4);
	PrintfSList(PHead1);

	Bubble(&PHead1);
	PrintfSList(PHead1);
}


void test8()
{

	PNode PHead,flag1,flag2,flag3;
	InitSList(&PHead);
	PushFront(&PHead, 1);
	PushFront(&PHead, 2);
	PushFront(&PHead, 3);
	PushFront(&PHead, 4);
	PushFront(&PHead, 5);
	flag1 = find(PHead, 4);
	flag2 = find(PHead, 1);
	flag2->PNext = flag1;
	flag3 = CircleNode(PHead);
	printf("%d", flag3->data);
}
int main()
{
	//test();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	test8();
	system("pause");
	return 0;
}