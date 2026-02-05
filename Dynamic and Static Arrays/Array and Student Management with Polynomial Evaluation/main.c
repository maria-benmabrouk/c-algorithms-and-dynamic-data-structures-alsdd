#include<stdio.h>
#include<math.h>
#define  MAX 100
struct student{
        char *name;
        float grade;
};
void fill_table(float table[100],int size){ // this function filling a table "table" that has the size "size"
 for(int ind=0;ind<size;ind++){
    printf("T[%d]=",ind);
    scanf("%f" , &table[ind]);
    };
   };
float max_table(float table[100],int size){// this function determining the maximum value in the table
   float max_element=table[0];
   for(int ind=1;ind<size;ind++){
    if(max_element<table[ind]){
      max_element= table[ind];
    };
   };
   return max_element;
};
float average_students(struct student average[MAX],int number){// this function return the average of the student
     float ave=0;
    for(int ind1=0;ind1<number;ind1++){
        printf("Enter the information of the student %d \n",ind1+1);
        puts("enter the name\n");
        getchar();
        scanf("%s",&average[ind1].name);
        puts("enter the grade\n");
        scanf("%f",&average[ind1].grade);
    };
    for(int ind2=0;ind2<number;ind2++){
     ave = ave + average[ind2].grade;
    };
    ave /= number;
    return ave;
};
float rusult_polynom(float table[MAX],int n,float X){
    float val=0;
    for(int coeff=0;coeff<=n;coeff++ ){
    val += table[coeff]*pow(X,coeff);
    };
    return val;
};
int main(){
   float table1[MAX];
   int max_ind=0;
   while(max_ind<=0 || max_ind>=100){
    puts("enter the size of the table\n ");
    scanf("%d" , &max_ind);
   };
  fill_table(table1,max_ind);//filling table
  printf("The maximum value in the table is : %f \n",max_table(table1,max_ind));//determining the maximum value in the table
  // caculate the average of students
  int number_students=0;
  struct student ave_stud[MAX];
  while(number_students<=0 || number_students>100){
  puts("please enter the number of students\n");
  scanf("%d",&number_students);
  };
  printf("the average of the students is : %f \n",average_students(ave_stud,number_students));
  //Calculate the value of a polynomial P(X) of a given degree n using the array
  //of its coefficients for a given value of X
  int degree=0;
  float X=0;
  float table_polynom[MAX];
  puts("Enter the degree n of the polynomial P(x)\n");
  scanf("%d",&degree);
  puts("Enter the coefficient of the polynomial\n");
  fill_table(table_polynom,degree+1);
  puts("Enter the number X\n");
  scanf("%f",&X);
  printf("P(%f)=%f",X,rusult_polynom(table_polynom,degree+1,X));
return 1;
};
