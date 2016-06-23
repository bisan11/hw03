#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "container.h"
#include "picture.h"
#include "gallery.h"
#include "errorHandling.h"
void initGallery(PTGALLERY *l) {
l->first=NULL;
l->last=NULL;
}

void deletebackslashn(char *line){
    int i=0;
    while(line[i]!='\n'){
        i++;
    }
    line[i]=0;
}
int howmanypictures(PTGALLERY *how){
    struct node*a=how->first;
    int count=0;
    while(a){
        a=a->next;
        count++;
    }
    return count;
}


int nopicturesingallery(struct node * actualpic,struct node * prevpic,struct node * nextpic){
if ((actualpic==prevpic)&&(prevpic=nextpic)){
   return 1;
}
   else if((prevpic==nextpic)){
    return 2;
}
else{
    return 3;
}

}

void getrows(int maxrows, struct node * node, ras value){
    int a=maxrows-node->norows;
    int filldown=a/2;
    int fillup=a-filldown;
    value ->nad = fillup;
    value->mid = node->norows;
    value->pod = filldown;
    value->sloupce = node->nochars;

}



void addlinetogallery(struct node * actual,PTGALLERY *ptgallery, struct node *newpic,char **line){

        if((ptgallery->first==NULL)&&(ptgallery->last==NULL)){
        ptgallery->first=newpic;
        ptgallery->last=newpic;
        newpic->next=NULL;
        newpic->prev=NULL;
    } else if(ptgallery->first == ptgallery->last){
        ptgallery->first = newpic;
        ptgallery->last->prev = newpic;
        newpic->next= ptgallery->last;
    } else {
        if(actual == ptgallery->first){
            ptgallery->first = newpic;
            actual->prev = newpic;
            newpic->next = actual;
        } else if(actual == ptgallery->last){

            newpic->prev = actual->prev;
            newpic->next=actual;
            actual->prev->next=newpic;
            actual->prev=newpic;

        } else {
            newpic->next= actual;
            newpic->prev = actual->prev;
            actual->prev = newpic;
        }
    }

newpic->value=line;
}



int max(int a, int b){
    if(a>=b){
        return a;
    } else {
        return b;
    }
}


void printgal(PTGALLERY *pic, struct node * actualpic){
    if((pic->first==NULL)||(pic->last==NULL)){
        return;
    }

    struct node * prevpic;
    struct node * nextpic;

    if(actualpic == pic->first){
        prevpic = pic->last;
    } else {
        prevpic = actualpic->prev;
    }

    if(actualpic == pic->last){
        nextpic = pic->first;
    } else {
        nextpic = actualpic->next;
    }

    int maximum=max(nextpic->norows,max(prevpic->norows,actualpic->norows));
    ras rows[3];
    for(int i=0;i<3;i++){
        rows[i]=malloc(sizeof(struct radky));
        if(!rows[i]){
            errorHandle(ERROR_NO_MEMORY);
            break;
        }
    }
    getrows(maximum, prevpic,rows[0]);
    getrows(maximum, actualpic,rows[1]);
    getrows(maximum, nextpic,rows[2]);

    int rowsnumval[3]={rows[0]->nad,rows[1]->nad, rows[2]->nad};
    int noloops=nopicturesingallery(actualpic,prevpic,nextpic);
  for (int i=0;i<maximum;i++){

    for (int k=0;k<noloops;k++){
        struct node * node;
        if(noloops==2){
        k=k+1;
        }
        switch(k){
        case 0:{node = prevpic; break;}
        case 1:{node = actualpic; break;}
        case 2:{node = nextpic; break;}
        }

        if(rows[k]->nad > 0){
            rows[k]->nad--;
            mezery(rows[k]->sloupce);
            if((noloops==2)&&(k==1)){
            printf(" | ");}
            if((noloops==3)&&(k!=2)){
            printf(" | ");}
        } else if(rows[k]->mid>0){
            printf("%s",node->value[i-rowsnumval[k]]);
            rows[k]->mid--;
            if((noloops==2)&&(k==1)){
            printf(" | ");}
            if((noloops==3)&&(k!=2)){
            printf(" | ");}
        } else if(rows[k]->pod>0){
            rows[k]->pod--;
            mezery(rows[k]->sloupce);
            if((noloops==2)&&(k==1)){
            printf(" | ");}
            if((noloops==3)&&(k!=2)){
            printf(" | ");}

        }
        if(noloops==2){
        k=k-1;
        }
    }printf("\n");

}

    for (int i=0;i<3;i++){
        free(rows[i]);
    }
    return;

}








