#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y);
void loadData();
void showBoard();
void player1();
void player2();
void player3();
void player4();
void xMovement(int px);
void oMovement(int px);
void movement3(int px);
void movement4(int px);
void header();

char data[33][48];
int diceNum = 0;
int i, j;
int playerX[4][2] = {
    {6, 10},
    {8, 10},
    {6, 11},
    {8, 11}};
int playerO[4][2] = {
    {32, 2},
    {34, 2},
    {32, 3},
    {34, 3}};
int playerThree[4][2] = {
    {37, 21},
    {39, 21},
    {37, 22},
    {39, 22}};
int playerFour[4][2] = {
    {14, 28},
    {16, 28},
    {14, 29},
    {16, 29}};
int score1 = 0, score2 = 0, score3 = 0, score4 = 0;
char name1[100];
char name2[100];
char name3[100];
char name4[100];

int main()
{
    int option = 100;
    loadData();
    while (option != 4)
    {
        system("cls");
        PlaySound("game.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        header();
        printf("1. Play Game \n");
        printf("2. Rules of Game \n");
        printf("3. Show Board \n");
        printf("4. Exit \n");
        printf("Select one option:  \n");
        int option;
        scanf("%d", &option);
        if (option == 1)
        {
            int choice = 100;
            while (choice != 4)
            {
                PlaySound("game.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                system("cls");
                header();
                playerX[0][0] = playerX[2][0] = 6;
                playerX[0][1] = playerX[1][1] = 10;
                playerX[1][0] = playerX[3][0] = 8;
                playerX[2][1] = playerX[3][1] = 11;

                playerO[0][0] = playerO[2][0] = 32;
                playerO[0][1] = playerO[1][1] = 2;
                playerO[1][0] = playerO[3][0] = 34;
                playerO[2][1] = playerO[3][1] = 3;

                playerThree[0][0] = playerThree[2][0] = 37;
                playerThree[0][1] = playerThree[1][1] = 21;
                playerThree[1][0] = playerThree[3][0] = 39;
                playerThree[2][1] = playerThree[3][1] = 22;

                playerFour[0][0] = playerFour[2][0] = 14;
                playerFour[0][1] = playerFour[1][1] = 28;
                playerFour[1][0] = playerFour[3][0] = 16;
                playerFour[2][1] = playerFour[3][1] = 29;

                printf("1. Two Player Ludo \n");
                printf("2. Three Player Ludo \n");
                printf("3. Four Player Ludo \n");
                printf("3. Back \n");
                int choice;
                printf("Enter one option: \n");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    system("cls");
                    header();
                    printf("Enter player 1 name: ");
                    scanf("%s", name1);
                    printf("Enter player 3 name: ");
                    scanf("%s", name3);
                    PlaySound(0, 0, 0);
                    system("cls");
                    showBoard();
                    while (1)
                    {
                        gotoxy(0, 0);
                        printf("%d", score1);
                        gotoxy(48, 32);
                        printf("%d", score3);
                        gotoxy(24, 16);
                        printf("%d", diceNum);
                        player1();
                        player3();
                        if (score1 == 4 || score3 == 4)
                        {
                            break;
                        }
                    }
                    system("cls");
                    PlaySound("game.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                    if (score1 == 4)
                    {
                        printf("Player 1 %s is winner", name1);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                    if (score3 == 4)
                    {
                        printf("Player 3 %s is winner", name3);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                }
                if (choice == 2)
                {
                    system("cls");
                    header();
                    printf("Enter player 1 name: ");
                    scanf("%s", name1);
                    printf("Enter player 2 name: ");
                    scanf("%s", name2);
                    printf("Enter player 3 name: ");
                    scanf("%s", name3);
                    PlaySound(0, 0, 0);
                    system("cls");
                    showBoard();
                    while (1)
                    {
                        gotoxy(0, 0);
                        printf("%d", score1);
                        gotoxy(48, 0);
                        printf("%d", score2);
                        gotoxy(48, 32);
                        printf("%d", score3);
                        gotoxy(24, 16);
                        printf("%d", diceNum);
                        player1();
                        player2();
                        player3();
                        if (score1 == 4 || score2 == 4 || score3 == 4)
                        {
                            break;
                        }
                    }
                    system("cls");
                    PlaySound("game.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                    if (score1 == 4)
                    {
                        printf("Player 1 %s is winner", name1);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                    if (score2 == 4)
                    {
                        printf("Player 2 %s is winner", name2);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                    if (score3 == 4)
                    {
                        printf("Player 3 %s is winner", name3);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                }
                if (choice == 3)
                {
                    system("cls");
                    header();
                    printf("Enter player 1 name: ");
                    scanf("%s", name1);
                    printf("Enter player 2 name: ");
                    scanf("%s", name2);
                    printf("Enter player 3 name: ");
                    scanf("%s", name3);
                    printf("Enter player 4 name: ");
                    scanf("%s", name4);
                    PlaySound(0, 0, 0);
                    system("cls");
                    showBoard();
                    while (1)
                    {
                        gotoxy(0, 0);
                        printf("%d", score1);
                        gotoxy(48, 0);
                        printf("%d", score2);
                        gotoxy(48, 32);
                        printf("%d", score3);
                        gotoxy(0, 32);
                        printf("%d", score4);
                        gotoxy(24, 16);
                        printf("%d", diceNum);
                        player1();
                        player2();
                        player3();
                        player4();
                        if (score1 == 4 || score2 == 4 || score3 == 4 || score4 == 4)
                        {
                            break;
                        }
                    }
                    system("cls");
                    PlaySound("game.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                    if (score1 == 4)
                    {
                        printf("Player 1 %s is winner", name1);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                    if (score2 == 4)
                    {
                        printf("Player 2 %s is winner", name2);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                    if (score3 == 4)
                    {
                        printf("Player 3 %s is winner", name3);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                    if (score4 == 4)
                    {
                        printf("Player 4 %s is winner", name4);
                        getch();
                        PlaySound(0, 0, 0);
                    }
                }
            }
        }
        if (option == 2)
        {
            system("cls");
            header();
            printf("Rules of game \n");
            printf("1. If you press any key else 'F' or 'f' then you lost your move \n");
            printf("2. If you press any worng key to change position of token then you will lose your move \n");
            printf("3. Clockwise movement of your tokens \n");
            getch();
        }
        if (option == 3)
        {
            system("cls");
            showBoard();
            getch();
        }
    }
}

void player1()
{
    char a = 0;
    int position = 0;
    gotoxy(0, 34);
    printf("%s Press 'F' or 'f' to move your dice \n", name1);
    scanf(" %c", &a);
    gotoxy(0, 34);
    printf(" ");
    gotoxy(0, 35);
    printf("     ");
    int b = a;
    if (b == 70 || b == 102)
    {
        diceNum = rand() % 7;
        if (diceNum == 0)
        {
            diceNum = 1;
        }
        gotoxy(24, 16);
        printf(" ");
        PlaySound(TEXT("move.wav"), NULL, SND_SYNC);
        gotoxy(24, 16);
        printf("%d", diceNum);
        gotoxy(24, 16);
        getch();
    }
    if (diceNum > 0)
    {
        int position;
        gotoxy(0, 34);
        printf("%s Which you want to move 1 2 3 or 4 \n", name1);
        scanf("%d", &position);
        gotoxy(0, 34);
        printf("				\n");
        gotoxy(0, 35);
        printf("     \n");
        if (position == 1)
        {
            int px = 0;
            xMovement(px);
        }
        else if (position == 2)
        {
            int px = 1;
            xMovement(px);
        }
        else if (position == 3)
        {
            int px = 2;
            xMovement(px);
        }
        else if (position == 4)
        {
            int px = 3;
            xMovement(px);
        }
    }
}

void player2()
{
    char a = 0;
    int position = 0;
    gotoxy(0, 34);
    printf("%s Press 'F' or 'f' to move your dice \n", name2);
    scanf(" %c", &a);
    gotoxy(0, 34);
    printf(" ");
    gotoxy(0, 35);
    printf("     ");
    int b = a;
    if (b == 70 || b == 102)
    {
        diceNum = rand() % 7;
        if (diceNum == 0)
        {
            diceNum = 1;
        }
        gotoxy(24, 16);
        printf(" ");
        PlaySound(TEXT("move.wav"), NULL, SND_SYNC);
        gotoxy(24, 16);
        printf("%d", diceNum);
        gotoxy(24, 16);
        getch();
    }
    if (diceNum > 0)
    {
        int position;
        gotoxy(0, 34);
        printf("%s Which you want to move 1 2 3 or 4 \n", name2);
        scanf("%d", &position);
        gotoxy(0, 34);
        printf("     \n");
        gotoxy(0, 35);
        printf("     \n");
        if (position == 1)
        {
            int px = 0;
            oMovement(px);
        }
        else if (position == 2)
        {
            int px = 1;
            oMovement(px);
        }
        else if (position == 3)
        {
            int px = 2;
            oMovement(px);
        }
        else if (position == 4)
        {
            int px = 3;
            oMovement(px);
        }
    }
}

void player3()
{
    char a = 0;
    int position = 0;
    gotoxy(0, 34);
    printf("%s Press 'F' or 'f' to move your dice \n", name3);
    scanf(" %c", &a);
    gotoxy(0, 34);
    printf("				\n");
    gotoxy(0, 35);
    printf("      ");
    int b = a;
    if (b == 70 || b == 102)
    {
        diceNum = rand() % 7;
        if (diceNum == 0)
        {
            diceNum = 1;
        }
        gotoxy(24, 16);
        printf(" ");
        PlaySound(TEXT("move.wav"), NULL, SND_SYNC);
        gotoxy(24, 16);
        printf("%d", diceNum);
        gotoxy(24, 16);
        getch();
    }
    if (diceNum > 0)
    {
        int position;
        gotoxy(0, 34);
        printf("%s Which you want to move 1 2 3 or 4 \n", name3);
        scanf("%d", &position);
        gotoxy(0, 34);
        printf("				\n");
        gotoxy(0, 35);
        printf("     \n");
        if (position == 1)
        {
            int px = 0;
            movement3(px);
        }
        else if (position == 2)
        {
            int px = 1;
            movement3(px);
        }
        else if (position == 3)
        {
            int px = 2;
            movement3(px);
        }
        else if (position == 4)
        {
            int px = 3;
            movement3(px);
        }
    }
}

void player4()
{
    char a = 0;
    int position = 0;
    gotoxy(0, 34);
    printf("%s Press 'F' or 'f' to move your dice \n", name4);
    scanf(" %c", &a);
    gotoxy(0, 34);
    printf("				\n");
    gotoxy(0, 35);
    printf("      ");
    int b = a;
    if (b == 70 || b == 102)
    {
        diceNum = rand() % 7;
        if (diceNum == 0)
        {
            diceNum = 1;
        }
        gotoxy(24, 16);
        printf(" ");
        PlaySound(TEXT("move.wav"), NULL, SND_SYNC);
        gotoxy(24, 16);
        printf("%d", diceNum);
        gotoxy(24, 16);
        getch();
    }
    if (diceNum > 0)
    {
        int position;
        gotoxy(0, 34);
        printf("%s Which you want to move 1 2 3 or 4 \n", name4);
        scanf("%d", &position);
        gotoxy(0, 34);
        printf("				\n");
        gotoxy(0, 35);
        printf("     \n");
        if (position == 1)
        {
            int px = 0;
            movement4(px);
        }
        else if (position == 2)
        {
            int px = 1;
            movement4(px);
        }
        else if (position == 3)
        {
            int px = 2;
            movement4(px);
        }
        else if (position == 4)
        {
            int px = 3;
            movement4(px);
        }
    }
}

void xMovement(int px)
{
    gotoxy(playerX[px][0], playerX[px][1]);
    printf(" \n");
    for (i = 0; i < 4; i++)
    {
        if (px != 1)
        {
            if (playerX[px][0] == playerX[i][0] && playerX[px][1] == playerX[px][1])
            {
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x \n");
            }
        }
    }
    if ((playerX[px][0] == 5 && playerX[px][1] == 14) || (playerX[px][0] == 8 && playerX[px][1] == 18) || (playerX[px][0] == 20 && playerX[px][1] == 29) || (playerX[px][0] == 27 && playerX[px][1] == 27) || (playerX[px][0] == 20 && playerX[px][1] == 5) || (playerX[px][0] == 27 && playerX[px][1] == 3) || (playerX[px][0] == 39 && playerX[px][1] == 14) || (playerX[px][0] == 42 && playerX[px][1] == 18))
    {
        for (i = 0; i < 4; i++)
        {
            if (playerX[px][0] == playerX[i][0] && playerX[px][1] == playerX[px][1])
            {
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("o \n");
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerX[px][0] == playerThree[i][0] && playerX[px][1] == playerThree[px][1])
            {
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("@ \n");
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerX[px][0] == playerFour[i][0] && playerX[px][1] == playerFour[px][1])
            {
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("* \n");
            }
        }
    }
    if (playerX[px][0] == 6 && playerX[px][1] == 10)
    {
        if (diceNum == 6)
        {
            gotoxy(5, 14);
            printf("x");
            playerX[px][0] = 5;
            playerX[px][1] = 14;
        }
        else
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerX[px][0] == 8 && playerX[px][1] == 10)
    {
        if (diceNum == 6)
        {
            data[8][10] = ' ';
            gotoxy(5, 14);
            printf("x");
            playerX[px][0] = 5;
            playerX[px][1] = 14;
        }
        else
        {
            gotoxy(8, 10);
            printf("x \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerX[px][0] == 6 && playerX[px][1] == 11)
    {
        if (diceNum == 6)
        {
            gotoxy(5, 14);
            printf("x");
            playerX[px][0] = 5;
            playerX[px][1] = 14;
        }
        else
        {
            gotoxy(6, 11);
            printf("x \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerX[px][0] == 8 && playerX[px][1] == 11)
    {
        if (diceNum == 6)
        {
            gotoxy(5, 14);
            printf("x");
            playerX[px][0] = 5;
            playerX[px][1] = 14;
        }
        else
        {
            gotoxy(8, 11);
            printf("x \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerX[px][0] >= 5 && playerX[px][0] <= 17 && playerX[px][1] == 14)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerX[px][0] = (playerX[px][0]) + a;
        if (playerX[px][0] <= 17)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else if (playerX[px][0] > 17)
        {
            b = (playerX[px][0] - 17) / 3;
            playerX[px][0] = 20;
            playerX[px][1] = playerX[px][1] - (1 + (b * 2));
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][0] == 20 && playerX[px][0] >= 1 && playerX[px][1] <= 11)
    {
        int a = 0, b = 0, c = 0;
        a = diceNum * 2;
        playerX[px][1] = (playerX[px][1]) - a;
        if (playerX[px][1] >= 1)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (((-1) * (playerX[px][1])) + 1) / 2;
            if (b <= 2)
            {
                playerX[px][1] = 1;
                if (b == 1)
                {
                    playerX[px][0] = 23;
                }
                else
                {
                    playerX[px][0] = 27;
                }
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x");
            }
            else
            {
                c = 1 + ((b - 2) * 2);
                playerX[px][0] = 27;
                playerX[px][1] = c;
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x");
            }
        }
    }
    else if (playerX[px][0] == 23 && playerX[px][1] == 1)
    {
        int a = 0, b = 0;
        a = playerX[px][0] + diceNum + 3;
        if (a == 27)
        {
            playerX[px][0] = a;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (diceNum * 2) - 1;
            playerX[px][0] = 27;
            playerX[px][1] = b;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][0] == 27 && playerX[px][1] >= 1 && playerX[px][1] <= 11)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerX[px][1] = (playerX[px][1]) + a;
        if (playerX[px][1] <= 11)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else if (playerX[px][1] > 11)
        {
            b = (playerX[px][1] - 11) / 2;
            playerX[px][0] += b * 3;
            playerX[px][1] = 14;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][0] >= 30 && playerX[px][0] <= 45 && playerX[px][1] == 14)
    {
        int a = 0, b = 0, c = 0;
        a = diceNum * 3;
        playerX[px][0] = (playerX[px][0]) + a;
        if (playerX[px][0] <= 45)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (playerX[px][0] - 45) / 3;
            if (b <= 2)
            {
                playerX[px][0] = 45;
                if (b == 1)
                {
                    playerX[px][1] = 16;
                }
                else
                {
                    playerX[px][1] = 18;
                }
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x");
            }
            else
            {
                c = ((b - 2) * 3);
                playerX[px][0] = 45 - c;
                playerX[px][1] = 18;
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x");
            }
        }
    }
    else if (playerX[px][0] == 45 && playerX[px][1] == 16)
    {
        int a = 0, b = 0;
        a = playerX[px][1] + diceNum + 2;
        if (a == 18)
        {
            playerX[px][1] = a;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (diceNum - 1) * 2;
            playerX[px][0] = 45 - b;
            playerX[px][1] = 18;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][0] >= 30 && playerX[px][0] <= 45 && playerX[px][1] == 18)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerX[px][0] = (playerX[px][0]) - a;
        if (playerX[px][0] >= 30)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else if (playerX[px][0] < 30)
        {
            b = (30 - playerX[px][0]) / 3;
            playerX[px][0] = 27;
            playerX[px][1] += 1 + b * 2;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][0] == 27 && playerX[px][1] >= 21 && playerX[px][1] <= 31)
    {
        int a = 0, b = 0, c = 0;
        a = diceNum * 2;
        playerX[px][1] = (playerX[px][1]) + a;
        if (playerX[px][1] <= 31)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (playerX[px][1] - 31) / 2;
            if (b <= 2)
            {
                playerX[px][1] = 31;
                if (b == 1)
                {
                    playerX[px][0] = 23;
                }
                else
                {
                    playerX[px][0] = 20;
                }
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x");
            }
            else
            {
                c = ((b - 2) * 2);
                playerX[px][0] = 20;
                playerX[px][1] = 31 - c;
                gotoxy(playerX[px][0], playerX[px][1]);
                printf("x");
            }
        }
    }
    else if (playerX[px][0] == 23 && playerX[px][1] == 31)
    {
        int a = 0, b = 0;
        a = playerX[px][0] + diceNum - 2;
        if (a == 20)
        {
            playerX[px][0] = a;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (diceNum * 2) - 2;
            playerX[px][0] = 20;
            playerX[px][1] = 31 - b;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][0] == 20 && playerX[px][1] <= 31 && playerX[px][1] >= 21)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerX[px][1] = (playerX[px][1]) - a;
        if (playerX[px][1] >= 21)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (21 - playerX[px][1]) / 2;
            playerX[px][0] = playerX[px][0] - (b * 3);
            playerX[px][1] = 18;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][1] == 18 && playerX[px][0] >= 2 && playerX[px][0] <= 17)
    {
        int a = 0, b = 0, c = 0;
        a = diceNum * 3;
        playerX[px][0] = (playerX[px][0]) - a;
        if (playerX[px][0] >= 2)
        {
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else
        {
            b = (((-1) * (playerX[px][0])) + 1) / 2;
            if (b <= 1)
            {
                playerX[px][1] = 16;
                playerX[px][0] = 2;
            }
            else
            {
                c = 2 + ((b - 1) * 3);
                playerX[px][0] = c;
                playerX[px][1] = 16;
            }
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    else if (playerX[px][1] == 16 && playerX[px][0] >= 2 && playerX[px][1] <= 17)
    {
        int a = 0;
        a = playerX[px][0] + (diceNum * 3);
        playerX[px][1] = (playerX[px][1]) + a;
        if (a == 20)
        {
            score1++;
            playerX[px][0] = 0;
            playerX[px][1] = 0;
        }
        else if (a <= 17)
        {
            playerX[px][0] = a;
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
        else if (a > 20)
        {
            gotoxy(0, 34);
            printf("You can't move it");
            getch();
            gotoxy(0, 34);
            printf("				\n");
            gotoxy(0, 35);
            printf("    \n");
            gotoxy(0, 36);
            printf("    \n");
            gotoxy(playerX[px][0], playerX[px][1]);
            printf("x");
        }
    }
    if ((playerX[px][0] == 5 && playerX[px][1] == 14) || (playerX[px][0] == 8 && playerX[px][1] == 18) || (playerX[px][0] == 20 && playerX[px][1] == 29) || (playerX[px][0] == 27 && playerX[px][1] == 27) || (playerX[px][0] == 20 && playerX[px][1] == 5) || (playerX[px][0] == 27 && playerX[px][1] == 3) || (playerX[px][0] == 39 && playerX[px][1] == 14) || (playerX[px][0] == 42 && playerX[px][1] == 18))
    {
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (playerX[px][0] == playerO[i][0] && playerX[px][1] == playerO[i][1])
            {
                if (i == 0)
                {
                    playerO[i][0] = 32;
                    playerO[i][1] = 2;
                    gotoxy(32, 2);
                    printf("o \n");
                }
                if (i == 1)
                {
                    playerO[i][0] = 34;
                    playerO[i][1] = 2;
                    gotoxy(34, 2);
                    printf("o \n");
                }
                if (i == 2)
                {
                    playerO[i][0] = 32;
                    playerO[i][1] = 3;
                    gotoxy(32, 3);
                    printf("o \n");
                }
                if (i == 3)
                {
                    playerO[i][0] = 34;
                    playerO[i][1] = 3;
                    gotoxy(34, 3);
                    printf("o \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerX[px][0] == playerThree[i][0] && playerX[px][1] == playerThree[i][1])
            {
                if (i == 0)
                {
                    playerThree[i][0] = 37;
                    playerThree[i][1] = 21;
                    gotoxy(37, 21);
                    printf("@ \n");
                }
                if (i == 1)
                {
                    playerThree[i][0] = 39;
                    playerThree[i][1] = 21;
                    gotoxy(39, 21);
                    printf("@ \n");
                }
                if (i == 2)
                {
                    playerThree[i][0] = 37;
                    playerThree[i][1] = 22;
                    gotoxy(37, 22);
                    printf("@ \n");
                }
                if (i == 3)
                {
                    playerThree[i][0] = 39;
                    playerThree[i][1] = 22;
                    gotoxy(39, 22);
                    printf("@ \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerX[px][0] == playerFour[i][0] && playerX[px][1] == playerFour[i][1])
            {
                if (i == 0)
                {
                    playerFour[i][0] = 14;
                    playerFour[i][1] = 28;
                    gotoxy(14, 28);
                    printf("* \n");
                }
                if (i == 1)
                {
                    playerFour[i][0] = 16;
                    playerFour[i][1] = 28;
                    gotoxy(16, 28);
                    printf("* \n");
                }
                if (i == 2)
                {
                    playerFour[i][0] = 14;
                    playerFour[i][1] = 29;
                    gotoxy(14, 29);
                    printf("* \n");
                }
                if (i == 3)
                {
                    playerFour[i][0] = 16;
                    playerFour[i][1] = 29;
                    gotoxy(16, 29);
                    printf("* \n");
                }
            }
        }
    }
}

void oMovement(int px)
{
    gotoxy(playerO[px][0], playerO[px][1]);
    printf(" \n");
    for (i = 0; i < 4; i++)
    {
        if (px != i)
        {
            if (playerO[px][0] == playerO[i][0] && playerO[px][1] == playerO[i][1])
            {
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("o \n");
            }
        }
    }
    if ((playerX[px][0] == 5 && playerX[px][1] == 14) || (playerX[px][0] == 8 && playerX[px][1] == 18) || (playerX[px][0] == 20 && playerX[px][1] == 29) || (playerX[px][0] == 27 && playerX[px][1] == 27) || (playerX[px][0] == 20 && playerX[px][1] == 5) || (playerX[px][0] == 27 && playerX[px][1] == 3) || (playerX[px][0] == 39 && playerX[px][1] == 14) || (playerX[px][0] == 42 && playerX[px][1] == 18))
    {
        for (i = 0; i < 4; i++) {
            if (playerO[px][0] == playerX[i][0] && playerO[px][1] == playerX[i][1]) {
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("x \n");
            }
        }
        for (i = 0; i < 4; i++) {
            if (playerO[px][0] == playerThree[i][0] && playerO[px][1] == playerThree[i][1]) {
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("@ \n");
            }
        }
        for (i = 0; i < 4; i++) {
            if (playerO[px][0] == playerFour[i][0] && playerO[px][1] == playerFour[i][1]) {
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("* \n");
            }
        }
    }
    if (playerO[px][0] == 32 && playerO[px][1] == 2) {
        if (diceNum == 6) {
            gotoxy(27, 3);
            printf("o");
            playerO[px][0] == 27;
            playerO[px][1] == 3;
        }
        else {
            gotoxy(32, 2);
            printf("o \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerO[px][0] == 34 && playerO[px][1] == 2) {
        if (diceNum == 6) {
            gotoxy(27, 3);
            printf("o");
            playerO[px][0] == 27;
            playerO[px][1] == 3;
        }
        else {
            gotoxy(34, 2);
            printf("o \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerO[px][0] == 32 && playerO[px][1] == 3) {
        if (diceNum == 6) {
            gotoxy(27, 3);
            printf("o");
            playerO[px][0] == 27;
            playerO[px][1] == 3;
        }
        else {
            gotoxy(32, 3);
            printf("o \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerO[px][0] == 34 && playerO[px][1] == 3) {
        if (diceNum == 6) {
            gotoxy(27, 3);
            printf("o");
            playerO[px][0] == 27;
            playerO[px][1] == 3;
        }
        else {
            gotoxy(34, 3);
            printf("o \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerO[px][0] == 27 && playerO[px][1] >= 3 && playerO[px][1] <= 11)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerO[px][1] = (playerO[px][1]) + a;
        if (playerO[px][1] <= 11)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else if (playerO[px][1] > 11)
        {
            b = (playerO[px][1] - 11) / 2;
            playerO[px][0] = playerO[px][0] + (b * 3);
            playerO[px][1] = 14;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] >= 30 && playerO[px][0] <= 45 && playerO[px][1] == 14)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 3;
        playerO[px][0] = (playerO[px][0]) + a;
        if (playerO[px][0] <= 45)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (playerO[px][0] - 45) / 3;
            if (b <= 2) {
                playerO[px][0] = 45;
                if (b == 1) {
                    playerO[px][1] = 16;
                }
                else {
                    playerO[px][1] = 18;
                }
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("o");
            }
            else {
                c = ((b - 2) * 3);
                playerO[px][0] = 45 - c;
                playerO[px][1] = 18;
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("o");
            }
        }
    }
    else if (playerO[px][0] == 45 && playerO[px][1] == 16)
    {
        int a = 0, b = 0;
        a = playerO[px][1] + diceNum + 2;
        if (a == 18)
        {
            playerO[px][1] = a;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (diceNum - 1) * 2;
            playerO[px][0] = 45 - b;
            playerO[px][1] = 18;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] >= 30 && playerO[px][0] <= 45 && playerO[px][1] == 18)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerO[px][0] = (playerO[px][0]) - a;
        if (playerO[px][0] >= 30)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else if (playerO[px][0] < 30)
        {
            b = (30 - playerO[px][0]) / 3;
            playerO[px][0] = 27;
            playerO[px][1] = playerO[px][1] + (1 + b * 2);
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] == 27 && playerO[px][1] >= 21 && playerO[px][1] <= 31)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 2;
        playerO[px][1] = (playerO[px][1]) + a;
        if (playerO[px][1] <= 31)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (playerO[px][1] - 31) / 2;
            if (b <= 2) {
                playerO[px][1] = 31;
                if (b == 1) {
                    playerO[px][0] = 23;
                }
                else {
                    playerO[px][0] = 20;
                }
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("o");
            }
            else {
                c = ((b - 2) * 2);
                playerO[px][0] = 20;
                playerO[px][1] = 31 - c;
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("o");
            }
        }
    }
    else if (playerO[px][0] == 23 && playerO[px][1] == 31)
    {
        int a = 0, b = 0;
        a = playerO[px][0] + diceNum - 2;
        if (a == 20)
        {
            playerO[px][0] = a;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (diceNum * 2) - 2;
            playerO[px][0] = 20;
            playerO[px][1] = 31 - b;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] == 20 && playerO[px][1] <= 31 && playerO[px][1] >= 21)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerO[px][1] = playerO[px][1] - a;
        if (playerO[px][1] >= 21)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (21 - playerO[px][1]) / 2;
            playerO[px][0] = playerO[px][0] - (b * 3);
            playerO[px][1] = 18;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][1] == 18 && playerO[px][0] >= 2 && playerO[px][0] <= 17)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 3;
        playerO[px][0] = (playerO[px][0]) - a;
        if (playerO[px][0] >= 2)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (((-1) * (playerO[px][0])) + 1) / 2;
            if (b <= 2) {
                playerO[px][0] = 2;
                if (b == 1) {
                    playerO[px][1] = 16;
                }
                else {
                    playerO[px][1] = 14;
                }
            }
            else {
                c = ((b - 2) * 3);
                playerO[px][0] = c;
                playerO[px][1] = 14;
            }
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] >= 2 && playerO[px][0] <= 17 && playerO[px][1] == 14)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerO[px][0] = playerO[px][0] + a;
        if (playerO[px][0] <= 17)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else if (playerO[px][0] > 17)
        {
            b = (playerO[px][0] - 17) / 3;
            playerO[px][0] = 20;
            playerO[px][1] = playerO[px][1] - (1+(b * 2));
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] == 20 && playerO[px][1] >= 1 && playerO[px][1] <= 11)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 2;
        playerO[px][1] = (playerO[px][1]) - a;
        if (playerO[px][1] >= 1)
        {
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else 
        {
            b = (((-1) * (playerO[px][0])) + 1) / 2;
            if (b <= 1) {
                playerO[px][1] = 1;
                playerO[px][0] = 23;
            }
            else {
                c = 1 + ((b - 1) * 2);
                playerO[px][1] = c;
                playerO[px][0] = 23;
            }
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    else if (playerO[px][0] == 23 && playerO[px][1] >= 1 && playerO[px][1] <= 11) {
        int a = 0;
        a = playerO[px][0] + (diceNum * 2);
        if (a == 13) {
            score2++;
            playerO[px][0] = 0;
            playerO[px][1] = 0;
        }
        else if (a <= 13) {
            playerO[px][0] = a;
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
        else if (a >= 15) {
            gotoxy(0, 34);
            printf("You can't move it");
            getch();
            gotoxy(0, 34);
            printf("				\n");
            gotoxy(0, 35);
            printf("     \n");
            gotoxy(0, 36);
            printf("     \n");
            gotoxy(playerO[px][0], playerO[px][1]);
            printf("o");
        }
    }
    if ((playerO[px][0] == 5 && playerO[px][1] == 14) || (playerO[px][0] == 8 && playerO[px][1] == 18) || (playerO[px][0] == 20 && playerO[px][1] == 29))
    {
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (playerO[px][0] == playerX[i][0] && playerO[px][1] == playerX[i][1])
            {
                if (i == 0)
                {
                    playerX[i][0] = 6;
                    playerX[i][1] = 10;
                    gotoxy(6, 10);
                    printf("x \n");
                }
                if (i == 1)
                {
                    playerX[i][0] = 8;
                    playerX[i][1] = 10;
                    gotoxy(8, 10);
                    printf("x \n");
                }
                if (i == 2)
                {
                    playerX[i][0] = 6;
                    playerX[i][1] = 11;
                    gotoxy(32, 3);
                    printf("x \n");
                }
                if (i == 3)
                {
                    playerX[i][0] = 8;
                    playerX[i][1] = 11;
                    gotoxy(8, 11);
                    printf("x \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerO[px][0] == playerThree[i][0] && playerO[px][1] == playerThree[i][1])
            {
                if (i == 0)
                {
                    playerThree[i][0] = 37;
                    playerThree[i][1] = 21;
                    gotoxy(37, 21);
                    printf("@ \n");
                }
                if (i == 1)
                {
                    playerThree[i][0] = 39;
                    playerThree[i][1] = 21;
                    gotoxy(39, 21);
                    printf("@ \n");
                }
                if (i == 2)
                {
                    playerThree[i][0] = 37;
                    playerThree[i][1] = 22;
                    gotoxy(37, 22);
                    printf("@ \n");
                }
                if (i == 3)
                {
                    playerThree[i][0] = 39;
                    playerThree[i][1] = 22;
                    gotoxy(39, 22);
                    printf("@ \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerO[px][0] == playerFour[i][0] && playerO[px][1] == playerFour[i][1])
            {
                if (i == 0)
                {
                    playerFour[i][0] = 14;
                    playerFour[i][1] = 28;
                    gotoxy(14, 28);
                    printf("* \n");
                }
                if (i == 1)
                {
                    playerFour[i][0] = 16;
                    playerFour[i][1] = 28;
                    gotoxy(16, 28);
                    printf("* \n");
                }
                if (i == 2)
                {
                    playerFour[i][0] = 14;
                    playerFour[i][1] = 29;
                    gotoxy(14, 29);
                    printf("* \n");
                }
                if (i == 3)
                {
                    playerFour[i][0] = 16;
                    playerFour[i][1] = 29;
                    gotoxy(16, 29);
                    printf("* \n");
                }
            }
        }
    }
}

void movement3(int px) {
    gotoxy(playerThree[px][0], playerThree[px][1]);
    printf(" \n");
    for (i = 0; i < 4; i++)
    {
        if (px != i)
        {
            if (playerThree[px][0] == playerThree[i][0] && playerThree[px][1] == playerThree[i][1])
            {
                gotoxy(playerO[px][0], playerO[px][1]);
                printf("@ \n");
            }
        }
    }
    if ((playerThree[px][0]==5 && playerThree[px][1]==14) || (playerThree[px][0]==8 && playerThree[px][1]==18) || (playerThree[px][0]==20 && playerThree[px][1]==29) || (playerThree[px][0]==27 && playerThree[px][1]==27) || (playerThree[px][0]==20 && playerThree[px][1]==5) || (playerThree[px][0]==27 && playerThree[px][1]==3) || (playerThree[px][0]==39 && playerThree[px][1]==14) || (playerThree[px][0]==42 && playerThree[px][1]==18))
    {
        for (i = 0; i < 4; i++) {
            if (playerThree[px][0] == playerO[i][0] && playerThree[px][1] == playerO[i][1]) {
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("o \n");
            }
        }
        for (i = 0; i < 4; i++) {
            if (playerThree[px][0] == playerX[i][0] && playerThree[px][1] == playerX[i][1]) {
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("x \n");
            }
        }
        for (i = 0; i < 4; i++) {
            if (playerThree[px][0] == playerFour[i][0] && playerThree[px][1] == playerFour[i][1]) {
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("* \n");
            }
        }
    }
    if (playerThree[px][0] == 37 && playerThree[px][1] == 21) {
        if (diceNum == 6) {
            gotoxy(42, 18);
            printf("@");
            playerThree[px][0] == 42;
            playerThree[px][1] == 18;
        }
        else {
            gotoxy(37, 21);
            printf("@ \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerThree[px][0] == 39 && playerThree[px][1] == 21) {
        if (diceNum == 6) {
            gotoxy(42, 18);
            printf("@");
            playerThree[px][0] == 42;
            playerThree[px][1] == 18;
        }
        else {
            gotoxy(39, 21);
            printf("@ \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerThree[px][0] == 37 && playerThree[px][1] == 22) {
        if (diceNum == 6) {
            gotoxy(42, 18);
            printf("@");
            playerThree[px][0] == 42;
            playerThree[px][1] == 18;
        }
        else {
            gotoxy(37, 22);
            printf("@ \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerThree[px][0] == 39 && playerThree[px][1] == 22) {
        if (diceNum == 6) {
            gotoxy(42, 18);
            printf("@");
            playerThree[px][0] == 42;
            playerThree[px][1] == 18;
        }
        else {
            gotoxy(39, 22);
            printf("@ \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerThree[px][0] >= 30 && playerThree[px][0] <= 42 && playerThree[px][1] == 18)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerThree[px][0] = (playerThree[px][0]) - a;
        if (playerThree[px][0] >= 30)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else if (playerThree[px][0] < 30)
        {
            b = (30 - playerThree[px][0]) / 3;
            playerThree[px][0] = 27;
            playerThree[px][1] = playerThree[px][1] + (1 + b * 2);
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][0] == 27 && playerThree[px][1] >= 21 && playerThree[px][1] <= 31)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 2;
        playerThree[px][1] = (playerThree[px][1]) + a;
        if (playerThree[px][1] <= 31)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (playerThree[px][1] - 31) / 2;
            if (b <= 2) {
                playerThree[px][1] = 31;
                if (b == 1) {
                    playerThree[px][0] = 23;
                }
                else {
                    playerThree[px][0] = 20;
                }
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("@");
            }
            else {
                c = ((b - 2) * 2);
                playerThree[px][0] = 20;
                playerThree[px][1] = 31 - c;
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("@");
            }
        }
    }
    else if (playerThree[px][0] == 23 && playerThree[px][1] == 31)
    {
        int a = 0, b = 0;
        a = playerThree[px][0] + diceNum - 2;
        if (a == 20)
        {
            playerThree[px][0] = a;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (diceNum * 2) - 2;
            playerThree[px][0] = 20;
            playerThree[px][1] = 31 - b;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][0] == 20 && playerThree[px][1] <= 31 && playerThree[px][1] >= 21)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerThree[px][1] = playerThree[px][1] - a;
        if (playerThree[px][1] >= 21)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (21 - playerThree[px][1]) / 2;
            playerThree[px][0] = playerThree[px][0] - (b * 3);
            playerThree[px][1] = 18;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][1] == 18 && playerThree[px][0] >= 2 && playerThree[px][0] <= 17)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 3;
        playerThree[px][0] = (playerThree[px][0]) - a;
        if (playerThree[px][0] >= 2)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (((-1) * (playerThree[px][0])) + 1) / 2;
            if (b <= 2) {
                playerThree[px][0] = 2;
                if (b == 1) {
                    playerThree[px][1] = 16;
                }
                else {
                    playerThree[px][1] = 14;
                }
            }
            else {
                c = ((b - 2) * 3);
                playerThree[px][0] = c;
                playerThree[px][1] = 14;
            }
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][0] >= 2 && playerThree[px][0] <= 17 && playerThree[px][1] == 14)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerThree[px][0] = playerThree[px][0] + a;
        if (playerThree[px][0] <= 17)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else if (playerThree[px][0] > 17)
        {
            b = (playerThree[px][0] - 17) / 3;
            playerThree[px][0] = 20;
            playerThree[px][1] = playerO[px][1] - (1+(b * 2));
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][0] == 20 && playerThree[px][1] >= 1 && playerThree[px][1] <= 11)
    {
        int a = 0, b = 0, c= 0;
        gotoxy(playerThree[px][0], playerThree[px][1]);
        printf(" ");
        a = diceNum * 2;
        playerThree[px][1] = (playerThree[px][1]) - a;
        if (playerThree[px][1] >= 1)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (((-1) * (playerThree[px][0])) + 1) / 2;
            if (b <= 2) {
                playerThree[px][1] = 1;
                if (b == 1) {
                    playerThree[px][0] = 23;
                }
                else {
                    playerThree[px][0] = 27;
                }
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("@");
            }
            else {
                c = 1 + ((b - 2) * 2);
                playerThree[px][0] = 27;
                playerThree[px][1] = c;
                gotoxy(playerThree[px][0], playerThree[px][1]);
                printf("@");
            }
        }
    }
    else if (playerThree[px][0] == 23 && playerThree[px][1] == 1)
    {
        int a = 0, b = 0;
        a = playerThree[px][0] + diceNum + 3;
        if (a == 27)
        {
            playerThree[px][0] = a;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (diceNum * 2) - 1;
            playerThree[px][0] = 27;
            playerThree[px][1] = b;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][0] == 27 && playerThree[px][1] >= 1 && playerThree[px][1] <= 11)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerThree[px][1] = (playerThree[px][1]) + a;
        if (playerThree[px][1] <= 11)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else if (playerThree[px][1] > 11)
        {
            b = (playerThree[px][1] - 11) / 2;
            playerThree[px][0] = playerThree[px][0] + (b * 3);
            playerThree[px][1] = 14;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][1] == 14 && playerThree[px][0] >= 30 && playerThree[px][0] <= 45)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 3;
        playerThree[px][0] = (playerThree[px][0]) + a;
        if (playerThree[px][0] <= 45)
        {
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else 
        {
            b = (playerThree[px][0] - 45) / 3;
            if (b <= 1) {
                playerThree[px][1] = 16;
                playerThree[px][0] = 45;
            }
            else {
                c = ((b - 1) * 3);
                playerThree[px][0] = 45 - c;
                playerThree[px][1] = 16;
            }
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    else if (playerThree[px][1] == 16 && playerThree[px][0] >= 30 && playerThree[px][0] <= 45) {
        int a = 0;
        a = playerThree[px][0] - (diceNum * 3);
        if (a == 27) {
            score3++;
            playerThree[px][0] = 0;
            playerThree[px][1] = 0;
        }
        else if (a >= 30) {
            playerThree[px][0] = a;
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
        else if (a < 27) {
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
            gotoxy(0, 35);
            printf("     \n");
            gotoxy(0, 36);
            printf("     \n");
            gotoxy(playerThree[px][0], playerThree[px][1]);
            printf("@");
        }
    }
    if ((playerThree[px][0]==5 && playerThree[px][1]==14) || (playerThree[px][0]==8 && playerThree[px][1]==18) || (playerThree[px][0]==20 && playerThree[px][1]==29) || (playerThree[px][0]==27 && playerThree[px][1]==27) || (playerThree[px][0]==20 && playerThree[px][1]==5) || (playerThree[px][0]==27 && playerThree[px][1]==3) || (playerThree[px][0]==39 && playerThree[px][1]==14) || (playerThree[px][0]==42 && playerThree[px][1]==18))
    {
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (playerThree[px][0] == playerO[i][0] && playerThree[px][1] == playerO[i][1])
            {
                if (i == 0)
                {
                    playerO[i][0] = 32;
                    playerO[i][1] = 2;
                    gotoxy(32, 2);
                    printf("o \n");
                }
                if (i == 1)
                {
                    playerO[i][0] = 34;
                    playerO[i][1] = 2;
                    gotoxy(34, 2);
                    printf("o \n");
                }
                if (i == 2)
                {
                    playerO[i][0] = 32;
                    playerO[i][1] = 3;
                    gotoxy(32, 3);
                    printf("o \n");
                }
                if (i == 3)
                {
                    playerO[i][0] = 34;
                    playerO[i][1] = 3;
                    gotoxy(34, 3);
                    printf("o \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerThree[px][0] == playerX[i][0] && playerThree[px][1] == playerX[i][1])
            {
                if (i == 0)
                {
                    playerX[i][0] = 6;
                    playerX[i][1] = 10;
                    gotoxy(6, 10);
                    printf("x \n");
                }
                if (i == 1)
                {
                    playerX[i][0] = 8;
                    playerX[i][1] = 10;
                    gotoxy(8, 10);
                    printf("x \n");
                }
                if (i == 2)
                {
                    playerX[i][0] = 6;
                    playerX[i][1] = 11;
                    gotoxy(6, 11);
                    printf("x \n");
                }
                if (i == 3)
                {
                    playerX[i][0] = 8;
                    playerX[i][1] = 11;
                    gotoxy(8, 11);
                    printf("x \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerThree[px][0] == playerFour[i][0] && playerThree[px][1] == playerFour[i][1])
            {
                if (i == 0)
                {
                    playerFour[i][0] = 14;
                    playerFour[i][1] = 28;
                    gotoxy(14, 28);
                    printf("* \n");
                }
                if (i == 1)
                {
                    playerFour[i][0] = 16;
                    playerFour[i][1] = 28;
                    gotoxy(16, 28);
                    printf("* \n");
                }
                if (i == 2)
                {
                    playerFour[i][0] = 14;
                    playerFour[i][1] = 29;
                    gotoxy(14, 29);
                    printf("* \n");
                }
                if (i == 3)
                {
                    playerFour[i][0] = 16;
                    playerFour[i][1] = 29;
                    gotoxy(16, 29);
                    printf("* \n");
                }
            }
        }
    }
}

void movement4(int px) {
    gotoxy(playerFour[px][0], playerFour[px][1]);
    printf(" \n");
    for (i = 0; i < 4; i++)
    {
        if (px != i)
        {
            if (playerFour[px][0] == playerFour[i][0] && playerFour[px][1] == playerFour[i][1])
            {
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("* \n");
            }
        }
    }
    if ((playerThree[px][0]==5 && playerThree[px][1]==14) || (playerThree[px][0]==8 && playerThree[px][1]==18) || (playerThree[px][0]==20 && playerThree[px][1]==29) || (playerThree[px][0]==27 && playerThree[px][1]==27) || (playerThree[px][0]==20 && playerThree[px][1]==5) || (playerThree[px][0]==27 && playerThree[px][1]==3) || (playerThree[px][0]==39 && playerThree[px][1]==14) || (playerThree[px][0]==42 && playerThree[px][1]==18))
    {
        for (i = 0; i < 4; i++) {
            if (playerFour[px][0] == playerO[i][0] && playerFour[px][1] == playerO[i][1]) {
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("o \n");
            }
        }
        for (i = 0; i < 4; i++) {
            if (playerFour[px][0] == playerThree[i][0] && playerFour[px][1] == playerThree[i][1]) {
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("@ \n");
            }
        }
        for (i = 0; i < 4; i++) {
            if (playerFour[px][0] == playerX[i][0] && playerFour[px][1] == playerX[i][1]) {
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("x \n");
            }
        }
    }
    if (playerFour[px][0] == 14 && playerFour[px][1] == 28) {
        if (diceNum == 6) {
            gotoxy(20, 29);
            printf("*");
            playerFour[px][0] == 20;
            playerFour[px][1] == 29;
        }
        else {
            gotoxy(14, 28);
            printf("* \n");
            gotoxy(0, 34);
            printf("You can't move it");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerFour[px][0] == 16 && playerFour[px][1] == 28) {
        if (diceNum == 6) {
            gotoxy(20, 29);
            printf("*");
            playerFour[px][0] == 20;
            playerFour[px][1] == 29;
        }
        else {
            gotoxy(16, 28);
            printf("* \n");
            gotoxy(0, 34);
            printf("You can't move it");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerFour[px][0] == 14 && playerFour[px][1] == 29) {
        if (diceNum == 6) {
            gotoxy(20, 29);
            printf("*");
            playerFour[px][0] == 20;
            playerFour[px][1] == 29;
        }
        else {
            gotoxy(14, 29);
            printf("* \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerFour[px][0] == 16 && playerFour[px][1] == 29) {
        if (diceNum == 6) {
            gotoxy(20, 29);
            printf("*");
            playerFour[px][0] == 20;
            playerFour[px][1] == 29;
        }
        else {
            gotoxy(16, 29);
            printf("* \n");
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
        }
    }
    else if (playerFour[px][0] == 20 && playerFour[px][1] <= 29 && playerFour[px][1] >= 21)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerFour[px][1] = playerFour[px][1] - a;
        if (playerFour[px][1] >= 21)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else 
        {
            b = (21 - playerFour[px][1]) / 2;
            playerFour[px][0] = playerFour[px][0] - (b * 3);
            playerFour[px][1] = 18;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][1] == 18 && playerFour[px][0] >= 2 && playerFour[px][0] <= 17)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 3;
        playerFour[px][0] = (playerFour[px][0]) - a;
        if (playerFour[px][0] >= 2)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else 
        {
            b = (((-1) * (playerFour[px][0])) + 1) / 2;
            if (b <= 2) {
                playerFour[px][0] = 2;
                if (b == 1) {
                    playerFour[px][1] = 16;
                }
                else {
                    playerFour[px][1] = 14;
                }
            }
            else {
                c = ((b - 2) * 3);
                playerFour[px][0] = c;
                playerFour[px][1] = 14;
            }
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][0] >= 2 && playerFour[px][0] <= 17 && playerFour[px][1] == 14)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerFour[px][0] = playerFour[px][0] + a;
        if (playerFour[px][0] < 18)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else if (playerFour[px][0] > 17)
        {
            b = (playerFour[px][0] - 17) / 3;
            playerFour[px][0] = 20;
            playerFour[px][1] = playerO[px][1] - (1+(b * 2));
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][0] == 20 && playerFour[px][1] >= 1 && playerFour[px][1] <= 11)
    {
        int a = 0, b = 0, c= 0;
        gotoxy(playerFour[px][0], playerFour[px][1]);
        printf(" ");
        a = diceNum * 2;
        playerFour[px][1] = (playerFour[px][1]) - a;
        if (playerFour[px][1] >= 1)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else 
        {
            b = (((-1) * (playerFour[px][1])) + 1) / 2;
            if (b <= 2) {
                playerFour[px][1] = 1;
                if (b == 1) {
                    playerFour[px][0] = 23;
                }
                else {
                    playerFour[px][0] = 27;
                }
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("*");
            }
            else {
                c = 1 + ((b - 2) * 2);
                playerFour[px][0] = 27;
                playerFour[px][1] = c;
                gotoxy(playerFour[px][0], playerFour[px][1]);
            	printf("*");
            }
        }
    }
    else if (playerFour[px][0] == 23 && playerFour[px][1] == 1)
    {
        int a = 0, b = 0;
        a = playerFour[px][0] + diceNum + 3;
        if (a == 27)
        {
            playerFour[px][0] = a;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else 
        {
            b = (diceNum * 2) - 1;
            playerFour[px][0] = 27;
            playerFour[px][1] = b;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][0] == 27 && playerFour[px][1] >= 1 && playerFour[px][1] <= 11)
    {
        int a = 0, b = 0;
        a = diceNum * 2;
        playerFour[px][1] = (playerFour[px][1]) + a;
        if (playerFour[px][1] <= 11)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else if (playerFour[px][1] > 11)
        {
            b = (playerFour[px][1] - 11) / 2;
            playerFour[px][0] = playerFour[px][0] + (b * 3);
            playerFour[px][1] = 14;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][1] == 14 && playerFour[px][0] >= 30 && playerFour[px][0] <= 45)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 3;
        playerFour[px][0] = (playerFour[px][0]) + a;
        if (playerFour[px][0] <= 45)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else 
        {
            b = (playerFour[px][0] - 45) / 3;
            if (b <= 2) {
                playerFour[px][0] = 45;
                if (b == 1) {
                    playerFour[px][1] = 16;
                }
                else {
                    playerFour[px][1] = 18;
                }
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("*");
            }
            else {
                c = ((b - 2) * 3);
                playerFour[px][0] = 45 - c;
                playerFour[px][1] = 18;
                gotoxy(playerFour[px][0], playerFour[px][1]);
                printf("*");
            }
        }
    }
    else if (playerFour[px][0] == 45 && playerFour[px][1] == 16)
    {
        int a = 0, b = 0;
        a = playerFour[px][1] + diceNum + 2;
        if (a == 18)
        {
            playerFour[px][1] = a;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else 
        {
            b = (diceNum - 1) * 2;
            playerFour[px][0] = 45 - b;
            playerFour[px][1] = 18;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][0] >= 30 && playerFour[px][0] <= 45 && playerFour[px][1] == 18)
    {
        int a = 0, b = 0;
        a = diceNum * 3;
        playerFour[px][0] = (playerFour[px][0]) - a;
        if (playerFour[px][0] >= 30)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else if (playerFour[px][0] < 30)
        {
            b = (30 - playerFour[px][0]) / 3;
            playerFour[px][0] = 27;
            playerFour[px][1] = playerFour[px][1] + (1 + b * 2);
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][0] == 27 && playerFour[px][1] >= 21 && playerFour[px][1] <= 31)
    {
        int a = 0, b = 0, c= 0;
        a = diceNum * 2;
        playerFour[px][1] = (playerFour[px][1]) + a;
        if (playerFour[px][1] <= 31)
        {
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else if (playerFour[px][1] > 31)
        {
            b = (playerFour[px][1] - 31) / 2;
            if (b == 1) {
                playerFour[px][1] = 31;
                playerFour[px][0] = 23;
            }
            else if (b > 1) {
                c = ((b - 1) * 2);
                playerFour[px][0] = 23;
                playerFour[px][1] = 31 - c;
            }
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    else if (playerFour[px][0] == 23 && playerFour[px][1] >= 31 && playerFour[px][0] <= 21) {
        int a = 0;
        a = playerFour[px][0] - (diceNum * 2);
        if (a == 19) {
            score4++;
            playerFour[px][0] = 0;
            playerFour[px][1] = 0;
        }
        else if (a <= 21) {
            playerFour[px][0] = a;
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
        else if (a <= 17) {
            gotoxy(0, 34);
            printf("You can't move it \n");
            getch();
            gotoxy(0, 34);
            printf("				\n");
            gotoxy(0, 35);
            printf("     \n");
            gotoxy(0, 36);
            printf("     \n");
            gotoxy(playerFour[px][0], playerFour[px][1]);
            printf("*");
        }
    }
    if ((playerFour[px][0] == 5 && playerFour[px][1] == 14) || (playerFour[px][0] == 8 && playerFour[px][1] == 18) || (playerFour[px][0] == 20 && playerFour[px][1] == 29))
    {
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (playerFour[px][0] == playerO[i][0] && playerFour[px][1] == playerO[i][1])
            {
                if (i == 0)
                {
                    playerO[i][0] = 32;
                    playerO[i][1] = 2;
                    gotoxy(32, 2);
                    printf("o \n");
                }
                if (i == 1)
                {
                    playerO[i][0] = 34;
                    playerO[i][1] = 2;
                    gotoxy(34, 2);
                    printf("o \n");
                }
                if (i == 2)
                {
                    playerO[i][0] = 32;
                    playerO[i][1] = 3;
                    gotoxy(32, 3);
                    printf("o \n");
                }
                if (i == 3)
                {
                    playerO[i][0] = 34;
                    playerO[i][1] = 3;
                    gotoxy(34, 3);
                    printf("o \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerFour[px][0] == playerX[i][0] && playerFour[px][1] == playerX[i][1])
            {
                if (i == 0)
                {
                    playerX[i][0] = 6;
                    playerX[i][1] = 10;
                    gotoxy(6, 10);
                    printf("x \n");
                }
                if (i == 1)
                {
                    playerX[i][0] = 8;
                    playerX[i][1] = 10;
                    gotoxy(8, 10);
                    printf("x \n");
                }
                if (i == 2)
                {
                    playerX[i][0] = 6;
                    playerX[i][1] = 11;
                    gotoxy(6, 11);
                    printf("x \n");
                }
                if (i == 3)
                {
                    playerX[i][0] = 8;
                    playerX[i][1] = 11;
                    gotoxy(8, 11);
                    printf("x \n");
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (playerFour[px][0] == playerThree[i][0] && playerFour[px][1] == playerThree[i][1])
            {
                if (i == 0)
                {
                    playerThree[i][0] = 37;
                    playerThree[i][1] = 21;
                    gotoxy(37, 21);
                    printf("@ \n");
                }
                if (i == 1)
                {
                    playerThree[i][0] = 39;
                    playerThree[i][1] = 21;
                    gotoxy(39, 21);
                    printf("@ \n");
                }
                if (i == 2)
                {
                    playerThree[i][0] = 37;
                    playerThree[i][1] = 22;
                    gotoxy(37, 22);
                    printf("@ \n");
                }
                if (i == 3)
                {
                    playerThree[i][0] = 39;
                    playerThree[i][1] = 22;
                    gotoxy(39, 22);
                    printf("@ \n");
                }
            }
        }
    }
}

void loadData() {
    int i = 0;
    FILE *myFile;
    myFile = fopen("data.txt", "r");
    if (myFile == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    
    char record[50];
    while (fgets(record, sizeof(record), myFile) != NULL) {
        for (j = 0; j < 48; j++) {
            data[i][j] = record[j];
        }
        i++;
    }

    fclose(myFile);
}

void header() {
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);
    printf("                                              \n");
	printf(" _                             _              \n");
	printf("| |                           | |             \n");
	printf("| |         _      _     _ _ _| |    _ _ _ _  \n");
	printf("| |        | |    | |   |  _ _| |   |  _ _  | \n");
	printf("| |        | |    | |   | |   | |   | |   | | \n");
	printf("| |_ _ _   | |_ __| |   | |_ _| |   | |_ _| | \n");
	printf("|_ _ _ _|  |__ _ _ _|   |_ _ _|_|   |_ _ _ _| \n");
	printf("\n");
	printf("\n");
    SetConsoleTextAttribute(colors, 7);
}

void showBoard() {
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    for (i = 0; i < 33; i++) {
        for (j = 0; j < 48; j++) {
            SetConsoleTextAttribute(colors, 7);
            if (i <= 19 && j <= 18) {
                SetConsoleTextAttribute(colors, 1);
            }
            else if (i >= 13 && i <= 19 && j == 19) {
                SetConsoleTextAttribute(colors, 1);
            }
            else if (i >= 14 && i <= 18 && j == 20) {
                SetConsoleTextAttribute(colors, 1);
            }
            else if (i >= 15 && i <= 17 && j == 21) {
                SetConsoleTextAttribute(colors, 1);
            }
            else if (i == 16 && j == 22) {
                SetConsoleTextAttribute(colors, 1);
            }
            else if (i <= 12 && j > 18) {
                SetConsoleTextAttribute(colors, 4);
            }
            else if (j >= 20 && j <= 28 && i == 13) {
                SetConsoleTextAttribute(colors, 4);
            }
            else if (j >= 21 && j <= 27 && i == 14) {
                SetConsoleTextAttribute(colors, 4);
            }
            else if (j >= 22 && j <= 26 && i == 15) {
                SetConsoleTextAttribute(colors, 4);
            }
            else if (i >= 20 && j <= 29) {
                SetConsoleTextAttribute(colors, 2);
            }
            else if (j >= 20 && j <= 28 && i == 19) {
                SetConsoleTextAttribute(colors, 2);
            }
            else if (j >= 21 && j <= 27 && i == 18) {
                SetConsoleTextAttribute(colors, 2);
            }
            else if (j >= 22 && j <= 26 && i == 17) {
                SetConsoleTextAttribute(colors, 2);
            }
            else if (i >= 13 && j > 29) {
                SetConsoleTextAttribute(colors, 6);
            }
            else if (i >= 13 && i <= 19 && j == 29) {
                SetConsoleTextAttribute(colors, 6);
            }
            else if (i >= 14 && i <= 18 && j == 28) {
                SetConsoleTextAttribute(colors, 6);
            }
            else if (i >= 15 && i <= 17 && j == 27) {
                SetConsoleTextAttribute(colors, 6);
            }
            else if (i == 16 && j == 26) {
                SetConsoleTextAttribute(colors, 6);
            }
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
    SetConsoleTextAttribute(colors, 7);
}

void gotoxy(int x, int y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y};
    SetConsoleCursorPosition(hStdout, position);
}

