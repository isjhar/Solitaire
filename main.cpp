#include "file.h"

int i,hand1,hand2;
tumpukan deck,deckbaru;
part s;
part2 t;
queue q;
telmkartu x;
char y,z;
int pil;


int main(){
    /*createtumpukan(&deck);
    shufflecard(&deck);
    shufflecard(&deck);*/
    while (pil!=3){
        y='w';
        if (pil!=2){
            createtumpukan(&deck);
            createemptystack(&s);
            createemptystack2(&t);
            createemptyqueue(&q);
        }
        system("cls");
        printf("-----Game Solitaire-----");
        printf("\n1. Main");
        printf("\n2. Shuffle Card");
        printf("\n3. Exit");
        printf("\nMasukkan Pilihan : ");scanf("%d",&pil);
        switch (pil){
            case 1 :
                shufflecard(&deck);
                setkartu(&s,deck,&q);
                while (y!='q' && gamefinish(t)!=1){
                    system("cls");
                    view(s,t,q);
                    y=getch();
                    z=getch();
                    hand1=konfersitoangka(y);
                    hand2=konfersitoangka(z);
                    if ((hand1!=7 && hand2!=7 && hand1!=hand2)|| (hand1==7) || (hand1==7 && hand2==7 )){
                        tukar(&s,&t,&q,hand1,hand2);
                    }
                }
                if (gamefinish(t)==1){
                    printf("\nPermainan Selesai, Tekan terserah untuk ke menu utama");
                } else {
                    printf("\nTekan terserah untuk ke menu utama");
                }
                break;
            case 2 :
                shufflecard(&deck);
                printf("Shuffle Card Berhasil");
                break;
        }
        getch();
    }
    return 0;
}


