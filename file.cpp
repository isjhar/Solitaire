#include "file.h"

void createtumpukan (tumpukan *x){
    int i,j,k;
    k=0;
    for(i=3;i<7;i++){
        for(j=49;j<62;j++){
            if(j==49){
                (*x)[k].info.angka=65;
            } else if (j==59){
                (*x)[k].info.angka=74;
            } else if (j==60){
                (*x)[k].info.angka=81;
            } else if (j==61){
                (*x)[k].info.angka=75;
            } else if(j==58){
                (*x)[k].info.angka=48;
            } else {
                (*x)[k].info.angka=j;
            }
            (*x)[k].info.bunga=i;
            (*x)[k].status=0;
            k++;
        }
    }
}

void createemptystack (part *s){
    int i;
    for(i=0;i<7;i++){
        (*s)[i].top=-1;
    }

}

void createemptystack2 (part2 *t){
    int i;
    for(i=0;i<7;i++){
        (*t)[i].top=-1;
    }
}


void createemptyqueue (queue *q){
    (*q).head=-1;
    (*q).tail=-1;
}

int isEmptyStack (part s, int i){
    if ((s)[i].top==-1){
        return 1;
    } else {
        return 0;
    }
}

int isEmptyQueue(queue q){
    if (q.head==-1 && q.tail==-1){
        return 1;
    } else {
        return 0;
    }
}

void shufflecard (tumpukan *lama){
    tumpukan baru;
    int k;
    int n = 52;
    int shuffleCount = rand() % 100 + 1;
    for(int l=0; l<shuffleCount; l++){
        for (k=n-1; k>=0; k--){
            if (k % 2 == 1) {
                baru[(n-k-1)/2].info.angka = (*lama)[k].info.angka;
                baru[(n-k-1)/2].info.bunga = (*lama)[k].info.bunga;
            } else if (k%2 == 0) {
                baru[(k/2)+n/2].info.angka = (*lama)[k].info.angka;
                baru[(k/2)+n/2].info.bunga = (*lama)[k].info.bunga;
            }
        }
        for (k=0;k<=n;k++){
            (*lama)[k].info.angka = baru[k].info.angka;
            (*lama)[k].info.bunga = baru[k].info.bunga;
        }
    }
}

void push (stack *s, telmkartu x){
    (*s).top = (*s).top+1;
    (*s).kartu[(*s).top].info.angka = x.info.angka;
    (*s).kartu[(*s).top].info.bunga = x.info.bunga;
    (*s).kartu[(*s).top].status= x.status;
}

void pop (stack *s, telmkartu *x){
    (*x).info.bunga = (*s).kartu[(*s).top].info.bunga;
    (*x).info.angka = (*s).kartu[(*s).top].info.angka;
    (*x).status = (*s).kartu[(*s).top].status;
    (*s).top = (*s).top-1;
}

void enqueue (queue *q, telmkartu x){
    if ((*q).head==-1){
        (*q).head=0;
        (*q).tail=0;
        (*q).kartu[0].info.angka = x.info.angka;
        (*q).kartu[0].info.bunga = x.info.bunga;
        (*q).kartu[0].status = x.status;
    } else {
        (*q).tail++;
        (*q).kartu[(*q).tail].info.angka = x.info.angka;
        (*q).kartu[(*q).tail].info.bunga = x.info.bunga;
        (*q).kartu[(*q).tail].status = x.status;
        (*q).kartu[(*q).tail].status = 0;
    }
}

void dequeue (queue *q, telmkartu *x){
    int i;
    if ((*q).head == (*q).tail && (*q).head != -1 && (*q).tail != -1 ){
        (*x).info.angka = (*q).kartu[(*q).head].info.angka;
        (*x).info.bunga = (*q).kartu[(*q).head].info.bunga;
        (*x).status = (*q).kartu[(*q).head].status;
        (*q).head--;
        (*q).tail--;
    } else {
        (*x).info.angka = (*q).kartu[(*q).head].info.angka;
        (*x).info.bunga = (*q).kartu[(*q).head].info.bunga;
        (*x).status = (*q).kartu[(*q).head].status;
        for (i=(*q).head;i<(*q).tail;i++){
            (*q).kartu[i].info.angka = (*q).kartu[i+1].info.angka;
            (*q).kartu[i].info.bunga = (*q).kartu[i+1].info.bunga;
            (*q).kartu[i].status = (*q).kartu[i+1].status;
        }
        (*q).kartu[(*q).head].status = 1;
        (*q).tail--;
    }
}

void setkartu (part *s,tumpukan x,queue *q){
    int i,j,k,l,m;
    l=0;
    for(i=0;i<7;i++){
        k=i;
        for(j=0;j<7-i;j++){
            push(&((*s)[k]),x[l]);
            k++;
            l++;
        }
    }
    for(m=l;m<52;m++){
        enqueue(&(*q),x[m]);
    }
}

