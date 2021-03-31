#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"


//初始化链表
LNode* initlist() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->data = 0;
	L->next = NULL;
	return L;
}

//检查输入的数据类型和长度是否正确
int chk_data(char *num) {
	int i;
	for (i = 0; num[i]; i++) { 
		if (num[i] > '9' || num[i] < '0') {
			printf("\n传入值含有非数值\n");
			return 0;
		}
	}
	if (i > 10) { 
		printf("\n超出了数字长度\n");
		return 0;
	}
	return 1;
}

//头部插入
Status InsertAthead(LNode* L, int data) {
	if(L==0) {
		printf("未初始化链表\n");
		return ERROR;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->next = L->next;
	node->data = data;
	L->next = node;
	return SUCCESS;
}

//尾部插入
Status InsertAttail(LNode* L, int data) {
	if(L==NULL) {
		printf("未初始化链表\n");
		return ERROR;
	}
	while (L->next!=NULL) {
		L = L->next;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->next = L->next;
	node->data = data;
	L->next = node;
	return SUCCESS;
}

//判断链表是否为空
void empty(LNode* L) {
	if (L->next == NULL) {
		printf("\n");
		printf("该链表为空\n");
	}

}

//求链表的长度
int linkedListlength(LNode* L) {
	if (L->next == NULL) {
		printf("\n");
		printf("该链表为空\n");
		return 0;
	}
	if (L->next != NULL) {
		LNode* node = L->next;
		int i;
		for (i = 1; node->next != NULL; i++) {
			node = node->next;
		}
		return i;
	}
}

//在i处插入一个结点
Status InsertAti(LNode* L, int index,int data) {
	int x = linkedListlength(L);
	empty(L);
	if (index < 1 || index>x) {
		printf("\n输入的index不合法\n");
		return ERROR;
	}
	if (x == 0) {
		LNode* tem = (LNode*)malloc(sizeof(LNode));
		tem->data = data;
		tem->next = L->next;
		L->next = tem;
		return SUCCESS;
	}
	LNode* node = L->next;
	for (int i = 1; i < index - 1; i++) {
		node = node->next;
	}
	//要插入的结点
	LNode* tem = (LNode*)malloc(sizeof(LNode));
	tem->data = data;
	tem->next = node->next;
	node->next = tem;
	return SUCCESS;
}

//删除结点
Status deleteAti(LNode* L,int index) {
	int x = linkedListlength(L);
	empty(L);
	if (index < 1 || index>x) {
		printf("\n输入的index不合法\n");
		return ERROR;
	}
	LNode* node = L->next;
	if (index == 1) {
		L->next = node->next;
		free(node);
		return SUCCESS;
	}
	for (int i = 1; i < index-1; i++) {
		node = node->next;
	}
	//要删除的结点
	LNode* tem = node->next;
	node->next = tem->next;
	free(tem);
	return SUCCESS;
}

//获取第i个元素的内容
Status linkedListget(LNode* L,int index) {
	empty(L);
	int x = linkedListlength(L);
	if (index < 1||index>x) {
		printf("\n输入的index不合法\n");
		return ERROR;
	}
	LNode* node = L->next;

	for (int i = 1; i <index; i++) {
		node = node->next;
	}
	printf("\n");
	printf("元素的内容：%d\n", node->data);
	return SUCCESS;
}

//根据内容查找元素索引
Status SearchList(LNode* L, ElemType e) {
	if(L->next==NULL||L==NULL) {
		printf("\n链表为空\n");
		return ERROR;
	}
	LNode*node=L->next;
	int i=1;
	while(node->data!=e) {
		node = node->next;
		i++;
		if(node==NULL) {
			printf("\n没有所查找的内容\n");
			return ERROR;
		}
	}
	printf("元素的内容：%d  其索引为：%d\n",node->data,i);
	return SUCCESS;
}

//反转链表
Status ReverseList(LNode* L) {
	if(L==NULL||L->next==NULL||L->next->next==NULL) {
		return ERROR;
	}
	LNode*p,*q,*r;
	p=L->next;
	L->next=NULL;
	q=NULL;
	r=NULL;
	while(p) {
		q=p->next;
		p->next=r;
		r=p;
		p=q;
	}
	L->next=r;
	return SUCCESS;
}

//找到中间结点
void FindMidNode(LNode* L) {
	LNode* fast=L;
	LNode* slow=L;
	int i;
	for(i=0; fast!=NULL; i++) {
		if(fast->next == NULL) {
			break;
		}
		fast = fast->next->next;
		slow =  slow->next;
	}
	printf("位于最中间结点的内容是：%d\n", slow->data);
	printf("位于最中间结点的位置是：%d\n", i);
}

//判断链表是否成环
void IsLoopList (LNode* L) {
	if (L==NULL||L->next == NULL) {
		printf("\n该链表为空\n");
		return;
	}
	LNode*fast=L->next;
	LNode*slow=L;
	while(slow!=fast) {
		if(fast==NULL||fast->next==NULL) {
			printf("\n链表不成环\n");
			return;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("\n链表成环\n");
	return ;
}

//清空链表
void ClearlinkedList(LNode* L) {
	LNode* p = L->next;
	LNode* q;
	while(p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next=NULL;
}

//销毁链表
void DestroyList (LNode* L) {
	LNode* p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
	L==NULL;
	printf("\n链表销毁成功\n");
	printf("\n请进行[1]操作重新初始化链表");
}

//遍历打印链表
void print(LNode* L) {
	if (L==NULL) {
		printf("\n");
		printf("该链表为空\n");
		return;
	}
	LNode* node = L->next;
	while (node) {
		printf("%d ->", node->data);
		node = node->next;
	}
	printf("NULL");
	printf("\n");
}
