#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
#define SIZE 10

int main() {
	LNode* L = initlist();
	int chk_data(char *num);
	char str[SIZE];
	printf("����������(����0,��������):");
	while(1) {
		scanf("%s", &str);
		if (chk_data(str) == 0) {
			printf("�������ݴ������������룡\n");
			continue;
		}
		if(atoi(str)==0) {
			break;
		}
		int a=atoi(str);
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
		printf("[9]��������                   [10]��ת����\n");
		int k;
		printf("��������Ҫִ�еĲ�����Ӧ�����֣�");
		scanf("%d", &k);
		switch (k) {
			case 1: {
				LNode* L = initlist();
				break;
			}
			case 2: {
				int chk_data(char *num);
				char str[SIZE];
				printf("����������(����0,��������):");
				while(1) {
					scanf("%s", &str);
					if (chk_data(str) == 0) {
						printf("�������ݴ������������룡\n");
						continue;
					}
					if(atoi(str)==0) {
						break;
					}
					int j=atoi(str);
					InsertAthead(L, j);
				}
				printf("\n");
				print(L);
				break;
			}
			case 3: {
				int chk_data(char *num);
				char str[SIZE];
				printf("����������(����0,��������):");
				while(1) {
					scanf("%s", &str);
					if (chk_data(str) == 0) {
						printf("�������ݴ������������룡\n");
						continue;
					}
					if(atoi(str)==0) {
						break;
					}
					int j=atoi(str);
					InsertAttail(L, j);
				}
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
				int x= linkedListlength(L);
				printf("\n");
				printf("�����ȣ�%d\n", x);
				break;
			}
			case 6: {
				int j,h;
				printf("������������");
				scanf("%d", &h);
				printf("���������ݣ�");
				while(1) {
					scanf("%s", &str);
					if (chk_data(str) == 0) {
						printf("�������ݴ������������룡\n");
						continue;
					}
					if(atoi(str)==0) {
						break;
					}
					int j=atoi(str);
					InsertAti(L, h, j);
				}
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
				int chk_data(char *num);
				char str[SIZE];
				printf("����������:");
				scanf("%s", &str);
				if (chk_data(str) == 0) {
					printf("\n�������ݴ�������������!\n");
					break;
				}
				int j=atoi(str);
				SearchList(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 9: {
				DestroyList(L);
				printf("\n");
				break;
			}
			case 10: {
				ReverseList(L);
				printf("\n");
				print(L);
				break;
			}
			default:
				break;
		}
	}
}
