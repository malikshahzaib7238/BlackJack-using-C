#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>                //Used for srand((unsigned) time(NULL)) command 

#include "colors.h"
#include "prototypes.h"
#define spade 06                 //Used to print spade symbol
#define club 05                  //Used to print club symbol
#define diamond 04               //Used to print diamond symbol
#define heart 03                 //Used to print heart symbol
#define RESULTS "blackjack.txt"  //File name is Blackjack
//Global Variables

int a, b, c;
int won, loss, draw;
int total_money = 500;
int bet;
int random_card;
int plyer_sum=0;
int trader_sum;
//Main Function
int main(void)
{
    //printf("\033[0;44m"); // blue background
    system("setterm -background blue");

    int choice1;
    asktitle();
    printf("\n");
    printf("\n");
    system("pause");
    return(0);
    system("setterm -default");
// To set the colout of the terminal to default
    //printf("\033[0m"); // reset background color
}  
void asktitle() // Function for asking player if they want to continue
{
    char choice1;
    int choice2;  
     printf("\n                 Are You Ready?                                  ");
     printf("\n                ----------------                                 ");
     printf("\n                      (Y/N)                                      \n");
     scanf("\n%c",&choice1);   
    while((choice1!='Y') && (choice1!='y') && (choice1!='N') && (choice1!='n')) // If invalid choice entered
    {                                                                          
        printf("\n");
        printf("Incorrect Choice. Please Enter Y for Yes or N for No.\n");
        scanf("%c",&choice1);
    }
    if((choice1 == 'Y') || (choice1 == 'y')) // If yes, continue. Prints menu.
    {
            printf("\nEnter 1 to Begin the Greatest Game Ever Played.");
            printf("\nEnter 2 to Exit Game. (Not Recommended)");
            printf("\nChoice: ");
            scanf("%d", &choice2); // Prompts user for choice
            if((choice2<1) || (choice2>3)) // If invalid choice entered
            {
                printf("\nIncorrect Choice. Please enter 1 or 2.\n");
                scanf("%d", &choice2);
            }
            switch(choice2) // Switch case for different choices
            {  
                case 1:                     
                   play();                   
                   break;
                case 2: // Case to exit game
                   printf("\nYour day could have been perfect.");
                   printf("\nHave an almost perfect day!\n\n");
                   system("pause");
                   exit(0);
                   break;
                default:
                   printf("\nInvalid Input");
            } // End switch case
    } // End if loop
    else if((choice1 == 'N') || (choice1 == 'n')) // If no, exit program
    {
        printf("\nYour day could have been perfect.");
        printf("\nHave an almost perfect day!\n\n");
        system("pause");
        exit(0);
    }
    return;
} // End function
int clubcard() //Displays Club Card Image
{
    srand(time(0)); //Generates random seed for rand() function
    a=rand()%13+1;    
    if(a<=9) //If random number is 9 or less, print card with that number
    {
    //Club Card
    green();
    printf("\n-------\n");
    printf("|");
    blue();
    printf("%c", club);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("%d",a); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", club);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==10) //If random number is 10, print card with J (Jack) on face
    {
    //Club Card
   green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", club);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("J"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", club);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==11) //If random number is 11, print card with A (Ace) on face
    {
   green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", club);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("A"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", club);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    if(plyer_sum<=10) //If random number is Ace, change value to 11 or 1 depending on dealer total
         {
             a=11;
         }
         else
         {
 
             a=1;
         }
    }
    if(a==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Club Card
   green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", club);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("Q"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", club);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    if(a==13) //If random number is 13, print card with K (King) on face
    {
    //Club Card
   green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", club);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("K"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", club);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    return a;          
}// End function
int diamondcard() //Displays Diamond Card Image
{
    srand(time(0)); //Generates random seed for rand() function
    a=rand()%13+1;    
    if(a<=9) //If random number is 9 or less, print card with that number
    {
    //Diamond Card
    green();
    printf("\n-------\n");
    printf("|");
    red();
    printf("%c", diamond);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("%d",a); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", diamond);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==10) //If random number is 10, print card with J (Jack) on face
    {
    //Diamond Card
    green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", diamond);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("J"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", diamond);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==11) //If random number is 11, print card with A (Ace) on face
    {
    //Diamond Card
     green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", diamond);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("A"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", diamond);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    if(plyer_sum<=10) //If random number is Ace, change value to 11 or 1 depending on dealer total
         {
             a=11;
         }     
         else
         {
             a=1;
         }
    }
    if(a==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Diamond Card
     green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", diamond);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("Q"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", diamond);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    } 
    if(a==13) //If random number is 13, print card with K (King) on face
    {
    //Diamond Card
    green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", diamond);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("K"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", diamond);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    return a;
}// End function
 
