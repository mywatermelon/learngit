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

void PushBack(PNode *PHead,int data);
void PushFront(PNode* PHead, int data);
void PopBack(PNode *PHead);
void PopFront(PNode* PHead);

PNode find(PNode PHead,int data);
PNode Findmid(PNode PHead);

void EraseNotEndNode(PNode pos);
void InsertNotHead(PNode pos,int data);

void PrintfSList(PNode PHead);
void PrintfFtoH(PNode PHead);

void Insert(PNode* PHead, PNode pos, int data);
void Erase(PNode* PHead, PNode pos);

void Remove(PNode* PHead, int data);
void RemoveAll(PNode* PHead, int data);

void ReverseEndToHead(PNode* PHead);

void UnionNode(PNode PHead1, PNode PHead2);

int HasCrosWithCircle(PNode PHead1, PNode PHead2);


