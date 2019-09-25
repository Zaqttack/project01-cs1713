/*
    airport-program.h
    Project 1
    Zaquariah Holland

    This file is the header file for declaring the functions used in the 'airport-program.c' file.
    It is also used for including the 'airport.h' header file where the constants, airport structure and other functions are declared.
*/
#ifndef AIRPORT_PROGRAM_H
#define AIRPORT_PROGRAM_H
#include "airport.h"

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu();
void fillAirports(Airport*);
void printAirports(Airport*, int);
void printAirport(Airport);
Airport findAirport(Airport*, int, char*);
double deg2rad(double);
double calculateDistance(Airport, Airport);
void findInRange(Airport*, int, Airport, int, Airport*, int*);

#endif