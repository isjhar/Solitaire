#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int bunga;
    int angka;
}infotype;

typedef struct elmkartu {
    infotype info;
    int status;
}telmkartu;

typedef elmkartu tumpukan[52];


typedef struct {
    tumpukan kartu;
    int top;
}stack;

typedef stack part[7];
typedef stack part2[4];

typedef struct {
    tumpukan kartu;
    int head;
    int tail;
}queue;



void createtumpukan (tumpukan *x);
void createemptystack (part *s);//membuat stack kosong
void createemptystack2 (part2 *t);
void createemptyqueue (queue *q);
int isEmptyStack (part s, int i);
int isEmptyQueue(queue q);
void shufflecard (tumpukan *lama);//mengocok kartu
void push (stack *s, infotype x);
void pop (stack *s, infotype *x);
void setkartu (part *s,tumpukan x,queue *q);
void view (part s,part2 t, queue q);
void enqueue (queue *q, telmkartu x);
void dequeue (queue *q, telmkartu *x);
int konfersitoangka (char x);
void getcard (part *s, queue *q, telmkartu *x,  int i);
void putcard (part *s, queue *q, telmkartu x, int j);
int iscocok (telmkartu x, telmkartu y);
int iscocok2 (telmkartu x, telmkartu y);
void tukar (part *s,part2 *t, queue *q, int x, int y);
int onlyking (part s, queue q, telmkartu x, int y);
int onlyAs (part2 s, telmkartu x, int y);
int gamefinish (part2 x);


#endif // FILE_H_INCLUDED
