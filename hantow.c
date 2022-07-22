#include <stdio.h>
#include <unistd.h>
#include <string.h> 
int peg1[9], peg2[9], peg3[9];
int nod;
void printX(){
int i;
    for (i=0; i<((2*nod)+1); i++) printf("X");
    printf("     ");
    for (i=0; i<((2*nod)+1); i++) printf("X");
    printf("     ");
    printf("     ");
    printf("\n\n");
}
void printTowLn(int radius){
    int s = (nod);
    int i;
    for (i=0; i<(s-radius);i++) printf(" ");
    for (i=0; i<(radius);i++) printf("+");
    printf("|");
    for (i=0; i<(radius);i++) printf("+");
    for (i=0; i<(s-radius);i++) printf(" ");
    printf("     ");
}
void printLn(int radius1, int radius2, int radius3){
    printTowLn(radius1);
    printTowLn(radius2);
    printTowLn(radius3);
    printf("\n");
}
void display_pegs(){
    int i;    
    for (i=8; i>=0 ; i--) {
        printLn(peg1[i],peg2[i],peg3[i]);
    }
    
    printX();
}
void move (int pegA[9], int pegB[9]){
    //make move
    int i;
    for (i=0; i<9 && pegA[i]!=0; i++){}
    i--;
    int j;
    for (j=0; j<9 && pegB[j]!=0; j++){}
    pegB[j]= pegA[i];
    pegA[i]= 0;
    display_pegs();
    sleep(1);
}
void hantow(int nod, int pego[9],int pegd[9], int pegh[9]){
    if (nod > 1) hantow (nod-1,pego,pegh,pegd);
    move (pego,pegd);
    if (nod > 1) hantow (nod-1,pegh,pegd,pego);
}
int main(int argc, char *argv[]) {
    int size = sizeof argv[1] / sizeof argv[1][0];
    if (argc != 2) {
        printf("Error, incorrect number of arguments\n");
        return 0;
    } if (strlen(argv[1]) != 1){
        printf("Error, wrong length\n");
        return 0;
    } if (argv[1][0] < '1' || argv[1][0] > '9'){
        printf("Error, wrong input\n");
        return 0;
    }
    nod = argv[1][0]-'0';
    int x = nod;
    // Initialize pegs
    int i;
    for (i = 0; i<9; i++){
        peg2[i]= 0;
        peg3[i]=0;
        peg1[i]=x;
        if (x>0) x--;
    }
    
    display_pegs();
    hantow(nod,peg1,peg2,peg3);
    printf("done\n");
}
