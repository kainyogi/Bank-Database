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
// FILE:              userfunctions.c
//
// DESCRIPTION:       a file that contains the functions that collect information from the user
//
***********************************************************************/
#include"record.h"
#include"prototypes.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**************************************************************
//
// FUNCTION NAME: collectAccountNo
//
// DESCRIPTION:   a function to collect user input to print a single record
//
// PARAMETERS:    char accountno[]: the char array to hold the user input
//                int accountnoLength: the length of the char array
//
// RETURN:        0: success
//
*************************************************************/
int collectAccountNo(struct record * bankarray, char accountno[], int accountnoLength)
{
    int quit = 1;
    int accNo;
    if(debug == 1)
    {
        printf("entered collectAccountNo with accountno (%s), accountnoLength (%d)\n", accountno, accountnoLength);
    }
    printf("Please enter the account number\n");
    while(quit)
    {

        fgets(accountno, sizeof(accountno), stdin);
        accNo = atoi(accountno);
        if(accNo > 0)
        {
            quit = 0;
        }
        else
        {
            printf("Please enter a valid account number\n");
            printf("Such as a number from 1 to 10000\n");
        }
    }
    if(debug == 1)
    {
        printf("Exitted collectAccountInfo with (%d)\n", accNo);
    }
    return accNo;
}

/*****************************************************************************
//
//  FUNCITON NAME:    collectInfo
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
int collectInfo(int *accountno, char uName[],int uNameLength, char uAddress[], int uAddressLength)
{
    char uAccountNo[20];
    /* char *errorInput; */

    int quit = 1;

    if(debug == 1)
    {
        printf("entered collectInfo with accountno (%d), uName (%s), uNameLength (%d), uAddress (%s), int uAddressLength (%d)\n", *accountno, uName, uNameLength, uAddress, uAddressLength);
    }
    printf("Please enter the account number\n");
    while(quit)
    {

        fgets(uAccountNo, sizeof(uAccountNo), stdin);
        *accountno = atoi(uAccountNo);
        if(*accountno > 0)
        {
            quit = 0;
        }
        else
        {
            printf("Please enter a valid account number\n");
            printf("Such as a number from 1 to 10000\n");
        }
    }

    printf("Please Enter your Name\n");
    fgets(uName, uNameLength, stdin);
    printf("Please Enter your Address\n");
    printf("And when complete please hit ENTER and type '+'\n");
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
    int check = 1;
	
    if(debug == 1)
    {
        printf("enetered getAddress with address[] (%s), and length (%d)\n", address, length);
    }
    while(quit)
    {
        fgets(address, length, stdin);	
        checkplus = strchr(address, '+');	
        if(checkplus != NULL)
        {	
            strncat(getAdd, address, checkplus-address);	
            quit = 0;
        }
        else
        {	
            strcat(getAdd, address);
            check = 0;	
        }
    }
    memcpy(address, getAdd, sizeof(getAdd));	
    if(debug == 1)
    {
        printf("Exit getaddress with a return value of (%d)\n", check);
    }
    return check;
}
