/*
    airport-program.h
    Project 1
    Zaquariah Holland

    This file is the header file for declaring the functions used in the 'airport-program.c' file.
    It is also used for including the 'airport.h' header file where the constants, airport structure and other functions are declared.
*/
#ifndef AIRPORT-PROGRAM_H
#define AIRPORT-PROGRAM_H
#include "airport.h"

typedef struct Airport_struct
{
	char code[4];
	char name[50];
	double log;
	double lat;
} Airport;

const int EARTH_RADIUS = 3961; 			//value in Miles

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu();
int fillAirports(Airport airports);
Airport findAirport(Airport airports[], int length, char code[]);
double calculateDistance(Airport airport1, Airport airport2);

#endif