int heartcard() //Displays Heart Card Image
{
    srand(time(0)); //Generates random seed for rand() function
    a=rand()%13+1;    
    if(a<=9) //If random number is 9 or less, print card with that number
    {
  green();
    printf("\n-------\n");
    printf("|");
    red();
    printf("%c", heart);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("%d",a); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", heart);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==10) //If random number is 10, print card with J (Jack) on face
    {
    //Heart Card
   green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", heart);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("J"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", heart);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==11) //If random number is 11, print card with A (Ace) on face
    {
    //Heart Card
    green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", heart);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("A"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", heart);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    if(plyer_sum<=10) //If random number is Ace, change value to 11 or 1 depending on dealer total
         {
             a=11;
         }     
         else
         {
             a=1;
         }
    }
    if(a==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Heart Card
    green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", heart);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("Q"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", heart);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    if(a==13) //If random number is 13, print card with K (King) on face
    {
    //Heart Card
   green();
    printf("-------\n");
    printf("|");
    red();
    printf("%c", heart);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("K"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    red();
    printf("%c", heart);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    return a;
} // End Function
int spadecard() //Displays Spade Card Image
{
    srand((unsigned) time(NULL)); //Generates random seed for rand() function
    a=rand()%13+1;    
    if(a<=9) //If random number is 9 or less, print card with that number
    {
    //Spade Card
    green();
    printf("\n-------\n");
    printf("|");
    blue();
    printf("%c", spade);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("%d",a); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", spade);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==10) //If random number is 10, print card with J (Jack) on face
    {
    //Spade Card
   green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", spade);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("J"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", spade);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    }
    if(a==11) //If random number is 11, print card with A (Ace) on face
    {
    //Spade Card
    green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", spade);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("A"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", spade);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    if(plyer_sum<=10) //If random number is Ace, change value to 11 or 1 depending on dealer total
         {
             a=11;
         }     
         else
         {
             a=1;
         }
    }
    if(a==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Spade Card
    green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", spade);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("Q"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", spade);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    if(a==13) //If random number is 13, print card with K (King) on face
    {
    //Spade Card
    green();
    printf("-------\n");
    printf("|");
    blue();
    printf("%c", spade);
    green();
    printf("    |\n");
    printf("|  ");
    yellow();
    printf("K"); 
    green();
    printf( "  |\n",a);
    printf("|    ");
    blue();
    printf("%c", spade);
    green();
    printf("|\n");
    printf("-------\n");
    reset();
    a=10; //Set card value to 10
    }
    return a;
} // End Function
 
