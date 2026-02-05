#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct Binary_tree{
   int val;
   struct Binary_tree* left;
   struct Binary_tree* right;
   struct Binary_tree* up;
};
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                                /*Abstract Machine for Binary Trees*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//allocate a new node v and return its address
struct Binary_tree* AllocateNode(int v){
       struct Binary_tree*p;
       p=malloc(sizeof(struct Binary_tree));
       p->left=NULL;
       p->right=NULL;
       p->val=v;
       p->up=NULL;
    return p;
}
// free and deallocate the node pointed to by p
void FreeNode(struct Binary_tree*p){
     free(p);
}
// return the containts of ‘val’ field
int NodeValue(struct Binary_tree*p){
   return p->val;
}
// return the containts of ‘left’ field (the left-subtree of p)
struct Binary_tree* LC(struct Binary_tree* p){
 return p->left;
}
// return the containts of ‘right’ field (the right-subtree of p)
struct Binary_tree* RC(struct Binary_tree* p){
 return p->right;
}
// assign v to ‘val’ field
void Ass_Node_Val(struct Binary_tree* p,int v){
     p->val=v;
}
// assign q to ‘left’ field (connect q as a left-subtree of p)
void Ass_LC(struct Binary_tree*p,struct Binary_tree*q){
     p->left=q;
}
// assign q to ‘right’ field (connect q as a right-subtree of p)
void Ass_RC(struct Binary_tree*p,struct Binary_tree*q){
     p->right=q;
}
// return the containts of ‘up’ field (the parent node of p)
struct Binary_tree* Parent(struct Binary_tree* p){
   return p->up;
}
// assign q to ‘up’ field (connect q as the parent node of p)
void Ass_Parent(struct Binary_tree* p,struct Binary_tree* q){
     p->up=q;
}
// Function to create a new node
void create_node(struct Binary_tree**p,int v){
    (*p)=AllocateNode(v);
    if ((*p) == NULL) {
        printf("Memory allocation failed \n");
        return;
    }
    (*p)->left=NULL;
    (*p)->right=NULL;
    (*p)->up=NULL;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                                    /*Tree Traversal Algorithms*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void write_inorder(struct Binary_tree* root){
 if(root!=NULL){
    printf(" --> %d",root->val);
    write_inorder(RC(root));
    write_inorder(LC(root));
     }
}
struct list{
     struct Binary_tree*node;
     struct list*Next;
};
struct queue{
  struct list*head;
  struct list*tail;
};
struct list* CreateNode(struct Binary_tree*treeNode){
   struct list*p=malloc(sizeof(struct list));
   if(p==NULL){
    printf("filed allocate memory\n");
    return NULL;
   }
   p->node=treeNode;
   p->Next=NULL;
   return p;
}
void CreateQueue(struct queue*Q){
    Q->head=NULL;
    Q->tail=NULL;
}
int IsEmpty(struct queue*Q){
    int p;
  if(Q->head==NULL){
    p=1;
  }else{
    p=0;
  }
  return p;
}
int IsFull(struct queue*Q){
  return 0;
}
// Function to add an element to the queue
void Enqueue(struct queue*Q,struct Binary_tree*treeNode){
   if(IsFull(Q)){
    printf("the queue is full\n");
    return;
   }
  struct list*p=CreateNode(treeNode);
  if(Q->head==NULL){
    Q->head=p;
    Q->tail=p;
    return;
  }
  Q->tail->Next=p;
  Q->tail=p;
}
// Function to remove an element from the queue
void Dequeue(struct queue*Q,struct Binary_tree**treeNode){
   if(IsEmpty(Q)){
    printf("the queue is empty\n");
    return;
   }
   struct list*q=Q->head;;
   if(Q->head==Q->tail){
    (*treeNode)=Q->head->node;
    Q->head=NULL;
    Q->tail=NULL;
    free(q);
    return;
   }
   (*treeNode)=Q->head->node;
   Q->head=Q->head->Next;
   free(q);
}
void WriteLevelByLevel(struct Binary_tree* root){
    struct queue*Q=malloc(sizeof(struct queue));
    struct Binary_tree*treeNode;
     CreateQueue(Q);
     Enqueue(Q,root);
     while(!IsEmpty(Q)){
            Dequeue(Q,&treeNode);
        printf(" --> %d ",treeNode->val);
        if(RC(treeNode)!=NULL){
            Enqueue(Q,RC(treeNode));
        }
        if(LC(treeNode)!=NULL){
            Enqueue(Q,LC(treeNode));
        }
     }
     free(Q);
}
void InsertInTree(struct Binary_tree**T,int NumberOfNodes){
   struct Binary_tree*p,*q;
   int v,choice;
   printf("enter the value of the root\n");
   scanf("%d",&v);
   create_node(&p,v);
   (*T)=p;
   for(int i=1;i<NumberOfNodes;i++){
   printf("enter your choice\n");
   printf("     1->insert in the left\n");
   printf("     2->insert in the right\n");
   scanf("%d",&choice);
   switch(choice){
        case 1:
            printf("enter the value\n");
            scanf("%d",&v);
            create_node(&q,v);
            p->left=q;
            p=q;
            break;
        case 2:
            printf("enter the value\n");
            scanf("%d",&v);
            create_node(&q,v);
            p->right=q;
            p=q;
            break;
        default:
            printf("this option does not exist\n");
            break;
            }
   }
}
void FreeTree(struct Binary_tree**T){
   if((*T)!=NULL){
   FreeTree(&(*T)->right);
   FreeTree(&(*T)->left);
   free(*T);
   }
}
//Binary Search Trees : BST
/*struct Binary_tree* BinarySearchTree(struct Binary_tree *T,int value){
 if(T->val==value) return T;
 if(T==NULL){
    return NULL;
 }
 else{
   if(value<T->val){
    BinarySearchTree(LC(T),value);
   }
   else{
    BinarySearchTree(RC(T),value);
     }
 }
}*/
void BST(struct Binary_tree *T,struct Binary_tree**p,struct Binary_tree**c,int value){
    if(T==NULL){
        (*p)=NULL;
        (*c)=NULL;
        return;
    }else{
      if(T->val==value){
        (*p)=NULL;
        (*c)=T;
      }else{
        if(value<T->val){
           BST(LC(T),p,c,value);
        }else{
           BST(RC(T),p,c,value);
        }
        if((*p)==NULL){
            (*p)=T;
        }
      }
    }
}
void InorderTraversalPrint(struct Binary_tree*T){
  if(T!=NULL){
    InorderTraversalPrint(LC(T));
    printf(" => %d",T->val);
    InorderTraversalPrint(RC(T));
  }
}
/*void CreateBinaryTree(struct Binary_tree**T,int NodeNumber){
   int number;
   if(NodeNumber<=0){
    return;
   }
   printf("enter the value\n");
   scanf("%d",&number);
   create_node(&(*T),number);
   if(NodeNumber==1){
    return;
   }
   struct Binary_tree*temp=(*T);
   for(int count=1;count<NodeNumber;count++){
   printf("enter the value\n");
   scanf("%d",&number);
   create_node(&temp,number);
   //if()
   }
}*/
void InsertInBinaryTree(struct Binary_tree**T,int number){
   if((*T)==NULL){
      create_node(T,number);
   }else{
     if((*T)->val==number){
        return;
     }
     if((*T)->val<number){
        InsertInBinaryTree(&(*T)->right,number);
     }
     if((*T)->val>number){
        InsertInBinaryTree(&(*T)->left,number);
     }
   }
}
void rangeQuery(struct Binary_tree*T,int a,int b){
    if(T==NULL){
        return;
    }
    if(T->val>a){
        rangeQuery(T->left,a,b);
    }
    if(T->val>=a && T->val<=b){
        printf(" => %d",T->val);
    }
    if(T->val<b){
        rangeQuery(T->right,a,b);
    }
}
struct stack{
   struct list*top;
};
void CreateStack(struct stack*S){
   S->top=NULL;
}
/*struct Binary_tree*FindMinAbove(struct Binary_tree*T,int a){
}*/
int Insertion(struct Binary_tree**T,int v){
    int res;
   if((*T==NULL)){
     create_node(T,v);
     return  TRUE;
   }else{
   if((*T)->val==v){
    return FALSE;
   }
   if((*T)->val<v){
      res=Insertion(&(*T)->right,v);
      Ass_RC((*T),(*T)->right);
      Ass_Parent((*T)->right,(*T));
   }
   if((*T)->val>v){
      res=Insertion(&(*T)->left,v);
      Ass_LC((*T),(*T)->left);
      Ass_Parent((*T)->left,(*T));
   }
   }
   return res;
}
int search(struct Binary_tree*root,struct Binary_tree**T,struct Binary_tree**Parent,int value){
    *T=root;
    *Parent=NULL;
    if(root==NULL){
        return FALSE;
    }
    while((*T)!=NULL){
        if((*T)->val==value){
            return TRUE;
        }
        (*Parent)=(*T);
        if((*T)->val<value){
            (*T)=(*T)->right;
        }
        if((*T)->val>value){
            (*T)=(*T)->left;
        }

    }
  return FALSE;
}
/*struct Binary_tree* Deletion(struct Binary_tree*T,int v){
   if(T==NULL){
    return T;
   }

}*/
int main(){
struct Binary_tree*T=NULL;
int number,value;
printf("enter the number of nodes of the tree\n");
scanf("%d",&number);
for(int i=0;i<number;i++){
        printf("enter the value");
        scanf("%d",&value);
        InsertInBinaryTree(&T,value);
}
rangeQuery(T,5,10);
//InsertInTree(&T,number);
//InorderTraversalPrint(T);
//write_inorder(T);
//WriteLevelByLevel(T);
    return 0;
}
