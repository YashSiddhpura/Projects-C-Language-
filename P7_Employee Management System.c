#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void insert_record();
void display_record();
void search_record();
void delete_record();
void update_record();
void sort_record();

struct employee
{
  char name[20],ssn[20],position[20];
  int salary,age;
  float exp;	
}emp;

int main()
{
	int choice = 0;
    while(choice != 7)
    {
        printf("\n-------------------------------------------------------");
        printf("\n\t Welcome to Employee Management System ");
        printf("\n-------------------------------------------------------");
        printf("\n The HR has entered the system @ %s ",__TIME__);
        printf("\n 1. Insert a record ");        
        printf("\n 2. Display a record ");
        printf("\n 3. Search a record ");
        printf("\n 4. Delete a record ");
        printf("\n 5. Update a record ");
        printf("\n 6. Sort a record ");
        printf("\n 7. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                    insert_record();
                    break;
            case 2:
                    display_record(); 
                    break;
            case 3:
                    search_record();
                    break;
            case 4:
                    delete_record();
                    break;
            case 5:
                    update_record();
                    break;
            case 6:
                    sort_record();
                    break;
            case 7: 
                    printf("\n Task is completed...!");
                    printf("\n The HR has left the system @ %s ",__TIME__);
                    exit(0);
                    break;      
            default:
                    printf("\n Invalid Input");                                                                                                                     
        }
    }
    return 0;
}

void insert_record()
{
    FILE *fp = fopen("record.txt", "a+");
    if (fp == NULL)
    {
        printf("\n !...ERROR: Cannot open the file...! ");
        return;
    }

    printf("\n Previous Stored Data \n");
    display_record();

    printf("\n ------INSERT A NEW RECORD------ \n");

    // Clear input buffer
    while (getchar() != '\n');

    printf("\n Enter Employee's Name: ");
    fgets(emp.name, 20, stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("\n Enter Employee's SSN: ");
    fgets(emp.ssn, 20, stdin);
    emp.ssn[strcspn(emp.ssn, "\n")] = '\0';

    printf("\n Enter Employee's Position: ");
    fgets(emp.position, 20, stdin);
    emp.position[strcspn(emp.position, "\n")] = '\0';

    printf("\n Enter Employee's Salary: ");
    scanf("%d", &emp.salary);

    printf("\n Enter Employee's Age: ");
    scanf("%d", &emp.age);

    printf("\n Enter Employee's Experience: ");
    scanf("%f", &emp.exp);

    fwrite(&emp, sizeof(emp), 1, fp);

    printf("\n------EMPLOYEE RECORD INSERTED SUCCESSFULLY------\n ");

    fclose(fp);

    printf("\n Updated Employee Record \n");
    display_record();
}

void display_record()
{
    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n !...ERROR: Cannot open the file...! ");
        return;
    }

    printf("\n ------Employee Details------\n ");
    printf("\n Name\tSSN\tPosition\tExperience\tSalary\tAge \n");

    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        printf("\n %s\t%s\t%s\t\t%f   \t%d\t%d ", emp.name, emp.ssn, emp.position, emp.exp, emp.salary, emp.age);
    }
    fclose(fp);
}

void search_record()
{
    char s1[20];
    int flag = 0;
    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n !...ERROR: Cannot open the file...! ");
        return;
    }

    printf("\n Enter Employee's SSN: ");
    while (getchar() != '\n');  // Clear input buffer
    fgets(s1, 20, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    while (fread(&emp, sizeof(emp), 1, fp) > 0)
    {
        if (strcmp(emp.ssn, s1) == 0)
        {
            flag = 1;
            printf("\n Name\tSSN\tPosition\tExperience\tSalary\tAge ");
            printf("\n %s\t%s\t%s\t\t%f  \t%d\t%d ", emp.name, emp.ssn, emp.position, emp.exp, emp.salary, emp.age);
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n RECORD NOT FOUND ");
    }

    fclose(fp);
}

void delete_record()
{
    char s2[20];
    int flag = 0;
    FILE *fp = fopen("record.txt", "r");
    FILE *ft = fopen("record1.txt", "wb");
    if (fp == NULL || ft == NULL)
    {
        printf("\n !...ERROR: Cannot open the file...! ");
        return;
    }

    printf("\n Previous Stored Record ");
    display_record();

    printf("\n Enter Employee's SSN which you want to delete: ");
    while (getchar() != '\n');  // Clear input buffer
    fgets(s2, 20, stdin);
    s2[strcspn(s2, "\n")] = '\0';

    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        if (strcmp(emp.ssn, s2) != 0)
        {
            fwrite(&emp, sizeof(emp), 1, ft);
        }
        else
        {
            flag = 1;
        }
    }

    fclose(fp);
    fclose(ft);

    if (flag == 0)
    {
        printf("\n\tNO RECORD FOUND ");
    }
    else
    {
        remove("record.txt");
        rename("record1.txt", "record.txt");
        printf("\n RECORD DELETED SUCCESSFULLY ");
    }

    display_record();
}

void update_record()
{
    char s3[20];
    int flag = 0;
    FILE *fp = fopen("record.txt", "r+");
    if (fp == NULL)
    {
        printf("\n !...ERROR: Cannot open the file...! ");
        return;
    }

    printf("\n Enter Employee's SSN which you want to update: ");
    while (getchar() != '\n');  // Clear input buffer
    fgets(s3, 20, stdin);
    s3[strcspn(s3, "\n")] = '\0';

    while (fread(&emp, sizeof(emp), 1, fp) > 0)
    {
        if (strcmp(emp.ssn, s3) == 0)
        {
            flag = 1;
            printf("\n Search Successful and Employee records are as follows\n\n");
            printf("\n Name\tSSN\tPosition\tExperience\tSalary\tAge ");
            printf("\n %s\t%s\t%s\t%f\t%d\t%d ", emp.name, emp.ssn, emp.position, emp.exp, emp.salary, emp.age);

            printf("\n------Enter New Record------\n");

            printf("\n Enter Employee's SSN: ");
            while (getchar() != '\n');  // Clear input buffer
            fgets(emp.ssn, 20, stdin);
            emp.ssn[strcspn(emp.ssn, "\n")] = '\0';

            printf("\n Enter Employee's Name: ");
            fgets(emp.name, 20, stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';

            printf("\n Enter Employee's Position: ");
            fgets(emp.position, 20, stdin);
            emp.position[strcspn(emp.position, "\n")] = '\0';

            printf("\n Enter Employee's Experience: ");
            scanf("%f", &emp.exp);
            printf("\n Enter Employee's Salary: ");
            scanf("%d", &emp.salary);
            printf("\n Enter Employee's Age: ");
            scanf("%d", &emp.age);

            fseek(fp, -(long)sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, fp);

            printf("\n Record Updated Successfully. Check the display ");
            break;
        }
    }

    if (flag == 0)
    {
        printf("\n\tERROR: Something went wrong ");
    }

    fclose(fp);
}

void sort_record()
{
    struct employee temp;
    struct employee arr[50];

    int i, j, k = 0;
    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("\n !...ERROR: Cannot open the file...! ");
        return;
    }

    i = 0;

    while (fread(&arr[i], sizeof(arr[i]), 1, fp) == 1)
    {
        i++, k++;
    }
    fclose(fp);

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (strcmp(arr[j].ssn, arr[j + 1].ssn) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n Sorted Employee Details are \n");
    for (i = 0; i < k; i++)
    {
        printf("\n %s\t%s\t%s\t%f\t%d\t%d ", arr[i].name, arr[i].ssn, arr[i].position, arr[i].exp, arr[i].salary, arr[i].age);
    }
}
