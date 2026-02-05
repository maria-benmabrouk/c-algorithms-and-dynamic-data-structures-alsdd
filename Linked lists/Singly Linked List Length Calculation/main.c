#include<stdio.h>
#include<stdlib.h>
struct table{
int value;
struct table* next_table;
};
int length_list(struct table*head){
    int count=0;
    struct table* ptr=head;
 while(ptr!=NULL){
    count +=1;
    ptr=ptr->next_table;
 };
 return count;
};
int main(){
struct table* head=malloc(sizeof(struct table));
int n=0;
if(head==NULL){
    printf("error");
    return 1;
}
printf("enter the number\t");
scanf("%d",&n);
struct table* ptr=head;
struct table*p;
for(int i=1;i<=n;i++){
  printf("enter the value %d :  ",i);
  scanf("%d",&ptr->value);
  if(i!=n){
  ptr->next_table=malloc(sizeof(struct table));
  ptr=ptr->next_table;};
};
p=ptr;
p->next_table=NULL;
printf("the lenght of the list is %d ",length_list(head));

  ptr=head;
  struct table * pt=ptr;
while(ptr!=NULL){
  pt=ptr;
  ptr=ptr->next_table;
  free(pt);
};
return 0;
}
