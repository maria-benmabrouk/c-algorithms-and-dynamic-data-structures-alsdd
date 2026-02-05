#include<stdio.h>
#include<math.h>
#define MAX 100
void filling_table(int table[MAX],int size){
    for(int ind=0;ind<size;ind++){
      printf("T[%d]=",ind);
      scanf("%d",&table[ind]);
    };
};
int binary_search(int table[],int size,int number){
int left=0, right=size-1, ind=-1;
while(right>=left){
int mid=(right-left)/2+left;
if(table[mid]==number){
ind=mid;
};
if(table[mid]>number){
right=mid-1;
}
else{
        left=mid+1;};
};
return ind;
};
int binary_search_recursive(int table[],int size,int number,int left,int right)
{   if(left>right){return -1;};
    int mid=(right-left)/2+left;
    if(table[mid]==number){return mid;};
    if(table[mid]>number){return binary_search_recursive(table,size,number,left,mid-1);}
    else{return binary_search_recursive(table,size,number,mid+1,right);};
};
void write_table(int table[],int size){
for(int ind=0;ind<size;ind++){
  printf("T[%d]=%d\t",ind,table[ind]);
};
};
void selection_sort(int table[],int size){
    int tmp=0;
for(int ind1=0;ind1<size;ind1++){
    for(int ind2=ind1+1;ind2<size;ind2++){
        if(table[ind1]>table[ind2]){
            tmp=table[ind1];
            table[ind1]=table[ind2];
            table[ind2]=tmp;
        };
    };
};
};
void insertion_sort(int table[],int size){
     for(int ind=1;ind<size;ind++){
       int tmp=table[ind];
       for(int ind2=ind-1;ind2<size && ind2>0 ;ind2--){
        if(table[ind2+1]<table[ind2]){
            table[ind2+1]=table[ind2];
            table[ind2]=tmp;
        };
       };
     };
};
void merging2tables(int tab1[],int tab2[],int tab3[],int size1,int size2){
    int ind1=0,ind2=0,ind=0;
    while(ind1<size1 && ind2<size2){
        if (tab1[ind1]<tab2[ind2]){
            tab3[ind]=tab1[ind1];
            ind1++;
            ind++;
        }
        else{tab3[ind]=tab2[ind2];
            ind2++;
            ind++;
        };
    };
    if(size1>size2){
       while(ind1<=size1){
      tab3[ind]=tab1[ind1];
      ind++;
      ind1++;
      } ;
    };
     if(size2>size1){
     while(ind2<=size2){
      tab3[ind]=tab2[ind2];
      ind++;
      ind2++;
     };
     };
};
void insertion_val(int table[],int *size,int ind,int val,int MAX_){
 if((*size)>=MAX_){
    puts("error");
 } else {if((*size)<MAX_){
   if(ind>*size || ind<0){
    puts("error");
   } else {if(ind<=(*size)){
    for(int in=*size;in>=ind;(in)--){
      table[in]=table[(in-1)];};
    };};
    table[ind]=val;
    (*size)++;
   };
 };
};
void insertion_in_sorted_table(int table[],int *size,int val){
    int ind=(*size)-1;
 while(ind>=0){
    if (table[ind]>val){
      table[ind+1]=table[ind];
    }else{
    table[ind+1]=val;
    break;
    };
    ind--;
 };
 (*size)++;
};
   int main(){
    int tableA[MAX];
    int tableB[]={10, 7, 6, 20, 45, 30, 5, 15};
    int tableC[]={5,9,8,45,10,30,17,18,12};
    int tableD[100];
    int tableE[MAX];
    int tableF[MAX]={1,3,4,5,6,7};
    int sizeA=0,sizeE=0,number=0,nomuro=0,val=0,ind=0,size=6;
    insertion_in_sorted_table(tableF,&size,2);
    write_table(tableF,size);
    insertion_sort(tableC,9);
    write_table(tableC,9);
    puts("\n enter the size of the table E\n");
    scanf("%d",&sizeE);
    filling_table(tableE,sizeE);
    insertion_sort(tableE,sizeE);
    write_table(tableE,sizeE);
    puts("\n enter the value");
    scanf("%d",&val);
    insertion_in_sorted_table(tableE,&sizeE,val);
    write_table(tableE,sizeE);
    puts("\n enter the index");
    scanf("%d",&ind);
    insertion_val(tableE,&sizeE,ind,val,100);
    write_table(tableE,sizeE);
    puts("\n -------------------------------\n");
    selection_sort(tableB,8);
    write_table(tableB,8);
    puts("\n the merge table \n");
    merging2tables(tableB,tableC,tableD,8,9);
    write_table(tableD,8+9);
    puts("\n enter the size of the table A");
    scanf("%d",&sizeA);
    puts("filling the table A");
    filling_table(tableA,sizeA);
    puts("enter the number that you need to search for it in the table\n ");
    scanf("%d",&number);

      nomuro=binary_search_recursive(tableA,sizeA,number,0,sizeA-1);
     if(nomuro==-1){printf("The number %d does not exist in the table\n",number);}
    else{printf("the number %d is exist in the table and its index is %d",number,nomuro); };
 return 0;
}
