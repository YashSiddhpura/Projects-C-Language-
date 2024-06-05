#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h> // Include conio.h for getche()

void signup();
void login();
void forgot();
void change_password();
void del_account();

struct account {
    char fname[20];
    char lname[20];
    char user_name[30];
    char phone[15];
    char gender;
    char dob[10];
    char pass1[20];
};

int menu() {
    int choice;
    printf("\n Following are the operations ");
    printf("\n 1. Signup ");
    printf("\n 2. Login ");
    printf("\n 3. Forgot Password or Username ");
    printf("\n 4. Change password ");
    printf("\n 5. Delete Account ");
    printf("\n 6. Exit ");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void takepassword(char *pass) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == '\r') { // Enter key
            pass[i] = '\0';
            break;
        } else if (ch == 8 || ch == 127) { // Backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pass[i++] = ch;
            printf("*");
        }
    }
}

int main() {
    while (1) {
        system("cls");
        switch (menu()) {
            case 1: 
                signup();
                break;
            case 2: 
                login();
                break;
            case 3: 
                forgot();
                break;
            case 4:
                change_password();
                break;
            case 5:
                del_account();
                break;
            case 6:
                printf("\n Task is done ");
                exit(0);
            default: 
                printf("\n Invalid Input ");                                     
        }
    }
    return 0;
}

void signup() {
    char pass2[20];

    struct account u; 
    printf("\n CREATING NEW ACCOUNT ");
    printf("\n Enter your first name: ");
    scanf("%s", u.fname);
    
    printf("\n Enter your last name: ");
    scanf("%s", u.lname);
    
    printf("\n Enter your user name: ");
    scanf("%s", u.user_name);
    
    printf("\n Enter your phone number: ");
    scanf("%s", u.phone);
    getchar(); // Consume the newline character left by previous scanf
    
    printf("\n Enter your gender: ");
    u.gender = getchar();
    getchar(); // Consume the newline character after gender input
    
    printf("\n Enter your Date of birth: ");
    scanf("%s", u.dob);
    getchar(); // Consume the newline character left by previous scanf
    
    printf("\n Enter your password: ");
    takepassword(u.pass1);

conf_pass:
    printf("\n Confirm password: ");
    takepassword(pass2);

    if (strcmp(u.pass1, pass2) != 0) {
        printf("\n Incorrect Password ");
        goto conf_pass;
    } else {
        printf("\n Account Created Successfully ");
    }

    FILE *fp = fopen("account.txt", "w+");
    if (fp == NULL) {
        printf("\n Error opening file. ");
        return;
    }
    fwrite(&u, sizeof(struct account), 1, fp);
    fclose(fp);
    getchar();
}

void login() {
    char user[30], log_pass[20];

    struct account u;
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("\n Error opening file. ");
        getchar();
        return;
    }
    fread(&u, sizeof(struct account), 1, fp);

name:
    printf("\n Enter Username: ");
    scanf("%s", user);
    if (strcmp(u.user_name, user) != 0) {
        printf("\n Please enter correct username ");
        goto name;  
    } else {
logpass: 
        printf("\n Enter password: ");
        takepassword(log_pass);
        if (strcmp(u.pass1, log_pass) != 0) {
            printf("\n Incorrect Password ");
            goto logpass; 
        } else {
            printf("\n Welcome %s ", u.user_name);
            printf("\n Details ");
            printf("\n Username: %s ", u.user_name);
            printf("\n First name: %s ", u.fname); 
            printf("\n Last name: %s ", u.lname);
            printf("\n Phone number: %s ", u.phone); 
            printf("\n Gender: %c ", u.gender); 
            printf("\n Date of Birth: %s ", u.dob);
            printf("\n Password %s ",u.pass1); 
            getchar();
        }
        fclose(fp);
    }
    getchar();
}

