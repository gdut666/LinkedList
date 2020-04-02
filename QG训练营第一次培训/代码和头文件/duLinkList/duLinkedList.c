#include "C:\Users\96556\Desktop\QG\QG训练营第一次培训\QG训练营第一次培训\代码和头文件\head\duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	Status ret = ERROR;
	*L = (DuLinkedList)malloc(sizeof(DuLinkedList));
	if(*L)
	ret = SUCCESS;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	(*L)->data = 0;
	return ret;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
	while(*L) {
		p = (*L)->next;
		free(*L);
		*L = p;
		if(p)
			p->prior = NULL;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	Status ret = ERROR;
	if(p) ret = SUCCESS;
	if (p->prior)
	{
		p->prior->next = q;
		q->prior = p->prior;
	}
	p->prior = q;
	q->next = p;
	return ret;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	Status ret = ERROR;
	if(p)
		ret =  SUCCESS;
	if(p->next){
		p->next->prior = q;
		q->next = p->next;
	}
	q->prior = p;
	p->next = q;
	return ret;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	Status ret = ERROR;
	if(p)
	{
		ret = SUCCESS;
		DuLNode *q;
		if (p->next&&p->next->next)
		{
			q = p->next;
			*e = q->data;
			q->next->prior = p;
			p->next = q->next;
			free(q);
		} else if (p->next)
			{
				q = p->next;
				free (q);
				p->next = NULL;		
			}
	}
	return ret;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p;
	p = L;
	while(p){
		(*visit)(p->data);
		p = p->next;
	}
}

void visit(ElemType e)
{
	printf("    %d\n",e);
}

int GetListSize(DuLinkedList L) {
	DuLNode *p = L;
	int cnt = 0;
	while (p) {
		cnt++;
		p = p->next;
	}
	return cnt;
}
