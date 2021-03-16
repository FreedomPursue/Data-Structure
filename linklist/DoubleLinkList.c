/*
*相比单链表的改进
*create note function
*InsertTail func(pHeader,*new)
*InsertTail部分，画图分析，把链表线连起来
*InsertNode部分，理解以谁为研究对象
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node *prev;
	struct node *next;
}Node;

struct node *pHeader = NULL;//first key 定义头指针

/********************** create_node******************************/
struct node* CreateNode(int dat)
{
	struct node *p = (struct node *) malloc (sizeof(struct node));
        if(NULL == p){
            printf("error\n");
            exit(0);
        }
        p->data = dat;
		p->next = NULL;
		p->prev = NULL;
		return p;
}

struct node* InsertTail(struct node *new)
{
    struct node *p = (struct node *) malloc(sizeof(struct node));
        p = pHeader;
    while(1)
    {
        if(NULL != p->next){
            p = p->next;
            printf("p->data = %d\n",p->data);
         }
        if(NULL == p->next){
            printf("insert null\n");
            break;
        }
     
    }
    p->next = new;
	//时刻谨记，本质是节点挂接，所以一般都是节点赋值给指针指向
	new->prev = p;
    return new;
}


struct node* InsertHeader(struct node* pHeader,struct node *new)
{
	/********其他节点挂接到new节点的前驱和后继******/
	new->next = pHeader->next; // Research obj:new->next
	new->prev = pHeader; 	//Research obj:new->prev
	/********new节点挂接到其他节点的前驱和后继******/
	pHeader->next->prev = new; //Research obj: new
	pHeader->next = new;  //Research obj: new
	//new->data = data;
	return new;

}
// add(List *list, List *node)
struct node* InsertNode(struct node* node,struct node *new)
{
	/********其他节点挂接到new节点的前驱和后继******/
	new->next = node->next; // Research obj:new->next
	new->prev = node; 	//Research obj:new->prev
	/********new节点挂接到其他节点的前驱和后继******/
	node->next->prev = new; //Research obj: new
	node->next = new;  //Research obj: new
	//new->data = data;
	return new;

}

int main(void)
{
	/******************second key： create_header_node**********************/
	/************************pHeader得指向头结点，才保证头指针，指针域不为空******/
	struct node *p = (struct node*) malloc(sizeof(struct node));
	struct node *locationNode1;
	struct node *locationNode2;
    if(NULL == p){
        printf("error\n");
        return -1;
    }
    p->data = 1;
	p->prev = NULL;
    p->next = NULL;
    pHeader = p;
	
	locationNode1 = pHeader->next = CreateNode(2);
	pHeader->next->next = CreateNode(3);
	#if 1
	pHeader->next->next->next = InsertNode(locationNode1,CreateNode(10));//lzy debug
	#endif 
	printf("pHeader->next->data = %d\n",pHeader->next->data);
	printf("pHeader->next->next->data = %d\n",pHeader->next->next->data);
	printf("pHeader->next->next->next->data = %d\n",pHeader->next->next->next->data);
	return 0;
		
} 
