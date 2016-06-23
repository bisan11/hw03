#ifndef PICTURE_H
#define PICTURE_H

/**
 *  @file   picture.h
 *  @author ...
 */

// TODO: picture declarations
#include "gallery.h"
struct picture{
    char* row;
    struct picture *next;
};
struct radky{
    int nad;
    int mid;
    int pod;
    int sloupce;
};
typedef struct radky * ras;


void savepicture(struct node * actual,PTGALLERY *ptgallery,struct node *newpic,char **line);
int createline(char *line,struct node *actualpic);
void printgal(PTGALLERY *pic, struct node *actualpic);
int newpicture(struct node * actual,struct node * pic,PTGALLERY *ptgallery);
#endif // PICTURE_H
