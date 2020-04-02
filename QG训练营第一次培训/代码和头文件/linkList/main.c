#include "C:\Users\96556\Desktop\QG\QG训练营第一次培训\QG训练营第一次培训\代码和头文件\linkList\linkedList.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
	showTitle();		//打印出程序的小介绍 
	int a[]={1,2,3,4,5,6,7,8,9};	//先通过数组创建一个单链表，便于操作 
	LNode *p = NULL,*q = NULL;		//有些操作需要用到指针这里建立两个 
	int choice = 0;				//用户输入数字 以选择对应的操作 
	int index;				//一些操作对应的结点的位置 
	int temp = 0;				//一些数据需要用的值 
	int i;					//循环控制变量 
	int e;					//一些操作需要返回一些int值 
	int len;				//链表长度 
	LinkedList head;		//无头链表的头指针 
	head = create(a,9);		//先通过数组创建一个链表，便于操作
	TraverseList(head,visit); 	//遍历链表 
	
	while(1)	//通过while 和switch case来进行操作 
	{
		showPrompt();	//提示操作 	//用户输入数字来操作链表 
		
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
		
		if(choice<0||choice>12)
        { 	
            printf("请输入正确的数字啊！2222\n");continue;
        }
        
        
        
        switch(choice)
        {
        	case 1:	//插入结点 
        		index = 0;
				len = GetListSize(head); 
        		p = q = (LinkedList)malloc(sizeof(LNode));
				printf("请输入要插在哪个位置的后面：");
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
                p = head;
                q->next = NULL;
                printf("请输入要插入的数据：");
                if ((q->data = scanf("%d",&temp)) == 0)
                {
					printf("插入失败！请保证你输入的是整数啊！\n");
					fflush(stdin);
					break;
				}
                else q->data = temp;
                for (i=0;i<index-1;i++)
                p = p->next;
                if(InsertList(p,q)==ERROR) printf("插入失败！\n");    //插入函数
                else printf("插入成功！\n");
                break;
                
            case 2:		//删除结点 
            	index = 0;
            	p = (LinkedList)malloc(sizeof(LNode));
            	p = head;
            	len = GetListSize(head);
            	printf("请输入要删除哪个位置的结点：");
            	index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("请输入正确的数字啊！\n");
						break;
				}
				else index = temp;
                if (index<0||index>len) {
					printf("该位置没有结点啊！");
					break;
				} else if (index == 1) {
					printf("请勿删除第一个结点！\n");
					break;
				}
            	for (i=1;i<index-1;i++)
                p = p->next;
                if (DeleteList(p, &e) == ERROR) printf("删除失败！\n");
                else printf("删除成功！\n");
                break;
                
            case 3:		//查找结点 
            	index = 0;
            	e = 0;
				printf("请输入要查找的结点的数据：");
			    e = scanf("%d",&temp);
					if (e == 0) {
						fflush(stdin);
						printf("请输入正确的数字啊！\n");
						break;
				}
				else e = temp;
			    if (SearchList(head, e ,&index) == ERROR) printf("未找到该结点！\n");
			    else printf("找到啦！这个结点在%d位置\n",index);
			    break;
			    
			case 4:		//修改结点 
				index = 0;
				len = GetListSize(head);
            	p = (LinkedList)malloc(sizeof(LNode));
            	p = head;
            	printf("请输入要修改的节点的位置：");
            	index = scanf("%d",&temp);
					if (index == 0) {
						fflush(stdin);
						printf("请输入正确的数字啊！\n");
						break;
				}
				else index = temp;
                if (index<=0||index>len) {
					printf("该位置没有结点啊！");
					break;
				}
            	printf("请输入要修改的节点的值；");
            	e = scanf("%d",&temp);
					if (e == 0) {
						fflush(stdin);
						printf("请输入正确的数字啊！\n");
						break;
				}
				else e = temp;
            	if (UpdateList(head, index,&e) == SUCCESS)
            	printf("修改成功！\n");
            	else printf("修改失败！\n");
            	break;
            	
            case 5:		//销毁链表 
            	DestroyList(&head);
				printf("销毁链表成功！请勿遍历链表\n");
				break;
				
			case 6:		//反转链表 
			if (ReverseList(&head) == SUCCESS) printf("反转链表成功！\n");
			else printf("反转链表失败！\n");break;
			
			case 7:		//链表奇偶结点互换 
				ReverseEvenList(&head); 
				printf("链表奇偶结点互换成功！\n");
				break;
			case 8:		//判断链表是否成环 
				if (IsLoopList(head) == SUCCESS) printf("链表成环\n");
				else printf("链表不成环\n");break;
				
			case 9:		//查找中间节点 
				index = 0;
				LNode *mid = NULL;
				mid = FindMidNode(&head,&index);
				if (mid) printf("查找中间结点成功！该所在位置为%d, 结点数据为%d\n",index,mid->data);
				else printf("查找中间结点失败！\n");
				break;
				
			case 10: 	//遍历链表 
				TraverseList(head,visit);break;
			
			case 11:	//初始化链表 
			if (InitList(&head) == SUCCESS) printf("初始化成功！\n");
			else printf("初始化失败！\n");break;
			
			case 12: return 0;		//退出 
			default : printf("请输入正确的数字啊！");break;
		}
	}
	return 0;
}




