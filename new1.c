#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 5
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
	
	strcpy(airports[3].code, "GIG");
	strcpy(airports[3].name, "Rio De Janeiro Galeão");
	airports[3].lat = -22.809999;
	airports[3].lon = -43.250555;
	
	strcpy(airports[4].code, "HKG");
	strcpy(airports[4].name, "Hong Kong Intl");
	airports[4].lat = 22.308889;
	airports[4].lon = 113.914722;
}

void printAirport(Airport airport) {
    printf("%s\t", airport.code);
    printf("%s\t\t", airport.name);
    printf("%lf\t", airport.lat);
    printf("%lf\n", airport.lon);
}

void printAiports(Airport airports[], int length) {
    int i = 0;
    
	printf("CODE\tName\t\t\t\tLatitude\tLongitude\n");
    for (i = 0; i < length; i++) {
        printAirport(airports[i]);
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
/*
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
*/
double deg2rad(double deg) {
  return (deg * M_PI / 180);
}

double calculateDistance(Airport airport1, Airport airport2) {
  double lat1, lon1, lat2, lon2, a, c, d;
  lat1 = deg2rad(airport1.lat);
  lon1 = deg2rad(airport1.lon);
  lat2 = deg2rad(airport2.lat);
  lon2 = deg2rad(airport2.lon);
  a = sin((lat2 - lat1)/2);
  c = sin((lon2 - lon1)/2);
  d = asin(sqrt(a * a + cos(lat1) * cos(lat2) * c * c));
  return 2.0 * EARTH_RADIUS * d;
}

void findInRange(Airport airports[], int length, Airport origin, int range, Airport* output, int *resultsLength) {
    int i;
    double currentAirport;
    int tempInt = 0;
    *resultsLength = 0;
    
    for (i = 0; i < length; i++) {
        currentAirport = calculateDistance(origin, airports[i]);
        if (range > currentAirport) {
            output[tempInt] = airports[i];
            tempInt++;
            *resultsLength += 1;
        }
    }
}

int main() {
    int i;
    char user[4];
    Airport a[MAX];
    Airport search;
    Airport range[MAX];
    int resultsLength;
    fillAiports(a);
    //printAiports(a, MAX);
    //fgets(user, 4, stdin);
    //search = findAirport(a, MAX, user);
    //printAirport(search);
    //printf("Distance apart %lf\n", calculateDistance(a[0], a[2]));
	/*
    printf("Distance apart %lf\n", calculateDistance(a[1], a[2]));
    printf("original airport: ");
    printAirport(a[1]);
    findInRange(a, MAX, a[1], calculateDistance(a[1], a[2]), range, &resultsLength);
    for (i = 0; i < resultsLength; i++) {
        printAirport(range[i]);
    }
	*/
	printf("Enter a 3 digit IATA code: ");
	fgets(user, sizeof(user), stdin);
	printf("%s\n", user);
}
