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
// FUNCTION NAME:         addRecordE
//
// DESCRIPTION:           a stub that will contain the function to add a record
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
    if(debug == 1)
    {
        printf("entered addRecord\n");
    }
    return 0;
}
/********************************************************************
//
// FUNCTION NAME:         printRecord
//
// DESCRIPTION:           a stub that will contain the function to print a record
//
// PARAMETERS:            struct record* bankarray: the record
//                        int accountno: the record to print
// RETURN VALUES:         1010: success
//
********************************************************************/
int printRecord (struct record * bankarray, int accountno)
{
    if(debug == 1)
    {
        printf("entered printRecord\n");
    }
    return 0;
}
/******************************************************************
//
// FUNCTION NAME:    printAllRecords
//
// DESCRIPTION:      a stub that will contain the function to print all records
//
// PARAMETERS:       struct record* account: the records to print
//
// RETURN:           none
//
*****************************************************************/
void printAllRecords(struct record * bankarray)
{
    if(debug == 1)
    {
        printf("entered printAllRecords\n");
    }

}
/***************************************************************
//
// FUNCTION NAME:    deleteRecord
//
// DESCRIPTION:      a stub that will contain the function to delete a record
//
// PARAMETERS        struct record** account: the datebase to select from
//                   int pointer: the record to delete
//
// RETURN:           0: success
//
***************************************************************/
int deleteRecord(struct record ** bankarray, int accountno)
{
    if(debug == 1)
    {
        printf("entered deleteRecord\n");
    }
    return 0;
}
/*****************************************************************************
//
//  FUNCITON NAME:    cAddRecord
//
//  DESCRIPTION:      a function to add a record to the database, gathering a name, address, and account number.
//
//  PARAMETERS:       int accountno: the int that will be editted in this function that will contain the account number
//                        uNameLength: the length of the uName char array
//                        uAddressLength: the length of the uAddress char array
//					  char uName: the char array that will be editted in this function that will contain the name
//                         uAddress: the char array that will be editted in this function that will contain the address
//
//  RETURN VALUES: 0: success
//
*****************************************************************************/

int collectInfo(int accountno, char uName[],int uNameLength, char uAddress[], int uAddressLength)
{
    char uAccountNo[20];
    char *errorInput;

    int quit = 1;
	
    if(debug == 1)
    {
        printf("entered collectInfo with accountno (%d), uName (%s), uNameLength (%d), uAddress (%s), int uAddressLength (%d)\n", accountno, uName, uNameLength, uAddress, uAddressLength);
    }
    printf("Please enter the account number\n");
    while(quit)
    {
        
        fgets(uAccountNo, sizeof(uAccountNo), stdin);	
        if(debug == 1)
        {
            printf("user input for the account number is %s\n", uAccountNo);
        }
        /* accountno =  strtol(uAccountNo, &errorInput, 20); */
        accountno = atoi(uAccountNo);
        if(accountno > 0)
        {
            if(debug == 1)
            {
                printf("user input for the account number after strtol is %d\n", accountno);
            }
            quit = 0;
        }
        else
        {	
            if(debug == 1)
            {
                printf("entered the fail check for the userinput for the accountno\n");
            }
            printf("Please enter a valid account number\n");
            printf("Such as a number from 1 to 10000\n");
        }
    }

    printf("Please Enter your Name\n");
    fgets(uName, uNameLength, stdin);	
    if(debug == 1)
    {
        printf("user input for name is %s\n", uName);
    }
    printf("Please Enter your Address\n");
    printf("And when complete please hit ENTER and type '+'\n");	
    if(debug == 1)
    {
        printf("getAddress called with parameters, uAddress (%s), and uAddressLength (%d)\n", uAddress, uAddressLength);
    }
    getAddress(uAddress, uAddressLength);
    return 0;
}
/*******************************************************************
//
// FUNCTION NAME:    getAddress
//
// DESCRIPTION:      a function to get a multiline address utilizing fgets and string.h 
//
// PARAMETERS        char address[]: the string that will contain the address
//                   int length: the length of the string
//
// RETURN VALUES:    0: success
//
*******************************************************************/
int getAddress(char address[], int length)
{
    char *checkplus;
    char getAdd[80] = ""; 
    int quit = 1;
	
    if(debug == 1)
    {
        printf("enetered getAddress with address[] (%s), and length (%d)\n", address, length);
    }
    while(quit)
    {
        fgets(address, length, stdin);	
        if(debug == 1)
        {
            printf("User input for address is %s\n", address);
        }
        checkplus = strchr(address, '+');	
        if(debug == 1)
        {
            printf("checkplus that checks if the user entered a plus is %p\n", checkplus);
        }
        if(checkplus != NULL)
        {	
            if(debug == 1)
            {
                printf("Entered checkplus is not null\n");
            }
            strncat(getAdd, address, checkplus-address);	
            if(debug == 1)
            {
                printf("getAdd is now %s\n", getAdd);
            }
            quit = 0;
        }
        else
        {	
            if(debug == 1)
            {
                printf("Entered checkplus is null\n");
            }
            strcat(getAdd, address);	
            if(debug == 1)
            {
                printf("getAdd is now %s\n", getAdd);
            }
        }
    }
    memcpy(address, getAdd, sizeof(getAdd));	
    if(debug == 1)
    {
        printf("User input for address is now %s\n", address);
    }
	
    return 0;
}
