#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct record{
    char keyword[50];
    struct record *left,*right;
    int count;
    int height;
}Record;
Record* load();
Record* add(Record*,char*);
int height(Record*);
Record* singleRotateRight(Record*);
Record* singleRotateLeft(Record*);
Record* doubleRotateRight(Record*);
Record* doubleRotateLeft(Record*);
void print(Record*);
void search(Record*,char[]);
void range_query(Record*,char,char);
void store(Record*);
void preprint(Record*,char[]);
void lenq(Record*,int);
int max(int,int);
#endif // DICTIONARY_H_INCLUDED
