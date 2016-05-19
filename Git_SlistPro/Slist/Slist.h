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

void PushBack(PNode *PHead,int data);//β��
void PushFront(PNode* PHead, int data);//ͷ��
void PopBack(PNode *PHead);//βɾ
void PopFront(PNode* PHead);//ͷɾ

PNode find(PNode PHead,int data);//����
PNode Findmid(PNode PHead);  //�����м���ĵ�ַ

void EraseNotEndNode(PNode pos);//ɾ����β���
void InsertNotHead(PNode pos,int data);//��ӷ�ͷ���

void PrintfSList(PNode PHead);//��ӡ��������
void PrintfFtoH(PNode PHead);//��β��ͷ��ӡ��������

void Insert(PNode* PHead, PNode pos, int data);//���ض�λ�ú���ӽ��
void Erase(PNode* PHead, PNode pos);//ɾ���ض����

void Remove(PNode* PHead, int data);//ɾ����һ���ض����
void RemoveAll(PNode* PHead, int data);//ɾ�����з��������Ľ��

void ReverseEndToHead(PNode* PHead);//��ת��������

void UnionNode(PNode PHead1, PNode PHead2);//�����������Ĺ���Ԫ��

PNode HasCircle(PNode PHead);//�ж������Ƿ񺬻� ���ؿ���ָ���ཻ��

int SlistLen(PNode PHead);//��������ĳ���

int IsCros(PNode PHead1, PNode PHead2);//�ж������������Ƿ��ཻ

PNode CrosNode(PNode PHead1, PNode PHead2);//�������ཻ����Ľ���

PNode Together(PNode *PHead1, PNode *PHead2);//�ϲ�������������, �ϲ�����Ȼ����

int HasCrosWithCircle(PNode PHead1, PNode PHead2);//�ж����������������Ƿ��ཻ


//5. ������ʵ��Լɪ��(JosephCircle)
//7. ����������ð������&��������
//8. �ϲ�������������, �ϲ�����Ȼ����
//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ�
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿
//14. ��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������
//15. ��������������������ͬ�����ݡ�void UnionSet(Node* l1, Node* l2);