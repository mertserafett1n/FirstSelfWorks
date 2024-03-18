#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mazesolver();
int guess01(int guess, int number);
void guessvoid(int guess, int number);
void guessgame();
void tetrisgame();
int scorecalc(int fcolor, int last_brick);
void displaybrickcolor(int brick1, int brick2, int a);
int menu();



int main(){
    srand(time(NULL));
    int a = 0;
    while(a != 4){
        a = menu();
    if(a == 1)
        guessgame();
    else if(a == 2)
        tetrisgame();
    else if(a == 3)
        mazesolver();
    else if(a == 4)
        printf("GoodBye, Have a good year.\n\n");
    }
    return 0;
}

int guess01(int guess, int number){
    if(guess == number )
        return 1;
    else
        return 0;
}
void guessvoid(int guess, int number){
    if(guess > number)
        printf("Too high, try again.\n");
    else if(guess < number)
        printf("Too low, try again.\n");
}
void guessgame(){
    int counter = 1;
    int guess, number;
    number = rand()%100;
    printf("Enter a guess between 1 and 100:  ");
    scanf("%d",&guess);
    guessvoid(guess,number);
    while(guess01(guess,number) == 0){
        printf("Enter a guess between 1 and 100:  ");
        scanf("%d",&guess);
        guessvoid(guess,number);
        counter++;
    }
    printf("Correct.  You got it in %d guesses\n\n\n", counter);
}
void tetrisgame(){
    int limit = 0, point = 0;
    int a = 0;
    int scndbrick = -1, temppoint;
    while(limit < 30){
        //1 for Green, 2 for Yellow, 3 for Blue, 4 for Red.
        // New brick's color. Between 1-4
        int last_brick = (rand() % 4) + 1;
        displaybrickcolor(last_brick,scndbrick,a);
        // Saving old point to cancel out last 2 brick if they are same.
        temppoint = point;  
        point += scorecalc(scndbrick, last_brick);
        limit++;        
        if(a == 1)
            limit++;            
        a = 0; 
        //saving second to last brick's color to calculate gainedscore.
        scndbrick = last_brick;             
        if(point > temppoint){              
            // setting a to 1 to display 2 bricks's colors with function displaybrickcolor. 
            limit-= 2, a = 1;
            scndbrick = (rand() % (4)) + 1;
        }
        printf("Current points : %d, Limit: %d\n\n\n", point,limit);
    }
    printf("Total Points: %d\n\n\n----------GAME OVER----------\n\n\n", point);
}

    //fcolor is second to last brick, // point is point of lastbrick if it can cancel out with second to brick.
int scorecalc(int scndbrick, int last_brick){
    if(scndbrick == last_brick)
    //returns gainedscore.
        return last_brick;
    else 
        return 0;
}
void displaybrickcolor(int brick1, int brick2, int a){
    //when a is 0 func display just 1 brick.
        if(a == 1){
            int temp = brick1;
            brick1 = brick2;
            brick2 = temp;
        }
        if(brick1 == 1)
            printf("brick 1: #Color of the  brick is Green\n");
        else if(brick1 == 2)
            printf("brick 1: #Color of the  brick is Yellow\n");
        else if(brick1 == 3)
            printf("brick 1: #Color of the  brick is Blue\n");
        else 
            printf("brick 1: #Color of the  brick is Red\n");
        if(a == 1){
            if(brick2 == 1)
                printf("brick 2: #Color of the  brick is Green\n");
            else if(brick2 == 2)
                printf("brick 2: #Color of the  brick is Yellow\n");
            else if(brick2 == 3)
                printf("brick 2: #Color of the  brick is Blue\n");
            else 
                printf("brick 2: #Color of the  brick is Red\n");
        }
}
void mazesolver(){
    int i, j,number;
    printf("Enter a row number: ");
    scanf("%d",&number);
    int spointx = 0, spointy = 0,epointx = 0,epointy = 0;
    while((spointy < epointy || (spointy == epointy && spointx < epointx)) != 1 ){
        spointx = (rand() % number) + 1;
        spointy = (rand() % number) + 1; 
        epointx = (rand() % number) + 1;
        epointy = (rand() % number) + 1;
    }
    for(i = 1; i <= number; i++){
        for( j = 1; j <= number; j++){
            if(i == spointy && j == spointx)
                printf("S");
            else if(i == epointy && j == epointx)
                printf("E"); 
            else
                printf(".");    
        }
        printf("\n");
    }
    int result = (epointy - spointy) * number + (epointx - spointx) - 1;
    printf("Number of dots between S and E from left to right is %d\n\n\n", result);
}

int menu(){
    printf("-----------------------Welcome to the Game Arena-----------------------\n1.	Guess My Number Game\n2.	Tetris Game\n3.	Maze Solver\n4.	Quit\n\n ");
    int a;
    scanf("%d",&a);
    return a;
}