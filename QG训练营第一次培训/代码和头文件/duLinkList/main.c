#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\96556\Desktop\QG\QG训练营第一次培训\QG训练营第一次培训\代码和头文件\duLinkList\duLinkedList.c"

int main() {
	printf("\t\t----------------------欢迎来到kanggege的双链表系统----------------------\n");
	printf("\t\t-                                                                      -\n");
	printf("\t\t------------------------------------------------------------------------\n");
	DuLinkedList head;
	int isInit = 0;
	DuLNode *p,*q;
	int e;
	int i;
	int temp;
	int index;
//	DuLNode *p = (DuLinkedList)malloc(sizeof(DuLNode));
//	p->data = 666;
//	p->next = NULL;
//	p->prior = NULL;
//	InitList_DuL(&head); 
//	InsertAfterList_DuL(head, p);
//	TraverseList_DuL(head,visit);
	int choice;
	int len; 
	while (1)
	{
		printf("\t\t请选择要进行什么操作(输入1-7)：\n");
	    printf("\t\t1、初始化链表\n");
	    printf("\t\t2、结点后插入\n");
	    printf("\t\t3、结点前插入\n");
	    printf("\t\t4、删除结点\n");
	    printf("\t\t5、销毁链表\n");
	    printf("\t\t6、遍历链表\n");
	    printf("\t\t7、退出\n");
	    
	    do {
			choice = scanf("%d",&temp);
			if (choice == 0) {
					fflush(stdin);
					printf("请输入正确的数字啊！\n");
				}
				else 
				{
					choice = temp;
					break;	
				}
		}while (choice == 0);
		
		if(choice<=0||choice>7)
        { 	
            printf("请输入正确的数字啊！\n");continue;
        }
		
		 switch (choice)
		 {
		 	case 1:
		 		if (InitList_DuL(&head) == SUCCESS)
		 		{
				 	printf("初始化成功！\n");
				 	isInit = 1;
				 	break;
				}
		 	case 2:
		 		if (isInit == 0) {
					printf("链表未初始化！\n");
					break;
				}
		 		p = q = (DuLinkedList)malloc(sizeof(DuLNode));
		 		p = head;
		 		len = GetListSize(head);
		 		printf("请输入要插在哪个位置后:");
		 		index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("请输入正确的数字啊！\n");
						break;
				}
				else index = temp;
				if (index<0||index>len) {
					printf("该位置没有结点啊！\n");
					break;
				}
		 		for (i=0;i<index-1;i++)
		 		p = p->next;
		 		
		 		printf("请输入要插入的数据：");
                if ((q->data = scanf("%d",&temp)) == 0)
                {
					printf("插入失败！请保证你输入的是整数啊！\n");
					fflush(stdin);
					break;
				}
                else q->data = temp;
				q->next = NULL;
				q->prior = NULL;
				if (InsertAfterList_DuL(p, q) == SUCCESS) printf("插入成功！\n");
				else printf("插入失败！\n"); 
				break;
			case 3:
					if (isInit == 0) {
					printf("链表未初始化！\n");
					break;
				}
				p = q = (DuLinkedList)malloc(sizeof(DuLNode));
		 		p = head;
		 		len = GetListSize(head);
		 		printf("请输入要插在哪个位置前:");
		 		index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("请输入正确的数字啊！\n");
						break;
				}
				else index = temp;
				if (index<=0||index>len) {
					printf("该位置没有结点啊！\n");
					break;
				}
		 		for (i=0;i<index-1;i++)
		 		p = p->next;
		 		
		 		printf("请输入要插入的数据：");
                if ((q->data = scanf("%d",&temp)) == 0)
                {
					printf("插入失败！请保证你输入的是整数啊！\n");
					fflush(stdin);
					break;
				}
                else q->data = temp;
				q->next = NULL;
				q->prior = NULL;
				if (InsertBeforeList_DuL(p, q) == SUCCESS) 
				{
					printf("插入成功！\n");
					if (p == head) head = q;
				}
				else printf("插入失败！\n");
				break;
				
			case 4:
					if (isInit == 0) {
					printf("链表未初始化！\n");
					break;
				}
				index = 0;
				e = 0;
				p = head;
				len = GetListSize(head);
				printf("请输入要删除的数据的位置：");
				scanf("%d",&index);
				if (index == 1) {
					printf("请勿删除头结点！\n");
					break;
				} 
				if (index<=0||index>len) {
					printf("该位置没有结点啊！\n");
					break;
				}
				for (i=1;i<index-1;i++)
		 		p = p->next;
		 		if (DeleteList_DuL(p, &e) == SUCCESS) printf("删除成功！\n");
		 		else printf("删除失败！\n");
		 		break;
		 	case 5:
		 			if (isInit == 0) {
					printf("链表未初始化！\n");
					break;
				}
		 		DestroyList_DuL(&head);
				 printf("链表销毁成功！\n");
				 isInit = 0;
				 break;
		 	case 6:
		 			if (isInit == 0) {
					printf("链表未初始化！\n");
					break;
				}
			 	TraverseList_DuL(head,visit);break;
			case 7:
				return 0;
		 } 
	}
	return 0;
}
