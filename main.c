#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ShipBattle.h"
#define ROW 3
#define COLUMN 3

void printShip(){
    printf("\n\n\n");
printf("                        C                                    \n");
printf("                CCCCCCCC C                                   \n");
printf("              CCC      C C       C                           \n");
printf("                CC     C C     C  C                          \n");
printf("                 CCCCCCC C   C     C                         \n");
printf("                       C C C        C        !sink your ship!\n");
printf("                       C C           C                       \n");
printf("                       C C            C                      \n");
printf("                       C C             C                     \n");
printf("                       C C             C                     \n");
printf("                       C C            C                      \n");
printf("                       C C           C                       \n");
printf("                       C C          C                        \n");
printf("                       C C         C                         \n");
printf("                       C C        C                          \n");
printf("                       C C       C                           \n");
printf("                       C C CCCCCC                            \n");
printf("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\n");
printf("  CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC  \n");
printf("    CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC    \n");
printf("      CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC      \n");
printf("        CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC        \n");
printf("          CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC          \n");
printf("            CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC            \n");
printf("\n\n\n");
system("pause");
printf("\n\n");
printf("        CCCC    C   C       C  C   C  \n");
printf("        C       C   C C     C  C  C   \n");
printf("        C       C   C   C   C  C C    \n");
printf("         CCC    C   C    C  C  CC     \n");
printf("            C   C   C     C C  C C    \n");
printf("            C   C   C      CC  C  C   \n");
printf("        CCCC    C   C       C  C   C  \n");
printf("\n\n");
printf("                   C   CCCCCCC   \n");
printf("                   C      C      \n");
printf("                   C      C      \n");
printf("                   C      C      \n");
printf("                   C      C      \n");
printf("                   C      C      \n");
printf("                   C      C      \n");
printf("\n\n\n\n");
}

void drawTable(){
    int i, j;
    int array[ROW][COLUMN];
    printf("\n");
    for(i=0; i<ROW; ++i){
        for(j=0; j<COLUMN;j++){
            array[i][j]=0;
            printf("%3d", array[i][j]);
        }
        printf("\n\n");
    }
}

int randPopulate(int ships[ROW][COLUMN])
{
    int i,j,count=0;
    srand((unsigned)time(0));
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            ships[i][j]=rand()%2+0;
            if(ships[i][j]==1)
            {
                count++;
            }
        }
    }
    return count;
}
void answers(int ships[ROW][COLUMN])
{
    FILE *fptr;
    fptr=fopen("answers.txt", "w");
    int i,j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            printf("%d ", ships[i][j]);
            fprintf(fptr, "%d ", ships[i][j]);
            fclose(fptr);
        }
        printf("\n");
    }
}

void startGame(){
  int shipsMatrix[ROW][COLUMN];
  int ships=randPopulate(shipsMatrix);
  char choice;
  printf("--IF YOU WANT TO START PLAYING GAME PRESS S--\n");
  printf("--IF YOU WANT TO THE RULES PRESS R-----------\n");
  printf("--IF YOU WANT TO SEE ANSWERS AND STOP PRESS a----\n");
  printf("--IF YOU WANT TO QUIT PRESS Q----------------\n");

 scanf("%c", &choice);
 scanf("%c", &choice);
  switch(choice){
    case 's':
    case 'S':   system("CLS");
                drawTable();
                printf("You have to sink %d ships\n", ships);
                printf("You have %d chances for that\n", ROW*COLUMN/2+ROW);

                playGame(shipsMatrix);
            break;
    case 'R':
    case 'r': rules();
            break;
    case 'a':
    case 'A': answers(shipsMatrix);
    case 'q':
    case 'Q': break;
  }
}


void playGame(int shipsMatrix[ROW][COLUMN]){
    int numGuesses=0; int i=1;
    battler user;
    char username[20];
    user.userName=NULL;
    printf("\nEnter your name: \n");
    scanf("%s", username);
    username[strlen(username) - 1] = '\0';
    user.userName = (char*)malloc((strlen(username)+1)*sizeof(char));
    strcpy(user.userName, username);

    printf("Good luck %s\n", user.userName);
    printf("Start sinking ships\n");
    printf("\n");
    coordSyst system;
    do{
    printf("\nEnter your number %d guess\n", i);
    printf("\n coordinate x=?\n  ");
    scanf("%d", &system.x);
    //validation
        while(system.x>ROW || system.x<1) {
            printf("Invalid option, try again ");
            scanf("%d", &system.x);
        }
    printf("coordinate y=?\n  ");
    scanf("%d", &system.y);
        while(system.y>ROW || system.y<1) {
            printf("Invalid option, try again ");
            scanf("%d", &system.y);
        }
    if(shipsMatrix[system.x][system.y]==1){
        printf("!!you got it :) \n");
        numGuesses++;
    }
    else printf("!!you missed :( \n");

    if(i>=ROW*COLUMN*3/4 && numGuesses!=randPopulate(shipsMatrix)) {
           printf("You have used up all your %d chances and lost the game\n", ROW*COLUMN*3/4);
           break;
           }
    i++;
     if(numGuesses==randPopulate(shipsMatrix)){
        printf("Congratulations you have won the game\n");
        break;
    }
    } while(numGuesses!=randPopulate(shipsMatrix));
     startGame();
}

void rules(){



printf("*****************************************************************************\n");
printf("In this game your enemy is computer which has put several ships on a matrix\n");
printf("Your objective in this game is to find these hidden ships and not use up all your chances\n");
printf("At first compiler tells you how many ships you have to think and how many chances you have for that\n");
printf("You are given 75% chances out of all possibilities to win\n");
printf("You will lose if you use up all your chances and not guess where all of the ships are\n");
printf("However you are given a chance to play again after that and win the game :)");
printf("******************************************************************************\n");
startGame();
}
int main(){
  printShip();
  int shipsMatrix[ROW][COLUMN];
  int ships=randPopulate(shipsMatrix);
  char choice;
  printf("---------------------------------------------\n");
  printf("----------WELCOME TO THE SHIP BATTLE---------\n");
  printf("--IF YOU WANT TO START PLAYING GAME PRESS S--\n");
  printf("--IF YOU WANT TO THE RULES PRESS R-----------\n");
  printf("--IF YOU WANT TO SEE ANSWERS AND STOP PRESS A----\n");
  printf("--IF YOU WANT TO QUIT PRESS Q----------------\n");

 scanf("%c", &choice);

  switch(choice){
    case 's':
    case 'S':   system("CLS");
                drawTable();
                printf("You have to sink %d ships\n", ships);
                printf("You have %d chances for that\n", ROW*COLUMN*3/4);
                playGame(shipsMatrix);
            break;
    case 'R':
    case 'r': rules();
            break;
    case 'a':
    case 'A': answers(shipsMatrix);
    case 'q':
    case 'Q': break;
}
return 0;
}
