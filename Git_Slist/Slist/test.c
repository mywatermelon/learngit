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
	PopFront(&PHead);
	PopFront(&PHead);
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

int main()
{
	//test();
	//test3();
	test4();
	system("pause");
	return 0;
}