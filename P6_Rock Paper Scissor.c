#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int you,computer;
int y=0,c=0;

int menu()
{
    int choice;
    printf("\n 1. Select Rock ");
    printf("\n 2. Select Paper ");
    printf("\n 3. Select Scissor ");
    printf("\n 4. Exit ");
    printf("\n Enter your choice ");
    scanf("%d",&choice);
    return(choice);
}

void setup()
{
 label:
  computer=rand()%4;
  if(computer==0)
  {
    goto label;
  }
  you=menu();
}

void makeLogic()
{   
   switch(you)
   { 
     case 1:
            if(computer==1)
            {
                printf("\n Its a Draw ");
                printf("\n You : Rock & Computer : Rock ");
            }
            else if(computer==2) 
            {
                printf("\n Computer Wins ");
                printf("\n You : Rock & Computer : Paper ");
                c++;
            }
            else
            {
                printf("\n You Win ");
                printf("\n You : Rock & Computer : Scissor ");
                y++;
            } 
            break;
     case 2: 
            if(computer==2)
            {
                printf("\n Its a Draw ");
                printf("\n You : Paper & Computer : Paper ");
            }
            else if(computer==1) 
            {
                printf("\n You Win ");
                printf("\n You : Paper & Computer : Rock ");
                y++;
            }
            else
            {
                printf("\n Computer Wins ");
                printf("\n You : Ppaper & Computer : Scissor ");
                c++;
            } 
            break;
     case 3:
            if(computer==3)
            {
                printf("\n Its a Draw ");
                printf("\n You : Scissor & Computer : Scissor ");
            }
            else if(computer==1) 
            {
                printf("\n Computer Wins ");
                printf("\n You : Scissor & Computer : Rock ");
                c++;
            }
            else
            {
                printf("\n You Win ");
                printf("\n You : Scissor & Computer : Paper ");
                y++;
            } 
            break;
     case 4:
            printf("\n Scores ");
            printf("\n You won %d times & Computer won %d times ",y,c);
            printf("\n Thank you for Playing ");
            exit(0);
     default:
            printf("\n Invalid Input ");       
   }
}

int main()
{   
    while(1)
    { 
		
     system("cls");   
     printf("\n Welcome to the Game of Rocks Papers Scissors "); 
     setup();
     makeLogic();
     getch();
    }
    return 0;
}
