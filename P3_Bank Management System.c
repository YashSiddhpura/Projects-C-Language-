#include<stdio.h>
#include<stdlib.h>

int totalAmt=1000,amt,amt1,amt2;
int Tdeposit=0,Ttransfer=0,Twithdraw=0;
int flag,flag1;
char name[20];
int acc_id,TD=0,TW=0,TR=0;

int list()
{
    int choice;
    printf("\n 1. Deposit amount ");
    printf("\n 2. Withdraw amount ");
    printf("\n 3. Transfer amount ");
    printf("\n 4. Check details ");
    printf("\n 5. Exit ");
    printf("\n Enter your choice ");
    scanf("%d",&choice);
    return(choice);
}

void deposit()
{
    printf("\n Enter the amount to be deposited in your account ");
    scanf("%d",&amt);
    totalAmt+=amt;
    TD++;
}

void withdraw()
{
    printf("\n Enter the amount to be withdraw from your account ");
    scanf("%d",&amt1);

    if(amt1<=totalAmt)
    {
         totalAmt-=amt1;
         flag=1;
         TW++;
    }
    else
    {
        printf("\n The amount cannot be withdrawed from your account ");
        flag=0;
    }
}

void transfer()
{
    printf("\n Enter the amount to be transfered from your account ");
    scanf("%d",&amt2);

    if(amt2<=totalAmt)
    {
         totalAmt-=amt2;
         flag1=1;
         TR++;
    }
    else
    {
        printf("\n The amount cannot be transfered from your account ");
        flag1=0;
    }
}

void checkD()
{
    printf("\n The total amount present in your account is %d",totalAmt);
    printf("\n The total amount deposited in your account is %d",Tdeposit);
    printf("\n The total amount withdrawed from your account is %d",Twithdraw);
    printf("\n The total amount transfered from your account is %d",Ttransfer);
    printf("\n");
}

void details()
{
    printf("\n Account holder name:- %s ",name);
    printf("\n Account ID:- %d ",acc_id);
    printf("\n The total amount is %d",totalAmt);
    printf("\n The amount is depostied %d times & the total amount deposited is %d",TD,Tdeposit);
    printf("\n The amount is withdrawed %d times & total amount withdrawed is %d",TW,Twithdraw);
    printf("\n The amount is transfered %d times & total amount transfered is %d",TR,Ttransfer);
    printf("\n");
}

int main()
{
    printf("\n !...Welcome to our Bank...!");
    printf("\n Enter your name ");
    scanf("%s",name);
    printf("\n Enter your account number ");
    scanf("%d",&acc_id);
    printf("\n Account Holder %s has logged in the system @%s ",name,__TIMESTAMP__);
    while(1)
    { 
      switch(list())
       {
         case 1:
                deposit();
                Tdeposit+=amt;
                break;
         case 2:
                withdraw();
                if(flag)
                 {
                     Twithdraw+=amt1;
                 }
                break;
         case 3:
                transfer();
                if(flag1)
                 {
                     Ttransfer+=amt2;
                 }        
                break;
         case 4:
                checkD();
                break;
         case 5: 
                details();
                printf("\n Thank you for visiting out bank ");
                printf("\n Account Holder %s has logged out the system @ %s ",name,__TIMESTAMP__);
                exit(0);
                break;
         default:
                 printf("\n Invalid Imput... ");                     
       }
    } 
    return 0;
}