#ifndef GALLERY_H
#define GALLERY_H

/**
 *  @file   gallery.h
 *  @author ...
 */

struct node {
   char** value;
   int nochars;
   int norows;
   struct node* next;
   struct node* prev;
};
typedef struct ptgallery {
    struct node *first;
    struct node *last;
}PTGALLERY;
void addlinetogallery(struct node * actual,PTGALLERY *ptgallery, struct node *newpic,char **line);
int max(int a, int b);
void deletebackslashn(char *line);
void mezery(int num);
void initGallery(PTGALLERY *l);
int howmanypictures(PTGALLERY *how);
#endif // GALLERY_H
