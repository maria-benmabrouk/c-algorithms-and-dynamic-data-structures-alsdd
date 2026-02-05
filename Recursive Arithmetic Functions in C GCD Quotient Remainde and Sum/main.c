#include <stdio.h>
#include <stdlib.h>
int  Quotient(int a,int b){
    if(a<b){
        return 0;
    }
       return Quotient(a-b,b)+1;
}
int somme(int n){
    if(n==0){
        return 0;
    }
    return somme(n-1)+n;

}
int Reste(int a,int b){
    if(a<b){
        return a;
    }
    return Reste(a-b,b);
}
int PGCD(int a,int b){
    if(a>b){
        return PGCD(a-b,b);
    }
    if(b>a){
        return PGCD(a,b-a);
    }
        return a;
}
int main()
{
    printf("%d",PGCD(504,135));
    return 0;
}
