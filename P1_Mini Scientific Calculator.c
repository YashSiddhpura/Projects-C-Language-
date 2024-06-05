#include <stdio.h>
//#include <conio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.142
int k=0;
float result=0.0;

float DegTORad(float num)
{
    float rad;
    rad=num*(pi/180);
    return(rad);
}
int menu1()
{
   int choice1;
    printf("\n 1. Addition with old result ");
    printf("\n 2. Substraction with old result ");
    printf("\n 3. Multiplication with old result ");
    printf("\n 4. Division with old result ");
    printf("\n 5. Exit ");
    printf("\n Enter your Choice ");
    scanf("%d", &choice1);
    return (choice1);

}
int menu()
{
    int choice;
    printf("\n 1. Addition           \t7.sine of an angle ");
    printf("\n 2. Substraction       \t8. cosine of an angle ");
    printf("\n 3. Multiplication     \t9. tan of an angle ");
    printf("\n 4. Division           \t10. power operation ");
    printf("\n 5. Division(Remainder)\t11. square root of a number/result ");
    printf("\n 6. Clear Data         \t12. Reciprocal of a number/result");
    printf("\n 13. Exit  ");
    printf("\n Enter your Choice ");
    scanf("%d", &choice);
    return (choice);
}

void Add()
{
    float num1,num2;
    if(k)
    {
        printf("\n Enter a number ");
        scanf("%f",&num1);
        result+=num1;
        printf("\n The result after addition is %f ",result);
    }
    else
    {
        printf("\n Enter two numbers ");
        scanf("%f%f",&num1,&num2);
        result=num1+num2;
        printf("\n The result after addition is %f ",result);
    }
}

void Sub()
{
    float num1,num2;
    if(k)
    {
        printf("\n Enter a number ");
        scanf("%f",&num1);
        result-=num1;
        printf("\n The result after subtraction is %f ",result);
    }
    else
    {
        printf("\n Enter two numbers ");
        scanf("%f%f",&num1,&num2);
        result=num1-num2;
        printf("\n The result after subtraction is %f ",result);
    }
}

void Mul()
{
    float num1,num2;
    if(k)
    {
        printf("\n Enter a number ");
        scanf("%f",&num1);
        result*=num1;
        printf("\n The result after Multiplication is %f ",result);
    }
    else
    {
        printf("\n Enter two numbers ");
        scanf("%f%f",&num1,&num2);
        result=num1*num2;
        printf("\n The result after Multiplication is %f ",result);
    }
}

void Div()
{
    float num1,num2;
    if(k)
    {
        printf("\n Enter a number ");
        scanf("%f",&num1);
        if(num1==0)
        {
            printf("\n ERROR: You cannot divide a number by 0");
            exit(0);
        }
        result/=num1;
        printf("\n The result after division is %f ",result);
    }
    else
    {
        printf("\n Enter two numbers ");
        scanf("%f%f",&num1,&num2);
        if(num2==0)
        {
            printf("\n ERROR: You cannot divide a number by 0");
            exit(0);
        }
        result=num1/num2;
        printf("\n The result after division is %f ",result);
    }
}

void DivR()
{
    int num1,num2,res1=0;
    if(k)
    {
        printf("\n Enter a number ");
        scanf("%d",&num1);
        res1=result;
        res1%=num1;
        result=res1;
        printf("\n The result after modulo division is %f ",result);
    }
    else
    {
        printf("\n Enter two numbers ");
        scanf("%d%d",&num1,&num2);
        result=num1%num2;
        printf("\n The result after Modulo division is %f ",result);
    }
}

void sinR()
{
        float num1,ans;
        printf("\n Enter the angle in degree ");
        scanf("%f",&num1);
        ans=sin(DegTORad(num1));
        printf("\n the answer after doing sine of a number is %f ",ans);
        switch(menu1())
        {
           case 1: result+=ans;
                   break; 
           case 2: result-=ans;
                   break; 
           case 3: result*=ans;
                   break; 
           case 4: result/=ans;
                   break; 
           case 5: printf("\n Task is Completed ");
                   break;  
        }
}

void cosR()
{
        float num1,ans;
        printf("\n Enter the angle in degree ");
        scanf("%f",&num1);
        ans=cos(DegTORad(num1));
        printf("\n the answer after doing cosine of a number is %f ",ans);
        switch(menu1())
        {
           case 1: result+=ans;
                   break; 
           case 2: result-=ans;
                   break; 
           case 3: result*=ans;
                   break; 
           case 4: result/=ans;
                   break; 
           case 5: printf("\n Task is Completed ");
                   break;  
        }
}

void tanR()
{
        float num1,ans;
        printf("\n Enter the angle in degree ");
        scanf("%f",&num1);
        ans=tan(DegTORad(num1));
        printf("\n the answer after doing tan of a number is %f ",ans);
        switch(menu1())
        {
           case 1: result+=ans;
                   break; 
           case 2: result-=ans;
                   break; 
           case 3: result*=ans;
                   break; 
           case 4: result/=ans;
                   break; 
           case 5: printf("\n Task is Completed ");
                   break;  
        }
}

void power()
{
    float num1,num2;
    if(k)
    {
        printf("\n Enter a index ");
        scanf("%f",&num1);
        result=pow(result,num1);
        printf("\n The result after raising the result w.r.t a power(input) is %f ",result);
    }
    else
    {
        printf("\n Enter base and index ");
        scanf("%f%f",&num1,&num2);
        result=pow(num1,num2);
        printf("\n The result after power operation is %f ",result);
    }
}


void squareR()
{
    float num1;
    if(k)
    {
        result=sqrt(result);
        printf("\n The result after performing square root of the result is  %f ",result);
    }
    else
    {
        printf("\n Enter number ");
        scanf("%f",&num1);
        result=sqrt(num1);
        printf("\n The result after finding the square root of a number is %f ",result);
    }
}


void recip()
{
    float num1;
    if(k)
    {
        result=(1/result);
        printf("\n The result after performing reciprocal of the result is %f ",result);
    }
    else
    {
        printf("\n Enter a number ");
        scanf("%f",&num1);
        if(num1==0)
        {
            printf("\n ERROR: You cannot divide a number by 0");
            exit(0);
        }
        result=(1/num1);
        printf("\n The result after finding the reciprocal of a number is %f ",result);
    }
}

void ClearR()
{
    result=0;
    k=0;
    printf("\n Old Data is cleared. ");
}
int main()
{
    printf("\n Welcome ...! \n The Calculator begins");
    while(1)
    {  
  //  clrscr(); .....Use it where conio.h is supproted      
     printf("\n\nOld Result is %f ",result);
     switch (menu())
     {
     case 1:
             Add();
             k=1;
             break;
     case 2:
             Sub();
             k=1;
             break;
     case 3:
             Mul();
             k=1;
             break;
     case 4:
             Div();
             k=1;
             break;
     case 5: 
             DivR();
             k=1;
             break;
     case 6: 
             ClearR();
             break;
     case 7: 
             sinR();
             k=1;
             break; 
     case 8: 
             cosR();
             k=1;
             break;  
     case 9: 
             tanR();
             k=1;
             break;      
     case 10: 
             power();
             k=1;
             break; 
     case 11: 
             squareR();
             k=1;
             break; 
     case 12: 
             recip();
             k=1;
             break;                                                                         
    case 13: printf("\n Operation is completed. \n Thank you ....!");
             exit(0);         
     default: printf("\n Invalid Input ...!");              
     }
 //  getch(); .....Use it where conio.h is supproted      
    } 
    return 0;
}