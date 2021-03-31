#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"


//��ʼ������
LNode* initlist() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->data = 0;
	L->next = NULL;
	return L;
}

//���������������ͺͳ����Ƿ���ȷ
int chk_data(char *num) {
	int i;
	for (i = 0; num[i]; i++) { 
		if (num[i] > '9' || num[i] < '0') {
			printf("\n����ֵ���з���ֵ\n");
			return 0;
		}
	}
	if (i > 10) { 
		printf("\n���������ֳ���\n");
		return 0;
	}
	return 1;
}

//ͷ������
Status InsertAthead(LNode* L, int data) {
	if(L==0) {
		printf("δ��ʼ������\n");
		return ERROR;
	}
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->next = L->next;
	node->data = data;
	L->next = node;
	return SUCCESS;
}

//β������
Status InsertAttail(LNode* L, int data) {
	if(L==NULL) {
		printf("δ��ʼ������\n");
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

//�ж������Ƿ�Ϊ��
void empty(LNode* L) {
	if (L->next == NULL) {
		printf("\n");
		printf("������Ϊ��\n");
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

//��i������һ�����
Status InsertAti(LNode* L, int index,int data) {
	int x = linkedListlength(L);
	empty(L);
	if (index < 1 || index>x) {
		printf("\n�����index���Ϸ�\n");
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
	//Ҫ����Ľ��
	LNode* tem = (LNode*)malloc(sizeof(LNode));
	tem->data = data;
	tem->next = node->next;
	node->next = tem;
	return SUCCESS;
}

//ɾ�����
Status deleteAti(LNode* L,int index) {
	int x = linkedListlength(L);
	empty(L);
	if (index < 1 || index>x) {
		printf("\n�����index���Ϸ�\n");
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
	//Ҫɾ���Ľ��
	LNode* tem = node->next;
	node->next = tem->next;
	free(tem);
	return SUCCESS;
}

//��ȡ��i��Ԫ�ص�����
Status linkedListget(LNode* L,int index) {
	empty(L);
	int x = linkedListlength(L);
	if (index < 1||index>x) {
		printf("\n�����index���Ϸ�\n");
		return ERROR;
	}
	LNode* node = L->next;

	for (int i = 1; i <index; i++) {
		node = node->next;
	}
	printf("\n");
	printf("Ԫ�ص����ݣ�%d\n", node->data);
	return SUCCESS;
}

//�������ݲ���Ԫ������
Status SearchList(LNode* L, ElemType e) {
	if(L->next==NULL||L==NULL) {
		printf("\n����Ϊ��\n");
		return ERROR;
	}
	LNode*node=L->next;
	int i=1;
	while(node->data!=e) {
		node = node->next;
		i++;
		if(node==NULL) {
			printf("\nû�������ҵ�����\n");
			return ERROR;
		}
	}
	printf("Ԫ�ص����ݣ�%d  ������Ϊ��%d\n",node->data,i);
	return SUCCESS;
}

//��ת����
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

//�ҵ��м���
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
	printf("λ�����м���������ǣ�%d\n", slow->data);
	printf("λ�����м����λ���ǣ�%d\n", i);
}

//�ж������Ƿ�ɻ�
void IsLoopList (LNode* L) {
	if (L==NULL||L->next == NULL) {
		printf("\n������Ϊ��\n");
		return;
	}
	LNode*fast=L->next;
	LNode*slow=L;
	while(slow!=fast) {
		if(fast==NULL||fast->next==NULL) {
			printf("\n�����ɻ�\n");
			return;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("\n����ɻ�\n");
	return ;
}

//�������
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

//��������
void DestroyList (LNode* L) {
	LNode* p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
	L==NULL;
	printf("\n�������ٳɹ�\n");
	printf("\n�����[1]�������³�ʼ������");
}

//������ӡ����
void print(LNode* L) {
	if (L==NULL) {
		printf("\n");
		printf("������Ϊ��\n");
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
