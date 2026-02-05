#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
//lists
typedef struct PhoneList{
       char*Name;
       int PhoneNumber;
       struct PhoneList*next;
}node;
void Allocate(node**head){
(*head)=malloc(sizeof(node));
}
void FreeList(node**head){
  node*p,*q;
  p=(*head);
  while(p!=NULL){
      q=p;
      free(p->Name);
      p=p->next;
      free(q);
  }
}
void displayList(node*head){
    int n=1;
    node*p=head;
 while(p!=NULL){
    printf("the information of the person %d\n",n);
    n++;
    printf("      the name of this person is %s\n",p->Name);
    printf("      the phone number of this person is %d\n",p->PhoneNumber);
    p=p->next;
 }
}
void AddPersonInFirst(node**head,char*nameOfPerson,int numberOfPhone){
   node*p,*q;
   Allocate(&p);
   (*head)->Name=malloc(strlen(nameOfPerson)+1);
    strcpy((*head)->Name,nameOfPerson);
   strcpy(p->Name,nameOfPerson);
   p->PhoneNumber=numberOfPhone;
   q=(*head);
   (*head)=p;
   p->next=q;
}
void AddPersonInLast(node**head,char*nameOfPerson,int numberOfPhone){
   if((*head)==NULL){
    Allocate(&(*head));
    (*head)->Name=malloc(strlen(nameOfPerson)+1);
    strcpy((*head)->Name,nameOfPerson);
    (*head)->PhoneNumber=numberOfPhone;
    (*head)->next=NULL;
   }else{

   node*p=(*head);
   while(p!=NULL){
    p=p->next;
   }
   Allocate(&(p->next));
   (*head)->Name=malloc(strlen(nameOfPerson)+1);
    strcpy((*head)->Name,nameOfPerson);
   strcpy(p->next->Name,nameOfPerson);
   p->next->PhoneNumber=numberOfPhone;
   p->next->next=NULL;
   }
}

void CreateList(node**head,int number){
    char nameOfPerson[MAX];
    int numberOfPhone;
    node*p;
    Allocate(&(*head));
    p=(*head);
  for(int i=1;i<=number;i++){
   printf("enter the informations of the person %d\n",i);
   printf("  enter its name ");
   scanf("%s",nameOfPerson);
   printf("  enter its number ");
   scanf("%d",&numberOfPhone);
   if(p!=(*head)){

   }
   p->Name=malloc(strlen(nameOfPerson)+1);
   strcpy(p->Name,nameOfPerson);
   p->PhoneNumber=numberOfPhone;
   if(i!=number){Allocate(&(p->next));
   p=p->next;}else{p->next=NULL;}
}
}
void CreateList2(){

}
int main(){
node* head;
printf("enter the number of persons\n");
int j;
scanf("%d",&j);
CreateList(&head,j);
displayList(head);
FreeList(&head);
    return 0;
}
