#include <stdio.h>
#include <string.h>
#define MAX 3

typedef struct Airport_struct
{
    char code[4];
    char name[50];
    double log;
    double lat;
} Airport;

void fillAiports(Airport airports[])
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
}

void printAiport(Airport airport)
{
    printf("%s\t", airport.code);
    printf("%s\t\t", airport.name);
    printf("%lf\t", airport.log);
    printf("%lf\n", airport.lat);
}

void printAiports(Airport airports[], int length)
{
    int i = 0;
    
	printf("CODE\tName\t\t\t\tLatitude\tLongitude\n");
    for (i = 0; i < length; i++)
    {
        printAiport(airports[i]);
	}
}

Airport findAirport(Airport airports[], int length, char code[])
{
	int i = 0;
	Airport temp;			//temp to return if no valid IATA code
	temp.log = -99999;
	temp.lat = -99999;
	
	for (i = 0; i < length; i++)
	{
		if (strcmp(airports[i].code, code) == 0);
		{
		    printf("iteration %d\n", i);
			return airports[i];
		}
	}
	return temp;
}

int main()
{
    char user[4];
    Airport a[MAX];
    Airport search;
    fillAiports(a);
    //printAiports(a, MAX);
    fgets(user, 4, stdin);
    search = findAirport(a, MAX, user);
    printAiport(search);
}
