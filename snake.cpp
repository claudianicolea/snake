#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void gotoxy(int x, int y){
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

int main(){

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    /*

    0 - black
    1 - blue
    2 - green
    3 - aqua
    4 - red
    5 - purple
    6 - yellow
    7 - white
    8 - gray
    9 - light blue
    10 / A - light green
    11 / B - light aqua
    12 / C - light red
    13 / D - light purple
    14 / E - light yellow
    15 / F - bright white

    */

    srand((unsigned)time(0));

    int x, y;
    int i, j;
    char c;
    int x_rand, y_rand;

    int direction;
    int schimba_obiect;
    char c1; // folosit pt enter

    int q; // obiect
    char v[5];
    v[1]=2; // smiley face
    v[2]=30; // triunghi
    v[3]=6; // inima rosie
    v[4]=22; // dreptunghi

    int length; //lungime sarpe
    int snake[100][100]; //sarpe (1-x, 2-y)

    int start1;
    int speed;

    int snake_color[6];
    snake_color[1]=0*16+9; // light blue
    snake_color[2]=0*16+11; // light aqua
    snake_color[3]=0*16+12; // light red
    snake_color[4]=0*16+13; // light purple
    snake_color[5]=0*16+14; // light yellow
    int color_index;
    int da;
    int color_index_rand, past_color_index_rand;
    int start;
    int index_caracter;
    int lives;
    int highest_score=0;

    //JOC

    while(1){

    index_caracter=1;
    start=0;
    da=0; // pt schimbul culorilor sarpelui dupa score=1
    color_index=0;
    color_index_rand=1;
    start1=0;
    length=2;
    lives=3;
    for(i=1; i<=length; i++){
        snake[i][1]=0;
        snake[i][2]=0;
    }
    q=v[1];
    direction=1;
    schimba_obiect=0;

    system("CLS");
    system("Color 0F");
    SetConsoleTextAttribute(h, 0*16+6);

    for(i=2; i<=100; i++){
        gotoxy(i, 0);
        printf("%c", 95);
        gotoxy(i, 19);
        printf("%c", 95);
    }
    for(i=1; i<=19; i++){
        gotoxy(2, i);
        printf("%c", 124);
        gotoxy(100, i);
        printf("%c", 124);
    }

    SetConsoleTextAttribute(h, 0*16+15);
    gotoxy(47, 5);
    printf("WELCOME!");
    gotoxy(40, 7);
    printf("CHOOSE A CHARACTER:");
    gotoxy(60, 15);
    printf("PRESS ENTER TO CONTINUE");

    while(!start){

        if(index_caracter==1){
            gotoxy(35, 9);
            printf("      "); // sageata stanga
            SetConsoleTextAttribute(h, 0*16+12);
            gotoxy(50, 9);
            printf("%c", v[1]); // caracter obiect
            SetConsoleTextAttribute(h, 0*16+15);
            gotoxy(60, 9);
            printf("%c (D)", 16); // sageata dreapta
            c1=getch();
            if(c1==13){
                start=1;
                q=v[index_caracter];
            }
            if(c1==100) index_caracter++; // dreapta
        }
        if(index_caracter>1 && index_caracter<4){
            SetConsoleTextAttribute(h, 0*16+15);
            gotoxy(35, 9);
            printf("(A) %c", 17); // sageata stanga
            SetConsoleTextAttribute(h, 0*16+12);
            gotoxy(50, 9);
            printf("%c", v[index_caracter]); // caracter obiect
            SetConsoleTextAttribute(h, 0*16+15);
            gotoxy(60, 9);
            printf("%c (D)", 16); // sageata dreapta
            c1=getch();
            if(c1==13){
                start=1;
                q=v[index_caracter];
            }
            if(c1==100) index_caracter++; // dreapta
            if(c1==97) index_caracter--; // stanga
        }
        if(index_caracter==4){
            SetConsoleTextAttribute(h, 0*16+15);
            gotoxy(35, 9);
            printf("(A) %c", 17); // sageata stanga
            SetConsoleTextAttribute(h, 0*16+12);
            gotoxy(50, 9);
            printf("%c", v[4]); // caracter obiect
            gotoxy(60, 9);
            printf("      "); // sageata dreapta
            c1=getch();
            if(c1==13){
                start=1;
                q=v[q+index_caracter-1];
            }
            if(c1==97) index_caracter--; // stanga
        }

    }

    system("CLS");

    start=0;

    speed=250;

    system("Color 94");

    gotoxy(55, 7);
    printf("3");
    Sleep(750);
    system("CLS");

    system("Color C2");

    gotoxy(55, 7);
    printf("2");
    Sleep(750);
    system("CLS");

    system("Color A5");

    gotoxy(55, 7);
    printf("1");
    Sleep(750);
    system("CLS");

    system("Color D1");
    gotoxy(54, 7);
    printf("GO!");
    Sleep(750);
    system("CLS");

    system("Color 0F");

    SetConsoleTextAttribute(h, 0*16+6);

    for(i=2; i<=100; i++){
        gotoxy(i, 0);
        printf("%c", 95);
        gotoxy(i, 19);
        printf("%c", 95);
    }
    for(i=1; i<=19; i++){
        gotoxy(2, i);
        printf("%c", 124);
        gotoxy(100, i);
        printf("%c", 124);
    }

    x_rand=(rand()%94)+4;
    y_rand=(rand()%15)+2;
    if(x_rand>=40 && x_rand<=63)
        while(x_rand>=40 && x_rand<=63) x_rand=(rand()%94)+4;
    if(y_rand==7)
        while(y_rand==7) y_rand=(rand()%15)+2;
    SetConsoleTextAttribute(h, snake_color[1]);
    gotoxy(x_rand, y_rand);
    printf("%c", q);

    SetConsoleTextAttribute(h, 0*16+6);
    gotoxy(3, 21);
    printf("LIVES: ");
    SetConsoleTextAttribute(h, 0*16+4);
    gotoxy(10, 21);
    printf("%c %c %c", 3, 3, 3);


    x=3;
    y=1;

    gotoxy(x, y);

    while(lives>0){

            for(i=1; i<=length; i++){
                SetConsoleTextAttribute(h, 0*16+6);
                if(snake[i][1]!=0){
                    gotoxy(snake[i][1], 19);
                    printf("%c", 95);
                }
            }

            SetConsoleTextAttribute(h, 0*16+6);
            gotoxy(91, 21);
            printf("SCORE: %d", length-2);

            if(schimba_obiect){
                x_rand=(rand()%94)+4;
                y_rand=(rand()%15)+2;
                if(x_rand>=40 && x_rand<=63)
                    while(x_rand>=40 && x_rand<=63) x_rand=(rand()%94)+4;
                if(y_rand==7)
                    while(y_rand==7) y_rand=(rand()%15)+2;

                schimba_obiect=0;
                past_color_index_rand=color_index_rand;
                color_index_rand=(rand()%5)+1;
                while(color_index_rand==past_color_index_rand) color_index_rand=(rand()%5)+1;
                SetConsoleTextAttribute(h, snake_color[color_index_rand]);

                    gotoxy(x_rand, y_rand);
                    printf("%c", q);
            }

            if(kbhit()){
                c=getch();
                gotoxy(snake[length][1], snake[length][2]);
                printf(" ");

                if(da){
                    SetConsoleTextAttribute(h, snake_color[past_color_index_rand]);
                }else SetConsoleTextAttribute(h, 0*16+15);

                if(start1){
                    for(i=length-1; i>=1; i--){
                        snake[i+1][1]=snake[i][1];
                        snake[i+1][2]=snake[i][2];
                    }
                    for(i=1; i<=length; i++){
                        gotoxy(snake[i][1], snake[i][2]);
                        printf("%c", 178);
                    }
                }
                snake[1][1]=x;
                snake[1][2]=y;

                start1=1;

                if(x==x_rand && y==y_rand){
                    Sleep(speed);
                    if(speed>75) speed=speed-25;
                    schimba_obiect=1;
                    gotoxy(x_rand, y_rand);
                    length++;
                    da=1;
                }

                // schimb de directie

                if(c=='s'){
                    y++;
                    direction=3; //jos
                }
                if(c=='w'){
                    y--;
                    direction=4; //sus
                }
                if(c=='d'){
                    x++;
                    direction=1; //dreapta
                }
                if(c=='a'){
                    x--;
                    direction=2; //stanga
                }

                gotoxy(x, y);

            }else{
                Sleep(speed);
                gotoxy(snake[length][1], snake[length][2]);
                printf(" ");

                if(da){
                    SetConsoleTextAttribute(h, snake_color[past_color_index_rand]);
                }else SetConsoleTextAttribute(h, 0*16+15);


                if(start1){
                    for(i=length; i>1; i--){
                        snake[i][1]=snake[i-1][1];
                        snake[i][2]=snake[i-1][2];
                    }
                    for(i=1; i<=length; i++){
                        gotoxy(snake[i][1], snake[i][2]);
                        printf("%c", 178);
                    }
                }
                snake[1][1]=x;
                snake[1][2]=y;
                start1=1;

                gotoxy(x, y);

                if(x==x_rand && y==y_rand){
                    Sleep(speed);
                    if(speed>100) speed=speed-25;
                    schimba_obiect=1;
                    gotoxy(x_rand, y_rand);
                    length++;
                    da=1;
                }

                if (direction==1) x++;
                if (direction==2) x--;
                if (direction==3) y++;
                if (direction==4) y--;

            }

            // schimb de directie

            if(x>99){
                direction=2;
                x--;

                lives--;

                if(lives==2){
                    gotoxy(14, 21);
                    printf(" ");
                }
                if(lives==1){
                    gotoxy(12, 21);
                    printf(" ");
                }

                if(lives==0){
                    SetConsoleTextAttribute(h, 0*16+6);
                    gotoxy(10, 21);
                    printf("0");

                    Sleep(500);
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(45, 9);
                    printf("GAME OVER");
                    Sleep(2000);

                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 11);
                    printf("PRESS ENTER TO CONTINUE");
                }else{
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 7);
                    printf("PRESS ENTER TO CONTINUE");
                }

                c1=getch();
                SetConsoleTextAttribute(h, 0*16+0);
                while(c1!=13) c1=getch();
                gotoxy(40, 7);
                printf("                       ");
            }
            if(y>19){
                direction=4;
                y--;
                // remake_border=1;

                lives--;

                if(lives==2){
                    gotoxy(14, 21);
                    printf(" ");
                }
                if(lives==1){
                    gotoxy(12, 21);
                    printf(" ");
                }

                if(lives==0){
                    SetConsoleTextAttribute(h, 0*16+6);
                    gotoxy(10, 21);
                    printf("0");

                    Sleep(500);
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(45, 9);
                    printf("GAME OVER");
                    Sleep(2000);

                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 11);
                    printf("PRESS ENTER TO CONTINUE");
                }else{
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 7);
                    printf("PRESS ENTER TO CONTINUE");
                }

                c1=getch();
                while(c1!=13) c1=getch();
                SetConsoleTextAttribute(h, 0*16+0);
                gotoxy(40, 7);
                printf("                       ");
            }
            if(x==2 && y!=0){
                direction=1;
                x++;

                lives--;

                if(lives==2){
                    gotoxy(14, 21);
                    printf(" ");
                }
                if(lives==1){
                    gotoxy(12, 21);
                    printf(" ");
                }

                if(lives==0){
                    SetConsoleTextAttribute(h, 0*16+6);
                    gotoxy(10, 21);
                    printf("0");

                    Sleep(500);
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(45, 9);
                    printf("GAME OVER");
                    Sleep(2000);

                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 11);
                    printf("PRESS ENTER TO CONTINUE");
                }else{
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 7);
                    printf("PRESS ENTER TO CONTINUE");
                }

                c1=getch();
                while(c1!=13) c1=getch();
                SetConsoleTextAttribute(h, 0*16+0);
                gotoxy(40, 7);
                printf("                       ");
            }
            if(y==0 && x!=0){
                direction=3;
                y++;

                lives--;

                if(lives==2){
                    gotoxy(14, 21);
                    printf(" ");
                }
                if(lives==1){
                    gotoxy(12, 21);
                    printf(" ");
                }

                if(lives==0){
                    SetConsoleTextAttribute(h, 0*16+6);
                    gotoxy(10, 21);
                    printf("0");

                    Sleep(500);
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(45, 9);
                    printf("GAME OVER");
                    Sleep(2000);

                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 11);
                    printf("PRESS ENTER TO CONTINUE");
                }else{
                    SetConsoleTextAttribute(h, 15*16+4);
                    gotoxy(40, 7);
                    printf("PRESS ENTER TO CONTINUE");
                }

                c1=getch();
                while(c1!=13) c1=getch();
                SetConsoleTextAttribute(h, 0*16+0);
                gotoxy(40, 7);
                printf("                       ");
            }

        }

        if(length-2>highest_score) highest_score=length-2;

        SetConsoleTextAttribute(h, 4*16+15);
        for(i=25; i<=75; i++)
            for(j=5; j<=15; j++){
                gotoxy(i, j);
                printf(" ");
            }
        gotoxy(40, 6);
        printf("THANKS FOR PLAYING!");
        gotoxy(28, 9);
        printf("YOUR SCORE: %d", length-2);
        gotoxy(28, 11);
        printf("YOUR HIGHEST SCORE: %d", highest_score);
        gotoxy(47, 13);
        printf("PRESS ENTER TO START AGAIN");

        c1=getch();
        while(c1!=13) c1=getch();
    }

    gotoxy(0, 150);
    return 0;
}
