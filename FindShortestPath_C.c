#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double WALLMATRIX[3][3][3];
WALLMATRIX M0 = {{{ 0, 1, 0},
                  { 1, 1, 1 },
                  { 0, 1, 0 }}};

WALLMATRIX M1 = {{{ 0, 1, 0},
                  { 1, 1, 0 },
                  { 0, 1, 0 }}};

WALLMATRIX M2 = {{{ 0, 1, 0},
                  { 1, 1, 1 },
                  { 0, 0, 0 }}};

WALLMATRIX M3 = {{{ 0, 1, 0},
                  { 1, 1, 0 },
                  { 0, 0, 0 }}};

WALLMATRIX M4 = {{{ 0, 1, 0},
                  { 0, 1, 1 },
                  { 0, 1, 0 }}};

WALLMATRIX M5 = {{{ 0, 1, 0},
                  { 0, 1, 1 },
                  { 0, 1, 0 }}};


WALLMATRIX M6 = {{{ 0, 1, 0},
                  { 0, 1, 1 },
                  { 0, 0, 0 }}};

WALLMATRIX M7 = {{{ 0, 1, 0},
                  { 0, 1, 0 },
                  { 0, 0, 0 }}};

WALLMATRIX M8 = {{{ 0, 0, 0},
                  { 1, 1, 1 },
                  { 0, 1, 0 }}};

WALLMATRIX M9 = {{{ 0, 0, 0},
                  { 1, 1, 0 },
                  { 0, 1, 0 }}};

WALLMATRIX M10 = {{{ 0, 0, 0},
                   { 1, 1, 1 },
                   { 0, 0, 0 }}};

WALLMATRIX M11 = {{{ 0, 0, 0},
                   { 1, 1, 0 },
                   { 0, 0, 0 }}};

WALLMATRIX M12 = {{{ 0, 0, 0},
                   { 0, 1, 1 },
                   { 0, 1, 0 }}};

WALLMATRIX M13 = {{{ 0, 0, 0},
                   { 0, 1, 0 },
                   { 0, 1, 0 }}};


void get2Tokens(char* str, int* intarr2) {
int i1=0,i2=0;
sscanf( str, "%d %d", &i1, &i2);
intarr2[0]=i1;
intarr2[1]=i2;
return ;
}

void get3Tokens(char* str, int* intarr3) {
int i1=0,i2=0,i3=0;
sscanf( str, "%d %d %d", &i1, &i2, &i3);
intarr3[0]=i1;
intarr3[1]=i2;
intarr3[2]=i3;
return ;
}

void getNTokens(char* str, int* intarr, int N) {
    /*char sdigitd[101] ;
    sdigitd[100]=0;*/
    int n=0;
    char *p = strtok(str, " ");
    while (p) {
        if(n>=N){
            return;
        }
        intarr[n++] = atoi(p);
        p = strtok(NULL, " ");
    }

    return ;
}


void fillWalls(int intarr, WALLMATRIX* wm) {
    /*char sdigitd[101] ;
    sdigitd[100]=0;*/
    /*
    (*wm)[0][0]=
    (*wm)[0][0]=
    (*wm)[0][0]=

    (*wm)[1][0]=
    (*wm)[1][0]=
    (*wm)[1][0]=

    (*wm)[2][0]=
    (*wm)[2][0]=
    (*wm)[2][0]=
*/
    return ;

} /* fillWalls*/

int main()
{

    /* Input file with maze information */

    FILE *mazeinfo=NULL;

    /* Reading maze text file */

    fopen_s(&mazeinfo,"C:/Users/anand.rathi/Documents/tmp/JAI/maze.txt","r");


    if (mazeinfo == NULL)
    {
        perror("Error Opening File\n");
        return(-1);
    }
    int totRowCol[2];
    int startRowCol[2];
    int endRowCol[2];

    char line[100 + 1] = "";  /* initialize all to 0 ('\0') */
    char *chkret=NULL;

    int *matrixRC =  0;
    WALLMATRIX *wallmatrixRC=NULL;
    int i=0;


    chkret = fgets(line, sizeof(line), mazeinfo );
    printf("1st line:%s \n", chkret);
    if (chkret!=NULL){
        get2Tokens(chkret, totRowCol);
    }
    printf("Row:%d, Col:%d  \n",totRowCol[0], totRowCol[1]);

    chkret = fgets(line, sizeof(line), mazeinfo );
    printf("2nd line:%s \n ", chkret);
    if (chkret!=NULL){
        get2Tokens(chkret, startRowCol);
    }
    printf("Strart Row:%d, Col:%d  \n", startRowCol[0], startRowCol[1]);

    chkret = fgets(line, sizeof(line), mazeinfo );
    printf("3rd line:%s \n ", chkret);
    if (chkret!=NULL){
        get2Tokens(chkret, endRowCol);
    }
    printf("End Row:%d, Col:%d  \n",endRowCol[0], endRowCol[1]);

    /* Create new Matrix of sizxe R,C*/
    matrixRC =  (int*)malloc(sizeof(int) * totRowCol[0] * totRowCol[1] );
    /* Create new array of WALLMATRIX for each  R,C */
    wallmatrixRC = (WALLMATRIX*)malloc(sizeof(WALLMATRIX) * totRowCol[0] * totRowCol[1] );

    int Cols = totRowCol[1];
    for(i=0;i<totRowCol[0];i++) {
        chkret = fgets(line, sizeof(line), mazeinfo );
        if (chkret!=NULL){
            getNTokens(chkret, &matrixRC[i*Cols] , Cols);
         }/* if*/
     }/* for */
    int r=0,c=0;
    for(r=0;r<totRowCol[0];r++) {
        for(c=0;c<totRowCol[1];c++) {
            printf( "%d " ,matrixRC[r*Cols + c]);
            fillWalls( matrixRC[r*Cols + c], (wallmatrixRC +r*Cols + c));
         }/* for c*/
         printf( "\n" );
     }/* for r */


    for(r=0;r<totRowCol[0];r++) {
        for(c=0;c<totRowCol[1];c++) {
            WALLMATRIX* wallRC = &wallmatrixRC[r*Cols + c];
            printf( "%d %d %d\n%d %d %d\n %d %d %d\n " ,
                   wallRC[0][0][0] , wallRC[0][0][1], wallRC[0][0][2]
                   ,wallRC[0][1][0] , wallRC[0][2][1], wallRC[0][2][2]
                   ,wallRC[0][2][0] , wallRC[0][2][1], wallRC[0][3][2]
                   );
         }/* for c*/
         printf( "\n" );
     }/* for r */

     return 0;

} /* MAIN */
