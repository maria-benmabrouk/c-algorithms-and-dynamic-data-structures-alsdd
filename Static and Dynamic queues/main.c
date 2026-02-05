#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
                                                  Queues static implementation
*/
//Queues static implementation : using shifts
typedef struct{
    int tab[max];
    int tail;
}queue1;
void create_queue1(queue1*q){
    q->tail=-1;
}
void enqueue1(queue1 *q,int val){
    if(q->tail==max-1){
        printf("the queue is full\n");
        return;
    }
    q->tail++;
    q->tab[q->tail]=val;
}
void dequeue1(queue1* q,int* value){
    if(q->tail==-1){
        printf("the queue is empty\n");
        return;
    }
    (*value)=q->tab[0];
    for(int i=0;i<q->tail;i++){
       q->tab[i]=q->tab[i+1];
    }
    q->tail--;
}
void display1(queue1*q){
        if((q->tail)==-1){
        printf("the queue is empty\n");
        return;
    }
    for(int i=0;i<=q->tail;i++){
        printf("the value %d is %d\n",i,q->tab[i]);
    }


}
//Queues static implementation : standard approach using circular arrays
typedef struct{
    int tab[max];
    int tail;
    int head;
}queue2;
void create_queue2(queue2*q){
    q->tail=2;
    q->head=2;
}
int isempty(queue2*q){
    if(q->head==q->tail){
        return 1;
    }
    return 0;
}
int isfull(queue2*q){
    if(q->head==(q->tail+1)%max){
        return 1;
    }
    return 0;
}
void enqueue2(queue2 *q,int val){
    if(isfull(q)){
        printf("the queue is full\n");
        return;
    }
    q->tab[q->tail]=val;
    q->tail=(q->tail+1)%max;
}
void dequeue2(queue2* q,int* value){
    if(isempty(q)){
        printf("the queue is empty\n");
        return;
    }
    (*value)=q->head;
    q->head=(q->head+1)%max;
}
void display2(queue2*q){
    if(isempty(q)){
        printf("the queue is empty\n");
        return;
    }
    int i=q->head;
    while(i!=q->tail){
        printf("the value is %d\n",q->tab[i]);
        i=(i+1)%max;
    }
}
/*
                                           Queues static implementation
*/
typedef struct Node{
    int value;
    struct Node*next;
}*node;
typedef struct{
    node head,tail;
}queue;
void create_queue(queue*q){
    q->head=NULL;
    q->tail=NULL;
}
int EmptyQueue(queue*q){
    if(q->head==NULL && q->tail==NULL){
        return 1;
    }
    return 0;
}
int FullQueue(queue*q){
    return 0;
}
void Enqueue(queue*q,int val){
    node p;
    p=malloc(sizeof(node));
    p->next=NULL;
    p->value=val;
    if(q->head==NULL){
        q->head=p;
        q->tail=p;
        return;
    }
    q->tail->next=p;
    q->tail=p;
}
void Dequeue(queue*q,int*val){
    if(EmptyQueue(q)){
            printf("the queue is empty\n");
            return;
    }
    node temp;
    temp=q->head;
    *val=q->head->value;
    q->head=q->head->next;
    free(temp);
    if(q->head==NULL){
        q->tail=NULL;
    }
}
int main()
{
  queue2 q;
  int n=0,val=0;
  create_queue2(&q);
  printf("enter the length of the queue\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("enter the value\n");
    scanf("%d",&val);
    enqueue2(&q,val);
  }
  display2(&q);
    return 0;
}
