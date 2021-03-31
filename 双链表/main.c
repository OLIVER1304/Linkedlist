#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
#define SIZE 10

int main() {
	LNode* L = initlist();
	int chk_data(char *num);
	char str[SIZE];
	printf("请输入数据(输入0,结束输入):");
	while(1) {
		scanf("%s", &str);
		if (chk_data(str) == 0) {
			printf("输入数据错误，请重新输入！\n");
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
		printf("[1]初始化链表                 [2]在头部插入结点\n");
		printf("[3]在尾部插入结点             [4]删除结点\n");
		printf("[5]求链表的长度               [6]在i处插入一个结点\n");
		printf("[7]获取第i个元素的内容        [8]据内容查找元素索引\n");
		printf("[9]销毁链表                   [10]反转链表\n");
		int k;
		printf("请输入需要执行的操作对应的数字：");
		scanf("%d", &k);
		switch (k) {
			case 1: {
				LNode* L = initlist();
				break;
			}
			case 2: {
				int chk_data(char *num);
				char str[SIZE];
				printf("请输入数据(输入0,结束输入):");
				while(1) {
					scanf("%s", &str);
					if (chk_data(str) == 0) {
						printf("输入数据错误，请重新输入！\n");
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
				printf("请输入数据(输入0,结束输入):");
				while(1) {
					scanf("%s", &str);
					if (chk_data(str) == 0) {
						printf("输入数据错误，请重新输入！\n");
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
				printf("请输入索引：");
				scanf("%d", &j);
				deleteAti(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 5: {
				int x= linkedListlength(L);
				printf("\n");
				printf("链表长度：%d\n", x);
				break;
			}
			case 6: {
				int j,h;
				printf("请输入索引：");
				scanf("%d", &h);
				printf("请输入数据：");
				while(1) {
					scanf("%s", &str);
					if (chk_data(str) == 0) {
						printf("输入数据错误，请重新输入！\n");
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
				printf("请输入i：");
				scanf("%d", &j);
				linkedListget(L, j);
				printf("\n");
				print(L);
				break;
			}
			case 8: {
				int chk_data(char *num);
				char str[SIZE];
				printf("请输入数据:");
				scanf("%s", &str);
				if (chk_data(str) == 0) {
					printf("\n输入数据错误，请重新输入!\n");
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
