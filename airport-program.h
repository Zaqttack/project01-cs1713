/*
    airport-program.h
    Project 1
    Zaquariah Holland

    This file is the header file for declaring the functions used in the 'airport-program.c' file.
    Used for including the 'airport.h' header file where the constants airport structure and other functions are declared.
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
/* 
    fillAirports 
    ---------------------------
    This function is run at the start to fill the airport struct array
	airports: requires pointer to airport struct
    Returns: VOID
*/
void fillAirports(Airport*);
/* 
    printAirports 
    ---------------------------
    Prints every airport in the array, uses printAirport to print individual struct variables
	airports: requires pointer to airport struct
	length: MAX size of array
    Returns: VOID
*/
void printAirports(Airport*, int);
/* 
    printAirport 
    ---------------------------
    Prints individual airports. Typically used by printAirports function
	airports: airport struct
    Returns: VOID
*/
void printAirport(Airport);
/* 
    findAirport 
    ---------------------------
    Finds and assigns an aiport to a temp struct.
	airports: requires pointer to airport struct
	length: MAX size of array
	code[]: user inputed command to compare to array
    Returns: a temp Airport struct
*/
Airport findAirport(Airport*, int, char*);
/* 
    deg2rad 
    ---------------------------
    Quickly converts degrees to radians; since needed so many times in calculateDistance
	deg: calls a double value in degrees
    Returns: a double value for radians
*/
double deg2rad(double);
/* 
    calculateDistance 
    ---------------------------
    Calculates the distance from two user inputed airport selections
	airport1: first airport struct to compare
	airport2: second airport struct to compare
    Returns: a double value for distance between two specified airports
*/
double calculateDistance(Airport, Airport);
/* 
    findInRange 
    ---------------------------
    Accepts a users initial starting location and specified range to calculate other aiports within the range.
	airports: requires pointer to airport struct
	length: MAX size of array
	origin: the original location to calculateDistance against all locations
	range: user inputed value to compare calculated distances too
	output: point to a defined struct in main to add each applicable airport to
	resultsLength: point to a defined int in main to use within a loop to print out each airport
    Returns: VOID
*/
void findInRange(Airport*, int, Airport, int, Airport*, int*);

#endif