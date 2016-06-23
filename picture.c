#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gallery.h"
#include "picture.h"
#include "errorHandling.h"


void freevalue(char ** value, int num){
    for (int i=0;i<=num;i++){
        free(value[i]);
    }
    free(value);
}
void savepicture(struct node * actual,PTGALLERY *ptgallery,struct node *newpic,char **line){
    addlinetogallery(actual,ptgallery,newpic,line);
}


int newpicture(struct node * actual,struct node * pic,PTGALLERY *ptgallery){
    unsigned numofnewline=1;

    char** radek=malloc(sizeof(char*));;
    char **need=radek;
    if(!radek){
        errorHandle(ERROR_NO_MEMORY);
        return 1;
    }

    char radek2[10000];
    unsigned int a=0;
    int b=2;
    unsigned int k=0;
    for (;k<numofnewline;k++){

        fgets(radek2,10000,stdin);

        deletebackslashn(radek2);

        a=strlen(radek2);
        if((a==0)&&(k==0)){
            return 1;
    }
        radek[k]=malloc((a+1)*sizeof(char));
        if(!radek[k]){

            do{
                fgets(radek2,10000,stdin);
            }while(radek2[0]!='\n');
             errorHandle(ERROR_NO_MEMORY);
            freevalue(radek,k);
            return 1;
            }

        radek=(char**)realloc(radek,(b*sizeof(char*)));
        if (!radek){


            do{
                fgets(radek2,10000,stdin);
            }while(radek2[0]!='\n');
                errorHandle(ERROR_NO_MEMORY);
            freevalue(need,k);
            return 1;
        }
        strcpy(radek[k],radek2);


    b++;
    if ((strlen(radek[k])==0)&&(k>0)){

        break;

    }
    if ((k!=0)&&(a!=strlen(radek[k-1]))){

        do{
            fgets(radek2,10000,stdin);
        }while(radek2[0]!='\n');
        errorHandle(ERROR_WRONG_FORMAT);
        freevalue(radek,k);

        return 1;}
    numofnewline++;
    }
    pic->norows=numofnewline-1;
    pic->nochars=strlen(radek[k-1]);
    savepicture(actual,ptgallery,pic,radek);
return 0;
}


