int randcard() //Generates random card
{           
     srand(time(0)); //Generates random seed for rand() function
     random_card = rand()%4+1;     
     if(random_card==1)
     {  
         clubcard();
         b=a;
     }
     if(random_card==2)
     {
         diamondcard();
         b=a;
     }
     if(random_card==3)
     {
         heartcard();
         b=a;
     }    
     if(random_card==4)
     {
         spadecard();
         b=a;
     }   
     return b;
} // End Function  
void play() //Plays game
{
     int p=0; // holds value of player_total
     int i=1; // counter for asking user to hold or stay (aka game turns)
     char choice3;     
     total_money = total_money;
     cash_test();
     printf("\nCash: $%d\n",total_money); //Prints amount of cash user has
     randcard(); //Generates random card
     plyer_sum = p + b; //Computes player total
     p = plyer_sum;
     printf("\nYour Total is %d\n", p); //Prints player total
     dealer(); //Computes and prints dealer total
     betting(); //Prompts user to enter bet amount
     while(i<=21) //While loop used to keep asking user to hit or stay at most twenty-one times
                  //  because there is a chance user can generate twenty-one consecutive 1's
     {
         if(p==21) //If user total is 21, win
         {
            printf("\nThe Dealer Has a Total of %d", trader_sum);
            cyan();
             printf("\nUnbelievable! You Win!\n");
             reset();
             won = won+1;
             total_money = total_money+bet;
             printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
             trader_sum=0;
             askover();
         }
         if(p>21) //If player total is over 21, lss
         {
            printf("\nThe Dealer Has a Total of %d", trader_sum);
            redBlink();  
             printf("\nWoah Buddy, You Went WAY over.\n");
             reset();
             loss = loss+1;
             total_money = total_money - bet;
             printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
             trader_sum=0;
             askover();
         }
         if(p<=21) //If player total is less than 21, ask to hit or stay
         {        
             printf("\n\nWould You Like to Hit or Stay?");
             scanf("%c", &choice3);
             while((choice3!='H') && (choice3!='h') && (choice3!='S') && (choice3!='s')) // If invalid choice entered
             {                                                                          
                 printf("\n");
                 printf("Please Enter H to Hit or S to Stay.\n");
                 scanf("%c",&choice3);
             }
             if((choice3=='H') || (choice3=='h')) // If Hit, continues
             {
                 randcard();
                 plyer_sum = p + b;
                 p = plyer_sum;
                 printf("\nYour Total is %d\n", p);
                 dealer();
                  if(trader_sum==21) //Is dealer total is 21, loss
                  {
                    printf("\nThe Dealer Has a Total of %d", trader_sum);
                    redBlink();  
                      printf("\nDealer Has the Better Hand. You Lose.\n");
                      reset();
                      loss = loss+1;
                      total_money = total_money - bet;
                      printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
                      trader_sum=0;
                      askover();
                  }
                  if(trader_sum>21) //If dealer total is over 21, win
                  {                   
                    printf("\nThe Dealer Has a Total of %d", trader_sum);
                    cyan();
                    
                      printf("\nDealer Has Went Over!. You Win!\n");
                      reset();
                      won = won+1;
                      total_money = total_money+bet;
                      printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
                      trader_sum=0;
                      askover();
                  }
             }
             if((choice3=='S') || (choice3=='s')) // If Stay, does not continue
             {
                printf("\nYou Have Chosen to Stay at %d. Wise Decision!\n", plyer_sum);
                stay();
             }
          }
             i++; //While player total and dealer total are less than 21, re-do while loop
     } // End While Loop
} // End Function
void dealer() //Function to play for dealer AI
{
     int z;
     if(trader_sum<17)
     {
      srand((unsigned) time(NULL) + 1); //Generates random seed for rand() function
      z=rand()%13+1;
      if(z<=10) //If random number generated is 10 or less, keep that value
      {
         c=z;
      }
      if(z>11) //If random number generated is more than 11, change value to 10
      {
         c=10;
      }
      if(z==11) //If random number is 11(Ace), change value to 11 or 1 depending on dealer total
      {
         if(trader_sum<=10)
         {
             c=11;
         }   
         else
         {
             c=1;
         }
      }
     trader_sum = trader_sum + c;
     }
           
     //printf("\nThe Dealer Has a Total of %d", trader_sum); //Prints dealer total
} // End Function
void stay() //Function for when user selects 'Stay'
{
    printf("\nThe Dealer Has a Total of %d", trader_sum); //Prints dealer total
     dealer(); //If stay selected, dealer continues going
     if(trader_sum>=17)
     {
      if(plyer_sum>trader_sum) //If player's total is more than dealer's total, win
      {
        cyan();
         printf("\nUnbelievable! You Win!\n");
         reset();
         won++;
         total_money = total_money+bet;
         printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
         trader_sum=0;
         askover();
      }
      if(plyer_sum==trader_sum) //If player's total is equal to dealer's total, draw
      {
        magenta();
        printf("\n Sadly the outcome of the match is inconclusive. Its a DRAW.\n");
        reset();
        draw++;
         printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
        trader_sum=0;
        askover();
        

      }
      if(plyer_sum<trader_sum) //If player's total is less than dealer's total, loss
      {
        red();
         printf("\nDealer Has the Better Hand. You Lose.\n");
         reset();
         loss++;
         total_money = total_money - bet;
         printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
         trader_sum=0;
         askover();
      }
      if(trader_sum>21) //If dealer's total is more than 21, win
      {
        cyan();
         printf("\nUnbelievable! You Win!\n");
         reset();
         won++;
         total_money = total_money+bet;
         printf("\nYou have %d Wins and %d Losses and %d draws. Awesome!\n", won, loss, draw);
         trader_sum=0;
         askover();
      }
     }
     else
     {
         stay();
     }
} // End Function
 
