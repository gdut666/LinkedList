#include "C:\Users\96556\Desktop\QG\QGѵ��Ӫ��һ����ѵ\QGѵ��Ӫ��һ����ѵ\�����ͷ�ļ�\linkList\linkedList.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
	showTitle();		//��ӡ�������С���� 
	int a[]={1,2,3,4,5,6,7,8,9};	//��ͨ�����鴴��һ�����������ڲ��� 
	LNode *p = NULL,*q = NULL;		//��Щ������Ҫ�õ�ָ�����ｨ������ 
	int choice = 0;				//�û��������� ��ѡ���Ӧ�Ĳ��� 
	int index;				//һЩ������Ӧ�Ľ���λ�� 
	int temp = 0;				//һЩ������Ҫ�õ�ֵ 
	int i;					//ѭ�����Ʊ��� 
	int e;					//һЩ������Ҫ����һЩintֵ 
	int len;				//������ 
	LinkedList head;		//��ͷ�����ͷָ�� 
	head = create(a,9);		//��ͨ�����鴴��һ���������ڲ���
	TraverseList(head,visit); 	//�������� 
	
	while(1)	//ͨ��while ��switch case�����в��� 
	{
		showPrompt();	//��ʾ���� 	//�û������������������� 
		
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
		
		if(choice<0||choice>12)
        { 	
            printf("��������ȷ�����ְ���2222\n");continue;
        }
        
        
        
        switch(choice)
        {
        	case 1:	//������ 
        		index = 0;
				len = GetListSize(head); 
        		p = q = (LinkedList)malloc(sizeof(LNode));
				printf("������Ҫ�����ĸ�λ�õĺ��棺");
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
                p = head;
                q->next = NULL;
                printf("������Ҫ��������ݣ�");
                if ((q->data = scanf("%d",&temp)) == 0)
                {
					printf("����ʧ�ܣ��뱣֤�����������������\n");
					fflush(stdin);
					break;
				}
                else q->data = temp;
                for (i=0;i<index-1;i++)
                p = p->next;
                if(InsertList(p,q)==ERROR) printf("����ʧ�ܣ�\n");    //���뺯��
                else printf("����ɹ���\n");
                break;
                
            case 2:		//ɾ����� 
            	index = 0;
            	p = (LinkedList)malloc(sizeof(LNode));
            	p = head;
            	len = GetListSize(head);
            	printf("������Ҫɾ���ĸ�λ�õĽ�㣺");
            	index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("��������ȷ�����ְ���\n");
						break;
				}
				else index = temp;
                if (index<0||index>len) {
					printf("��λ��û�н�㰡��");
					break;
				} else if (index == 1) {
					printf("����ɾ����һ����㣡\n");
					break;
				}
            	for (i=1;i<index-1;i++)
                p = p->next;
                if (DeleteList(p, &e) == ERROR) printf("ɾ��ʧ�ܣ�\n");
                else printf("ɾ���ɹ���\n");
                break;
                
            case 3:		//���ҽ�� 
            	index = 0;
            	e = 0;
				printf("������Ҫ���ҵĽ������ݣ�");
			    e = scanf("%d",&temp);
					if (e == 0) {
						fflush(stdin);
						printf("��������ȷ�����ְ���\n");
						break;
				}
				else e = temp;
			    if (SearchList(head, e ,&index) == ERROR) printf("δ�ҵ��ý�㣡\n");
			    else printf("�ҵ�������������%dλ��\n",index);
			    break;
			    
			case 4:		//�޸Ľ�� 
				index = 0;
				len = GetListSize(head);
            	p = (LinkedList)malloc(sizeof(LNode));
            	p = head;
            	printf("������Ҫ�޸ĵĽڵ��λ�ã�");
            	index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("��������ȷ�����ְ���\n");
						break;
				}
				else index = temp;
                if (index<=0||index>len) {
					printf("��λ��û�н�㰡��");
					break;
				}
            	printf("������Ҫ�޸ĵĽڵ��ֵ��");
            	e = scanf("%d",&temp);
					if (e == 0) {
						fflush(stdin);
						printf("��������ȷ�����ְ���\n");
						break;
				}
				else e = temp;
            	if (UpdateList(head, index,&e) == SUCCESS)
            	printf("�޸ĳɹ���\n");
            	else printf("�޸�ʧ�ܣ�\n");
            	break;
            	
            case 5:		//�������� 
            	DestroyList(&head);
				printf("��������ɹ��������������\n");
				break;
				
			case 6:		//��ת���� 
			if (ReverseList(&head) == SUCCESS) printf("��ת����ɹ���\n");
			else printf("��ת����ʧ�ܣ�\n");break;
			
			case 7:		//������ż��㻥�� 
				ReverseEvenList(&head); 
				printf("������ż��㻥���ɹ���\n");
				break;
			case 8:		//�ж������Ƿ�ɻ� 
				if (IsLoopList(head) == SUCCESS) printf("����ɻ�\n");
				else printf("�����ɻ�\n");break;
				
			case 9:		//�����м�ڵ� 
				index = 0;
				LNode *mid = NULL;
				mid = FindMidNode(&head,&index);
				if (mid) printf("�����м���ɹ���������λ��Ϊ%d, �������Ϊ%d\n",index,mid->data);
				else printf("�����м���ʧ�ܣ�\n");
				break;
				
			case 10: 	//�������� 
				TraverseList(head,visit);break;
			
			case 11:	//��ʼ������ 
			if (InitList(&head) == SUCCESS) printf("��ʼ���ɹ���\n");
			else printf("��ʼ��ʧ�ܣ�\n");break;
			
			case 12: return 0;		//�˳� 
			default : printf("��������ȷ�����ְ���");break;
		}
	}
	return 0;
}




