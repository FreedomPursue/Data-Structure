/******************
**********相比单链表的改进******************
**********1 create note function
**********2 InsertTail func(pHeader,*new)
**********3 InsertTail部分，画图分析，把链表线连起来
**********4 注意赋值的方向逻辑，是已于节点赋值给新的指针
************************************/

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
            return -1;
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
	new->prev = p;		
	//p = new->prev;//曾这样赋值过，写反了，想想为什么会写反。
    return new;
}


int main(void)
{
	/******************second key： create_header_node**********************/
	/************************pHeader得指向头结点，才保证头指针，指针域不为空******/
	struct node *p = (struct node*) malloc(sizeof(struct node));
    if(NULL == p){
        printf("error\n");
        return -1;
    }
    p->data = 1;
	p->prev = NULL;
    p->next = NULL;
    pHeader = p;
	
	pHeader->next = CreateNode(2);
	pHeader->next->next = InsertTail(CreateNode(3));
	//pHeader->next->next = InsertTail(CreateNode(3));
	printf("pHeader->next->next->data = %d\n",pHeader->next->next->data);
	printf("pHeader->next->next->prev->data = %d\n",pHeader->next->next->prev->data);
	return 0;
		
}