void cash_test() //Test for if user has cash remaining in purse
{
     if (total_money <= 0) //Once user has zero remaining cash, game ends and prompts user to play again
     {
        red();
        printf("You Are Bankrupt. Game Over");
        reset();
        total_money = 500;
        askover();
     }
} // End Function
int betting() //Asks user amount to bet
{
 printf("\n\nEnter Bet: $");
 scanf("%d", &bet);
 if (bet > total_money) //If player tries to bet more money than player has
 {
        printf("\nYou cannot bet more money than you have.");
        printf("\nEnter Bet: ");
        scanf("%d", &bet);
        return bet;
 }
 else return bet;
} // End Function
void askover() // Function for asking player if they want to play again
{
    char choice1;
     printf("\nWould You Like To Play Again?");
     printf("\nPlease Enter Y for Yes or N for No\n");
     scanf("\n%c",&choice1);
    while((choice1!='Y') && (choice1!='y') && (choice1!='N') && (choice1!='n')) // If invalid choice entered
    {                                                                          
        printf("\n");
        printf("Incorrect Choice. Please Enter Y for Yes or N for No.\n");
        scanf("%c",&choice1);
    } 
    if((choice1 == 'Y') || (choice1 == 'y')) // If yes, continue.
    {
            play();
    }
    else if((choice1 == 'N') || (choice1 == 'n')) // If no, exit program
    {
        fileresults();
        printf("\nBYE!!!!\n\n");
        system("pause");
        exit(0);
    }
    return;
} // End function
void fileresults() //Prints results into Blackjack.txt file in program directory
{
    FILE *fpresults; //File pointer is fpresults
    fpresults = fopen("C://Users//Shekhani Laptops//Documents//C Programming//Programs//BlackJack//BlackJack//blackjack.txt", "w"); //Creates file and writes into it
    if(fpresults == NULL) // what to do if file missing from directory
    {
               printf("\nError: File Missing\n");
               system("pause");
               exit(1);
    }
    else
    {    
     fprintf(fpresults,"\n\t RESULTS");
     fprintf(fpresults,"\n\t---------\n");
     fprintf(fpresults,"\nYou Have Won %d Times\n", won);
     fprintf(fpresults,"\nYou Have Lost %d Times\n", loss);
     fprintf(fpresults,"\nKeep Playing and Set an All-Time Record!");
    }
     fclose(fpresults);
     return;
     
}