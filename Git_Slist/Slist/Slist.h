#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct PNode
{
	int data;
	struct PNode *PNext;
}Node, *PNode;

void InitSList(PNode *PHead);
PNode NewNode(int data);

void PushBack(PNode *PHead,int data);//尾插
void PushFront(PNode* PHead, int data);//头插
void PopBack(PNode *PHead);//尾删
void PopFront(PNode* PHead);//头删

PNode find(PNode PHead,int data);//查找
PNode Findmid(PNode PHead);  //返回中间结点的地址

void EraseNotEndNode(PNode pos);//删除非尾结点
void InsertNotHead(PNode pos,int data);//添加非头结点

void PrintfSList(PNode PHead);//打印整个链表
void PrintfFtoH(PNode PHead);//从尾到头打印整个链表

void Insert(PNode* PHead, PNode pos, int data);//在特定位置后添加结点
void Erase(PNode* PHead, PNode pos);//删除特定结点

void Remove(PNode* PHead, int data);//删除第一个特定结点
void RemoveAll(PNode* PHead, int data);//删除所有符合条件的结点

void ReverseEndToHead(PNode* PHead);//翻转整个链表

void UnionNode(PNode PHead1, PNode PHead2);//输出两个已排序单链表中相同的数据

int SlistLen(PNode PHead);//返回链表的长度

int IsCros(PNode PHead1, PNode PHead2);//判断连个单链表是否相交

PNode CrosNode(PNode PHead1, PNode PHead2);//求两个相交链表的交点

PNode Together(PNode *PHead1, PNode *PHead2);//合并两个有序链表, 合并后依然有序

int HasCrosWithCircle(PNode PHead1, PNode PHead2);//判断两个带环的链表是否相交

void Bubble(PNode *PHead);//冒泡排序

void QuickSoft(PNode *PHead); //快排

PNode Find_k(PNode PHead,int k); //查找倒数第k个元素

PNode JosephCircle(PNode *PHead, int step); //单链表实现约瑟夫环

PNode HasCircle(PNode PHead);//判断链表是否含环 返回快慢指针相交的地址

PNode CircleNode(PHead);//返回含环链表的环的入口点


//5. 单链表实现约瑟夫环(JosephCircle)
//13. 判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
//14. 复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
//还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。