#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\96556\Desktop\QG\QGѵ��Ӫ��һ����ѵ\QGѵ��Ӫ��һ����ѵ\�����ͷ�ļ�\duLinkList\duLinkedList.c"

int main() {
	printf("\t\t----------------------��ӭ����kanggege��˫����ϵͳ----------------------\n");
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
		printf("\t\t��ѡ��Ҫ����ʲô����(����1-7)��\n");
	    printf("\t\t1����ʼ������\n");
	    printf("\t\t2���������\n");
	    printf("\t\t3�����ǰ����\n");
	    printf("\t\t4��ɾ�����\n");
	    printf("\t\t5����������\n");
	    printf("\t\t6����������\n");
	    printf("\t\t7���˳�\n");
	    
	    do {
			choice = scanf("%d",&temp);
			if (choice == 0) {
					fflush(stdin);
					printf("��������ȷ�����ְ���\n");
				}
				else 
				{
					choice = temp;
					break;	
				}
		}while (choice == 0);
		
		if(choice<=0||choice>7)
        { 	
            printf("��������ȷ�����ְ���\n");continue;
        }
		
		 switch (choice)
		 {
		 	case 1:
		 		if (InitList_DuL(&head) == SUCCESS)
		 		{
				 	printf("��ʼ���ɹ���\n");
				 	isInit = 1;
				 	break;
				}
		 	case 2:
		 		if (isInit == 0) {
					printf("����δ��ʼ����\n");
					break;
				}
		 		p = q = (DuLinkedList)malloc(sizeof(DuLNode));
		 		p = head;
		 		len = GetListSize(head);
		 		printf("������Ҫ�����ĸ�λ�ú�:");
		 		index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("��������ȷ�����ְ���\n");
						break;
				}
				else index = temp;
				if (index<0||index>len) {
					printf("��λ��û�н�㰡��\n");
					break;
				}
		 		for (i=0;i<index-1;i++)
		 		p = p->next;
		 		
		 		printf("������Ҫ��������ݣ�");
                if ((q->data = scanf("%d",&temp)) == 0)
                {
					printf("����ʧ�ܣ��뱣֤�����������������\n");
					fflush(stdin);
					break;
				}
                else q->data = temp;
				q->next = NULL;
				q->prior = NULL;
				if (InsertAfterList_DuL(p, q) == SUCCESS) printf("����ɹ���\n");
				else printf("����ʧ�ܣ�\n"); 
				break;
			case 3:
					if (isInit == 0) {
					printf("����δ��ʼ����\n");
					break;
				}
				p = q = (DuLinkedList)malloc(sizeof(DuLNode));
		 		p = head;
		 		len = GetListSize(head);
		 		printf("������Ҫ�����ĸ�λ��ǰ:");
		 		index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("��������ȷ�����ְ���\n");
						break;
				}
				else index = temp;
				if (index<=0||index>len) {
					printf("��λ��û�н�㰡��\n");
					break;
				}
		 		for (i=0;i<index-1;i++)
		 		p = p->next;
		 		
		 		printf("������Ҫ��������ݣ�");
                if ((q->data = scanf("%d",&temp)) == 0)
                {
					printf("����ʧ�ܣ��뱣֤�����������������\n");
					fflush(stdin);
					break;
				}
                else q->data = temp;
				q->next = NULL;
				q->prior = NULL;
				if (InsertBeforeList_DuL(p, q) == SUCCESS) 
				{
					printf("����ɹ���\n");
					if (p == head) head = q;
				}
				else printf("����ʧ�ܣ�\n");
				break;
				
			case 4:
					if (isInit == 0) {
					printf("����δ��ʼ����\n");
					break;
				}
				index = 0;
				e = 0;
				p = head;
				len = GetListSize(head);
				printf("������Ҫɾ�������ݵ�λ�ã�");
				scanf("%d",&index);
				if (index == 1) {
					printf("����ɾ��ͷ��㣡\n");
					break;
				} 
				if (index<=0||index>len) {
					printf("��λ��û�н�㰡��\n");
					break;
				}
				for (i=1;i<index-1;i++)
		 		p = p->next;
		 		if (DeleteList_DuL(p, &e) == SUCCESS) printf("ɾ���ɹ���\n");
		 		else printf("ɾ��ʧ�ܣ�\n");
		 		break;
		 	case 5:
		 			if (isInit == 0) {
					printf("����δ��ʼ����\n");
					break;
				}
		 		DestroyList_DuL(&head);
				 printf("�������ٳɹ���\n");
				 isInit = 0;
				 break;
		 	case 6:
		 			if (isInit == 0) {
					printf("����δ��ʼ����\n");
					break;
				}
			 	TraverseList_DuL(head,visit);break;
			case 7:
				return 0;
		 } 
	}
	return 0;
}
