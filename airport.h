/*
    airport.h
    Project 1
    Zaquariah Holland

    This .h contains all #define declarations and the Airport struct with 4 variables
*/
#ifndef AIRPORT_H
#define AIRPORT_H
#define MAX 12
#define EARTH_RADIUS 3961

typedef struct Airport_struct {
	char code[4];
	char name[50];
	double lon;
	double lat;
} Airport;

#endif