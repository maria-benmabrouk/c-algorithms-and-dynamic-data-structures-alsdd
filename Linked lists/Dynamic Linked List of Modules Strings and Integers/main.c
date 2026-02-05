#include<stdio.h>
#include<stdlib.h>
struct Module{
    char var_string[30];
    int var_int;
    struct Module * next;

};
int main(){
    int choice=0;
struct Module *head=NULL;
head=(struct Module*)malloc(sizeof(struct Module));
struct Module *ptr=head;
 printf("enter the string \n");
 scanf("%s",ptr->var_string);
 printf("enter the integer \n");
 scanf("%d",&ptr->var_int);
first:
printf("what is your choice?\n");
printf("1-add a list\n ");
printf("2-End\n");
scanf("%d",&choice);
switch (choice){
case 1:
  ptr->next=(struct Module *)malloc(sizeof(struct Module));
  ptr=ptr->next;
   printf("enter the string \n");
 scanf("%s",ptr->var_string);
 printf("enter the integer \n");
 scanf("%d",&ptr->var_int);
goto first;
case 2:
    ptr->next=NULL;
    printf("the end");
break;
default: goto first;
};
puts("\n------------------the list------------------");
int count=0;
ptr=head;
while(ptr!=NULL){
 count++;
 printf("\n%d =====>",count);
 printf("%s =====> ",ptr->var_string);
 printf("%d =====> ",ptr->var_int);
 printf("%p",ptr->next);
 ptr=ptr->next;
};
/*puts("---------------------------------------------");
struct Module *add=(struct Module*)malloc(sizeof(struct Module));
ptr=head;
add->next=ptr;
head=&add;*/
return 0;
}