void view (part s,part2 t, queue q){
    int i,j,k;
    for (i=0;i<7;i++){
        printf("%d (%c) : ",i+1, intToInputKey(i));
        for(j=0;j<=s[i].top;j++){
            if (j==s[i].top){
                s[i].kartu[j].status=1;
            }
            if (s[i].kartu[j].status==1){
                printf("%c%s ",s[i].kartu[j].info.angka,bungaToString(s[i].kartu[j].info.bunga));
            } else {
                printf("**  ");
            }
        }
        printf("\n");
    }
    k=q.tail;
    printf("\ndeck (a) : \n");

    if (isEmptyQueue(q)!=1){
        q.kartu[q.head].status = 1;
        while (k!=q.head-1){
            if (q.kartu[k].status == 0){
                printf("**  ");
            } else {
                printf("%c%s  ",q.kartu[k].info.angka,bungaToString(q.kartu[k].info.bunga));
            }
            k--;
        }
    }
    printf("\n\n");
    for (i=0;i<4;i++){
        printf("Deck %d (%c) : ",i+1,intToInputKeyDeck(i));
        for (j=0;j<=t[i].top;j++){
            printf("%c%s  ",t[i].kartu[j].info.angka,bungaToString(t[i].kartu[j].info.bunga));
        }
        printf("\n");
    }

    printf("\nH : Heart");
    printf("\nD : Diamond");
    printf("\nC : Clove");
    printf("\nS : Spade");
    printf("\n\n");
}

int konfersitoangka (char x){
    int i;
    switch (x){
        case 'z' : i=0;break;
        case 'x' : i=1;break;
        case 'c' : i=2;break;
        case 'v' : i=3;break;
        case 'b' : i=4;break;
        case 'n' : i=5;break;
        case 'm' : i=6;break;
        case 'a' : i=7;break;
        case 's' : i=8;break;
        case 'd' : i=9;break;
        case 'f' : i=10;break;
        case 'g' : i=11;break;
    }
    return i;
}

void getcard (part *s, queue *q, telmkartu *x,  int i){
    if (i==7){
        if (isEmptyQueue((*q))!=1){
            dequeue(&(*q),&(*x));
        } else {
            (*x).info.angka=NULL;
            (*x).info.bunga=NULL;
            (*x).status=NULL;
        }
    } else {
        if (isEmptyStack((*s),i)==0){
            pop(&(*s)[i],&(*x));
        } else {
            (*x).info.angka=NULL;
            (*x).info.bunga=NULL;
            (*x).status=NULL;
        }
        if ((*s)[i].top!=-1){
            (*s)[i].kartu[(*s)[i].top].status = 1;
        }
    }
}

void putcard (part *s, part2 *t, queue *q, telmkartu x, int j){
    if (j==7){
        if (x.info.angka!=NULL){
            enqueue(&(*q),x);
        }
    } else if (j>=8 && j<=11){
            push(&((*t)[j-8]),x);
    } else {
        if (x.info.angka!=NULL){
            push(&((*s)[j]),x);
        }
    }
}

int onlyking (part s, queue q, telmkartu x, int y){
    if (isEmptyStack(s,y)==1 && x.info.angka==75){
        return 1;
    } else {
        return 0;
    }
}

int onlyAs (part2 s, telmkartu x, int y){
        if (isEmptyStack(s,y-8)==1 && x.info.angka==65){
            return 1;
        } else {
            return 0;
        }
}

int konversi (int x){
    int j;
    switch(x){
        case 65 : j=49; break;
        case 74 : j=59; break;
        case 81 : j=60; break;
        case 75 : j=61; break;
        case 48 : j=58; break;
        default : j=x; break;
    }
    return j;
}
//3 love
//4 cidu
//5 kelor
//6 skop

