#include <stdio.h>
#include <stdlib.h>

// define element type
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

//��ʼ������
LNode* initlist() ;

//���������������ͺͳ����Ƿ���ȷ 
int chk_data(char *num);

//ͷ������
Status InsertAthead(LNode* L, int data) ;

//β������
Status InsertAttail(LNode* L, int data) ;

//�ж������Ƿ�Ϊ��
void empty(LNode* L) ;

//������ĳ���
int linkedListlength(LNode* L) ;

//��i������һ�����
Status InsertAti(LNode* L, int index,int data) ;

//ɾ�����
Status deleteAti(LNode* L,int index) ;

//��ȡ��i��Ԫ�ص�����
Status linkedListget(LNode* L,int index) ;

//�������ݲ���
Status SearchList(LNode* L, ElemType e);

//��ת���� 
Status ReverseList(LNode* L); 

//�ҵ��м��� 
void FindMidNode(LNode* L); 

//�ж������Ƿ�ɻ�
void  IsLoopList (LNode* L);

//�������
void ClearlinkedList(LNode* L) ;

//��������
void DestroyList (LNode* L) ;

//������ӡ����
void print(LNode* L) ;
