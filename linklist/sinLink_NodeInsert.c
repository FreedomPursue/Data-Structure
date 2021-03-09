#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	
	int data;
	struct Node *pnext;

} Linklist;

Linklist *pheader = NULL; // null poiner

Linklist* CreateNode(int data)
{

	Linklist *p = (Linklist *)malloc(sizeof(Linklist));
	if(p != NULL){
		p->data = data;
		p->pnext = NULL;
	}
	return p;
}

Linklist* InsertTail(Linklist* newnode,int data)
{
	Linklist *p = pheader;
	Linklist *newp = (Linklist *)malloc(sizeof(Linklist));
	newnode = newp;
	while(p != NULL)
	{
		p =  p->pnext;
	}

	newnode->pnext = NULL;
	newnode->data = data;
	p = newnode;
	return newnode;
}

Linklist* InsertNode(Linklist *newnode,int i,int data)
{
	Linklist *p = pheader;
	Linklist *node = (Linklist *)malloc(sizeof(Linklist));
	newnode = node; // malloc pointer to stack pointer
	if(p != NULL)
	{
		for(int j =0; j< i ;j++)
		{	
		p = p->pnext;			
		}
		node->pnext = p->pnext; // fisrt
		p->pnext = node; 	//second
		node->data = data;
	
	return newnode;
	}
}

int main(void){

	Linklist *p = (Linklist *)malloc(sizeof(Linklist));
	int data = 2;
	p->data = 1;
	p->pnext = NULL;
	pheader = p;
	Linklist *node,*newnode, *insertnode;
	pheader->pnext = CreateNode(data);
	pheader->pnext->pnext = InsertTail(newnode,3);
	pheader->pnext->pnext->pnext = InsertTail(newnode,4);
	InsertNode(insertnode,0,5);
	printf("pheader->data = %d\n",pheader->data);
	printf("pheader->pnext->data = %d\n",pheader->pnext->data);
	printf("pheader->pnext->pnext->data = %d\n",pheader->pnext->pnext->data);
	printf("pheader->pnext->pnext->pnext->data = %d\n",pheader->pnext->pnext->pnext->data);
	printf("pheader->pnext->pnext->pnext->pnext->data = %d\n",pheader->pnext->pnext->pnext->pnext->data);
	free(p);
	return 0;
}
