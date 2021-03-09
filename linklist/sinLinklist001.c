#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;

struct node *pHeader = NULL;//first key 定义头指针

/********************** create_node******************************/
struct node* CreateLinkList(int dat)
{
	struct node *p = (struct node *) malloc (sizeof(struct node));
        if(NULL == p){
            printf("error\n");
            return -1;
        }
        p->data = dat;
        //pHeader->next = p1;
		return p;
}
/********************* third key: 一定要传参插入的新结点，且新结点必须是数据域和指针域非空************/
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
    p->next = NULL;
    pHeader = p;
	
	pHeader->next = CreateLinkList(2);
	pHeader->next->next = CreateLinkList(3);	
	pHeader->next->next->next = CreateLinkList(4);
    pHeader->next->next->next->next = InsertTail(CreateLinkList(5));
	/*struct node *p2 = (struct node*) malloc(sizeof(struct node));
    if(NULL == p2){
        printf("error\n");
        return -1;
    }
    p2->data = 3;
    pHeader->next->next= p2;	
    */
	printf("pHeader->data = %d\n",pHeader->data);//1
	printf("pHeader->next->data = %d\n",pHeader->next->data);//2
	printf("pHeader->next->next->data = %d\n",pHeader->next->next->data);//3
	printf("pHeader->next->next->next->data = %d\n",pHeader->next->next->next->data);//4
	printf("pHeader->next->next->next->next->data = %d\n",pHeader->next->next->next->next->data);//5



    return 0;
}






