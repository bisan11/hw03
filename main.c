#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "container.h"
#include "picture.h"
#include "gallery.h"
#include "errorHandling.h"


void freepic(struct node* node){
    for (int i=0;i<=node->norows;i++){
        free(node->value[i]);
    }
    free(node->value);
    free(node);
}

int checkparametr(int argc, char** argv){
    if (argc==1){
printf ("GALERIE OBRAZKU :: NAPOVEDA\n\n----Spusteni programu\n");
printf("-s  vypne tuto napovedu\n\n----Prikazy\nn  nacte novy obrazek\n");
printf("d  smaze aktualni obrazek\nl r rotace galerie vlevo a v pravo\n");
printf("s  zjisti pocet obrazku v galerii\nq  ukonci program\n\n");
    }
    if (argc==2) {
    if (strcmp(argv[1],"-s")==0){




        return 0;
            }

        else {
            printf ("spatne zadany parametr");
            return -2;
        }}
    if (argc>2){
        puts("pocet parametru musi byt maximalne 1");
        return -2;
    }
return 0;
}



int main(int argc, char* argv[])
{

int parameter=checkparametr (argc,argv);
if (parameter!=0){
    return -2;}

PTGALLERY *ptgallery=malloc(sizeof(PTGALLERY));
if(!ptgallery){
    errorHandle(ERROR_NO_MEMORY);
    return 0;
}
struct node * actualPic=NULL;
initGallery(ptgallery);

char c;
char bond[5000];
struct node *newpic;

while (1){
    printf(">");
    fgets(bond,5000,stdin);

    if (strlen(bond)>2){
        errorHandle(ERROR_WRONG_CMD);

    }
    else {
        c=bond[0];
        int b=0;
    switch (c){
    case 'n':;

    newpic=malloc(sizeof(struct node));
    if(!newpic){
        errorHandle(ERROR_NO_MEMORY);
        break;
    }
    newpic->next=NULL;
    newpic->prev=NULL;
        b=newpicture(actualPic,newpic,ptgallery);
        if(!b){
            actualPic = newpic;

            printgal(ptgallery, actualPic);
        }else{
            printgal(ptgallery, actualPic);

            free(newpic);
        }

        break;
    case 'd':
        if((ptgallery->first == NULL)||(ptgallery->last == NULL)){
            break;
        } else if((ptgallery->first == ptgallery->last)){
            ptgallery->first = NULL;
            ptgallery->last = NULL;
            free(actualPic->value);
            free(actualPic);
            actualPic=NULL;
            break;
        } else {
            if(!(actualPic->prev)){
                ptgallery->first = actualPic->next;
                actualPic = actualPic->next;
                freepic(ptgallery->first->prev);
                ptgallery->first->prev = NULL;
            } else if(actualPic->next == NULL){
                ptgallery->last=actualPic->prev;
                actualPic = actualPic->prev;
                freepic(ptgallery->last->next);
                ptgallery->last->next=NULL;
            } else {
                struct node *needed=actualPic;
                actualPic->prev->next=actualPic->next;
                actualPic->next->prev=actualPic->prev;

                actualPic = actualPic->next;
                free (needed);
            }
        }
        printgal(ptgallery,actualPic);
        break;
    case 'r':
        if(ptgallery->first==actualPic){
            actualPic=ptgallery->last;
        } else {
            actualPic=actualPic->prev;
        }
        printgal(ptgallery, actualPic);
        break;
    case 'l':
        if(ptgallery->last==actualPic){
            actualPic=ptgallery->first;
        } else {
            actualPic=actualPic->next;
        }
        printgal(ptgallery, actualPic);
        break;
    case 's':
        printf ("size: %i\n",howmanypictures(ptgallery));
        break;
    case 'q':
        actualPic = ptgallery->first;
       while(actualPic!=NULL){
           if(actualPic->next !=NULL){
           actualPic = actualPic->next;
           freepic(actualPic->prev);
           } else {
               freepic(actualPic);
           break;
           }

       }
        free(ptgallery);

        return 0;
    case '\n':
        break;
    default:
        errorHandle(ERROR_WRONG_CMD);
        break;
    }}}
return 0;
}



