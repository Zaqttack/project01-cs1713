#inlcude <stdio.h>
#include <math.h>
#include "airport-program.h"

fillAirports(Airports airports)
{
	strcpy(airports[0].code, "SAT");
	strcpy(airports[0].name, "San Antonio Intl");
	airports[0].log = 29.533958;
	airports[0].lat = -98.469056;
	
	strcpy(airports[1].code, "BKK");
	strcpy(airports[1].name, "Bangkok Suvarnabhumi");
	airports[1].log = 13.681108;
	airports[1].lat = 100.747283;
	
	strcpy(airports[2].code, "CDG");
	strcpy(airports[2].name, "Paris Charles De Gaulle");
	airports[2].log = 49.009722;
	airports[2].lat = 2.547780;
	
	strcpy(airports[3].code, "GIG");
	strcpy(airports[3].name, "Rio De Janeiro Galeão");
	airports[3].log = -22.809999;
	airports[3].lat = -43.250555;
	
	strcpy(airports[4].code, "HKG");
	strcpy(airports[4].name, "Hong Kong Intl");
	airports[4].log = 22.308889;
	airports[4].lat = 113.914722;
	
	strcpy(airports[5].code, "JFK");
	strcpy(airports[5].name, "New York-JFK");
	airports[5].log = 40.639926;
	airports[5].lat = -73.778694;
	
	strcpy(airports[6].code, "JNB");
	strcpy(airports[6].name, "O.R. Tambo Johannesburg");
	airports[6].log = -26.133693;
	airports[6].lat = 28.242317;
	
	strcpy(airports[7].code, "LAX");
	strcpy(airports[7].name, "Los Angeles Intl");
	airports[7].log = 33.942496;
	airports[7].lat = -118.408048;
	
	strcpy(airports[8].code, "LHR");
	strcpy(airports[8].name, "London Heathrow");
	airports[8].log = 51.477500;
	airports[8].lat = -0.461388;
	
	strcpy(airports[9].code, "MEX");
	strcpy(airports[9].name, "Mexico City Benito Juarez");
	airports[9].log = 19.436303;
	airports[9].lat = -99.072096;
	
	strcpy(airports[10].code, "SIN");
	strcpy(airports[10].name, "Singapor Changi");
	airports[10].log = 1.359211;
	airports[10].lat = 103.989333;
	
	strcpy(airports[11].code, "NRT");
	strcpy(airports[11].name, "Tokyo Narita");
	airports[11].log = 35.765556;
	airports[11].lat = 140.385556;
}

void printAirports(Airport airpots[], int length)
{
	int i;
	
	printf("CODE\tName\t\t\t\tLatitude\tLongitude\n");
	for ( i = 0; i < length; i++)
	{
		printAiport(airports[i]);
	}
}

void printAiport(Airport airport)
{
	printf("%s\t", airport.code);
	printf("%s\t\t", airport.name);
	printf("%lf\t", airport.log);
	printf("%lf\n", airport.lat);
}

Airport findAirport(Airport airports[], int length,char code[])
{
	int i = 0;
	Airport temp;			//temp to return if no valud code
	temp.log = -99999;
	temp.lat = -99999;
	
	for (i = 0; i < length; i++)
	{
		if (strcmp(airportsp[i].code, toupper(code)) == 0)
		{
			return airports[i];
		}
	}
	return temp;
}

double calculateDistance(Airport airport1, Airport airport2)
{
	double totalLog;
	double totalLat;
	double a, c, d;
	
	totalLog = airport2.log - airport1.log;
	totalLat = airport2.lat - airport1.lat;
	a = pow( sin( totalLat / 2 ), 2 ) + cos( airport1.lat ) * cos( airport2.lat ) * pow ( sin( totalLog / 2 ), 2 );
	c = 2 * atan2( sqrt(a), sqrt( 1 - a ));
	d = EARTH_RADIUS * c;
	
	return c;
}