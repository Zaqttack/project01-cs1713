#include <stdio.h>
#include <string.h>
#include <math.h>
#include "airport-program.h"

void fillAirports(Airport* airports) {
	strcpy(airports[0].code, "SAT");
	strcpy(airports[0].name, "San Antonio Intl\t");
	airports[0].lat = 29.533958;
	airports[0].lon = -98.469056;
	
	strcpy(airports[1].code, "BKK");
	strcpy(airports[1].name, "Bangkok Suvarnabhumi\t");
	airports[1].lat = 13.681108;
	airports[1].lon = 100.747283;
	
	strcpy(airports[2].code, "CDG");
	strcpy(airports[2].name, "Paris Charles De Gaulle\t");
	airports[2].lat = 49.009722;
	airports[2].lon = 2.547780;
	
	strcpy(airports[3].code, "GIG");
	strcpy(airports[3].name, "Rio De Janeiro Galeão\t");
	airports[3].lat = -22.809999;
	airports[3].lon = -43.250555;
	
	strcpy(airports[4].code, "HKG");
	strcpy(airports[4].name, "Hong Kong Intl\t\t");
	airports[4].lat = 22.308889;
	airports[4].lon = 113.914722;
	
	strcpy(airports[5].code, "JFK");
	strcpy(airports[5].name, "New York-JFK\t\t");
	airports[5].lat = 40.639926;
	airports[5].lon = -73.778694;
	
	strcpy(airports[6].code, "JNB");
	strcpy(airports[6].name, "O.R. Tambo Johannesburg\t");
	airports[6].lat = -26.133693;
	airports[6].lon = 28.242317;
	
	strcpy(airports[7].code, "LAX");
	strcpy(airports[7].name, "Los Angeles Intl\t");
	airports[7].lat = 33.942496;
	airports[7].lon = -118.408048;
	
	strcpy(airports[8].code, "LHR");
	strcpy(airports[8].name, "London Heathrow\t\t");
	airports[8].lat = 51.477500;
	airports[8].lon = -0.461388;
	
	strcpy(airports[9].code, "MEX");
	strcpy(airports[9].name, "Mexico City Benito Juarez");
	airports[9].lat = 19.436303;
	airports[9].lon = -99.072096;
	
	strcpy(airports[10].code, "SIN");
	strcpy(airports[10].name, "Singapor Changi\t\t");
	airports[10].lat = 1.359211;
	airports[10].lon = 103.989333;
	
	strcpy(airports[11].code, "NRT");
	strcpy(airports[11].name, "Tokyo Narita\t\t");
	airports[11].lat = 35.765556;
	airports[11].lon = 140.385556;
}

void printAirports(Airport* airports, int length) {
	int i;
	
	printf("\nCODE\tName\t\t\t\tLatitude\tLongitude\n");
	for ( i = 0; i < length; i++)
	{
		printAirport(airports[i]);
	}
}

void printAirport(Airport airport) {
	printf("%s\t", airport.code);
	printf("%s\t", airport.name);
	printf("%lf\t", airport.lat);
	printf("%lf\n", airport.lon);
}

Airport findAirport(Airport* airports, int length, char code[]) {
	int i;
	Airport temp;			//temp to return if no valid IATA code
	temp.lat = -99999;
	
	for (i = 0; i < length; i++) {
		if (strcmp(airports[i].code, code) == 0) {
			return airports[i];
		}
	}
	return temp;
}

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

void findInRange(Airport* airports, int length, Airport origin, int range, Airport* output, int* resultsLength) {
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