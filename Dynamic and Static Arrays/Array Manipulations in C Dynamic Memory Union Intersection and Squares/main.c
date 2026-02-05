#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
void filling_table(int table[MAX],int *size){
puts("enter the size of the table");
scanf("%d",size);
for(int ind=0;ind<(*size);ind++){
    printf("table[%d]=",ind);
    scanf("%d",&table[ind]);
};
};
void reading_table(int table[MAX],int *size){
   for(int ind=0;ind<(*size);ind++){
    printf("Table[%d]=%d\n",ind,table[ind]);
   };
};
void squares_table(int table_a[MAX],int table_b[MAX],int size_a,int size_b,int*p,int *size){
 int i=0;
for(int ind_a=0;ind_a<size_a;ind_a++){
     int n_a=sqrt(table_a[ind_a]);
    if(n_a*n_a==table_a[ind_a]){
      *(p+i)=table_a[ind_a];
       i++;
       (*size)++;
    };
};
for(int ind_b=0;ind_b<size_b;ind_b++){
      int n_b=sqrt(table_b[ind_b]);
      if(n_b*n_b==table_b[ind_b]){
        *(p+i)=table_b[ind_b];
        i++;
        (*size)++;
      };
};
};
void read_tab(int table[],int size){
for(int ind=0;ind<size;ind++){
  printf("table[%d]=%d\n",ind,table[ind]);
};
};
void intersection(int tableA[],int tableB[],int sizeA,int sizeB,int inter[],int *size){
   for(int ind_a=0;ind_a<sizeA;ind_a++){
      for(int ind_b=0;ind_b<sizeB;ind_b++){
        if(tableA[ind_a]==tableB[ind_b]){
          inter[(*size)]=tableA[ind_a];
          (*size)++;
        };
      };
   };
};
void union_table(int tableA[],int tableB[],int sizeA,int sizeB,int table_union[],int* size){
      for(int indA=0;indA<sizeA;indA++){
        for(int indB=0;indB<sizeB;indB++){
          if(tableA[indA]==tableB[indB]){
            table_union[(*size)]=tableA[indA];
            (*size)++;
          };
        };
      };
};
void difference(int tab1[],int tab2[],int size1,int size2,int table[],int *size ){
  int indA=0;
  while(indA<size1){
    int indB=0, cont=0;
    while(indB<size2){
      if(tab1[indA]==tab2[indB]){
        cont++;
      };
      indB++;
    };
    if(cont==0){
        table[*size]=tab1[indA];
          (*size)++;
    };
    indA++;
  };
  indA=0;
  while(indA<size2){
    int indB=0, cont=0;
    while(indB<size1){
      if(tab1[indB]==tab2[indA]){
        cont++;
      };
      indB++;
    };
    if(cont==0){
        table[*size]=tab2[indA];
         (*size)++;
   };
   indA++;
  };
};
int main(){
    int tableA[MAX];
    int tableB[MAX];
    int sizeA=0,sizeB=0,sizeC=0,sizeD=0,sizeE=0,sizeF=0;
    int *tableC=(int*)malloc((sizeC)*sizeof(int));
    int *tableD=(int*)calloc((sizeD),sizeof(int));
    int *tableE=(int*)malloc(sizeE*sizeof(int));
    int *tableF=(int*)malloc(sizeF*sizeof(int));
  filling_table(tableA,&sizeA);
  filling_table(tableB,&sizeB);
  puts("the union -------------------------");
  union_table(tableA,tableB,sizeA,sizeB,tableF,&sizeF);
  read_tab(tableF,sizeF);
  puts("the difference -------------------------");
  difference(tableA,tableB,sizeA,sizeB,tableE,&sizeE);
  read_tab(tableE,sizeE);
  puts("the intersection -----------------------");
  intersection(tableA,tableB,sizeA,sizeB,tableD,&sizeD);
  read_tab(tableD,sizeD);
  puts("the table of squares -------------------");
  squares_table(tableA,tableB,sizeA,sizeB,tableC,&sizeC);
  read_tab(tableC,sizeC);
  puts("the table A ----------------------------");
  reading_table(tableA,&sizeA);
  puts("the table B ----------------------------");
reading_table(tableB,&sizeB);
free(tableE);
free(tableC);
free(tableD);
free(tableF);
return 0;
}
