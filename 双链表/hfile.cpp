#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"



//��ʼ������
LNode* initlist() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}

//ͷ������
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

//β������
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

//�ж������Ƿ�Ϊ��
void empty(LNode* L) {
	if (L->next == NULL) {
		printf("\n");
		printf("������Ϊ��\n");
		return;
	}
}

//������ĳ���
int linkedListlength(LNode* L) {
	if (L->next == NULL) {
		printf("\n");
		printf("������Ϊ��\n");
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

//ɾ�����
void deleteAti(LNode* L, int index) {
	empty(L);
	int x = linkedListlength(L);
	if (index < 1 || index>x) {
		printf("�����index���Ϸ�\n");
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

//��ȡ��i��Ԫ�ص�����
Status linkedListget(LNode* L, int index) {
	empty(L);
	int x = linkedListlength(L);
	if (index < 1 || index>x) {
		printf("�����index���Ϸ�\n");
		return ERROR;
	}
	LNode * node = L->next;
	for (int i = 1; i < index; i++) {
		node = node->next;
	}
	printf("\n");
	printf("Ԫ�ص����ݣ�%d\n", node->data);
	return SUCCESS;
}

//�������ݲ���Ԫ������
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
	printf("Ԫ�ص����ݣ�%d  ������Ϊ��%d\n",node->data,i);
	return SUCCESS;
}

//��ת����
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

//��i������һ�����
Status InsertAti(LNode * L, int index, int data) {
	int x = linkedListlength(L);
	empty(L);
	if (index < 1 || index>x) {
		printf("�����index���Ϸ�\n");
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
	//Ҫ����Ľ��
	LNode* tem = (LNode*)malloc(sizeof(LNode));
	tem->data = data;
	node->pre->next = tem;
	tem->pre = node->pre;
	tem->next = node;
	node->pre = tem;
	return SUCCESS;
}

//��������
void DestroyList(LNode* L) {
	LNode* p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
}

//������ӡ����
void print(LNode* L) {
	LNode* node = L->next;
	while (node) {
		printf("%d <=>", node->data);
		node = node->next;
	}
	printf("NULL");
	printf("\n");
}
