#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp" 

int main() {
	LNode* L = initlist();
	int a;
	printf("������int��������(���븺��,��������):");
	while(1){
        scanf("%d", &a);
        if(a<0){
           break;
		}
		InsertAttail(L, a);
	}
	printf("\n");
	print(L);
	while (1) {
		printf("\n");
		printf("[1]��ʼ������                 [2]��ͷ��������\n");
		printf("[3]��β��������             [4]ɾ�����\n");
		printf("[5]������ĳ���               [6]��i������һ�����\n");
		printf("[7]��ȡ��i��Ԫ�ص�����        [8]�����ݲ���Ԫ������\n");
		printf("[9]�������                   [10]��������\n");
		printf("[11]��ת����                  [12]�ҵ��м���\n");
		printf("[13]�ж������Ƿ�ɻ�\n");
		printf("\n");
		int k;
		printf("��������Ҫִ�еĲ�����Ӧ�����֣�");
		scanf("%d",&k);
		switch (k) {
			case 1: {
				LNode* L = initlist();
				break;
			}
			case 2: {
				int j;
				printf("���������ݣ�");
				scanf("%d", &j);
				InsertAthead(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 3: {
				int j;
				printf("���������ݣ�");
				scanf("%d", &j);
				InsertAttail(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 4: {
				int j;
				printf("������������");
				scanf("%d", &j);
				deleteAti(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 5: {
				int x =linkedListlength(L);
				printf("\n");
				printf("�����ȣ�%d\n", x);
				break;
			}
			case 6: {
				int j,h;
				printf("������i��");
				scanf("%d", &j);
				printf("���������ݣ�");
				scanf("%d", &h);
				InsertAti(L, j, h);
				printf("\n");
				print(L);
				break;
			}
			case 7: {
				int j;
				printf("������i��");
				scanf("%d", &j);
				linkedListget(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 8: {
				int j;
				printf("���������ݣ�");
				scanf("%d", &j);
				SearchList(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 9: {
				ClearlinkedList(L);
				printf("\n");
				print(L);
				break;
			}
			case 10: {
				DestroyList(L);
				printf("\n");
				break;
			}
			case 11: {
				ReverseList(L);
				printf("\n");
				print(L);
				break;
			}
			case 12: {
			    FindMidNode(L); 
				printf("\n");
				print(L);
				break;
			}
			case 13: {
			   int x=IsLoopList (L);
			   if(x=1){
			   	printf("����ɻ�\n");
			   } else if(x=0){
			    printf("����û�гɻ�\n");
			   } 
				printf("\n");
				print(L);
				break;
			}
		}
	}

}
