#include "C:\Users\96556\Desktop\QG\QGѵ��Ӫ��һ����ѵ\QGѵ��Ӫ��һ����ѵ\�����ͷ�ļ�\head\linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L) {
	 LinkedList p = (LinkedList)malloc(sizeof(LinkedList));		//����ռ� 
	 Status ret = ERROR;	//��һ���� 
	 p->next = NULL;
	 p->data = 0;
	 *L = p;
	 if (*L)	//�ж��Ƿ������ڴ�ɹ� 
	 	ret = SUCCESS;
	 else 
	 {
	 	ret = ERROR;
	 	printf("Memory allocation failure\n");
	 }
	 return ret; 
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p = NULL;
	LinkedList q = NULL;
	p = *L;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

//LinkedList CreateList(LinkedList* L,int *a) {
//	int i,len = strlen(a);
//	LinkedList p = (LinkedList)malloc(sizeof(LNode));
//	LinkedList q = (*L);
//	for (i=0;i<len;i++)
//	{
//		p->data = *(arr+i);
//		p->next = NULL;
//		
//	}
//}

LinkedList create(int *arr, int n) {
//	Status ret = ERROR;
//	if (*pHead) ret = SUCCESS;
//	int number;
//	LNode *last,*p;
//	last = *pHead;
//	do
//	{
//		printf("please input an interger:");
//		scanf("%d",&number);
//		if (number != 0)
//		{
//			p = (LNode*)malloc(sizeof(LNode));
//			p->data = number;
//			p->next = NULL;
//			while (last->next)
//			last = last->next;
//			last->next = p;
//		}else printf("input ended\n");
//	}while (number != 0);
//	return ret;
	if(arr==NULL) return NULL;  //������Ϊ�����飬����NULL
    int i=0;
    LinkedList p,q,head;   
    p=q=(LinkedList)malloc(sizeof(LNode));
    p->data=*arr;       //��ȡ��������
    while(i<n)
    {
        if(i==0)
        {
            head = p;     //��i=0ʱ��ȡ��ͷָ��
        }
        else
        {
            q->next=p;  //��i!=0ʱ����������
        }
        q=p;i++;
        p=(LinkedList)malloc(sizeof(LNode));
        p->data=*(arr+i);   //��ȡ��һԪ��
    }
    q->next=NULL;   //���һλָ��ָ��NULL
    return(head);   //����ͷָ��
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	Status ret = ERROR;
	if (p)
	{
		ret = SUCCESS;
		q->next = p->next;
		p->next = q;
	}
	return ret;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	Status ret = ERROR;
	if (p && p->next)
	{
		ret = SUCCESS;
		LNode *q = NULL;
		q = p->next;
		*e = q->data;
		p->next = q->next;
		free(q);
	}
	return ret;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L,void (*visit)(ElemType e)) {
//	LNode *p;
//	int cnt = 0;
//	if (L->data == 0)
//	p = L->next;
//	else p = L;
//	while (p)
//	{
//		cnt++;
//		printf("The %4d data is %d\n",cnt,p->data);
//		p = p->next;
//	}
	LNode *p;
	p = L;
	int cnt = 0;
	while(p){
		cnt++;
		printf("The %d data is:",cnt);
		visit(p->data);
		p = p->next;
	}	
}

void visit(ElemType e) {
	printf("%d \n",e);
}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e,int *index) {
	Status ret = ERROR;
	int cnt = 1;
	LNode *p;
	p = L;
	while (p)
	{
		if(p->data == e)
		{
			ret = SUCCESS;
			break;
		}
		else {
			p = p->next;
			cnt++;
		}
	}
	*index = cnt;
	return ret;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	Status ret = ERROR;
	LNode *pPre,*pCurr,*pNext;
	if ((*L) && (*L)->next)
	{
		ret = SUCCESS;
		pPre = *L;
		pCurr = (*L)->next;
		(*L)->next = NULL;
		while (pCurr)
		{
			pNext = pCurr->next;
			pCurr->next = pPre;
			pPre = pCurr;
			pCurr = pNext;
		}
		(*L) = pPre;
	}
	return ret;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	Status ret = ERROR;
	LNode *pFast,*pSlow;
	pFast = pSlow = L;
	while (pFast && pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if (pSlow == pFast)
		{
			ret = SUCCESS;
			break;
		}
	}
	return ret;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *pPre,*pCurr,*pNext;
	if (*L && (*L)->next)
	{
		pPre = *L;
		*L = pPre->next;
		while (pPre && pPre->next)
		{
			pCurr = pPre->next;
			pNext = pCurr->next;
			if (pCurr->next && pCurr->next->next)
			pPre->next = pCurr->next->next;
			else 
			pPre->next = pCurr->next;
			pCurr->next = pPre;
			pPre = pNext;
		}
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L,int *index) {
	LNode *mid = *L;
	int i;
	int count;
	for ( count=0;mid;count++ )
	{
		mid = mid->next;
	}
	mid = *L;
	for ( i=0;i<count/2;i++)
	mid = mid->next;
	*index = count/2+1;
	return mid;
}

Status UpdateList(LinkedList L,int index,int *value) {
	Status ret = ERROR;
	int i;
	LNode *p = L;
	for (i=0;i<index-1;i++)
	p = p->next;
	p->data = *value;
	if(p) ret = SUCCESS;
	return ret;
}

void showTitle() {
	printf("\t\t----------------------��ӭ����kanggege�ĵ�����ϵͳ----------------------\n");
	printf("\t\t-    ����������Ϊ��ͷ����Ϊ�˷�����������������ʼ����һ������      -\n");
	printf("\t\t------------------------------------------------------------------------\n");
}

void showPrompt() { 
	printf("\t\t��ѡ��Ҫ����ʲô����(����1-12)��\n");
    printf("\t\t1������ڵ�\n");
    printf("\t\t2��ɾ���ڵ�\n");
    printf("\t\t3�����ҽڵ�\n");
    printf("\t\t4���޸Ľڵ�\n");
    printf("\t\t5����������\n");
    printf("\t\t6����ת����\n");
    printf("\t\t7��������ż�ڵ㻥��\n");
    printf("\t\t8���ж������Ƿ�ɻ�\n");
    printf("\t\t9�������м�ڵ�\n");
    printf("\t\t10����ӡ����\n");
    printf("\t\t11����ʼ������\n"); 
    printf("\t\t12���˳�\n");
} 

int GetListSize(LinkedList L) {
	LNode *p = L;
	int cnt = 0;
	while (p) {
		cnt++;
		p = p->next;
	}
	return cnt;
}


