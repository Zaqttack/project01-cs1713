#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 3
#define EARTH_RADIUS 3961

typedef struct Airport_struct {
    char code[4];
    char name[50];
    double lat;
    double lon;
} Airport;

void fillAiports(Airport airports[]) {
	strcpy(airports[0].code, "SAT");
	strcpy(airports[0].name, "San Antonio Intl");
	airports[0].lat = 29.533958;
	airports[0].lon = -98.469056;
	
	strcpy(airports[1].code, "BKK");
	strcpy(airports[1].name, "Bangkok Suvarnabhumi");
	airports[1].lat = 13.681108;
	airports[1].lon = 100.747283;
	
	strcpy(airports[2].code, "CDG");
	strcpy(airports[2].name, "Paris Charles De Gaulle");
	airports[2].lat = 49.009722;
	airports[2].lon = 2.547780;
}

void printAiport(Airport airport) {
    printf("%s\t", airport.code);
    printf("%s\t\t", airport.name);
    printf("%lf\t", airport.lat);
    printf("%lf\n", airport.lon);
}

void printAiports(Airport airports[], int length) {
    int i = 0;
    
	printf("CODE\tName\t\t\t\tLatitude\tLongitude\n");
    for (i = 0; i < length; i++) {
        printAiport(airports[i]);
	}
}

Airport findAirport(Airport airports[], int length, char code[])
{
	int i;
	Airport temp;			//temp to return if no valid IATA code
	temp.lat = -99999;
	temp.lon = -99999;
	
	for (i = 0; i < length; i++) {
		if (strcmp(airports[i].code, code) == 0) {
			return airports[i];
		}
	}
	return temp;
}

double calculateDistance(Airport airport1, Airport airport2)
{
	double dLon;
	double dLat;
	double a, c, d;
	
	dLon = airport2.lon - airport1.lon;
	dLat = airport2.lat - airport1.lat;
	printf("%lf\n%lf\n", dLon, dLat);
	a = pow((sin(dLat / 2)), 2 ) + cos(airport1.lat) * cos(airport2.lat) * pow((sin(dLon / 2)), 2 );
	printf("%lf\n", a);
	c = 2 * atan2( sqrt(a), sqrt( 1 - a ));
	printf("%lf\n", c);
	d = EARTH_RADIUS * c;
	
	return d;
}

int main() {
    char user[4];
    Airport a[MAX];
    Airport search;
    fillAiports(a);
    //printAiports(a, MAX);
    //fgets(user, 4, stdin);
    //search = findAirport(a, MAX, user);
    //printAiport(search);
    printf("Distance apart %lf\n", calculateDistance(a[0], a[2]));
}
