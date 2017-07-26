#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* insatbeg(struct node*,int);
struct node* insatend(struct node*,int);
struct node* insatmidaf(struct node*,int,int);
struct node* insatmidbef(struct node*,int,int);
struct node* deletebeg(struct node*);
struct node* deletend(struct node*);
struct node* delaf(struct node*,int);
struct node* delbef(struct node*, int);
void printll(struct node*);
int main(){
    int x;
    struct node *start=NULL;
    printf("Enter elements of linked list (-1 to end):");
    scanf("%d",&x);
    while(x!=-1){
        struct node *new_node=malloc(sizeof(struct node));
        if(start==NULL){
            start=new_node;
            new_node->next=NULL;
        }
        else{
            struct node *ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }
        new_node->data=x;
        scanf("%d",&x);
    }
    printll(start);
    printf("Enter element to insert at beginning: ");
    scanf("%d",&x);
    start=insatbeg(start,x);
    printf("New Linked List: ");
    printll(start);
    printf("Enter element to insert at end: ");
    scanf("%d",&x);
    start=insatend(start,x);
    printf("New Linked List: ");
    printll(start);
    printf("Enter element 1 to insert after element 2: ");
    int y;
    scanf("%d %d",&x,&y);
    start=insatmidaf(start,x,y);
    printf("New Linked List: ");
    printll(start);
    printf("Enter element 1 to insert before element 2: ");
    scanf("%d %d",&x,&y);
    start=insatmidbef(start,x,y);
    printf("New Linked List: ");
    printll(start);
    printf("Now first element will be deleted: ");
    start=deletebeg(start);
    printll(start);
    printf("Now last element will be deleted: ");
    start=deletend(start);
    printll(start);
    printf("Enter element to delete after: ");
    scanf("%d",&x);
    start=delaf(start,x);
    printll(start);
    printf("Enter element to delete before: ");
    scanf("%d",&x);
    start=delbef(start,x);
    printll(start);
    return 0;
}
struct node* insatbeg(struct node *start,int x){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->next=start;
    start=newnode;
    newnode->data=x;
    return start;
}
struct node* insatend(struct node *start,int x){
    struct node *newnode=malloc(sizeof(struct node));
    struct node *ptr=start;
    newnode->data=x;
    newnode->next=NULL;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newnode;
    return start;
}
struct node* insatmidaf(struct node *start,int x,int y){
    struct node *newnode=malloc(sizeof(struct node));
    struct node *ptr=start;
    newnode->data=x;
    while(ptr->data!=y)
        ptr=ptr->next;
    newnode->next=ptr->next;
    ptr->next=newnode;
    return start;
}
struct node* insatmidbef(struct node *start, int x, int y){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=x;
    struct node *ptr=start;
    while(ptr->next->data!=y)
        ptr=ptr->next;
    newnode->next=ptr->next;
    ptr->next=newnode;
    return start;
}
void printll(struct node *start){
    struct node *ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node* deletebeg(struct node *start){
    struct node *ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct node* deletend(struct node *start){
    struct node *ptr=start;
    while(ptr->next->next!=NULL)
        ptr=ptr->next;
    free(ptr->next);
    ptr->next=NULL;
    return start;
}
struct node* delaf(struct node *start, int x){
    struct node *ptr=start,*ptr1;
    while(ptr->data!=x)
        ptr=ptr->next;
    ptr1=ptr->next;
    ptr->next=ptr1->next;
    free(ptr1);
    return start;
}
struct node* delbef(struct node *start, int x){
    struct node *ptr=start,*ptr1;
    while(ptr->next->next->data!=x)
        ptr=ptr->next;
    ptr1=ptr->next;
    ptr->next=ptr1->next;
    free(ptr1);
    return start;
}
