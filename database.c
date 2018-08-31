/***********************************************************************
//
// NAME:              KAIN YOGI
//
// HOMEWORK:          3B
//
// CLASS:             ICS 212
//
// INSTRUCTOR:        RAVI NARAYAN
//
// DATE:              FEB 25, 2018
//
// FILE:              database.c
//
// DESCRIPTION:       a file that contains the functions that directly effect the database
//
***********************************************************************/
#include"record.h"
#include"prototypes.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*********************************************************************
//
// FUNCTION NAME:         addRecord
//
// DESCRIPTION:           a function that will add a node to the struct record linked list
//
// PARAMETERS:            struct record** bankarray: the record
//                        int accountno: the account number
//                        char[] name: the name
//                               address: the address
// RETURN VALUES:         0: success
//
********************************************************************/

int addRecord (struct record ** bankarray, int accountno , char  name[],char address[])
{
    int accountAlter;
    int validAdd = 1;
    struct record *temp;
    struct record *current;
    if(debug == 1)
    {
        printf("entered addRecord with bankarray (%p),accountno (%d), name (%s), and address (%s)\n",&bankarray, accountno, name, address);
    }
    temp = malloc(sizeof(struct record));
    temp->accountno = accountno;
    strcpy(temp->name, name);
    strcpy(temp->address,address);
    temp->next = NULL;
    if(*bankarray == NULL || (*bankarray)->accountno > temp->accountno)
    {
        temp->next = *bankarray;
        *bankarray = temp;
        current = *bankarray;
        validAdd = 0;
    }
    else
    {
        if((*bankarray)->next == NULL || (*bankarray)->accountno == temp->accountno)
        {
            accountAlter = temp->accountno;
            accountAlter++;
            temp->accountno = accountAlter;
        }
        current = *bankarray;
        while(current->next != NULL && current->next->accountno <= temp->accountno)
        {
            if(current->next->accountno == temp->accountno)
            {
                accountAlter = temp->accountno;
                accountAlter++;
                temp->accountno = accountAlter;
            }
            else
            {
                current = current->next;
            }
        }
        temp->next = current->next;
        current->next = temp;
        validAdd = 0;
    }
    if(debug == 1)
    {
        printf("Returning addRecord with (%d)\n", validAdd);
    }
    return validAdd;  
}
/******************************************************************
//
// FUNCTION NAME:         printRecord
//
// DESCRIPTION:           A function that prints a certain record with the account number
//
// PARAMETERS:            struct record* bankarray: the record
//                        int accountno: the record to print
// RETURN VALUES:         0: success
//
********************************************************************/
int printRecord (struct record * bankarray, int accountno)
{
    int validreturn = 1;
    struct record *temp = bankarray;
    if(debug == 1)
    {
        printf("entereded printRecord with accountno (%d)\n", accountno);
    }
    if(temp == NULL)
    {
        printf("the list is empty");
    }
    while(temp != NULL)
    {
        if(temp->accountno == accountno)
        {
            printf("%d\n", temp->accountno);
            printf("%s", temp->name);
            printf("%s", temp->address);
            printf("+\n");
            validreturn = 0;
        }
        temp = temp->next;
    }
    if(debug == 1)
    {
        printf("Exited from printRecord with a return value of (%d)\n", validreturn);
    }
    return validreturn;
}
/******************************************************************
//
// FUNCTION NAME:    printAllRecords
//
// DESCRIPTION:      A function that will print all nodes in the linked list
//
// PARAMETERS:       struct record* account: the records to print
//
// RETURN:           none
//
*****************************************************************/
void printAllRecords(struct record * bankarray)
{
    struct record *temp = bankarray;
    if(debug == 1)
    {
        printf("entered printAllRecords\n");
    }
    if(temp == NULL)
    {
        if(debug == 1)
        {
            printf("entered bankarray == NULL\n");
        }
        printf("The list is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d\n", temp->accountno);
            printf("%s", temp->name);
            printf("%s", temp->address);
            printf("+\n");
            temp = temp->next;
        }
    }
}
/***************************************************************
//
// FUNCTION NAME:    deleteRecord
//
// DESCRIPTION:      a function that will delete a record at  acertain account numberd
//
// PARAMETERS        struct record** account: the datebase to select from
//                   int pointer: the record to delete
//
// RETURN:           0: success
//
***************************************************************/
int deleteRecord(struct record ** bankarray, int accountno)
{
    int validDelete = 1;
    struct record * current = *bankarray;
    struct record * prev = *bankarray;
    if(debug == 1)
    {
        printf("entered deleteRecord with accountno (%d)", accountno);
    }
    if(*bankarray == NULL)
    {
        printf("the list is empty\n");
    }
    else if((*bankarray)->next  == NULL && (*bankarray)->accountno == accountno)
    {    
        *bankarray = current->next;
        validDelete = 0;
        free(current);
    }
    else
    {
        while(current->next != NULL && current->accountno != accountno)
        {
            prev = current;
            current = current->next;
        }
        if(current->next == NULL && current->accountno != accountno)
        {
            printf("The account does not exist\n");
        }
        else
        {
            prev->next = current->next;
            free(current);
            validDelete = 0;
        }
    }
    if(debug == 1)
    {
        printf("Exitted deleteRecord with return value of (%d)\n", validDelete);
    }
    return validDelete;
}
/****************************************************************
//
// FUNCTION NAME: readfile
//
// DESCRIPTION:   a function that will read a file containing existing
//
// PARAMETERS:    struct record ** bankarray: the structure that will house all the values read
//                char filename[]: the file that will be read. 
//
// RETURN:        0: success
//                1: failure
*****************************************************************/
int readfile(struct record **bankarray, char filename[])
{
    struct record *temp = *bankarray;
    int check = 1;
    int accountnum = 0;
   
    char line[500];
    char address[100] = "";
    char name[80] = "";

    FILE *file;
    file = fopen(filename, "r");
     
    if(debug == 1)
    {
        printf("Entered readfile with filename (%s)\n", filename);
    }
    if(file == NULL)
    {
        check = 1;
        printf("File does not exist");
    }
    else
    {
        while(!feof(file))
        {
            if(fgets(line, sizeof(line), file) != NULL)
            {
                accountnum = atoi(line);
            }
            if(fgets(line, sizeof(line), file) != NULL)
            {
                strcpy(name, line);
            }
            memset(address, '\0', sizeof(address));
            while(fgets(line, sizeof(line), file) != NULL && strcmp(line, "+\n") != 0)
            {
                strcat(address, line);
                check = 0;
            }
            addRecord(&temp, accountnum, name, address);
            address[0] = '\0';
            accountnum = 0;
        }
    }
    fclose(file);
    if(debug == 1)
    {
        printf("EXitted readfile with return of (%d)\n", check);
    }
    return check;
}
/***************************************************************
//
// FUNCTION NAME: writefile
//
// DESCRIPTION:   a function that will write the contents of the bankarray structure to a file
//
// PARAMETERS:    struct record * bankarray: the structure that will contain the values
//                char filename[]: the file that will be written to
// RETURN:
***************************************************************/
void writefile(struct record * bankarray, char filename[])
{
    struct record * temp = bankarray;
    FILE *file;
    file = fopen(filename, "w");
    if(debug == 1)
    {
        printf("entered write file with filename of (%s)\n'", filename);
    }
    if(file == NULL)
    {
        printf("File does not exist\n");
    }
    else if(temp == NULL)
    {
        printf("List is empty nothing saved");
    }
    else
    {
        while(temp != NULL)
        {
            fprintf(file, "%d\n", temp->accountno);
            fprintf(file, "%s", temp->name);
            fprintf(file, "%s+\n", temp->address);
            temp = temp->next;
        }
    }
    fclose(file);
}

