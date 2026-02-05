#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct etudiant{
     char nom[30];
     int  age;
     int moyenne;
     struct etudiant* suivant;
};
struct etudiant* creerEtudiant(char nomE[30],int ageE,int moyenneE){
    struct etudiant* nouvE=(struct etudiant*)malloc(sizeof(struct etudiant));
    strcpy(nouvE->nom,nomE);
    nouvE->age=ageE;
    nouvE->moyenne=moyenneE;
return nouvE;
};
void afficherList(struct etudiant* test){
    struct etudiant* courant=test;
    while(courant !=NULL){
        printf("%s =>\n",courant->nom);
        printf("%d =>\n",courant->age);
        printf("%d =>\n",courant->moyenne);
        courant=courant->suivant;

    };
};
int main(){
    struct etudiant* head;
    struct etudiant* premier=creerEtudiant("maria",18,18);
    struct etudiant* deuxieme=creerEtudiant("meriem",17,17);
    struct etudiant* troisieme=creerEtudiant("sara",16,16);
    struct etudiant* fin=creerEtudiant("imen",15,15);
    head=premier;
    premier->suivant=deuxieme;
    deuxieme->suivant=troisieme;
    troisieme->suivant=fin;
    fin->suivant=NULL;
    afficherList(head);
  printf("%d",head->suivant->age);

return 0;
}
