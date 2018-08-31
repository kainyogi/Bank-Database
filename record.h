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
// FILE:              record.h
//
// DESCRIPTION:       a file that contains the struct record
//
***********************************************************************/
struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};