void forgot() {
    int choice1;    
    char username[20];
    char password[20];
    char pno[15];

    struct account u;
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("\n Error opening file. ");
        return;
    }
    fread(&u, sizeof(struct account), 1, fp);    
    printf("\n 1. Search By username ");
    printf("\n 2. Search By password ");
    printf("\n 3. Search By phone no ");
    printf("\n 4. Return Back ");
    printf("\n Enter your choice: ");
    scanf("%d", &choice1);
  
    switch (choice1) {
        case 1:
            printf("\n Enter your username: ");
            scanf("%s", username);
            if (strcmp(username, u.user_name) != 0) {
                printf("\n Username Not Found ");
            } else {
                printf("\n Account Found ");
                printf("\n Username: %s ", u.user_name);
                printf("\n First name: %s ", u.fname); 
                printf("\n Last name: %s ", u.lname);
                printf("\n Phone number: %s ", u.phone); 
                printf("\n Gender: %c ", u.gender); 
                printf("\n Date of Birth: %s ", u.dob); 
                printf("\n Password: %s ", u.pass1);
                getchar();   
            }
            break;
        case 2:
            printf("\n Enter your password: ");
            scanf("%s", password);
            if (strcmp(password, u.pass1) != 0) {
                printf("\n Password Not Found ");
            } else {
                printf("\n Account Found ");
                printf("\n Username: %s ", u.user_name);
                printf("\n First name: %s ", u.fname); 
                printf("\n Last name: %s ", u.lname);
                printf("\n Phone number: %s ", u.phone); 
                printf("\n Gender: %c ", u.gender); 
                printf("\n Date of Birth: %s ", u.dob); 
                printf("\n Password: %s ", u.pass1);
                getchar();   
            }
            break;     
        case 3:
            printf("\n Enter your phone no.: ");
            scanf("%s", pno);
            if (strcmp(pno, u.phone) != 0) {
                printf("\n Phone number Not Found ");
            } else {
                printf("\n Account Found ");
                printf("\n Username: %s ", u.user_name);
                printf("\n First name: %s ", u.fname); 
                printf("\n Last name: %s ", u.lname);
                printf("\n Phone number: %s ", u.phone); 
                printf("\n Gender: %c ", u.gender); 
                printf("\n Date of Birth: %s ", u.dob); 
                printf("\n Password: %s ", u.pass1);
                getchar();   
            }
            break;
        case 4: 
            return;
        default: 
            printf("\nInvalid Choice ");                     
            break;                      
    }  
    fclose(fp);
    getchar();
}

void change_password() {    
    int num1, num2;
    char pass2[20];

    srand(time(0));
    num1 = rand();
 
no:
    printf("\n Random number: %d ", num1);
    printf("\n Enter above number: ");
    scanf("%d", &num2);
    if (num1 == num2) {
        struct account u;
        FILE *fp = fopen("account.txt", "r");
        if (fp == NULL) {
            printf("\n Error opening file. ");
            return;
        }
        fread(&u, sizeof(struct account), 1, fp);
        fclose(fp);
     
        printf("\n Enter new password: ");
        takepassword(u.pass1);
     
pass:
        printf("\n Confirm password: ");
        takepassword(pass2);
        if (strcmp(u.pass1, pass2) != 0) { 
            printf("\n Incorrect Password ");
            goto pass;
        } else {
            fp = fopen("account.txt", "w");
            if (fp == NULL) {
                printf("\n Error opening file. ");
                return;
            }
            fwrite(&u, sizeof(struct account), 1, fp);
            printf("\n Password Changed Successfully ");
            getchar();
        }
        fclose(fp);
    } else { 
        printf("\n Entered the correct number ");
        goto no;
    }
    getchar();
}

void del_account() {
    char c, c1;
    
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("\n Error opening file. ");
        return;
    }
    
    c1 = fgetc(fp);
    if (c1 == EOF) {
        printf("\n No account to be deleted "); 
    } else {
        printf(" Are you sure [Y/N] ");
        c = getche();
    
        if (c == 'Y' || c == 'y') {
            fp = fopen("account.txt", "w");
            if (fp == NULL) {
                printf("\n Error opening file. ");
                return;
            }
            fprintf(fp, " ");
            printf("\n Account is deleted ");
            getchar();
        } else if (c == 'N' || c == 'n') {
            printf("\n Account deletion is stopped ");
            getchar(); 
        }
    }
    fclose(fp);
    getchar();
}
