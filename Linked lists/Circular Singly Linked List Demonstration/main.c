#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct node{
 int n;
 struct node* next;
};
struct node1{
   struct node1* left;
   int val;
   struct node1* right;
};
#define BLUE "\033[44m"
int main(){

struct node* head=malloc(sizeof(struct node));
int i;
puts(BLUE"enter the size");
scanf("%d",&i);
   if (head==NULL) return -1;
    else{
      struct node* p=head;
      for(int j=0;j<i;j++){
      int l=0;
    printf("enter the value");
    scanf("%d",&l);
    p->n=l;
    p->next=malloc(sizeof(struct node));
    if(j<i-1){
    p=p->next;}
    else{
        p->next=NULL;
    }
      }
      p->next=head;
    }
    struct node* q=head;
for(int k=0 ;k<10 ;k++){
    printf("===> %d \n",q->n);
    if(k<9){
        q=q->next;
    }
}
return 0;
}
