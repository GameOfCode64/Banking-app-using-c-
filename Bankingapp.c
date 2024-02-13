#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct user
{
    char phone[50];
    char name[50];
    char ac[50];
    char pass[50];
    float balance;
};

int main()
{
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pass[50], nam[50];
    int opt, choise;
    float amount;
    char cout = 'y';
    printf("\n What do you want to do? ");
    printf("\n 1) Register an Account: ");
    printf("\n 2) Login to an Account: ");
    printf("\n Your Choice: \t");
    scanf("%d", &opt);

    if (opt == 1)
    {
        system("cls");
        printf("Enter your Account No: \t");
        scanf("%s", usr.ac);
        printf("Enter your Name: \t");
        scanf("%s", usr.name);
        printf("Enter your Phone No: \t");
        scanf("%s", usr.phone);
        printf("Enter your New Password: \t");
        scanf("%s", usr.pass);
        usr.balance = 0;
        strcpy(filename, usr.name);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n Account Register Succesfully");
        }
        else
        {
            printf("\n somthing want Wrong place try again");
        }
        fclose(fp);
    }
    if (opt == 2)
    {
        system("cls");
        printf("\n Enter Your Name: \t");
        scanf("%s", &nam);
        printf("\n Enter Your phone no: \t");
        scanf("%s", &phone);
        printf("\n Enter Your Password: \t");
        scanf("%s", &pass);
        strcpy(filename, nam);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\n Account number not Register");
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pass, usr.pass))
            {
                while (cout == 'y')
                {
                    system("cls");

                    printf("\nPress 1 for Check balance");
                    printf("\nPress 2 for deposit an amount");
                    printf("\nPress 3 for withdraw a amount");
                    printf("\nPress 4 for Transfer a amount");
                    printf("\nPress 5 for change the Password");
                    printf("\n Your Choice: ");
                    scanf("%d", &choise);

                    switch (choise)
                    {
                    case 1:
                        printf("Check Balance: ");
                        printf("\n \n Your Account Balance: Rs.%.2f", usr.balance);
                        break;
                    case 2:
                        printf("  Deposit an Amount ");
                        printf("\n \n Enter a Amount: ");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("Successfully deposited");
                            printf("\n \n Your Account Balance: Rs.%.2f", usr.balance);
                        }
                        fclose(fp);
                        break;
                    case 3:
                        printf("\t \t  Withdraw an Amount");
                        printf("\n \n Enter a Amount: ");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("Successfully Withdraw");
                            printf("\n \n Your Account Balance: Rs.%.2f", usr.balance);
                        }
                        fclose(fp);
                        break;
                    case 4:
                        printf("\t Transfer an Amount \n");
                        printf("Enter a Name You want to Trasfar Money: ");
                        scanf("%s", &phone);
                        printf("Enter a Amount: ");
                        scanf("%f", &amount);
                        if (amount > usr.balance)
                        {
                            printf("\n Insufficient");
                        }
                        else
                        {
                            strcpy(filename, phone);
                            fp = fopen(strcat(filename, ".dat"), "w");
                            fread(&usr1, sizeof(struct user), 1, fp);
                            fclose(fp);
                            fp = fopen(filename, "w");
                            usr1.balance += amount;
                            fwrite(&usr1, sizeof(struct user), 1, fp);
                            fclose(fp);
                            if (fwrite != NULL)
                            {
                                printf("Transaction Successful \n \n");
                                strcpy(filename, usr.name);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                printf("Details: \n");
                                printf("\tName: %s \n", phone);
                                usr.balance -= amount;
                                printf("\tAmount: %f", amount);
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                fclose(fp);
                            }
                        }
                        break;
                    case 5:
                        printf("Reset Account Password: ");
                        break;
                    default:
                        break;
                    }

                    printf("\nDo you want to [y/n] \n");
                    scanf("%s", &cout);
                }
            }
            else
            {

                printf("\n Invalid Password");
            }
        }
    }
    return 0;
}