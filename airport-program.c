/* 
    airport-program.c
    Project 1
    Zaquariah Holland

    This is the driver for the airport program. It displays the main menu presenting a selection of options 
    for the user to get information about the airports in the system. The main function will then call functions
    in 'airport.c' to calculate and retrieve information, which will then be printed here. 
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "airport-program.h"

/* 
    main 
    ---------------------------
    This is the main driver of your program. See the comments below on how to complete the driver.
    Returns: 0 
*/
int main(int argc, char *argv[])
{
    Airport airports[MAX];	// MAX defined in 'airport.h'
	Airport output[MAX];	// MAX defined in 'airport.h'
	Airport search;			// an empty struct varible
	Airport range[MAX];
	Airport temp1;
	Airport temp2;
	char user1[4];
	char user2[4];
	int i;
	int choice;
	int userRange;
	int resultsLength;		// used for a pointer
	
    fillAirports(airports);

    while(1)
    {
        /* Call the function to print the menu */
        printMenu();
        /* Get the menu choice from the user */
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                /*
                    1. Get a 3-letter airport code from the user.
                    2. Call findAirport()
                    3. If either the airport's latitude or longitude is -99999, that means the airport was not found. Print an appropriate error. 
                    4. If airport found, print the airport information.
                */ 
				printf("Enter a 3 letter IATA code : ");
				scanf("%s", user1);
				temp1 = findAirport(airports, MAX, user1);
				if (temp1.lat == -99999) {
					printf("IATA Code does not exits!\n");
					break;
				}
				else {
					printf("\nCODE\tName\t\t\t\tLatitude\tLongitude\n");
					printAirport(temp1);
				}
                break;
            case 2:
                /*
                    Call the printAirports() function.
                */
				printAirports(airports, MAX);
                break;
            case 3:
                /*
                    1. Get two 3-letter airport codes from the user.
                    2. Call findAirport() twice (one each for each of the airport codes entered).
                    3. If either airport's latitude or longitude is -99999, that means that airport was not found. Print an appropriate error.
                    4. If both airports found successfully, call the calculateDistance() function.
                    5. Print out the distance between the two airports.
                */
				printf("Enter the 1st 3 letter IATA code : ");
				scanf("%s", user1);
				temp1 = findAirport(airports, MAX, user1);
				printf("Enter the 2nd 3 letter IATA code : ");
				scanf("%s", user2);
				temp2 = findAirport(airports, MAX, user2);
				if (temp1.lat == -99999 || temp2.lat == -99999) {
					printf("IATA Code does not exits!\n");
					break;
				}
				else {
					printf("Distance between %s and %s is %lf miles.\n", temp1.code, temp2.code, calculateDistance(temp1, temp2));
				}
                break;
            case 4:
                /*  
                    1. Get a 3-letter airport code from the user. 
                    2. Call findAirport() on this origin airport code.
                    3. If the airport's latitude or longitude is -99999, that means the
					   airport was not found. Print an appropriate error.
                    4. If airport found successfully, get a range in miles (integer) 
					   from the user. 
                    5. Call findInRange() to get an array of Airports within the specified 
					   range of the origin airport.
                    6. Print the return array of airports in range. If the result length 
					   returned is zero, print a message that no airports were found.
                */
				printf("Enter a 3 letter IATA code : ");
				scanf("%s", user1);
				temp1 = findAirport(airports, MAX, user1);
				if (temp1.lat == -99999) {
					printf("IATA Code does not exits!\n");
					break;
				}
				printf("Your range (in miles) : ");
				scanf("%d", &userRange);
				findInRange(airports, MAX, temp1, userRange, range, &resultsLength);
				if (resultsLength < 1) {
					printf("No airports found within %d miles\n", userRange);
					break;
				}
				else {
					printf("\nCODE\tName\t\t\t\tLatitude\tLongitude\n");
					for (i = 0; i < resultsLength; i++) {
						if (range[i].lat == temp1.lat) {
							
						}
						else {
							printAirport(range[i]);
						}
					}
				}
                break;
            case 0:
            default:
                printf("Good-bye!\n");
                return 0;
        }
    }
    return 0;
}

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu() {
    printf("\n#########################################\n");
    printf("\tAirport Program Menu\n");
    printf("#########################################\n");
    printf("\t1 - Get Airport Information\n");
    printf("\t2 - Get Airport Listing\n");
    printf("\t3 - Get Distance Between Two Airports\n");
    printf("\t4 - Find Airports Within Range\n");
    printf("\t0 - Quit\n");
    printf("Enter your selection: ");
}
