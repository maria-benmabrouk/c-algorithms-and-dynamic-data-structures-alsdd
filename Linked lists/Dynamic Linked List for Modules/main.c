#include<stdio.h>
#include<stdlib.h>
struct module{
    int number;
    struct module*next;
};
int main(){
    struct module*head=NULL;
    head=malloc(sizeof(struct module));
    struct module*ptr=head;
      int i=0;
  do{  printf("enter the number");
    scanf("%d",&ptr->number);
    printf("%d",ptr->number);
    i=0;
    puts("\n do you want to add a new module\n");
    printf("select 1-yes , 2-no\n");
    scanf("%d",&i);
    switch(i){
case 1:
    ptr->next=malloc(sizeof(struct module));
    ptr=ptr->next;

    break;
case 2:
     ptr->next=NULL;
    break;
default:
    continue;
    break;

    };
  }while(i!=2);

return 0;
}