int iscocok (telmkartu x, telmkartu y){
    int a,b;
        a = konversi(x.info.angka);
        b = konversi(y.info.angka);
        if (b-a==1){
            if ((y.info.bunga == 3 && x.info.bunga == 3) ||
                (y.info.bunga == 3 && x.info.bunga == 4) ||
                (y.info.bunga == 4 && x.info.bunga == 3) ||
                (y.info.bunga == 4 && x.info.bunga == 4) ||
                (y.info.bunga == 5 && x.info.bunga == 5) ||
                (y.info.bunga == 6 && x.info.bunga == 5) ||
                (y.info.bunga == 6 && x.info.bunga == 6) ||
                (y.info.bunga == 5 && x.info.bunga == 6)){
                return 0;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
}

int iscocok2 (telmkartu x, telmkartu y){
    int a,b;

        a = konversi(x.info.angka);
        b = konversi(y.info.angka);
        if (a-b==1){
            if ((y.info.bunga == 3 && x.info.bunga == 3) ||
                (y.info.bunga == 4 && x.info.bunga == 4) ||
                (y.info.bunga == 5 && x.info.bunga == 5) ||
                (y.info.bunga == 6 && x.info.bunga == 6)){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
}

void tukar (part *s,part2 *t, queue *q, int x, int y){
    telmkartu z;
    stack temp;
    int i = 0;
    int found = 0;
    if (x<8 && y>=8 && y<=11){
        if (x==7){
            if ((onlyAs((*t),(*q).kartu[(*q).head],y)==1) || iscocok2((*q).kartu[(*q).head],(*t)[y-8].kartu[(*t)[y-8].top])==1){
                getcard(&(*s),&(*q),&z,x);
                putcard(&(*s),&(*t),&(*q),z,y);
            }
        } else {
            if ((onlyAs((*t),(*s)[x].kartu[(*s)[x].top],y)==1) || iscocok2((*s)[x].kartu[(*s)[x].top],(*t)[y-8].kartu[(*t)[y-8].top])==1){
                getcard(&(*s),&(*q),&z,x);
                putcard(&(*s),&(*t),&(*q),z,y);
            }
        }
    } else if (x!=7){
        temp.top = -1;
        while (i<(*s)[x].top && found !=1) {
            if ((*s)[x].kartu[i].status==1){
                found = 1;
            } else {
                i++;
            }
        }

        if (onlyking((*s),(*q),(*s)[x].kartu[i],y)==1 || iscocok((*s)[x].kartu[i],(*s)[y].kartu[(*s)[y].top])==1) {
            while ((*s)[x].top>=i){
                getcard(&(*s),&(*q),&z,x);
                push(&temp,z);
        }
            while (temp.top!=-1){
                pop(&temp,&z);
                putcard(&(*s),&(*t),&(*q),z,y);
            }
        }
    } else {
        if (x==y || iscocok((*q).kartu[(*q).head],(*s)[y].kartu[(*s)[y].top])==1 || onlyking((*s),(*q),(*q).kartu[(*q).head],y)==1){
            getcard(&(*s),&(*q),&z,x);
            putcard(&(*s),&(*t),&(*q),z,y);
        }
    }
}

int gamefinish (part2 x){
    if (x[0].kartu[x[0].top].info.angka == 75 &&
        x[1].kartu[x[1].top].info.angka == 75 &&
        x[2].kartu[x[2].top].info.angka == 75 &&
        x[3].kartu[x[3].top].info.angka == 75){
        return 1;
    } else {
        return 0;
    }
}

char* bungaToString(int bunga){
    switch(bunga){
    case 3:
        return ANSI_COLOR_RED "H" ANSI_COLOR_RESET;
    case 4:
        return ANSI_COLOR_RED "D" ANSI_COLOR_RESET;
    case 5:
        return "C";
    case 6:
        return "S";
    }
    return "undefinied";
}

infotype getHand(part *s, part2 t, queue q, char key){
    switch (key){
        case 'z' : return (*s)[0].kartu[(*s)[0].top].info;
        case 'x' : return (*s)[1].kartu[(*s)[1].top].info;
        case 'c' : return (*s)[2].kartu[(*s)[2].top].info;
        case 'v' : return (*s)[3].kartu[(*s)[3].top].info;
        case 'b' : return (*s)[4].kartu[(*s)[4].top].info;
        case 'n' : return (*s)[5].kartu[(*s)[5].top].info;
        case 'm' : return (*s)[6].kartu[(*s)[6].top].info;
        case 'a' :
            if(isEmptyQueue(q)!=1)
                return q.kartu[q.head].info;
            break;
        case 's' : return (t)[0].kartu[(t)[0].top].info;
        case 'd' : return (t)[1].kartu[(t)[1].top].info;
        case 'f' : return (t)[2].kartu[(t)[2].top].info;
        case 'g' : return (t)[3].kartu[(t)[3].top].info;

    }
    infotype hand;
    hand.angka=NULL;
    hand.bunga=NULL;
    return hand;
}

void printHand(infotype hand){
    if(hand.angka == NULL){
        printf("\nHand : null");
        return;
    }
    printf("\nHand : %c%s",hand.angka,bungaToString(hand.bunga));
}

char intToInputKey(int i){
    switch (i){
        case 0 : return 'z';
        case 1 : return 'x';
        case 2 : return 'c';
        case 3 : return 'v';
        case 4 : return 'b';
        case 5 : return 'n';
        case 6 : return 'm';
    }
    return '0';
}

char intToInputKeyDeck(int i){
    switch (i){
        case 0 : return 's';
        case 1 : return 'd';
        case 2 : return 'f';
        case 3 : return 'g';
    }
    return '0';
}
