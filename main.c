/****************************************************************************
//
//    NAME:        KAIN YOGI
//
//    HOMEWORK:    3B
//
//    CLASS:       ICS 212
//
//    INSTRUCTOR   RAVI NARAYAN
//
//    DATE:        FEB 25, 2018
//    
//    FILE:        main.c
//
//    DESCRIPTION: contains the user functions for later port to another file for homework3b
//
*******************************************************************************/
#include"record.h"
#include"prototypes.h"
#include<stdio.h>
#include<string.h>

int debug = 0;

/**************************************************************************
//
//  FUNCTION NAME: main
//
//  DESCRIPTION:   a userinterface function that contains the menu selection 
//
//  PARAMETERS:    int argc
//                 char* argv
//
//  RETURN VALUES: 0: success
//
**************************************************************************/

int main(int argc, char* argv[])
{
    struct record * start;

    char uInput[100] = "";
    char uName[30] = "";
    char uAddress[80] = "";
    char uPrint[10] = "";

    int accountno = 0;
    int choice = 0;
    int quit = 1;

    start = NULL;

    if(argc > 1 && argc < 3)
    {
        if((strcmp(argv[1], "debug") == 0))
        {
        printf("Debug mode is now ON\n");
        debug = 1;
        }
    
        else
        {    
            printf("command not found\n");
        }
    }
    readfile(&start,"bankarray.txt");
    while(quit)
    {
        if(debug == 1)
        {
            printf("Before memset userinput arrays are\nuInput is %s\nuName is %s\nuAddress is %s\n", uInput, uName, uAddress); 
        }
        memset(&uInput[0], '\0', sizeof(uInput)); 
        memset(&uName[0], '\0', sizeof(uName));
        memset(&uAddress[0], '\0', sizeof(uAddress));
        memset(&uPrint[0], '\0', sizeof(uPrint));
        if(debug == 1)
        {
            printf("After memset userinput arrays are\nuInput is %s\nuName is %s\nuAddress is %s\n", uInput, uName, uAddress); 
        }
        printf("------------WELCOME TO NARAYAN BANKING------------\n");
        printf("please enter your menu choice\nmenu choice is also CASE SENSITIVE\n");
        printf(" Add  -- add Record\n Print -- Print Information about a record\n Printall -- Print all information in the database\n Delete -- Delete an existing record\n Quit -- Quit\n");
        fgets(uInput, sizeof(uInput), stdin);
        if(debug == 1)
        {
            printf("user input (uInput) is %s\n", uInput); 
        }
        if(strcmp(uInput, "Add\n") == 0 || strcmp(uInput, "Print\n") == 0 || strcmp(uInput, "Printall\n") == 0 || strcmp(uInput, "Delete\n") == 0 || strcmp(uInput, "Quit\n") == 0)
        {
            if(debug == 1)
            {
                printf("enetered validility check successfully\n"); 
            }
            if(strcmp(uInput, "Add\n") == 0)
            {
                if(debug == 1)
                {
                    printf("Entered if statement that checks if user entered 'Add'\n"); 
                }
                choice  = 1;
                if(debug == 1)
                {
                    printf("choice is now %d\n", choice); 
                }
            }
            else if(strcmp(uInput, "Print\n") == 0)
            {
                if(debug == 1)
                {
                    printf("Entered if statement that checks if user entered 'Add'\n"); 
                }
                choice  = 2;
                if(debug == 1)
                {
                    printf("choice is now %d\n", choice); 
                }
            }
            else if(strcmp(uInput, "Printall\n") == 0)
            {
                if(debug == 1)
                {
                    printf("Entered if statement that checks if user entered 'Add'\n"); 
                }
                choice  = 3;
                if(debug == 1)
                {
                    printf("choice is now %d\n", choice); 
                }
            }
            else if(strcmp(uInput, "Delete\n") == 0)
            {
                if(debug == 1)
                {
                    printf("Entered if statement that checks if user entered 'Add'\n"); 
                }
                choice  = 4;
                if(debug == 1)
                {
                    printf("choice is now %d\n", choice); 
                }
            }
            else if(strcmp(uInput, "Quit\n") == 0)
            {
                if(debug == 1)
                {
                    printf("Entered if statement that checks if user entered 'Add'\n"); 
                }
                choice = 5;
                if(debug == 1)
                {
                    printf("choice is now%d\n", choice);
                }
            }
            switch(choice)
            {
                case 1:
                    if(debug == 1)
                    {
                        printf("Entered Case 1\n");
                        printf("Entering collectInfo with accountno (%d), uName (%s), the size of uName (%lu), uAddress (%s), the size of uAddress (%lu)\n", accountno, uName, sizeof(uName), uAddress, sizeof(uAddress));
                    }
                    collectInfo(&accountno, uName,sizeof(uName), uAddress,sizeof(uAddress));
                    if(debug == 1)
                    {
                        printf("Entering addRecord with start (%p), accountno (%d), uName (%s), uAddress (%s)\n", &start, accountno, uName, uAddress);
                    }
                    addRecord(&start, accountno, uName, uAddress);
                    choice = 0;
                    break;
                case 2:
                    if(debug == 1)
                    {
                        printf("Entered Case 2\n");
                    }
                    printRecord(start, collectAccountNo(start,uPrint, sizeof(uPrint)));
                    break;
                case 3:
                    if(debug == 1)
                    {
                        printf("Entered Case 3\n");
                    }
                    printAllRecords(start);
                    break;
                case 4:
                    if(debug == 1)
                    {
                        printf("Entered Case 4\n");
                    }
                    deleteRecord(&start, collectAccountNo(start, uPrint, sizeof(uPrint)));
                    break;
                case 5:
                    if(debug == 1)
                    {
                        printf("Entered Case 5\n");
                    }
                    writefile(start, "bankarray.txt");
                    quit = 0;
                    break;
            }
        }
        else
        {
            printf("Please type a Valid Choice for the menu\n");
        }
    }
    return 0;
}
