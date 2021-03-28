#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"



//初始化链表
LNode* initlist() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}

//头部插入
Status InsertAthead(LNode* L, int data) {
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (L->next == NULL) {
		node->next = L->next;
		node->pre = L;
		L->next = node;
		node->data = data;
	} else {
		node->next = L->next;
		L->next->pre = node;
		node->pre = L;
		L->next = node;
		node->data = data;
	}
	return SUCCESS;
}

//尾部插入
Status InsertAttail(LNode* L, int data) {
	while (L->next != NULL) {
		L = L->next;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->next = L->next;
	node->pre = L;
	node->data = data;
	L->next = node;
	return SUCCESS;
}

//判断链表是否为空
void empty(LNode* L) {
	if (L->next == NULL) {
		printf("\n");
		printf("该链表为空\n");
		return;
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

//删除结点
void deleteAti(LNode* L, int index) {
	empty(L);
	int x = linkedListlength(L);
	if (index < 1 || index>x) {
		printf("输入的index不合法\n");
		return;
	}
	LNode* node = L->next;
	if (index == 1) {
		if (node->next == NULL) {
			L->next = NULL;
			free(node);
			return;
		} else {
			L->next = node->next;
			node->next->pre = L;
			free(node);
		}
	} else {
		for (int i = 1; i < index ; i++) {
			node = node->next;
		}
		if (index==x) {
			node->pre->next = node->next;
			free(node);
		} else {
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
		}

	}
}

//获取第i个元素的内容
Status linkedListget(LNode* L, int index) {
	empty(L);
	int x = linkedListlength(L);
	if (index < 1 || index>x) {
		printf("输入的index不合法\n");
		return ERROR;
	}
	LNode * node = L->next;
	for (int i = 1; i < index; i++) {
		node = node->next;
	}
	printf("\n");
	printf("元素的内容：%d\n", node->data);
	return SUCCESS;
}

//根据内容查找元素索引
Status SearchList(LNode* L, ElemType e) {
	if(L->next==NULL) {
		return ERROR;
	}
	LNode*node=L->next;
	int i=1;
	while(node->data!=e&&node!=NULL) {
		node = node->next;
		i++;
	}
	printf("元素的内容：%d  其索引为：%d\n",node->data,i);
	return SUCCESS;
}

//反转链表
Status ReverseList(LNode* L) {
	if(L==0||L->next==0) {
		return ERROR;
	}
	LNode*p,*q,*r;  
	p=L->next;
	L->next=NULL;
	q=NULL;
	r=NULL;
	while(p) {
		if(r==NULL){
		q=p->next;
		p->next=r;
		r=p;
		p=q;
		}
		q=p->next;
		p->next=r;
		r->pre=p;
		r=p;
		p=q;
	}
	L->next=r;
	r->pre=L;
	return SUCCESS;
}

//在i处插入一个结点
Status InsertAti(LNode * L, int index, int data) {
	int x = linkedListlength(L);
	empty(L);
	if (index < 1 || index>x) {
		printf("输入的index不合法\n");
		return ERROR;
	}
	if (x == 0) {
		LNode* tem = (LNode*)malloc(sizeof(LNode));
		tem->data = data;
		tem->next = L->next;
		L->next = tem;
	}
	LNode* node = L->next;
	for (int i = 1; i < index; i++) {
		node = node->next;
	}
	//要插入的结点
	LNode* tem = (LNode*)malloc(sizeof(LNode));
	tem->data = data;
	node->pre->next = tem;
	tem->pre = node->pre;
	tem->next = node;
	node->pre = tem;
	return SUCCESS;
}

//销毁链表
void DestroyList(LNode* L) {
	LNode* p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
}

//遍历打印链表
void print(LNode* L) {
	LNode* node = L->next;
	while (node) {
		printf("%d <=>", node->data);
		node = node->next;
	}
	printf("NULL");
	printf("\n");
}
