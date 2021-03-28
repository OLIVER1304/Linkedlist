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

//初始化链表
LNode* initlist() ;

//头部插入
Status InsertAthead(LNode* L, int data) ;

//尾部插入
Status InsertAttail(LNode* L, int data) ;

//判断链表是否为空
void empty(LNode* L) ;

//求链表的长度
int linkedListlength(LNode* L) ;

//在i处插入一个结点
Status InsertAti(LNode* L, int index,int data) ;

//删除结点
Status deleteAti(LNode* L,int index) ;

//获取第i个元素的内容
Status linkedListget(LNode* L,int index) ;

//根据内容查找
Status SearchList(LNode* L, ElemType e);

//反转链表 
Status ReverseList(LNode* L); 

//找到中间结点 
void FindMidNode(LNode* L); 

//判断链表是否成环
int  IsLoopList (LNode* L);

//清空链表
void ClearlinkedList(LNode* L) ;

//销毁链表
void DestroyList (LNode* L) ;

//遍历打印链表
void print(LNode* L) ;
