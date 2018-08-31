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
// FILE:              prototypes.h
//
// DESCRIPTION:       a file that contains the prototypes of all the functions except main
//
***********************************************************************/
int addRecord (struct record ** bankarray, int accountno, char name[],char address[]);
int printRecord (struct record * bankarray, int accountno);
void printAllRecords(struct record * bankarray);
int deleteRecord(struct record ** bankarray, int acccountno);
int readfile(struct record ** bankarray, char file[]);
void writefile(struct record * bankarray, char file[]);

int collectInfo(int *accountno, char name[],int nameLength, char address[], int addressLength);
int collectAccountNo(struct record *bankarray, char accountno[], int accountnoLength);
int getAddress(char address[], int length);

extern int debug;
