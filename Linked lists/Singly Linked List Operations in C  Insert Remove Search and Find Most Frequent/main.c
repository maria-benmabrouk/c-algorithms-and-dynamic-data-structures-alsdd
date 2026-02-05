#include<stdio.h>
#include<stdlib.h>
struct node{
int value;
struct node*next;
};
void Allocate(struct node** p){
  *p=(struct node*)malloc(sizeof(struct node));
}
void Ass_val(struct node* p,int val){
 p->value=val;
}
void Ass_adr(struct node*p,struct node*q){
 p->next=q;
}
int CreateList(struct node**head,int size){
struct node* p,*q;
int val=0;
for(int i=1;i<=size;i++){
  Allocate(&p);
  if(p==NULL){
    puts("error");;
    return 1;
  }
  puts("\n enter the value");
  scanf("%d",&val);
  Ass_val(p,val);
  if(i==1){
    *head=p;
  }
  else{
    Ass_adr(q,p);
  }
  q=p;
};
q->next=NULL;
return 0;
}
void DisplayList(struct node*head){
  struct node*p=head;
  while(p!=NULL){
    printf("\n the value is %d",p->value);
    p=p->next;
  }
}
struct node* next_node(struct node*p){
    if(p==NULL){
        return NULL;
    }
return p->next;
};
int most_frequent(struct node* head){
    if (head==NULL){
        printf("the list is empty");
        return -1;
    }
    int n=0,val=0;
    struct node*p=head;
    while(p!=NULL){
        int i=1;
        int l=p->value;
        struct node*q=p->next;
        while(q!=NULL){
            if(q->value==l){
                i++;
            };
            q=q->next;
        }
        if(i>n){
        n=i;
        val=l;
        }
        p=p->next;
    }
return val;
}
struct node* addr_value(struct node*head,int val){
  struct node*p=head;
  while(p!=NULL){
    if(p->value==val){
        return p;
    };
    p=p->next;
  }
  return NULL;
};
void remove_value(struct node**head,int val,int all){
    struct node*p=*head,*q=NULL;
    while(p!=NULL){
        if(p->value==val){
            if(q==NULL){
             *head=p->next;
            }
            else{
                Ass_adr(q,p->next);
            }
             struct node*cpt=p;
             p=p->next;
             free(cpt);
             if(!all){break;}
        }
        else{
         q=p;
         p=p->next;
        }
    }
}
int main(){
struct node* head;
int size=0;
first:
puts("enter the size");
scanf("%d",&size);
if(size<=0){
    goto first;
};
CreateList(&head,size);
DisplayList(head);
int val1=0,all=0;
puts("\n enter the value that you need to remove it");
scanf("%d",&val1);
second:
puts("\n Enter your choice 0-only first value 1-all values");
scanf("%d",&all);
if(all<0 || all>1){goto second ;};
remove_value(&head,val1,all);
DisplayList(head);
printf("\n the most_frequent is %d \n",most_frequent(head));
DisplayList(head);
return 0;
}
